#include <stdio.h>
#define anz 10


double praemien(double betraege[], int anzahl, double grenze, double praemie)
{
  double sum = 0.0;
  for (int i = 0; i < anzahl; i++) {
    if (betraege[i] >= grenze) {
      sum += praemie;
    }
  }
  return sum;
}

int eingabe(double betraege[], int max)
{
  int counter = 0;
  double input = 0;
  while(input >= 0.0 && counter < max)
  {
    printf("Zahl %d: ", counter + 1);
    scanf("%lf", &input);
    if (input < 0) { continue; }
    else { betraege[counter] = input; }
    counter++;
  }
  return counter;
}

double sum(double betraege[], int anzahl)
{
  double sum = 0.0;
  for (int i = 0; i < anzahl; i++) {
    sum += betraege[i];
  }
  return sum;
}



int main()
{
    double arr[anz] = {0};
    double grenze, praemie, gesamt;
    int n;

    n = eingabe(arr, anz);

    printf("Untergrenze: ");
    scanf("%lf", &grenze);
    printf("Praemie: ");
    scanf("%lf", &praemie);

    printf("Summe vor Praemien: %.2f\n", sum(arr, n));
    gesamt = praemien(arr, n, grenze, praemie);
    printf("Praemien gesamt: %.2f\n", gesamt);
    printf("Summe nach Praemien: %.2f\n", sum(arr, n) + gesamt);

    return 0;
}
