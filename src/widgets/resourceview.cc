#include "resourceview.h"

#include <gtkmm.h>

namespace ProcessMonitor {

ResourceView* ResourceView::Create()
{
  auto builder = Gtk::Builder::create_from_resource("/widgets/resourceview.glade");
  ProcessMonitor::ResourceView *widget;
  builder->get_widget_derived("resourceview", widget);

  return widget;
}

ResourceView::ResourceView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
  Gtk::Box(cobject),
  builder_(refGlade)
{
  
}

}