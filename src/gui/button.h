#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button();
    uint getId() const;
    void setId(const uint &value);
    bool getIsShow() const;
    void setIsShow(bool value);

private:
    uint id;
    bool isShow = false;
};

#endif // BUTTON_H
