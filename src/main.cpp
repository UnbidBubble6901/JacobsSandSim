#include "raylib.h"
#include "square.h"
#include "config.h"
#include "math.h"
#include <vector>
#include <algorithm>
//#include <iostream>

int main() {

    const int scale = Config::pixelSize;

    std::vector<Square> squares;
    Square box = Square(GetMouseX(), GetMouseY(), 1, false);

    const int rows = Config::height;
    const int cols = Config::width;
    //bool table[rows][cols] = {false}; --> deprecated
    std::vector<std::vector<bool>> matrix(cols, std::vector<bool>(rows));
    int cursor_size = 5;

    

    InitWindow(Config::width * scale, Config::height * scale, "Sand");

    SetTargetFPS(30);

    

    while (!WindowShouldClose())
    {

        Vector2 m = GetMousePosition();

        BeginDrawing();
        
        //update

        for (Square& s : squares){
            s.update(matrix);
        }

        box.update((m.x - ((int)m.x % scale)) / scale, (m.y - ((int)m.y % scale)) / scale);

        //draw

        ClearBackground(BLACK);

        for (int i = squares.size() - 1; i >= 0; i--) {
            if (squares[i].exists(matrix)) {
                squares[i].draw();
            } else {
                squares.erase(squares.begin() + i);
            }
        }
        
        box.draw(cursor_size);

        //input

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {

            for (int i = 0; i < cursor_size; i++){
                for (int j = 0; j < cursor_size; j++){

                    int x = (m.x - ((int)m.x % scale)) / scale - cursor_size / 2;     // x and y are in actual pixels
                    int y = (m.y - ((int)m.y % scale)) / scale - cursor_size / 2;
                    if (x >= 0 && y >= 0 && x + i < cols && y + j < rows && !matrix[x + i][y + j]){
                        squares.emplace_back(x + i, y + j, 1, true);
                        matrix[x + i][y + j] = true;
                    }

                }
            }

            
        }
        else if(IsKeyPressed(KEY_C)) {
            squares.clear();

            for (int i = 0; i < cols; i++){
                for (int j = 0; j < rows; j++){
                    matrix[i][j] = false;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
}