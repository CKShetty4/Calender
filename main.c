#include <stdio.h>
#include <stdlib.h>

int get_1st_weekday(int year, int month) {
    int t = year;
    int m = month;
    if (m < 3) {
        m += 12;
        t -= 1;
    }
    //calculates the day of the week using Zeller's Congruence formula
    int q = 1;
    int K = t % 100;
    int J = t / 100;
    int f = q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J;
    int d = (f - 1) % 7;
    if (d < 0) d += 7;
    return d; //final result d is the day of the week, where 0 = Saturday, 1 = Sunday,..., 6 = Friday.
}

int main() {
    system("Color 3F");//The system function is used to set the console color to bright white on a blue background (this is a Windows-specific command).
    /*
    This follows the pattern of <Background><Text>. The following is the color codes that can be used:
    0 : Black
    1 : Blue
    2 : Green
    3 : Aqua
    4 : Red
    5 : Purple
    6 : Yellow
    7 : White
    8 : Gray
    9 : Light Blue
    A : Light Green
    B : Light Aqua
    C : Light Red
    D : Light Purple
    E : Light Yellow
    F : Bright White
    */
    int year, month, day, daysInMonth, weekDay = 0, startingDay;
    printf("\nEnter your desired year:");
    scanf("%d", &year);

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0)//checks if the year is a leap year, and if so, sets the number of days in February to 29.
        monthDay[1] = 29;

    printf("\nDo you want to see the calendar for a specific month? (1 for yes, 0 for no):");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter the month (1-12):");
        scanf("%d", &month);
        month -= 1; // adjust for 0-based indexing

        daysInMonth = monthDay[month];
        printf("\n\n---------------%s-------------------\n", months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

        startingDay = get_1st_weekday(year, month + 1);//The program calculates the starting day of the month using the get_1st_weekday function.

        for (weekDay = 0; weekDay < startingDay; weekDay++)
            printf("     ");

        for (day = 1; day <= daysInMonth; day++) {
            printf("%5d", day);

            if (++weekDay > 6) {
                printf("\n");
                weekDay = 0;
            }
        }
        printf("\n");
    } else {
        for (month = 0; month < 12; month++) {

            daysInMonth = monthDay[month];
            printf("\n\n---------------%s-------------------\n", months[month]);
            printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

            startingDay = get_1st_weekday(year, month + 1);

            for (weekDay = 0; weekDay < startingDay; weekDay++)
                printf("     ");

            for (day = 1; day <= daysInMonth; day++) {
                printf("%5d", day);

                if (++weekDay > 6) {
                    printf("\n");
                    weekDay = 0;
                }
            }
            printf("\n");
        }
    }

    return 0;//The program returns 0 to indicate that it has finished successfully.
}
