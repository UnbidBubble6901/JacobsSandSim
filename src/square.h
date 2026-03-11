#pragma once
#include "raylib.h"
#include <vector>

class Square {
    private:
        int x;
        int y;
        bool fill;
        Color color;


    public:
        Square(int x, int y, int size, bool fill);

        void update(std::vector<std::vector<bool>> &matrix);
        void update(int x, int y);
        void draw();
        void draw(int size);
        bool exists(std::vector<std::vector<bool>> &matrix);
};