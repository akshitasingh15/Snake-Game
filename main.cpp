using namespace std;

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

int score;

// Function to display board and update after each movement
void board() {
	
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    
    vector<COORD> snake_body=snake.get_body();
    
    cout<< "SCORE: "<<score<<"\n\n";
    
    for (int i = 0; i < HEIGHT; i++) {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1)
                cout << "#";
                
            else if (i == snake_pos.Y && j + 1 == snake_pos.X)
                cout << "O";  // Snake head
            else if(i == food_pos.Y && j+1 == food_pos.X) cout << "*";
            
            else {
            	bool isBodyPart=false;
            	for(int k=0; k< snake_body.size()-1; k++){
            		if(i==snake_body[k].Y && j+1 == snake_body[k].X){
            			cout<< 'o';
            			isBodyPart=true;
            			break;
					}
				}
				if(!isBodyPart)
					cout<<' ';
			}
        }
        cout << "#\n";
    }
}

int main() {
	
	score=0;
	srand(time(NULL));
	
	food.gen_food();
	
	bool game_over = false;
	
    while (!game_over) {
        board();
        
 		if (_kbhit()) {  // Check if a key is pressed
            switch (_getch()) {
                case 'w': snake.direction('u'); break;
                case 's': snake.direction('d'); break;
                case 'a': snake.direction('l'); break;
                case 'd': snake.direction('r'); break;
            }
        }
        
        //To check for collison
        if(snake.collided()) game_over=true;
        
        //To increase score and length of snake if food is eaten
        if(snake.eaten(food.get_pos()))
        {
        	food.gen_food();
        	snake.grow();
        	score=score+10;
		}
        
        snake.move_snake();
        
        //For updating the cursor position after every update 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
    return 0;
}

