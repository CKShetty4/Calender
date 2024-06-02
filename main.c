#include <stdio.h>
#include <stdlib.h>

int get_1st_weekday(int year, int month) {
    int t = year;
    int m = month;
    if (m < 3) {
        m += 12;
        t -= 1;
    }
    int q = 1;
    int K = t % 100;
    int J = t / 100;
    int f = q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J;
    int d = (f - 1) % 7;
    if (d < 0) d += 7;
    return d;
}

int main() {
    system("Color 3F");
    int year, month, day, daysInMonth, weekDay = 0, startingDay;
    printf("\nEnter your desired year:");
    scanf("%d", &year);

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0)
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

    return 0;
}
