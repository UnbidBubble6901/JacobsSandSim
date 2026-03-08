#pragma once
#include "raylib.h"

class Square {
    private:
        int x;
        int y;
        int size;
        bool fill;


    public:
        Square(int x, int y, int size, bool fill);

        void update(bool table[1000][1000]);
        void update(int x, int y);
        void draw();
};