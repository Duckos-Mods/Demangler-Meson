
project('demangler', 'cpp', default_options: ['cpp_std=c++latest'], version: '1.0.0')
sources = [
    'src/Demangle.cpp',
    'src/DLangDemangle.cpp',
    'src/ItaniumDemangle.cpp',
    'src/MicrosoftDemangle.cpp',
    'src/MicrosoftDemangleNodes.cpp',
    'src/RustDemangle.cpp',

    'include/demangler/Demangle.h',
    'include/demangler/DemangleConfig.h',
    'include/demangler/ItaniumDemangle.h',
    'include/demangler/MicrosoftDemangle.h',
    'include/demangler/MicrosoftDemangleNodes.h',
    'include/demangler/StringViewExtras.h',
    'include/demangler/Utility.h',
]    

headers = [
    'include/demangler/Demangle.h',
    'include/demangler/DemangleConfig.h',
    'include/demangler/ItaniumDemangle.h',
    'include/demangler/MicrosoftDemangle.h',
    'include/demangler/MicrosoftDemangleNodes.h',
    'include/demangler/StringViewExtras.h',
    'include/demangler/Utility.h',
]
source_includes = include_directories('include/', 'include/demangler')
testing = get_option('enableTests') 

meson_lib = static_library(
    'demangler',
    sources : sources,
    include_directories: source_includes,
    install : true,
    )

install_headers(headers, subdir: 'demangler')

project_dep = declare_dependency(
  include_directories: source_includes,
  link_with : meson_lib
)
set_variable(meson.project_name() + '_dep', project_dep)

project_description = 'Meson Wrapper For LLVM Demangler'
pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : project_description,
  subdirs : meson.project_name(),
  libraries : meson_lib,
)



if testing
    test_sources = [
        'test/main.cpp'
    ]
    executable(
        'demangler',
        test_sources,
        include_directories: source_includes,
        link_with: meson_lib, 
        
    )
endif
