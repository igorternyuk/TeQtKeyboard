#include "button.hpp"
#include <QMouseEvent>
#include <QDebug>

Button::Button(const QString text, QWidget *parent):
    QPushButton(text, parent)
{}

void Button::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit onLeftButtonClicked(this);
    } else if(event->button() == Qt::RightButton)
    {
        emit onRightButtonClicked(this);
    }
}
