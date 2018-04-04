# meson modules
gnome = import('gnome')

# project dependencies
gtkdep = dependency('gtkmm-3.0')

src = [
  'main.cc',

  # widgets
  'widgets/graphview.cc',
  'widgets/graphview.h',
  'widgets/processview.cc',
  'widgets/processview.h',

  # common
  'common/core.cc',
  'common/core.h',

  # windows
  'windows/mainwindow.cc',
  'windows/mainwindow.h'
]

resources = gnome.compile_resources(
  'resources',
  'resources.xml',
  source_dir : './',
  c_name : 'as'
)

executable(
  'process-monitor',
  src,
  resources,
  dependencies: gtkdep
)
