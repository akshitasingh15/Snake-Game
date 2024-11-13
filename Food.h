#ifndef FOOD_H
#define FOOD_H

#include<windows.h>
#include<cstdlib>

#define WIDTH 50
#define HEIGHT 25

class Food
{	
	private:
		COORD pos; //position of food
	
	public:
		void gen_food(); //function to generate food randomly
		COORD get_pos(); //function to get position of generated food
};

#endif
