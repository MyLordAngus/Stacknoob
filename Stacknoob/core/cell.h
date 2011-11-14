#ifndef CELL_H
#define CELL_H

enum colorType {BLACK ,CYAN ,YELLOW ,MAGENTA ,ORANGE ,BLUE ,GREEN ,RED };

class Cell
{
protected:
    colorType color;
    bool is_blank;

public:
    Cell();
    Cell(colorType _color, bool _blank);
    bool isEmpty();
    void setIsBlank(bool b) { this->is_blank = b; }
};

#endif // CELL_H
