# Snake-Game
A interactive snake game made using C++
.1. Introduction
  This documentation explains a user-friendly Snake game developed in C++,     using fundamental programming concepts such as encapsulation, abstraction,   operator overloading. The game follows the classic rules of ”Snake,” where   the player controls the snake’s direction to consume food items on the       grid, increasing its length and score. The game ends if the snake collides   with itself.

2. Classes and Files
  - Snake Class
    The Snake class models the snake’s properties and behaviors. It includes:
    • Attributes: position, velocity, direction, length, and body.
    • Methods: Functions for movement, direction change, collision                 detection, and growth.
  - Food Class
      The Food class is responsible for generating food items at random 
      positions on the grid
      • Attributes: position of the food.
      • Methods: Functions for generating new food coordinates and                   retrieving current food coordinates.

File Structure
  The game is organized into five files:
  1. Snake.h: The header file declaring the Snake class.
  2. Snake.cpp: The function file for the movement of the snake.
  3. Food.h: The header file declaring the Food class.
  4. Food.cpp: The function file to generate food at random (x,y) position
  5. main.cpp: The main game file that integrates Snake and Food and handles      the game loop.

3. Functions
Snake Class Functions
  1. Constructor: Snake(COORD pos, int vel)
  • Initializes the snake with a starting position and velocity.
  • Sets the initial length to 1, starting in the neutral direction (’n’).

  2. void direction(char dir)
  • Changes the snake’s direction based on user input (w, a, s, d for up, left, down, and right,
  respectively).

  3. void grow()
  • Increments the length of the snake by 1 when food is eaten.

  4. COORD get pos()
  • Returns the current position of the snake’s head.

  5. vector<COORD> get body()
  • Returns the positions of all parts of the snake’s body.

  7. void move snake()
  • Moves the snake in its current direction by updating its position.
  • Handles the wrapping of the snake across grid edges (from left to right, top to bottom).
  • Maintains the size of the body vector by pushing the new position and removing the oldest one if
  necessary.
  8. bool eaten(COORD food)
  • Checks if the snake’s head coordinates match the food’s coordinates, indicating food consumption.
  9. bool collided()
  • Detects if the snake has collided with the boundary or itself.
  • Checks if the head of the snake occupies the same space as any other part of the body or if it
  exceeds the grid boundaries.
Food Class Functions
1. void gen food()
• Generates a new position for the food item at random grid coordinates within the defined game
area.
2. COORD get pos()
• Returns the current position of the food item.
2
Main Function and Game Loop
1. board()
• Renders the game grid, including the boundary walls, the snake’s head and body, and the food.
• Displays the current score.
• The grid is 50x25, defined by constants WIDTH and HEIGHT.
2. Main Game Loop (main())
• Initializes the snake and food objects.
• Handles user inputs to change the snake’s direction.
• Calls move snake() to advance the snake based on its direction.
• Checks if the snake has eaten food, grows the snake, and updates the score.
• Checks for collision with itself or boundary to end the game.
• Resets cursor position after each iteration to maintain grid position.
4. Gameplay Logic
• Movement: The snake moves based on the user’s directional input. The snake’s position updates
continuously, and any change is reflected on the next iteration of the game loop.
• Food Consumption: When the snake’s head reaches the food’s coordinates, it eats the food. The snake
grows by one unit, and a new food item is generated at a random position.
• Boundary Wrapping: If the snake moves past the screen edges, it wraps around to the other side. This
is controlled by checking the pos variable against the WIDTH and HEIGHT values.
• Collision Detection: A collision occurs if the snake’s head collides with any part of its body.
5. Specifications and Edge Cases
• Boundary Handling: If the snake moves beyond the grid edges, it wraps to the opposite edge, allowing
continuous movement across the screen.
• Self-Collision Detection: When the snake collides with itself, the game ends. This is checked by
comparing the head position with all other body positions.
• Direction Constraints: The snake cannot instantly reverse direction (for example, from left to right)
in one step, to avoid unintended self-collisions.
