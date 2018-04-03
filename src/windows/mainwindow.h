#ifndef NAUTILIDAE_MAINWINDOW_H
#define NAUTILIDAE_MAINWINDOW_H

#include <gtkmm.h>

namespace PorcessMonitor {

class MainWindow : public Gtk::Window {
 public:
  static MainWindow* Create();
  MainWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade);

 private:
  Glib::RefPtr<Gtk::Builder> builder_;
};

}

#endif