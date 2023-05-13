#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Player {
private:
    float x;            // Player's X position
    float y;            // Player's Y position
    float rotation;     // Player's rotation angle
    float movementSpeed; // Player's movement speed

public:
    Player(float startX, float startY, float startRotation, float startSpeed)
        : x(startX), y(startY), rotation(startRotation), movementSpeed(startSpeed) {}

    // Getters and Setters
    float getX() const { return x; }
    float getY() const { return y; }
    float getRotation() const { return rotation; }
    float getMovementSpeed() const { return movementSpeed; }

    void setPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }

    void setRotation(float newRotation) {
        rotation = newRotation;
    }

    // Key Binding Functions
    void processKeyInput(int key, int action, float deltaTime) {
        if (action == GLFW_PRESS) {
            switch (key) {
            case GLFW_KEY_W:
                moveForward(deltaTime);
                break;
            case GLFW_KEY_S:
                moveBackward(deltaTime);
                break;
            case GLFW_KEY_A:
                rotate(-M_PI_2 * deltaTime);
                break;
            case GLFW_KEY_D:
                rotate(M_PI_2 * deltaTime);
                break;
            default:
                break;
            }
        }
    }

    
private:
    // Movement Functions
    void moveForward(float deltaTime) {
        moveInDirection(rotation, deltaTime);
    }

    void moveBackward(float deltaTime) {
        moveInDirection(rotation + M_PI, deltaTime);
    }

    void moveLeft(float deltaTime) {
        moveInDirection(rotation - M_PI_2, deltaTime);
    }

    void moveRight(float deltaTime) {
        moveInDirection(rotation + M_PI_2, deltaTime);
    }

    // Rotate the player
    void rotate(float angle) {
        rotation += angle;
        normalizeRotation();
    }
    void moveInDirection(float direction, float deltaTime) {
        float dx = movementSpeed * cos(direction) * deltaTime;
        float dy = movementSpeed * sin(direction) * deltaTime;
        x += dx;
        y += dy;
    }

    void normalizeRotation() {
        while (rotation < 0)
            rotation += 2 * M_PI;
        while (rotation >= 2 * M_PI)
            rotation -= 2 * M_PI;
    }
};
