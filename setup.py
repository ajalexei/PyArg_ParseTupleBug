import datetime
from setuptools import setup, Extension

now = datetime.datetime.now()                                           # current date
vn = '.'.join(map(str, [now.year, now.month, now.day]))

c_std = 'c11'

bug = Extension(
	'papt.bug',
	['src/bug.c'],
    language = 'c',
    include_dirs=[],
	library_dirs = [],
    libraries = [],
    extra_compile_args = ['-std=' + c_std, '-Wall', '-pedantic']
)

setup(
	name = 'papt',	                                                    # name of the package
	version = vn,														# version of the package
	author = '',                                                        # author of the package
	author_email = '',                                                  # email of the author
	packages = ['papt'],
    package_dir = {'papt': 'src'},
	license='LICENSE.txt',
	description = 'Reproduce a PyArg_ParseTuple bug',
	long_description = open('README.txt').read(),
	ext_modules = [bug]
)
