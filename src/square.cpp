#include "square.h"
#include "config.h"

Square::Square(int x, int y, int size, bool fill) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->fill = fill;
}

void Square::update(bool table[1000][1000]) {
    if(y + size < Config::height){
        
        if(!table[x][y + 1]){
            table[x][y] = false;
            table[x][y + 1] = true;
            y += 1;
        }
        else if(!table[x + 1][y + 1]){
            table[x][y] = false;
            table[x + 1][y + 1] = true;
            y += 1;
            x += 1;
        }
        else if(x > 0 && !table[x - 1][y + 1]){
            table[x][y] = false;
            table[x - 1][y + 1] = true;
            y += 1;
            x -= 1;
        }
        
        
    }
}

void Square::update(int x, int y){
    this->x = x;
    this->y = y;
}

void Square::draw() {

    int scale = Config::pixelSize;

    if(fill){
        DrawRectangle(x * scale, y * scale, size * scale, size * scale, YELLOW);
    }
    else {
        DrawRectangleLines(x * scale, y * scale, size * scale, size * scale, WHITE);
    }
}