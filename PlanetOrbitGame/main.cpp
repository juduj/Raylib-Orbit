#include <iostream>
#include "raylib.h"
#include <cmath>

struct Planet
{
    double x, y, radius;

    Planet(double x, double y, double radius)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
};

void RotateAroundPoint(double& x, double& y, double x_center, double y_center, double angle, double rotationalSpeed) {
    // Define rotation speed (in radians per second)
    double rotationSpeed = rotationalSpeed; // Modify this value to change rotation speed

    // Scale the rotation speed by deltaTime
    double scaledAngle = rotationSpeed * GetFrameTime();

    // Translate the point so that the center becomes the origin
    double translatedX = x - x_center;
    double translatedY = y - y_center;

    // Apply rotation using trigonometric functions and scaled angle
    double rotatedX = translatedX * cos(scaledAngle) - translatedY * sin(scaledAngle);
    double rotatedY = translatedX * sin(scaledAngle) + translatedY * cos(scaledAngle);

    // Translate back to the original coordinate system
    x = rotatedX + x_center;
    y = rotatedY + y_center;
}


int main()
{
    
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Planet-Orbit");

    SetTargetFPS(60);       

    int pointX = screenWidth / 2;
    int pointY = screenHeight / 2;
    
    // 128 is just random constant for just a visual distance between the sun
    Planet planet(pointX + 128, pointY, 16);
    
    while (!WindowShouldClose())    
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircle(planet.x, planet.y, planet.radius, BLUE);
        DrawCircle(pointX, pointY, 16, YELLOW);
        RotateAroundPoint(planet.x, planet.y, pointX, pointY, PI / 2.0, 2.0);

        EndDrawing();
    }
    
    CloseWindow();        

    return 0;
}