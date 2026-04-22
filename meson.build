project('kinari', 'c', 'cpp', version: '0.1.0')

mozjs_p = subproject('mozjs')
mozjs = mozjs_p.get_variable('mozjs_dep')

inc = include_directories('include')
src = ['src/main.cpp', 'src/kinari.cpp', 'src/global/global.cpp', 'src/global/print.cpp']

executable('kinari',
    src,
    export_dynamic: true,
    cpp_args: ['-Wno-invalid-offsetof'],
    dependencies: mozjs,
    include_directories: inc,
    link_args: ['-fuse-ld=mold'])