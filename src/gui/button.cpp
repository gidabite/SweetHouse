#include "button.h"

Button::Button()
{

}

uint Button::getId() const
{
    return id;
}

void Button::setId(const uint &value)
{
    id = value;
}

bool Button::getIsShow() const
{
    return isShow;
}

void Button::setIsShow(bool value)
{
    isShow = value;
}

