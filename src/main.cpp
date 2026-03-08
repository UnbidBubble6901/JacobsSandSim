#include "raylib.h"
#include "square.h"
#include "config.h"
#include "math.h"
#include <vector>

int main() {

    const int scale = Config::pixelSize;

    std::vector<Square> squares;
    Square box = Square(GetMouseX(), GetMouseY(), 1, false);

    const int rows = 1000;
    const int cols = 1000;
    bool table[rows][cols] = {false};

    

    InitWindow(Config::width * scale, Config::height * scale, "Sand");

    SetTargetFPS(30);

    

    while (!WindowShouldClose())
    {

        Vector2 m = GetMousePosition();

        BeginDrawing();

        //check input

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            int x = (m.x - ((int)m.x % scale)) / scale;     // x and y are in actual pixels
            int y = (m.y - ((int)m.y % scale)) / scale - 1;
            if (!table[x][y]){
                squares.emplace_back(x, y, 1, true);
                table[x][y] = true; 
            }
            
        }

        

        //update

        for (Square& s : squares){
            s.update(table);
        }

        box.update((m.x - ((int)m.x % scale)) / scale, (m.y - ((int)m.y % scale)) / scale);

        //draw

        ClearBackground(BLACK);

        for (Square& s : squares){
            s.draw();
        }
        
        box.draw();

        EndDrawing();
    }

    CloseWindow();
}