#include "square.h"
#include "config.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Square::Square(int x, int y, int size, bool fill) {
    this->x = x;
    this->y = y;
    //this->size = size;
    this->fill = fill;
    float randomHue = 60;
    float randomSaturation = (float)GetRandomValue(40, 50) / 100.0f;
    float randomValue = (float)GetRandomValue(85, 100) / 100.0f;
    this->color = ColorFromHSV(randomHue, randomSaturation, randomValue);
    srand(time(0));
}

void Square::update(std::vector<std::vector<bool>> &matrix) {

    
    int random = rand() % 2;

    bool rightFree = false;
    bool leftFree = false;
    bool centreFree = false;

    if(y + 1 < Config::height){
        if(!matrix[x][y + 1]){
            matrix[x][y] = false;
            matrix[x][y + 1] = true;
            y += 1;
        }
        else if(x + 1 < Config::width && !matrix[x + 1][y + 1] && random == 1){
            matrix[x][y] = false;
            matrix[x + 1][y + 1] = true;
            y += 1;
            x += 1;
        }
        else if(x > 0 && !matrix[x - 1][y + 1]){
            matrix[x][y] = false;
            matrix[x - 1][y + 1] = true;
            y += 1;
            x -= 1;
        }
        else if(x + 1 < Config::width && !matrix[x + 1][y + 1]){
            matrix[x][y] = false;
            matrix[x + 1][y + 1] = true;
            y += 1;
            x += 1;
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
        DrawRectangle(x * scale, y * scale, 1 * scale, 1 * scale, color);
    }

}

void Square::draw(int size){

    int scale = Config::pixelSize;

    DrawRectangleLines(x * scale - (size * scale) / 2, y * scale - (size * scale) / 2, size * scale, size * scale, WHITE);
}

bool Square::exists(std::vector<std::vector<bool>> &matrix){

    if(matrix[x][y]){
        return true;
    }

    return false;
}