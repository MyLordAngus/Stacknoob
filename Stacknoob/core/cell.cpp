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

bool Cell::isEmpty()
{
    if(this->is_blank)
    {
        return true;
    }
    return false;
}
