// 1154.一年中的第几天
#include <stdbool.h>
#include <stdlib.h>

int leapYear(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? 1 : 0;
}

// date format is YYYY-MM-DD
int dayOfYear(char *date)
{
    int year = atoi(date);      // atoi converts the strng argument str to an integer
    int month = atoi(date + 5); // return 5th
    int day = atoi(date + 8);
    int amount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (leapYear(year))
        amount[1] = 29;

    int ans = 0;
    for (int i = 0; i < month - 1; i++)
        ans += amount[i];

    return ans + day;
}