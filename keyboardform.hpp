#ifndef KEYBOARDFORM_HPP
#define KEYBOARDFORM_HPP

#include <QWidget>

namespace Ui
{
    class KeyboardForm;
}

class QHBoxLayout;
class Button;

class KeyboardForm : public QWidget
{
    Q_OBJECT

public:
    explicit KeyboardForm(QWidget *parent = nullptr);
    ~KeyboardForm();
signals:
    void keyPressed(const QString &);
private:
    enum
    {
        BUTTON_SIZE = 50,
        FONT_SIZE = 24
    };
    Ui::KeyboardForm *ui;
    QHBoxLayout* loadKeys(char start, char end, QColor color);
    QHBoxLayout* loadKeys(const QString &chars, QColor color);
    Button *createKey(const QString& text, QColor color);
};

#endif // KEYBOARDFORM_HPP
