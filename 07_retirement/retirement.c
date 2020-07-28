#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  double accountBalance = initial;
  int currentAge = startAge-1;
  
  for (int i=0; i <working.months; i++) {
    int years = currentAge / 12;
    int months = currentAge % 12;
    currentAge += 1;
    printf("Age %3d month %2d you have $%.21f\n", years, months, accountBalance);
    accountBalance = accountBalance * (1 + working.rate_of_return) + working.contribution;
  }

  for (int i = 0; i < retired.months; i++) {
    int years = currentAge / 12;
    int months = currentAge % 12;
    currentAge += 1;
    printf("Age %3d month %2d you have$%.21f\n", years, months, accountBalance);
    accountBalance = accountBalance * (1 + retired.rate_of_return) + retired.contribution;
  }
  return;
}

int main (void) {
  retire_info Working;
  Working.months = 489;
  Working.contribution = 1000;
  Working.rate_of_return = (.045 / 12.0);

  retire_info Retired;
  Retired.months = 384;
  Retired.contribution = -4000;
  Retired.rate_of_return = (.01 / 12.0);

  retirement(327, 21435, Working, Retired);

  return 0;
  

}
