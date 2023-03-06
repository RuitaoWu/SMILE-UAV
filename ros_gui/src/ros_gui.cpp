#include "ros_gui.h"
#include "ui_ros_gui.h"

RosGui::RosGui(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RosGui)
{
  ui->setupUi(this);
  nh.reset(new ros::NodeHandle("~"));

  //subscrib
  std::string listen_topic;
  nh->param<std::string>("listen_topic",listen_topic,"/listener/sub");
  sub = nh->subscribe<std_msgs::String>(listen_topic, 1000, &RosGui::chatterCallback, this);

  //publish a message
  std::string hello_topic;
  nh->param<std::string>("hello_topic",hello_topic,"talker");
  pub=nh->advertise<std_msgs::String>(hello_topic,1000);
}

RosGui::~RosGui()
{
  delete ui;
}
void RosGui::spinOnce(){
  if(ros::ok()){
    ros::spinOnce();
  }else{
    QApplication::quit();
  }
}
void RosGui::chatterCallback(const std_msgs::String::ConstPtr &msg){
    auto qstring_msg = QString::fromStdString( msg->data.c_str() );
    ui->listener->setText("qstring_msg");

}

void RosGui::on_upButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"up button";
  msg.data=ss.str();
  system("roslaunch ros_gui gazebo.launch");
  ROS_INFO("%s", msg.data.c_str());
}
void RosGui::on_downButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"down button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());
}
void RosGui::on_leftButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"left button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());
}
void RosGui::on_rightButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"right button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());
}
void RosGui::on_forwardButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"forward button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());
}
void RosGui::on_backwardButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"backward button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());
}

// start button click event
void RosGui::on_startButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss<<"Test message: start";
  system("rostopic pub -1 /default/joint_motor_controller/command std_msgs/Float64 50.0");
  msg.data = ss.str();
  //publish message
  pub.publish(msg);
  ui->talker->setText(QString(msg.data.c_str()));
  //change button name
  //if the name is start change to stop
  if(ui->startButton->text().compare("Start") == 0){
    ui->startButton->setAutoFillBackground(true);
    QPalette pal = ui->startButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    ui->startButton->setText(QString("Stop"));
  }else{
    ui->talker->setText(QString("Test message: stop"));
    ui->startButton->setText(QString("Start"));
  }
}
