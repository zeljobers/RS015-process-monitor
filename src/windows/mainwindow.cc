#include "mainwindow.h"

#include <iostream>
#include <gtkmm.h>

namespace PorcessMonitor {

MainWindow* MainWindow::Create() {
  auto builder = Gtk::Builder::create_from_resource("/windows/mainwindow.glade");
  PorcessMonitor::MainWindow *window;
  builder->get_widget_derived("mainwindow", window);

  return window;
}

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
  Gtk::Window(cobject),
  builder_(refGlade)
{
  Gtk::HeaderBar *headerbar;
  builder_->get_widget("headerbar", headerbar);

  show_all();
}

}