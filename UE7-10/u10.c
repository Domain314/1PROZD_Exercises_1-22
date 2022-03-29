#include <stdio.h>

int main()
{
  int firstParticipant = 1, newParticipant = 99, bestParticipant = 1, amount = 1;
  while (newParticipant != 0)
  {
    amount++;
    printf(": ");
    scanf(" %d", &newParticipant);
    if (newParticipant == 0) {
      continue;
    }

    if (newParticipant <= firstParticipant && newParticipant != 0)
    {
      firstParticipant++;
      printf("position #1: %d\n", firstParticipant);

      if (newParticipant == 1) {
        bestParticipant = amount;
        printf("new leader: #%d\n", bestParticipant);
      }
    }
  }
  printf("final position #1: %d\n", firstParticipant);
  printf("winner: #%d", bestParticipant);

  return 0;
}
