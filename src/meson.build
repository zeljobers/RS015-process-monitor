# meson modules
gnome = import('gnome')

# project dependencies
gtkdep = dependency('gtkmm-3.0')

src = [
  'main.cc',

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
