#include "graphview.h"

#include <gtkmm.h>

namespace ProcessMonitor {

GraphView* GraphView::Create()
{
  auto builder = Gtk::Builder::create_from_resource("/widgets/graphview.glade");
  ProcessMonitor::GraphView *widget;
  builder->get_widget_derived("graphview", widget);

  return widget;
}

GraphView::GraphView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
  Gtk::Box(cobject),
  builder_(refGlade)
{
  
}

}