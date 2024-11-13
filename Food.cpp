#include "Food.h"

//Generate food at random x and y positions
void Food::gen_food()
{
	pos.X=rand() % (WIDTH - 3) + 1;
	pos.Y=rand() % (HEIGHT - 3) + 1;
}

// Get the current position of food generated
COORD Food::get_pos(){
	return pos;
}
