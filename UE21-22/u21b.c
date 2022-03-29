#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int GRID_SIZE = 50;

typedef struct vector3 {
    int x;
    int y;
    int t;
}vector3;

typedef struct game {
    int turns;
    vector3* antPos;
    char** grid;
}game;

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
    game newGame, *gamePtr = &newGame;
    gamePtr = (game*)malloc(sizeof(game));
    gamePtr->grid = setupGrid();
    gamePtr->turns = input_->t;
    gamePtr->antPos = input_;
    gamePtr->antPos->t = 0;
    return gamePtr;
}

void printGrid(game* game_)
{
    printf("\e[1;1H\e[2J");

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", game_->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vector3* scanInput()
{
    vector3* input = (vector3*)malloc(sizeof(vector3));
    printf("Number of turns: "); scanf(" %d", &input->t);
    printf("Start position: "); scanf(" %d %d", &input->y, &input->x);
    return input;
}

char changeColor(char c_)
{
    return (c_ == '.') ? '#' : '.';
}

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

void moveAnt(game* game_, int x_, int y_)
{
    game_->grid[game_->antPos->x][game_->antPos->y] = changeColor(game_->grid[game_->antPos->x][game_->antPos->y]);
    game_->antPos->x += x_;
    game_->antPos->y += y_;
    setDirection(game_);
}

void setAnt(game* game_)
{
    for (int i = 0; i < game_->turns; i++) {
        switch (game_->antPos->t) {
            case 0: moveAnt(game_, -1, 0); break;   // north
            case 1: moveAnt(game_, 0, 1); break;    // east
            case 2: moveAnt(game_, 1, 0); break;    // south
            case 3: moveAnt(game_, 0, -1); break;    // west
        }
        printGrid(game_);
        char c;
        scanf(" %c", &c);
    }
    game_->grid[game_->antPos->x][game_->antPos->y] = 'a';
}

int main()
{
    while (1) {
        vector3* input = scanInput();
        game* newGame = setupNewGame(input);
        setAnt(newGame);

        //printGrid(newGame);
    }


}
