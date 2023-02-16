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
  nh->param<std::string>("listen_topic",listen_topic,"sub");
  sub = nh->subscribe<std_msgs::String>(listen_topic, 1, &RosGui::chatterCallback, this);

  //publish a message
  std::string hello_topic;
  nh->param<std::string>("hello_topic",hello_topic,"chatter");
  pub=nh->advertise<std_msgs::String>(hello_topic,1);
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
    ROS_INFO("%s",msg->data.c_str() );
}

void RosGui::on_pushButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"test message";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());

  pub.publish(msg);
}
void RosGui::on_pushButton2_clicked(){
  std::string listen_topic;
  nh->param<std::string>("listen_topic",listen_topic,"sub");
  sub = nh->subscribe<std_msgs::String>(listen_topic, 1, &RosGui::chatterCallback, this);
}
