#include <QApplication>
#include "ros_gui.h"


int main(int argc, char *argv[])
{

//  ros::init(argc, argv, "gui_node",ros::init_options::AnonymousName);
  ros::init(argc, argv, "ros_gui_node");
  QApplication a(argc, argv);

  RosGui w;

  // set the window title as the node name
  w.setWindowTitle(QString::fromStdString(
                       ros::this_node::getName()));

  // load the icon from our qrc file and set it as the application icon
//  QIcon icon(":/icons/my_gui_icon.png");
//  w.setWindowIcon(icon);

  w.show();
  return a.exec();
}
