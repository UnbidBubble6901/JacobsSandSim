#pragma once
#include "raylib.h"
#include <vector>
#include <random>

class Square {
    private:
        int x;
        int y;
        bool fill;
        Color color;


    public:
        Square(int x, int y, int size, bool fill);
        
        static std::mt19937 gen;
        static std::uniform_int_distribution<int> random;

        void update(std::vector<std::vector<uint8_t>> &matrix);
        void update(int x, int y);
        void draw();
        void draw(int size);
        bool exists(std::vector<std::vector<uint8_t>> &matrix);
};