#include "cell.h"

Cell::Cell()
{
    color = BLACK;
    is_blank = true;
}

Cell::Cell(colorType _color, bool _blank = false)
{
    color = _color;
    is_blank = _blank;
}

bool Cell::isBlank()
{
    if(this->is_blank)
    {
        return true;
    }
    return false;
}

QColor Cell::getQColor()
{
    QColor color;
    if(this->is_blank) color.setRgb(0, 0, 0);
    else{
        switch(this->color)
        {
        case BLUE: color.setRgb(0, 0, 255); break;
        case YELLOW: color.setRgb(0, 255, 255); break;
        default: color.setRgb(255, 255, 255);
        }
    }
    return color;
}
