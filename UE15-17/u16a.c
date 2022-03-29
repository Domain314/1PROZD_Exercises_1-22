/*
* ArrayWalker314 by Artjom Moisejev - Copyright (C) 2021 <domain_69@hotmail.de>
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

// grid size: MAX * MAX
const int MAX = 100;

typedef struct vector2{
    int x;
    int y;
}vector2;

// struct with all info at one place
// pos = actual position of player, letter = last used letter, grid = grid, error = flag for inputError
typedef struct game {
    vector2 pos;
    char letter;
    char** grid;
    int error;
}game;

// returns next letter in alphabet
char nextLetter(game* _game)
{
    _game->letter += 1;
    if (_game->letter > 'Z')
    { _game->letter = 'A'; }

    return _game->letter;
}

// return true, when target position == '.'
int checkLetter(game * _game, int _x, int _y)
{
    return (_game->grid[_x][_y] == '.');
}

// return true, when target position is inside grid border
int checkMove(int _i)
{
    return (_i >= 0 && _i < MAX);
}

// summarize checks to move, change position and letter in this position.
void moveTo(game* _game, int _x, int _y)
{
    int x = _game->pos.x + _x;
    int y = _game->pos.y + _y;
    if (checkMove(x) && checkMove(y) && checkLetter(_game, x, y))
    {
        _game->pos.x += _x;
        _game->pos.y += _y;
        _game->grid[_game->pos.x][_game->pos.y] = nextLetter(_game);
        _game->error = 0;
    } else {
        printf("not possible\n");
        _game->error = 1;   // set errorFlag to repeat asking for new input.
    }
}

// movement controller
void processChoice(game* _game, char _choice)
{
    // uncomment for wasd-movement
    // switch (_choice) {
    //     case 'w': moveTo(_game, 0,-1); break;
    //     case 's': moveTo(_game, 0, 1); break;
    //     case 'a': moveTo(_game,-1, 0); break;
    //     case 'd': moveTo(_game, 1, 0); break;
    //     default: break;
    // }

    // comment for wasd-movement
    switch (_choice) {
        case 'n': moveTo(_game, 0,-1); break;
        case 's': moveTo(_game, 0, 1); break;
        case 'w': moveTo(_game,-1, 0); break;
        case 'e': moveTo(_game, 1, 0); break;
        default: break;
    }
}

// ask for and return input
char scanChoice()
{
    char choice;
    printf("walk to: "); scanf(" %c", &choice); printf("\n");
    return choice;
}

// display grid
void printGrid(game* _game)
{
    for (int y = 0; y < MAX; y++) {
        for (int x = 0; x < MAX; x++) {
            printf("%c", _game->grid[x][y] );
        }
        printf("\n");
    }
}

// main loops for asking input, processing it and printing the output, until 'x'
void gameLoop(game* _game)
{
    char choice = ' ';
    moveTo(_game, -1, 0);     // first setup to display position
    while (choice != 'x') {
        printGrid(_game);
        do {
            choice = scanChoice();
            if (choice == 'x') break;
            processChoice(_game, choice);
        } while(_game->error);    // errorFlag => repeat asking for new input

    }
}

// setup a game and return it
game setupGame()
{
    game newGame;
    newGame.pos.x = 1; newGame.pos.y = 0;   // set pos.x = 1 for beeing able to make one move in gameLoop
    newGame.letter = 'z'; newGame.error = 0; // set last letter too high to trigger letter > 'Z'
    newGame.grid = (char**)malloc(sizeof(char*)*MAX);   // allocate rows
    for (int x = 0; x < MAX; x++) {
        newGame.grid[x] = malloc(sizeof(char)*MAX);   // allocate collumns
        for (int y = 0; y < MAX; y++) {
            newGame.grid[x][y] = '.';     // set all entries to '.'
        }
    }
    return newGame;
}

// create new game and a pointer to it, then starting gameLoop.
// using pointer to keep stack clean, when passing it as parameter
int main()
{
    game newGame = setupGame(), *gamePtr = &newGame;
    gameLoop(gamePtr);
    return 0;
}
