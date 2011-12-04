#ifndef CELL_H
#define CELL_H

#include <QColor>

enum colorType { BLACK, CYAN, YELLOW, MAGENTA, ORANGE, BLUE, GREEN, RED };

class Cell
{
public:
    Cell();
    Cell(colorType, bool);

    bool isBlank();
    void setIsBlank(bool b) { this->is_blank = b; }
    void setColor(colorType c) { this->color = c; }

    /// Return the QColor object to paint it on view
    QColor getQColor();

protected:
    colorType color;
    bool is_blank;
};

#endif // CELL_H
