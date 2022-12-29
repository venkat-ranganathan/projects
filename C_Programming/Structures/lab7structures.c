/**
 * @file lab7structures.c
 * @Venkat Ranganathan
 * @brief
 * @version 0.1
 * @date 2022-12-28
 *
 * @copyright Copyright (c) 2022
 *
 */

// preprocessor directives
#include "lab7structures.h"

/*

In Lab-7, we will implement a program that calculates:
●	The number of elapsed days between two dates.
●	On which day of the week a particular date falls.


Notes:

// using typedef allows you use use 'Date' in this case instead of struct all the time
typedef struct
{
    // data
} Date; (Date is the data type)

// in function call, don't include data type, only the variable of the data type
validate(d1);

unsigned int validate(Date d);

*/

/*
Implement the function "unsigned int validate(Date d)" to check if the given date in the structure “d” is valid.
The function should return “1” if the date is valid or return “0” if the date is not valid.
*/
unsigned int validate(Date d)
{
    // return 0 if “year” is either less than 1901 or greater than 2020.
    if (d.year < 1901 || d.year > 2020)
    {
        return 0;
    }

    // return 0 if “month” is equal to 0 or greater than 12.
    else if (d.month == 0 || d.month > 12)
    {
        return 0;
    }

    // return 0 if “day” is equal to 0.
    else if (d.day == 0)
    {
        return 0;
    }

    // return 0 if “month” is February and the “day” is greater than 29.
    else if (d.month == 2 && d.day > 29)
    {
        return 0;
    }

    // return 0 if “month” is April, June, September, or November, and the “day” is greater than 30.
    else if ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day > 30)
    {
        return 0;
    }

    // return 0 if “month” is January, March, May, July, August, October, or December, and the “day” is greater than 31.
    else if ((d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) && d.day > 31)
    {
        return 0;
    }

    // return 1 if none of the above conditions are true
    else
    {
        return 1;
    }
}

/*
Implement the function "unsigned int calculateYear(Date d)" to calculate a value based on the year
of the given date in the structure “d”. The function should return the computed value,
which is of type unsigned integer.
*/
unsigned int calculateYear(Date d)
{
    // return year - 1 if the "month" is January or February
    if (d.month == 1 || d.month == 2)
    {
        return d.year - 1;
    }

    // return year if the "month" is not January or February
    else
    {
        return d.year;
    }
}

/*
Implement the function "unsigned int calculateMonth(Date d)" to calculate a value based on the month
of the given date in the structure “d”. The function should return the computed value,
which is of type unsigned integer.
*/
unsigned int calculateMonth(Date d)
{
    // return month + 13 if "month" is January or February
    if (d.month == 1 || d.month == 2)
    {
        return d.month + 13;
    }

    // else return month + 1
    else
    {
        return d.month + 1;
    }
}

/*
Implement the function "unsigned int calculateN(Date d)" to calculate the “N” value based
on the formula below for the given date in the structure “d”. The function should return
the computed “N” value, which is of type unsigned integer.
*/
unsigned int calculateN(Date d)
{
    // given 'N' calculation
    unsigned int N = ((1461 * calculateYear(d)) / 4) + ((153 * calculateMonth(d)) / 5) + d.day;

    // return calculated 'N'
    return N;
}

/*
Implement the function "unsigned int elapsedDays(Date d1, Date d2)" to calculate the number
of elapsed days between two given dates in the structures “d1” and “d2”. The function should
return the computed number of days, which is of type unsigned integer.
*/
unsigned int elapsedDays(Date d1, Date d2)
{
    // returns 0 if structures d1 or d2 are invalid dates
    if (validate(d1) == 0 || validate(d2) == 0)
    {
        return 0;
    }

    // otherwise returns the difference between the two dates (with the assumption that d2 will always be a larger value than d1)
    return calculateN(d2) - calculateN(d1);
}

/*
Implement the function "unsigned int dayOfWeek(Date d, char daystr[])" to calculate on which
day of the week a particular date falls. The function receives as parameters a given date in
the structure “d” and an array of characters “daystr”, which will hold the day of the week
after it is computed. The function should return “1” if the computation was successful or return “0”
if the given date is not valid.
*/
unsigned int dayOfWeek(Date d, char daystr[])
{
    // returns 0 if structure d is an invalid date
    if (validate(d) == 0)
    {
        return 0;
    }

    // declare integer day equal to calculated 'N' value minus 621049
    // int day = calculateN(d) - 621049;

    // sets day of week equal to the remainder of calculated day value divided by 7
    // int dayWeek = day % 7;

    // set structure d.day equal to the calculated N value minus 621049 (given constant) and used modulus operator to find the remainder
    d.day = (calculateN(d) - 621049) % 7;

    // checks remainder from d.day with cases and returns corresponding day of week
    // remainder is from 0 to 6, Sunday to Saturday, respectively
    // originally used a bunch of if / if else statements, but switch statement looks cleaner
    // it wouldn't work when I tried to just set daystr equal to a specific day of the week, had to use strcpy()
    switch (d.day)
    {
    case 0:
        strcpy(daystr, "Sunday");
        break;
    case 1:
        strcpy(daystr, "Monday");
        break;
    case 2:
        strcpy(daystr, "Tuesday");
        break;
    case 3:
        strcpy(daystr, "Wednesday");
        break;
    case 4:
        strcpy(daystr, "Thursday");
        break;
    case 5:
        strcpy(daystr, "Friday");
        break;
    case 6:
        strcpy(daystr, "Saturday");
        break;
    }

    // returns 1 if calculation went through okay
    return 1;
}
