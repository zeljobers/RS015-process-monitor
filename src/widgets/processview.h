#ifndef PROCESSMONITOR_WIDGETS_PROCESSVIEW_H_
#define PROCESSMONITOR_WIDGETS_PROCESSVIEW_H_

#include <gtkmm.h>

namespace ProcessMonitor {

class ProcessView : public Gtk::Widget {
 public:
  static ProcessView* Create();
  ProcessView(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade);

 private:
  Glib::RefPtr<Gtk::Builder> builder_;
  Gtk::TreeView* treeprocess_;
};

}

#endif