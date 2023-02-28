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
    ui->listener->setText(qstring_msg);
    ROS_INFO("%s",msg->data.c_str() );

}

void RosGui::on_upButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"up button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());

  pub.publish(msg);
}
void RosGui::on_downButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"down button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());

  pub.publish(msg);
}
void RosGui::on_leftButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"left button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());

  pub.publish(msg);
}
void RosGui::on_rightButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"right button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());

  pub.publish(msg);

}
void RosGui::on_forwardButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"forward button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());

  pub.publish(msg);
}
void RosGui::on_backwardButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss <<"backward button";
  msg.data=ss.str();
  ROS_INFO("%s", msg.data.c_str());

  pub.publish(msg);
}
void RosGui::on_startButton_clicked(){
  std_msgs::String msg;
  std::stringstream ss;
  ss<<"Test message: start";
  msg.data = ss.str();
  pub.publish(msg);
  // QString qstr = QString(msg.data.c_str());
  ui->listener->setText(QString(msg.data.c_str()));
  if(ui->startButton->text().compare("Start") == 0){
    ui->startButton->setAutoFillBackground(true);
    QPalette pal = ui->startButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    ui->startButton->setText(QString("Stop"));
  }else{
    ui->listener->setText(QString("Test message: stop"));
    ui->startButton->setText(QString("Start"));
  }
}
