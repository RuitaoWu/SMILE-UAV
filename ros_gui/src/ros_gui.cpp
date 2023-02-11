#include "ros_gui.h"
#include "ui_ros_gui.h"

RosGui::RosGui(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RosGui)
{
  ui->setupUi(this);
}

RosGui::~RosGui()
{
  delete ui;
}
