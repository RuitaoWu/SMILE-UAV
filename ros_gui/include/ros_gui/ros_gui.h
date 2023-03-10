#ifndef ROS_GUI_H
#define ROS_GUI_H
#include "ros/ros.h"
#include <QWidget>
#include <std_msgs/String.h>
namespace Ui {
class RosGui;
}

class RosGui : public QWidget
{
  Q_OBJECT

public:
  explicit RosGui(QWidget *parent = nullptr);
  ~RosGui();
   void chatterCallback(const std_msgs::String::ConstPtr& msg);

public slots:
    void spinOnce();
private slots:
    void on_upButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_forwardButton_clicked();
    void on_backwardButton_clicked();
    void on_startButton_clicked();


private:
  Ui::RosGui *ui;
  
  ros::NodeHandlePtr nh;
  ros::Subscriber sub;
  ros::Publisher pub;
};

#endif // ROS_GUI_H
