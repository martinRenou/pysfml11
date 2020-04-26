import os
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

__version__ = '0.0.2'


class get_pybind_include(object):
    """Helper class to determine the pybind11 include path

    The purpose of this class is to postpone importing pybind11
    until it is actually installed, so that the ``get_include()``
    method can be invoked. """

    def __init__(self, user=False):
        self.user = user

    def __str__(self):
        import pybind11
        return pybind11.get_include(self.user)

include_dirs = [get_pybind_include(), get_pybind_include(user=True)]
library_dirs = []

conda_prefix = os.getenv('CONDA_PREFIX', os.getenv('MINICONDAPATH', os.getenv('CONDA')))
if conda_prefix:
    if sys.platform.startswith('win'):
        include_dirs.append(os.path.join(conda_prefix, 'Library', 'include'))
        library_dirs.append(os.path.join(conda_prefix, 'Library', 'lib'))
    else:
        include_dirs.append(os.path.join(conda_prefix, 'include'))
        library_dirs.append(os.path.join(conda_prefix, 'lib'))
else:
    include_dirs.append('/usr/local/include')
    library_dirs.append('/usr/local/lib')

ext_modules = [
    Extension(
        'pysfml11',
        ['src/main.cpp'],
        include_dirs=include_dirs,
        library_dirs=library_dirs,
        libraries=['sfml-network', 'sfml-audio', 'sfml-graphics', 'sfml-window', 'sfml-system'],
        language='c++'
    ),
]


# As of Python 3.6, CCompiler has a `has_flag` method.
# cf http://bugs.python.org/issue26689
def has_flag(compiler, flagname):
    """Return a boolean indicating whether a flag name is supported on
    the specified compiler.
    """
    import tempfile
    with tempfile.NamedTemporaryFile('w', suffix='.cpp') as f:
        f.write('int main (int argc, char **argv) { return 0; }')
        try:
            compiler.compile([f.name], extra_postargs=[flagname])
        except setuptools.distutils.errors.CompileError:
            return False
    return True


def cpp_flag(compiler):
    """Return the -std=c++[11/14/17] compiler flag.

    The newer version is prefered over c++11 (when it is available).
    """
    flags = ['-std=c++17', '-std=c++14', '-std=c++11']

    for flag in flags:
        if has_flag(compiler, flag): return flag

    raise RuntimeError('Unsupported compiler -- at least C++11 support '
                       'is needed!')


class BuildExt(build_ext):
    """A custom build extension for adding compiler-specific options."""
    c_opts = {
        'msvc': ['/EHsc'],
        'unix': [],
    }
    l_opts = {
        'msvc': [],
        'unix': [],
    }

    if sys.platform == 'darwin':
        darwin_opts = ['-stdlib=libc++', '-mmacosx-version-min=10.14']
        c_opts['unix'] += darwin_opts
        l_opts['unix'] += darwin_opts

    def build_extensions(self):
        ct = self.compiler.compiler_type
        opts = self.c_opts.get(ct, [])
        link_opts = self.l_opts.get(ct, [])
        if ct == 'unix':
            opts.append('-DVERSION_INFO="%s"' % __version__)
            opts.append(cpp_flag(self.compiler))
            if has_flag(self.compiler, '-fvisibility=hidden'):
                opts.append('-fvisibility=hidden')
        elif ct == 'msvc':
            opts.append('/DVERSION_INFO=\\"%s\\"' % __version__)
        for ext in self.extensions:
            ext.extra_compile_args = opts
            ext.extra_link_args = link_opts
        build_ext.build_extensions(self)

setup(
    name='pysfml11',
    version=__version__,
    author='Martin Renou',
    author_email='martin.renou@gmail.com',
    url='https://github.com/martinRenou/pysfml11',
    description='Python binding for the SFML library, using pybind11',
    long_description='',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.4'],
    setup_requires=['pybind11>=2.4'],
    cmdclass={'build_ext': BuildExt},
    zip_safe=False,
)
