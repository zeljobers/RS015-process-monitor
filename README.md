# Process Monitor

Process Monitor is a simple, Gtk based, process monitor for Linux.

For the roadmap please see the [projects page](https://github.com/MATF-RS18/RS015-process-monitor/projects/1). 

## Building from source

Pre requirements for building from source are:
- g++
- gtkmm
- meson
- ninja

To build the repository simply do:
```
# clone the repo
git clone https://github.com/MATF-RS18/RS015-process-monitor.git ProcessMonitor
cd ProcessMonitor

# build the repo
meson build
ninja -C build

# launch the app
./build/src/process-monitor
```

## Contributing

Use MVVM pattern when adding new pieces of code.

Use [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) for the coding style.

## License

Process Monitor is licenced under the MIT license
