#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class QMouseEvent;

class Button: public QPushButton
{
    Q_OBJECT
public:
    explicit Button(const QString text = "Button",
                    QWidget *parent = nullptr);
signals:
    void onLeftButtonClicked(Button*);
    void onRightButtonClicked(Button*);
private slots:
    void mousePressEvent(QMouseEvent* event);
};

#endif // BUTTON_H
