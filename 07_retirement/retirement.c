#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void print_monthly_info(int months, double balance) {
  printf("Age %3d month %2d you have $%.21f\n", months / 12, months % 12, balance);

  return;
}

double balance_calc(double balance, retire_info retire_stats) {
  balance += balance * retire_stats.rate_of_return;
  balance += retire_stats.contribution;

  return balance;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  double accountBalance = initial;
  int currentAge = startAge-1;
  
  for (int i=0; i <working.months; i++) {
    currentAge += 1;
    print_monthly_info(currentAge, accountBalance);
    accountBalance = balance_calc(accountBalance, working);
  }

  for (int i = 0; i < retired.months; i++) {
    currentAge += 1;
    print_monthly_info(currentAge, accountBalance);
    accountBalance = balance_calc(accountBalance, retired);
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
