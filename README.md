# Process Monitor

Process Monitor is a simple... well.. process monitor for Linux that uses Gtk 3 for the UI. Not sure what wisdom you expected with reading this line....

## Building from source

Pre requirements for building from source are:
- g++
- gtkmm
- meson
- ninja

To build the repository simly do:
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

## License

Process Monitor is licenced under the MIT license