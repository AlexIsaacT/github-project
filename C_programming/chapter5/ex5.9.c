#include<stdio.h>
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int main()
{
   int year, month, day, yearday;
   int  x, y;
   printf ("Enter Year, Month and Day : ");
   scanf ("%d%d%d", &year, &month, &day);
   printf ("The corresponding day of the year is %d\n", day_of_year(year, month, day));
   printf ("Enter the Year, Yearday : ");
   scanf ("%d%d", &year, &yearday);
   month_day(year, yearday, &x, &y);
   printf ("The corresponding month and day are %d and %d\n", x, y);
   return 0;
}
static char daytab[2][13] = {
   {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
  int i, leap;
  char *p;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  p = &daytab[leap][1];
  for (i = 1; i < month; i++, p++)
    day += *p;
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;
  char *p;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  p = &daytab[leap][1];
  for (i = 1; yearday > *p; i++, p++)
     yearday -= *p;
  *pmonth = i;
  *pday = yearday;
}
