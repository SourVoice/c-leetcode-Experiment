// 1185. 一周中的第几天
int leap(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

char *dayOfTheWeek(int day, int month, int year)
{
    char *weekend[8] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int monthday[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_monthday[12] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int sumDay = 0;
    int here = 0;
    if (year < 2022)
    {
        for (int i = 2021; i >= year; i--)
            if (leap(i))
                sumDay += 366;
            else
                sumDay += 365;
        if (leap(year))
            for (int i = 1; i < month; i++)
                sumDay -= leap_monthday[i];
        else
            for (int i = 1; i < month; i++)
                sumDay -= monthday[i];
        sumDay -= day;
        sumDay += 3;
        if (!(sumDay % 7))
            return weekend[1];
        else
            here = sumDay % 7;
        return weekend[8 - here];
    }
    if (year == 2022)
    {
        if (month > 1 || (day >= 3 && month == 1))
        {
            for (int i = 1; i < month; i++)
                sumDay += monthday[i];
            sumDay += day;
            here = (sumDay - 2) % 7;
            if (!here)
                return weekend[7];
            return weekend[here];
        }
        else
            return weekend[7 - day % 7];
    }
    if (year > 2022)
    {
        for (int i = 2022; i < year; i++)
            if (leap(i))
                sumDay += 366;
            else
                sumDay += 365;
        if (leap(year))
            for (int i = 1; i < month; i++)
                sumDay += leap_monthday[i];
        else
            for (int i = 1; i < month; i++)
                sumDay += monthday[i];
        sumDay += day;
        here = (sumDay - 2) % 7;
        if (!here)
            return weekend[7];
        return weekend[here];
    }
    return day;
}