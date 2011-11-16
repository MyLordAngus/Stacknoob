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
    return this->is_blank;
}

QColor Cell::getQColor()
{
    QColor color;
    if(this->is_blank) { color.setRgb(100, 100, 100); }
    else{
        switch(this->color)
        {
        case BLACK: color.setRgb(255, 0, 0); break;
        case CYAN: color.setRgb(150, 200, 200); break;
        case YELLOW: color.setRgb(255, 200, 50); break;
        case MAGENTA: color.setRgb(120, 0, 120); break;
        case ORANGE: color.setRgb(255, 150, 50); break;
        case BLUE: color.setRgb(0, 130, 130); break;
        case GREEN: color.setRgb(60, 200, 60); break;
        case RED: color.setRgb(255, 60, 60); break;
        default: color.setRgb(255, 0, 0); break;
        }
    }
    return color;
}
