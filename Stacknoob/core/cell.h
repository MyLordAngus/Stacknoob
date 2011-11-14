#ifndef CELL_H
#define CELL_H

class Cell
{
protected:
    enum colorType {BLACK, RED , BLUE};
    colorType color;
    bool is_blank;

public:
    Cell();
    Cell(colorType _color, bool _blank);
    bool isEmpty();
    void setIsBlank(bool b) { this->is_blank = b; }
};

#endif // CELL_H