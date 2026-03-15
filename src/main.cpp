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
    int cursor_size = 10;
    int fps = 60;
    int tps = 30;
    int frame_counter = 1;

    

    InitWindow(Config::width * scale, Config::height * scale, "jacob sand sim");

    SetTargetFPS(fps);

    

    while (!WindowShouldClose())
    {

        

        Vector2 m = GetMousePosition();

        BeginDrawing();

        //update

        frame_counter++;

        if (frame_counter == (fps / tps)){
            for (Square& s : squares){
                s.update(matrix);
            }
            frame_counter = 0;
        }

        

        box.update((m.x - ((int)m.x % scale)) / scale, (m.y - ((int)m.y % scale)) / scale);

        //input

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {

            for (int i = 0; i < cursor_size; i++){
                for (int j = 0; j < cursor_size; j++){

                    int x = (m.x - ((int)m.x % scale)) / scale - cursor_size / 2;
                    int y = (m.y - ((int)m.y % scale)) / scale - cursor_size / 2;
                    if (x >= 0 && y >= 0 && x + i < cols && y + j < rows && !matrix[x + i][y + j]){
                        squares.emplace_back(x + i, y + j, 1, true);
                        matrix[x + i][y + j] = true;
                    }

                }
            }

            
        }
        else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {

            for (int i = 0; i < cursor_size; i++){
                for (int j = 0; j < cursor_size; j++){

                    int x = (m.x - ((int)m.x % scale)) / scale - cursor_size / 2;
                    int y = (m.y - ((int)m.y % scale)) / scale - cursor_size / 2;
                    if (x >= 0 && y >= 0 && x + i < cols && y + j < rows){
                        matrix[x + i][y + j] = false;
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

        DrawFPS(10 * scale, 5 * scale);

        EndDrawing();

        
    }

    CloseWindow();
}