import os
import sys

__version__ = '0.0.2'

setup_args = dict(
    name="pysfml11",
    version=__version__,
    author='Martin Renou',
    author_email='martin.renou@gmail.com',
    url='https://github.com/martinRenou/pysfml11',
    description='Python binding for the SFML library, using pybind11',
    long_description='',
    extras_require={"test": "pytest"},
    zip_safe=False,
)

print('--- BUILD PYSFML11', os.getenv('PYSFML11_BUILD_DEPENDENCIES'))

if os.getenv('PYSFML11_BUILD_DEPENDENCIES') == '1':
    print('--- BUILD PYSFML11 WITH DEPENDENCIES')
    try:
        from skbuild import setup
        from skbuild.exceptions import SKBuildError
        from skbuild.cmaker import get_cmake_version
        from packaging.version import LegacyVersion

        setup_requires = []
        try:
            if LegacyVersion(get_cmake_version()) < LegacyVersion("3.15"):
                setup_requires.append('cmake')
        except SKBuildError:
            setup_requires.append('cmake')
    except ImportError:
        print(
            'scikit-build is required to build from source.', file=sys.stderr)
        print('Please run:', file=sys.stderr)
        print('', file=sys.stderr)
        print('  python -m pip install scikit-build')
        sys.exit(1)

    def accept_file(name):
        return not (
            name.endswith('.a') or      # static libraries
            name.endswith('.lib') or    # lib files
            name.endswith('.hpp') or    # headers
            name.endswith('.h') or      # headers
            name.endswith('.cmake') or  # cmake files
            name.endswith('.pc') or     # package-config files
            name.endswith('.txt')       # text files
        )

    def cmake_process_manifest_hook(cmake_manifest):
        print(cmake_manifest)
        print('\n\n')
        cmake_manifest = list(filter(accept_file, cmake_manifest))
        print(cmake_manifest)
        return cmake_manifest

    setup(
        **setup_args,
        # packages=['pysfml11'],
        setup_requires=setup_requires,
        cmake_args=[
            '-DCMAKE_INSTALL_LIBDIR=lib',
            '-DPYTHON_EXECUTABLE:FILEPATH=' + sys.executable
        ],
        cmake_process_manifest_hook=cmake_process_manifest_hook
    )
else:
    from setuptools import setup

    import pybind11
    from pybind11.setup_helpers import Pybind11Extension, build_ext

    include_dirs = [pybind11.get_include(False), pybind11.get_include(True)]
    library_dirs = []

    conda_prefix = os.getenv(
        'CONDA_PREFIX', os.getenv('MINICONDAPATH', os.getenv('CONDA')))
    if conda_prefix:
        if sys.platform.startswith('win'):
            include_dirs.append(
                os.path.join(conda_prefix, 'Library', 'include'))
            library_dirs.append(
                os.path.join(conda_prefix, 'Library', 'lib'))
        else:
            include_dirs.append(
                os.path.join(conda_prefix, 'include'))
            library_dirs.append(
                os.path.join(conda_prefix, 'lib'))
    else:
        include_dirs.append('/usr/local/include')
        library_dirs.append('/usr/local/lib')

    ext_modules = [
        Pybind11Extension(
            "pysfml11",
            ["src/main.cpp"],
            include_dirs=include_dirs,
            library_dirs=library_dirs,
            libraries=[
                'sfml-network', 'sfml-audio', 'sfml-graphics',
                'sfml-window', 'sfml-system'
            ],
            language='c++'
        ),
    ]

    setup(
        **setup_args,
        ext_modules=ext_modules,
        cmdclass={'build_ext': build_ext},
    )
