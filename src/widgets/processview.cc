#include "processview.h"

#include <gtkmm.h>

namespace ProcessMonitor {

ProcessView* ProcessView::Create()
{
  auto builder = Gtk::Builder::create_from_resource("/widgets/processview.glade");
  ProcessMonitor::ProcessView *widget;
  builder->get_widget_derived("processview", widget);

  return widget;
}

ProcessView::ProcessView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
  Gtk::Widget(cobject),
  builder_(refGlade)
{
  builder_->get_widget("treeprocess", treeprocess_);
}

}
