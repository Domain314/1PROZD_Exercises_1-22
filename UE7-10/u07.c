#include <stdio.h>

void printGrades(int _grades)
{
  switch (_grades) {
    case 0: printf("Ausgezeichneter Erfolg!"); break;
    case 1: printf("Guter Erfolg!"); break;
    case 2: printf("Nicht bestanden!"); break;
    case 3: printf("Bestanden."); break;
  }
}

void printError(int _error)
{
  switch (_error) {
    case 0: printf("Erwarte genau 3 Noten!"); break;
    case 1: printf("Erste Note muss zwischen 1 und 5 liegen!"); break;
    case 2: printf("Zweite Note muss zwischen 1 und 5 liegen!"); break;
    case 3: printf("Dritte Note muss zwischen 1 und 5 liegen!"); break;
  }
}

void calcGrades(int _userInput)
{
  int x, y, z;
  x = _userInput / 100;
  y = (_userInput % 100) / 10;
  z = _userInput % 10;

  if (x > 9 || x < 1)
    { printError(0); }
  else if (x > 5 || x < 1)
    { printError(1); }
  else if (y > 5 || y < 1)
    { printError(2); }
  else if (z > 5 || z < 1)
    { printError(3); }
  else if (x == 5 || y == 5 || z == 5)
    { printGrades(2); }
  else if (x + y + z > 4)
    { printGrades(3); }
  else if (x + y + z == 4)
    { printGrades(1); }
  else if (x + y + z == 3)
    { printGrades(0); }

}

int main()
{
  int userInput;
  printf("Noten: ");
  scanf("%d", &userInput);
  calcGrades(userInput);  //324
  return 0;
}
