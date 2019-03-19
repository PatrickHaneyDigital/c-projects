#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double add_interest (double balance, double rate_of_return, double contribution) {
  double interest = balance * rate_of_return;
  balance += interest;
  balance += contribution;
  return balance;
  }

double retire_calc (double balance, int start_age, retire_info person) {
  int months = person.months;
  for (int month_count = 0; month_count < months; month_count++) {
    printf("Age %3d month %2d you have $%.02f\n", (start_age + month_count)/12, (start_age + month_count) % 12, balance); 
    balance = add_interest(balance, person.rate_of_return, person.contribution);
  }
  return balance;
  }

void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  double after_working;
  after_working = retire_calc(initial,startAge,working);
  startAge += working.months;
  after_working = retire_calc(after_working,startAge,retired);
  }

/*void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  double balance = initial;
  int currentAge;
  for (int month_count = 0; month_count < working.months; month_count++) {
    printf("Age %3d month %2d you have $%.02f\n", (startAge + month_count)/12, (startAge + month_count) % 12, balance);
    balance += (balance * working.rate_of_return);
    balance += working.contribution;
  }
  currentAge = startAge + working.months;
  for (int month_count = 0; month_count < retired.months; month_count++) {
    printf("Age %3d month %2d you have $%.02f\n", (currentAge + month_count)/12, (currentAge + month_count) % 12, balance);
    balance += (balance * retired.rate_of_return);
    balance += retired.contribution;
  }
  }*/
    

int main(void) {
  retire_info person;
  person.months = 489;
  person.contribution = 1000;
  person.rate_of_return = (0.045/12);
  retire_info rperson;
  rperson.months = 384;
  rperson.contribution = -4000;
  rperson.rate_of_return = (.01/12);
  retirement(327,21345.00,person,rperson);
  return EXIT_SUCCESS;
}
