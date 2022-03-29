#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 10;

typedef struct vector2{
  int x;
  int y;
}vector2;

typedef struct game {
  vector2 pos;
  char** grid;
}game;

void setupGrid(char _grid[][MAX])
{
    char dot = '.';
    for (int y = 0; y < MAX; y++) {
        for (int x = 0; x < MAX; x++) {
            _grid[x][y] = dot;
        }
    }
}

void printGrid(char _grid[][MAX])
{
  for (int y = 0; y < MAX; y++) {
    for (int x = 0; x < MAX; x++) {
      printf("%c", _grid[x][y] );
    }
    printf("\n");
  }
}

char scanChoice()
{
  char choice;
  printf("walk to: "); scanf(" %c", &choice);
  return choice;
}

void moveX(int _x, int _pos, char _grid[][MAX])
{
  //if (_grid[][])
}

void moveY(int _y, int _pos, char _grid[][MAX])
{

}

void moveTo(char choice, vector2 _pos, char _grid[][MAX])
{
  char* targetPos;
  switch (choice) {
    case 'n': moveX(-1, _pos.x, _grid); break;
    case 's': moveX(1, _pos.x, _grid); break;
    case 'w': moveY(-1, _pos.y, _grid); break;
    case 'e': moveY(1, _pos.y, _grid); break;
  }
}

void gameLoop(char _grid[][MAX])
{
  char choice;
  vector2 pos = {0,0};

  while (1) {
    choice = scanChoice();
    if (choice == 'x') break;
    moveTo(choice, pos, _grid);
  }
}



int main()
{
    char grid[MAX][MAX];

    setupGrid(grid);
    printGrid(grid);
    printf("%d %d", pos.x, pos.y);

    return 0;
}
