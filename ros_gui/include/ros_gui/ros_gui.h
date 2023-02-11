#ifndef ROS_GUI_H
#define ROS_GUI_H
#include "ros/ros.h"
#include <QWidget>

namespace Ui {
class RosGui;
}

class RosGui : public QWidget
{
  Q_OBJECT

public:
  explicit RosGui(QWidget *parent = nullptr);
  ~RosGui();

private:
  Ui::RosGui *ui;
};

#endif // ROS_GUI_H
