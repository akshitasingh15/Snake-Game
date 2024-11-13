#include "Snake.h"
#include <windows.h>  // Needed for COORD definition

// Constructor to initialize the snake with starting position and velocity
Snake::Snake(COORD pos, int vel) {
    this->pos = pos;
    this->vel = vel;
    len = 1;
    dir = 'n';  
    body.push_back(pos);  
}

// Set the direction of the snake based on user input
void Snake::direction(char dir) {
    this->dir = dir;
}

// Increase the length of the snake (called when food is eaten)
void Snake::grow() {
    len++;
}

// Get the current position of the snake's head
COORD Snake::get_pos() {
    return pos;
}

// Get the positions of the entire snake body
vector<COORD> Snake::get_body() {
    return body;
}

// Move the snake in the current direction
void Snake::move_snake() {
    // Update position based on direction
    switch(dir) {
        case 'u': pos.Y -= vel; break;
        case 'd': pos.Y += vel; break;
        case 'l': pos.X -= vel; break;
        case 'r': pos.X += vel; break;
    }

    // Wrap around screen (left to right, top to bottom)
    if (pos.X > WIDTH - 2) pos.X = 1;
    if (pos.X < 1) pos.X = WIDTH - 2;
    if (pos.Y > HEIGHT - 2) pos.Y = 1;
    if (pos.Y < 1) pos.Y = HEIGHT - 2;

    // Update the body positions
    body.push_back(pos);
    if (body.size() > len) body.erase(body.begin());  // Keep the body length consistent
}

// Check if the snake's head is at the food position
bool Snake::eaten(COORD food_pos) {
    return (pos.X == food_pos.X && pos.Y == food_pos.Y);
}

// Check if the snake has collided with the wall or itself
bool Snake::collided() {
    // Check for collision with the boundary
    if (pos.X < 1 || pos.X > WIDTH - 2 || pos.Y < 1 || pos.Y > HEIGHT - 2) return true;

    // Check for collision with itself
    for (int i = 0; i < len - 1; i++) {
        if (pos.X == body[i].X && pos.Y == body[i].Y) return true;
    }
    return false;
}

// Operator overload to check if two COORD positions are equal
bool operator==(const COORD &c1, const COORD &c2) {
    return c1.X == c2.X && c1.Y == c2.Y;
}

// Operator overload to check if two COORD positions are not equal
bool operator!=(const COORD &c1, const COORD &c2) {
    return !(c1 == c2);
}

