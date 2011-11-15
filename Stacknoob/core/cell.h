#ifndef CELL_H
#define CELL_H

#include <QColor>

enum colorType {BLACK, CYAN ,YELLOW ,MAGENTA ,ORANGE ,BLUE ,GREEN ,RED };

class Cell
{
protected:
    colorType color;
    bool is_blank;

public:
    Cell();
    Cell(colorType _color, bool _blank);
    bool isBlank();
    void setIsBlank(bool b) { this->is_blank = b; }
    void setColor(colorType _color) { this->color = _color; }
    QColor getQColor();
};

#endif // CELL_H
