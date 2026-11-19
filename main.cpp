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
    Texture2D game_photo = LoadTexture("game_image.png");  //Image Generated Using Claude.
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
            /* Gets Dimensions for the buttonImage and stores it in a rectangle called dest2
            gained from example - sprite button */
            Rectangle dest2 = { 0, 0, gameButton.width * 2.0f, gameButton.height * 2.0f };
            DrawTexturePro(game_photo, source, dest, {0, 0}, 0.0f, WHITE);
            /* ADDED all 4 Answer Boxes to the Game Screen
            As well as Text for the Answer to be ontop of the answer boxes Based on coordinates
            on the screen to make them evenly spread out.*/
            DrawTexturePro(gameButton, source2, dest2, Vector2{-105, -100}, 0.0f, WHITE);
            DrawTexturePro(gameButton, source2, dest2, Vector2{-605, -100}, 0.0f, WHITE);
            DrawTexturePro(gameButton, source2, dest2, Vector2{-105, -250}, 0.0f, WHITE);
            DrawTexturePro(gameButton, source2, dest2, Vector2{-605, -250}, 0.0f, WHITE);
            string Question = "EX: Who is Our Professor In CS 103";
            string A = "Madeline Blount";
            string B = "John Pork";
            string C = "Donald Trump";
            string D = "Barack Obama";
            // Used Gemini to help me make sure the text and questions are always centered and never misaligned.
            DrawText(Question.c_str(), (GetScreenWidth() - MeasureText("EX: Who is Our Professor In CS 103", 50)) / 2, 100, 50, WHITE);
            /* Added Varibles for each answer question on each button converted each string to a char to be able to draw the string
            gained from geeksforgeeks. (https://www.geeksforgeeks.org/cpp/basic_string-c_str-function-in-c-stl/) */
            DrawText(A.c_str(), 125 + (dest2.width - MeasureText("Madeline Blount", 25)) / 2, 125 + (dest2.height - 25) / 2, 25, WHITE);
            DrawText(B.c_str(), 625 + (dest2.width - MeasureText("John Pork", 25)) / 2, 125 + (dest2.height - 25) / 2, 25, WHITE);
            DrawText(C.c_str(), 125 + (dest2.width - MeasureText("Donald Trump", 25)) / 2, 275 + (dest2.height - 25) / 2, 25, WHITE);
            DrawText(D.c_str(), 625 + (dest2.width - MeasureText("Barack Obama", 25)) / 2, 275 + (dest2.height - 25) / 2, 25, WHITE);
            /* Gained From example - sprite button used to read the text on the 
            Button and we could be able to switch the text on the button for whenever.
            As well as example - input mouse to get the position of the mouse wherever
            to be able to track which button was clicked.*/
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    Vector2 mousePos = GetMousePosition();
                    Rectangle buttonA = { 105.0f, 100.0f, dest2.width, dest2.height };
                    Rectangle buttonB = { 605.0f, 100.0f, dest2.width, dest2.height };
                    Rectangle buttonC = { 105.0f, 250.0f, dest2.width, dest2.height };
                    Rectangle buttonD = { 605.0f, 250.0f, dest2.width, dest2.height };
                    cout << "You clicked: ";
                    if (CheckCollisionPointRec(mousePos, buttonA)) {
                        cout << A << endl;
                    }
                    else if (CheckCollisionPointRec(mousePos, buttonB)) {
                        cout << B << endl;
                    }
                    else if (CheckCollisionPointRec(mousePos, buttonC)) {
                        cout << C << endl;
                    }
                    else if (CheckCollisionPointRec(mousePos, buttonD)) {
                        cout << D << endl;
                    }
                }
            }
        EndDrawing();
    }

    UnloadTexture(start_photo);
    UnloadTexture(game_photo);
    UnloadTexture(gameButton);
    CloseWindow();

    return 0;
}
