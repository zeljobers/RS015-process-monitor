#include <gtkmm.h>

#include "windows/mainwindow.h"

int main(int argc, char *argv[])
{
  // TODO: Make separate debug and release configurations
  putenv((char*)"GTK_THEME=Adwaita-dark");

  auto app = Gtk::Application::create(argc, argv, "org.gnome.process-monitor");
  auto window = PorcessMonitor::MainWindow::Create();

  return app->run(*window);
}