#include <iostream>
#include "raylib.h"
#define NUM_FRAMES  3      
using namespace std;
/* Used Gemini To help figure out why screen wouldn't stay after clicking enter 
and switching back to the start screen
*/
enum GameScreen {
    START_SCREEN,
    GAMEPLAY_SCREEN,
};

int main() {
    InitWindow(1500, 800, "Team 13 Hackathon");
    SetTargetFPS(30);

    Texture2D start_photo = LoadTexture("Start_Screen.png"); //Image Generated Using Claude.
    Texture2D game_photo = LoadTexture("game_image.jpg"); 
    Texture2D gameButton = LoadTexture("Answer_Button.png"); // Load button texture

    float frameHeight = (float)gameButton.height/NUM_FRAMES;
    SetTargetFPS(60);

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
        ClearBackground(WHITE);

        if (currentScreen == START_SCREEN) {
            //Drew the Start Screen 
            Rectangle source = { 0, 0, (float)start_photo.width, (float)start_photo.height };
            Rectangle dest   = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
            DrawTexturePro(start_photo, source, dest, {0, 0}, 0.0f, WHITE);
        }
        else if (currentScreen == GAMEPLAY_SCREEN) {
            // Drew The GamePlay BackGround.
            Rectangle source = { 0, 0, (float)game_photo.width, (float)game_photo.height };
            Rectangle source2 = { 0, 0, 340, 340};
            Rectangle dest = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
            Rectangle dest2 = { 0, 0, gameButton.width * 1.5f, gameButton.height * 1.5f };
            DrawTexturePro(game_photo, source, dest, {0, 0}, 0.0f, WHITE);
            DrawText("GAMEPLAY SCREEN", 425, 20, 50, MAROON);

            //ADDED all 4 Answer Boxes to the Game Screen
            DrawTexturePro(gameButton, source2, dest2, Vector2{0, -200}, 0.0f, WHITE);
            DrawText("Answer A", 225, 475, 25, WHITE);
            DrawTexturePro(gameButton, source2, dest2, Vector2{-800, -200}, 0.0f, WHITE);
            DrawText("Answer B", 1025, 475, 25, WHITE);
            DrawTexturePro(gameButton, source2, dest2, Vector2{0, -400}, 0.0f, WHITE);
            DrawText("Answer C", 225, 675, 25, WHITE);
            DrawTexturePro(gameButton, source2, dest2, Vector2{-800, -400}, 0.0f, WHITE);
            DrawText("Answer D", 1025, 675, 25, WHITE);


        }
        EndDrawing();
    }

    UnloadTexture(start_photo);
    UnloadTexture(game_photo);
    UnloadTexture(gameButton);
    CloseWindow();

    return 0;
}
