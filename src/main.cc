#include <gtkmm.h>
#include <iostream>

#include "common/core.h"
#include "windows/mainwindow.h"

int main(int argc, char *argv[]) {
  // TODO: Make separate debug and release configurations
  putenv((char*)"GTK_THEME=Adwaita-dark");

  auto app = Gtk::Application::create(argc, argv, "org.gnome.process-monitor");
  auto window = ProcessMonitor::MainWindow::Create();

  return app->run(*window);

  /* ProcessView interaction example
  
  ProcessMonitor::Core& core = ProcessMonitor::Core::getInstance();
  std::vector<int>& pids = core.get_pid_list();

  while (true) {
    core.refresh_pids();

    for (auto &pid : pids) {
      auto pidinfo = core.get_pid_info(pid);
      std::cout << pid << " " << pidinfo.name << " " << pidinfo.memory << std::endl;
    }

    // "lazy" pause
    char c;
    std::cin >> c;
  }*/
}
