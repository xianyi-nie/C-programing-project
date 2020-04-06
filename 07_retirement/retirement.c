#include <stdio.h>
#include <stdlib.h>

struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement (int starAge, double initial, retire_info working, retire_info retired)
{
  for (int i = 0; i < working.months; i++)
    {
      int workingAge = starAge / 12;
      int workingmonth = starAge % 12;
      printf ("Age %3d month %2d you have $%.2f\n", workingAge, workingmonth, initial);
      initial = initial * working.rate_of_return + initial + working.contribution;
      starAge = starAge + 1;
    }
  for (int j = 0; j < retired.months; j++)
    {   
      int retiredAge = starAge / 12;
      int retiredmonth = starAge % 12;
      printf ("Age %3d month %2d you have $%.2f\n", retiredAge, retiredmonth, initial);
      initial = initial * retired.rate_of_return + initial + retired.contribution;
      starAge = starAge +1;
    }
}

int main()
{
  retire_info working;
  retire_info retired;
 
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;
    
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;
  
  retirement (327, 21345, working, retired);
    return 0;
}

