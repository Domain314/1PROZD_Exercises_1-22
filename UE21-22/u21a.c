/*
 * LangtonsAnt314 by Artjom Moisejev - Copyright (C) 2021 <domain_69@hotmail.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// changeable grid size and step mode activation
// step mode: after input, press ENTER to make one step
// fast forward in step mode: hold ENTER
#define GRID_SIZE 10
#define STEP_MODE 0

// vector3 for returning 3 ints and easier handling movement
typedef struct vector3 {
    int x;
    int y;
    int t;
}vector3;

// holds all info at one place
typedef struct game {
    int turns;
    vector3* antPos;
    char** grid;
}game;

// allocate space and set all entries to '.'
char** setupGrid()
{
    char** grid = (char**)calloc(GRID_SIZE, sizeof(char*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (char*)calloc(GRID_SIZE, sizeof(char));
        memset(grid[i], '.', GRID_SIZE);
    }
    return grid;
}

game* setupNewGame(vector3* input_)
{
    game* gamePtr = (game*)malloc(sizeof(game));
    gamePtr->grid = setupGrid();
    gamePtr->turns = input_->t;
    gamePtr->antPos = input_;
    gamePtr->antPos->t = 0;   // first turn: north
    return gamePtr;
}

void printGrid(game* game_)
{
    if (STEP_MODE)
    {
      printf("\e[1;1H\e[2J");   // clear display in linux (sorry windows users)
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c", game_->grid[i][j]);
            if (STEP_MODE) {
              printf(" ");  // print a space between dots to make quadratic grid
            }
        }
        printf("\n");
    }
}

// get input and allocate space for it
vector3* scanInput()
{
    vector3* input = (vector3*)malloc(sizeof(vector3));
    printf("Number of turns: "); scanf(" %d", &input->t);
    printf("Start position: "); scanf(" %d %d", &input->y, &input->x);
    return input;
}

// flip colour on grid cell
char changeColour(char c_)
{
    return (c_ == '.') ? '#' : '.';
}

// turn ant left/right when stepping on '.'/'#'
void setDirection(game* game_)
{
    if (game_->grid[game_->antPos->x][game_->antPos->y] == '.') {
        game_->antPos->t = (game_->antPos->t +1) % 4;
    } else {
        game_->antPos->t = (game_->antPos->t -1);
        if (game_->antPos->t == -1)
        {
          game_->antPos->t += 4;
        }
    }
}

// change colour of last cell and set next position and direction
void moveAnt(game* game_, int x_, int y_)
{
    game_->grid[game_->antPos->x][game_->antPos->y] = changeColour(game_->grid[game_->antPos->x][game_->antPos->y]);
    game_->antPos->x += x_;
    game_->antPos->y += y_;
    setDirection(game_);
}

int isOutsideBoundaries(game* game_)
{
  return (game_->antPos->x >= GRID_SIZE ||
          game_->antPos->y >= GRID_SIZE ||
          game_->antPos->x < 0 ||
          game_->antPos->y < 0);
}

// stepping of the ant
void setAnt(game* game_)
{
    for (int i = 0; i < game_->turns; i++) {    // for n turns..
        switch (game_->antPos->t) {             // depending on direction, move..
            case 0: moveAnt(game_, -1, 0); break;   // north
            case 1: moveAnt(game_, 0, 1); break;    // east
            case 2: moveAnt(game_, 1, 0); break;    // south
            case 3: moveAnt(game_, 0, -1); break;    // west
        }
        if (isOutsideBoundaries(game_)) break;  // left the grid? => break stepping loop
        if (STEP_MODE)
        { // display grid + steps in step-mode
          printGrid(game_); printf("steps: %d\n", i);
          char c; scanf("%c", &c);  // wait for ENTER
        }
    } // display ant as 'a' or 'A', depending on the cell colour, after last step
    if (game_->grid[game_->antPos->x][game_->antPos->y] == '.') {
      game_->grid[game_->antPos->x][game_->antPos->y] = 'a';
    } else {
      game_->grid[game_->antPos->x][game_->antPos->y] = 'A';
    }
    printGrid(game_);
}

// free all allocs
void freeAll(vector3* input_, game* game_)
{
  for (int i = 0; i < GRID_SIZE; i++) {
    free(game_->grid[i]);
  }
  free(game_->grid);
  free(game_);
  free(input_);
}

int main()
{
  vector3* input = scanInput();
  game* newGame = setupNewGame(input);
  setAnt(newGame);
  freeAll(input, newGame);
}
