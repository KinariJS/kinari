project('mozjs', 'cpp', version: '150')

cpp = meson.get_compiler('cpp')
host_os = host_machine.system()

supported = ['linux']

if host_os not in supported
    error(host_os + ' is unsupported')
endif

defs = ['-DDEBUG', '-DXP_UNIX']

name = 'mozjs-' + host_os + '-x86_64'

dep = subproject(name)

src_dir = meson.current_source_dir() / '..' / name

inc_dir = dep.get_variable('inc')
lib_dir = src_dir / 'lib'

libs = []
foreach l : ['js_static', 'mozglue', 'jsrust']
    libs += cpp.find_library(l, dirs: lib_dir, static: true)
endforeach

additional_libs = []
if host_os == 'linux'
    additional_libs += dependency('zlib')
endif

mozjs_dep = declare_dependency(
    include_directories: inc_dir,
    dependencies: [libs, additional_libs],
    compile_args: ['-std=gnu++20', defs]
)