#include <iostream>
#include "raylib.h"
using namespace std;
/* Used Gemini To help figure out why screen wouldn't stay after clicking enter 
and switching back to the start screen
*/
enum GameScreen {
    START_SCREEN,
    GAMEPLAY_SCREEN,
};

int main() {
    const int screenWidth = 1500;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Team 13 Hackathon");
    SetTargetFPS(30);

    Texture2D start_photo = LoadTexture("Start_Screen.png"); //Image Generated Using Claude.
    Texture2D game_photo = LoadTexture("game_image.jpg"); 


    GameScreen currentScreen = START_SCREEN;
    /* Used Gemini To help figure out why screen wouldn't stay after clicking enter     
    and switching back to the start screen
    */
    while (!WindowShouldClose()) {
        if (currentScreen == START_SCREEN) {
            if (IsKeyPressed(KEY_ENTER)) {
                currentScreen = GAMEPLAY_SCREEN;
            }
        }
        if (currentScreen == GAMEPLAY_SCREEN) {
            if (IsKeyPressed(KEY_ONE)) {
                currentScreen = START_SCREEN;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        if (currentScreen == START_SCREEN) {
            Rectangle source = { 0, 0, (float)start_photo.width, (float)start_photo.height };
            Rectangle dest   = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
            DrawTexturePro(start_photo, source, dest, {0, 0}, 0.0f, WHITE);
        }
        else if (currentScreen == GAMEPLAY_SCREEN) {
            Rectangle source = { 0, 0, (float)game_photo.width, (float)game_photo.height };
            Rectangle dest   = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
            DrawTexturePro(game_photo, source, dest, {0, 0}, 0.0f, WHITE);
            DrawText("GAMEPLAY SCREEN", 600, 20, 20, MAROON);
        }

        EndDrawing();
    }

    UnloadTexture(start_photo);
    UnloadTexture(game_photo);
    CloseWindow();

    return 0;
}
