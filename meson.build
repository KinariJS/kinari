project('kinari', 'c', 'cpp', version: '0.1.0')

mozjs_p = subproject('mozjs')
mozjs = mozjs_p.get_variable('mozjs_dep')

inc = include_directories('include')
src = ['src/main.cpp', 'src/boilerplate.cpp']

executable('kinari', src, dependencies: mozjs, include_directories: inc)