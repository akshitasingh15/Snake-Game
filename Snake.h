#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>
#include <iostream>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{   
    private:
        COORD pos; //position of snake
        int vel; //velocity of snake
        char dir; //direction of snake
        int len; //length of snake
        vector<COORD> body;
        
    public:
        Snake(COORD pos, int vel); //constructor to make snake
        
        void move_snake(); //to move snake
        void direction(char dir); //to change direction of snake
        COORD get_pos(); //to get the current position of snake
        vector<COORD> get_body();
        bool eaten(COORD food); //check if snake at food
        void grow(); //to grow length of snake after eating food
        bool collided(); //to check if snake collided with boundary

        // Operator overloads
        friend bool operator==(const COORD &c1, const COORD &c2);
        friend bool operator!=(const COORD &c1, const COORD &c2);
};

#endif

