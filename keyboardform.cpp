#include "keyboardform.hpp"
#include "ui_keyboardform.h"
#include "button.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

KeyboardForm::KeyboardForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyboardForm)
{
    ui->setupUi(this);
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(loadKeys('a', 'm', QColor("#2ccbdc")));
    mainLayout->addLayout(loadKeys('n', 'z', QColor("#2ccbdc")));
    mainLayout->addLayout(loadKeys("aбвгдеёжзийклмно", QColor("#ffff66")));
    mainLayout->addLayout(loadKeys("прстуфхцшщъыьэюя", QColor("#ffff66")));
    mainLayout->addLayout(loadKeys("äöüßñóéáúíçãõôїєі", QColor("#a0db8e")));
    mainLayout->addLayout(loadKeys("!?':;.¡¿@#$%^*", QColor("#f6546a")));
    mainLayout->addLayout(loadKeys("()_+-*/{}[]{}", QColor("#f6546a")));
    this->setLayout(mainLayout);
}

KeyboardForm::~KeyboardForm()
{
    delete ui;
}

QHBoxLayout *KeyboardForm::loadKeys(char start, char end, QColor color)
{
    auto hbox = new QHBoxLayout(this);
    for(auto ch = start; ch <= end; ++ch)
    {
        QString title(ch);
        auto key = createKey(title, color);
        hbox->addWidget(key);
    }
    hbox->setMargin(0);
    return hbox;
}

QHBoxLayout *KeyboardForm::loadKeys(const QString &chars, QColor color)
{
    auto hbox = new QHBoxLayout(this);
    for(auto ch: chars)
    {
        QString title(ch);
        auto key = createKey(title, color);
        hbox->addWidget(key);
    }
    hbox->setMargin(0);
    return hbox;
}

Button *KeyboardForm::createKey(const QString &text, QColor color)
{
    auto key = new Button(text, this);
    connect(key, &Button::onLeftButtonClicked, [&](Button *btn){
        emit keyPressed(btn->text());
    });
    connect(key, &Button::onRightButtonClicked, [&](Button *btn){
        emit keyPressed(btn->text().toUpper());
    });
    key->setFixedSize(BUTTON_SIZE, BUTTON_SIZE);
    key->setFont(QFont("Arial", FONT_SIZE));
    auto pal = key->palette();
    pal.setColor(QPalette::Button, color);
    key->setAutoFillBackground(true);
    key->setPalette(pal);
    key->update();
    return key;
}
