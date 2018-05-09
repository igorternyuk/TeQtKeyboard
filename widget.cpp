#include "widget.h"
#include "ui_widget.h"
#include "keyboardform.hpp"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    mKeyboard = new KeyboardForm(this);
    ui->setupUi(this);
    ui->lineEdit->setClearButtonEnabled(true);
    ui->scrollArea->setWidget(mKeyboard);
    connect(mKeyboard, &KeyboardForm::keyPressed, [&](auto &keyText){
        auto text = ui->lineEdit->text();
        auto pos = ui->lineEdit->cursorPosition();
        text.insert(pos, keyText);
        ui->lineEdit->setText(text);
    });
}

Widget::~Widget()
{
    delete ui;
}
