#include "widget.h"
#include <QPushButton>
#include <QDebug>
#include "mybrowser.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *nut = new QPushButton("nut",this);
    connect(nut,SIGNAL(clicked()),this,SLOT(nutbam()));
}

Widget::~Widget()
{

}

void Widget::nutbam()
{

    QString filePath = MyBrowser::getPath();
    qDebug() << "Path: " << filePath;


}
