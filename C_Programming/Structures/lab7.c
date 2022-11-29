/******************** DO NOT MAKE ANY CHANGES TO THIS FILE *******************/
#include "lab7structures.h"
#include "lab7structures.h"

int main(void)
{
    printf("########## Testing elapsedDays() ##########\n");
    Date d1, d2;
    unsigned int elapsed;

    printf("Test 1: ");
    // 2/1/1900
    d1.year = 1900;
    d1.month = 2;
    d1.day = 1;
    // 8/5/2004
    d2.year = 2004;
    d2.month = 8;
    d2.day = 5;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 0);
    printf("Passed!\n");

    printf("Test 2: ");
    // 8/8/1988
    d1.year = 1988;
    d1.month = 8;
    d1.day = 8;
    // 1/1/2021
    d2.year = 2021;
    d2.month = 1;
    d2.day = 1;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 0);
    printf("Passed!\n");

    printf("Test 3: ");
    // 13/8/1950
    d1.year = 1950;
    d1.month = 13;
    d1.day = 8;
    // 10/15/2004
    d2.year = 2004;
    d2.month = 10;
    d2.day = 15;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 0);
    printf("Passed!\n");

    printf("Test 4: ");
    // 2/10/1920
    d1.year = 1920;
    d1.month = 2;
    d1.day = 10;
    // 1/0/1970
    d2.year = 1970;
    d2.month = 1;
    d2.day = 0;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 0);
    printf("Passed!\n");

    printf("Test 5: ");
    // 7/1/2010
    d1.year = 2010;
    d1.month = 7;
    d1.day = 1;
    // 7/1/2010
    d2.year = 2010;
    d2.month = 7;
    d2.day = 1;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 0);
    printf("Passed!\n");

    printf("Test 6: ");
    // 12/31/1999
    d1.year = 1999;
    d1.month = 12;
    d1.day = 31;
    // 1/1/2000
    d2.year = 2000;
    d2.month = 1;
    d2.day = 1;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 1);
    printf("Passed!\n");

    printf("Test 7: ");
    // 7/2/2015
    d1.year = 2015;
    d1.month = 7;
    d1.day = 2;
    // 7/16/2015
    d2.year = 2015;
    d2.month = 7;
    d2.day = 16;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 14);
    printf("Passed!\n");

    printf("Test 8: ");
    // 8/8/2004
    d1.year = 2004;
    d1.month = 8;
    d1.day = 8;
    // 2/26/2005
    d2.year = 2005;
    d2.month = 2;
    d2.day = 26;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 202);
    printf("Passed!\n");

    printf("Test 9: ");
    // 11/30/1958
    d1.year = 1958;
    d1.month = 11;
    d1.day = 30;
    // 1/31/1959
    d2.year = 1959;
    d2.month = 1;
    d2.day = 31;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 62);
    printf("Passed!\n");

    printf("Test 10: ");
    // 1/1/1901
    d1.year = 1901;
    d1.month = 1;
    d1.day = 1;
    // 12/31/2020
    d2.year = 2020;
    d2.month = 12;
    d2.day = 31;
    elapsed = elapsedDays(d1, d2);
    assert(elapsed == 43829);
    printf("Passed!\n");

    printf("> Passed elapsedDays() tests!\n\n");

    printf("########## Testing dayOfWeek() ##########\n");
    char daystr[STR_SIZE] = "";
    unsigned int status;

    printf("Test 1: ");
    // 12/31/1900
    d1.year = 1900;
    d1.month = 12;
    d1.day = 31;
    daystr[0] = '\0';
    status = dayOfWeek(d1, daystr);
    assert(status == 0);
    printf("Passed!\n");

    printf("Test 2: ");
    // 3/1/1905
    d1.year = 1905;
    d1.month = 3;
    d1.day = 1;
    daystr[0] = '\0';
    status = dayOfWeek(d1, daystr);
    assert(status == 1);
    assert(strcmp(daystr, "Wednesday") == 0);
    printf("Passed!\n");

    printf("Test 3: ");
    // 5/12/1985
    d1.year = 1985;
    d1.month = 5;
    d1.day = 12;
    daystr[0] = '\0';
    status = dayOfWeek(d1, daystr);
    assert(status == 1);
    assert(strcmp(daystr, "Sunday") == 0);
    printf("Passed!\n");

    printf("Test 4: ");
    // 7/9/2004
    d1.year = 2004;
    d1.month = 7;
    d1.day = 9;
    daystr[0] = '\0';
    status = dayOfWeek(d1, daystr);
    assert(status == 1);
    assert(strcmp(daystr, "Friday") == 0);
    printf("Passed!\n");

    printf("Test 5: ");
    // 9/20/2018
    d1.year = 2018;
    d1.month = 9;
    d1.day = 20;
    daystr[0] = '\0';
    status = dayOfWeek(d1, daystr);
    assert(status == 1);
    assert(strcmp(daystr, "Thursday") == 0);
    printf("Passed!\n");

    printf("Test 6: ");
    // 11/10/2018
    d1.year = 2018;
    d1.month = 11;
    d1.day = 10;
    daystr[0] = '\0';
    status = dayOfWeek(d1, daystr);
    assert(status == 1);
    assert(strcmp(daystr, "Saturday") == 0);
    printf("Passed!\n");

    printf("Test 7: ");
    // 12/9/2019
    d1.year = 2019;
    d1.month = 12;
    d1.day = 9;
    daystr[0] = '\0';
    status = dayOfWeek(d1, daystr);
    assert(status == 1);
    assert(strcmp(daystr, "Monday") == 0);
    printf("Passed!\n");

    printf("Test 8: ");
    // 12/22/2020
    d1.year = 2020;
    d1.month = 12;
    d1.day = 22;
    daystr[0] = '\0';
    status = dayOfWeek(d1, daystr);
    assert(status == 1);
    assert(strcmp(daystr, "Tuesday") == 0);
    printf("Passed!\n");

    printf("> Passed dayOfWeek() tests!\n\n");

    printf("> All Tests Passed Successfully!\n");
}
