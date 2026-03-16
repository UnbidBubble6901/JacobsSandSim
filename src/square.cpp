#include "square.h"
#include "config.h"
#include <cstdlib>
#include <ctime>
#include <random>

std::mt19937 Square::gen(std::random_device{}());
std::uniform_int_distribution<int> Square::random(0, 1); // 0 o 1

Square::Square(int x, int y, int size, bool fill) {
    this->x = x;
    this->y = y;
    //this->size = size;
    this->fill = fill;
    float randomHue = 60;
    float randomSaturation = (float)GetRandomValue(40, 50) / 100.0f;
    float randomValue = (float)GetRandomValue(85, 100) / 100.0f;
    this->color = ColorFromHSV(randomHue, randomSaturation, randomValue);

    
    
}

void Square::update(std::vector<std::vector<uint8_t>> &matrix) {

    

    if(y + 1 < Config::height){
        if(!matrix[x][y + 1]){
            matrix[x][y] = false;
            matrix[x][y + 1] = true;
            y += 1;
        }
        else{
            int direction = random(gen) == 0 ? -1 : 1;
            int nextX = x + direction;

            if (nextX >= 0 && nextX < Config::width && !matrix[nextX][y + 1]) {
                matrix[x][y] = false;
                matrix[nextX][y + 1] = true;
                x = nextX;
                y += 1;
            }
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

bool Square::exists(std::vector<std::vector<uint8_t>> &matrix){

    if(matrix[x][y]){
        return true;
    }

    return false;
}