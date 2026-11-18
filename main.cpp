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
    const int screenWidth = 1500;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Team 13 Hackathon");
    SetTargetFPS(30);

    Texture2D start_photo = LoadTexture("Start_Screen.png"); //Image Generated Using Claude.
    Texture2D game_photo = LoadTexture("game_image.jpg"); 
    Texture2D gameButton = LoadTexture("Answer_Button.png"); // Load button texture

    float frameHeight = (float)gameButton.height/NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)gameButton.width, frameHeight };
    int btnState = 0;               
    bool btnAction = false;      
    Rectangle btnBounds = { screenWidth/2.0f - gameButton.width/2.0f, screenHeight/2.0f - (float)gameButton.height/NUM_FRAMES/2.0f, (float)gameButton.width, frameHeight }; 
    Vector2 mousePoint = { 0.0f, 0.0f };
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
            Rectangle source = { 0, 0, (float)start_photo.width, (float)start_photo.height };
            Rectangle dest   = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
            DrawTexturePro(start_photo, source, dest, {0, 0}, 0.0f, WHITE);
        }
        else if (currentScreen == GAMEPLAY_SCREEN) {
            Rectangle source = { 0, 0, (float)game_photo.width, (float)game_photo.height };
            Rectangle source2 = { 0, 0, 340, 340};
            Rectangle dest   = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
            DrawTexturePro(game_photo, source, dest, {0, 0}, 0.0f, WHITE);
            DrawTextureRec(gameButton, source2,  Vector2{100, 250}, WHITE); 
            DrawText("GAMEPLAY SCREEN", 600, 20, 20, MAROON);
            mousePoint = GetMousePosition();
            btnAction = false;
            if (CheckCollisionPointRec(mousePoint, btnBounds)) {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
                else btnState = 1;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
            }
            else btnState = 0;
            if (btnAction)
            {
                cout << "hello" << endl;
                cout << btnBounds.x << " " << btnBounds.y;
            }
            sourceRec.y = btnState*frameHeight;
            }

        EndDrawing();
    }

    UnloadTexture(start_photo);
    UnloadTexture(game_photo);
    UnloadTexture(gameButton);
    CloseWindow();

    return 0;
}
