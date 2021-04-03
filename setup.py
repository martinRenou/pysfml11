import os
import sys
from setuptools import setup

import pybind11
from pybind11.setup_helpers import Pybind11Extension, build_ext

__version__ = '0.0.2'

include_dirs = [pybind11.get_include(False), pybind11.get_include(True)]
library_dirs = []

conda_prefix = os.getenv(
    'CONDA_PREFIX', os.getenv('MINICONDAPATH', os.getenv('CONDA')))
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
    name="pysfml11",
    version=__version__,
    author='Martin Renou',
    author_email='martin.renou@gmail.com',
    url='https://github.com/martinRenou/pysfml11',
    description='Python binding for the SFML library, using pybind11',
    long_description="",
    ext_modules=ext_modules,
    extras_require={"test": "pytest"},
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
)
