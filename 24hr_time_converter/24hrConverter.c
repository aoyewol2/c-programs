// Program by Ashley Oyewole - This program converts 24-hour time to 12-hour time.

#include <stdio.h>

int main(void) {

    // integer variables
	int hour, minute;

    printf("24-Hour Clock Time Converter\n----\n");

    printf("Enter a 24-hour time: ");
    scanf("%d:%02d", &hour, &minute);

    // check for invalid output
    if (hour > 23 || minute > 60) {
        printf("Invalid input! ");

        printf("Enter a 24-hour time: ");
        scanf("%d:%02d", &hour, &minute);
    }

    // if time is greater than 12
    if (hour > 12) {
        
        hour = hour - 12;
        printf("Equivalent 12-hour time: %d:%02d PM\n", hour, minute);
    }

    // if time is 12, make PM
    else if (hour == 12) {
        printf("Equivalent 12-hour time: %d:%02d PM\n", hour, minute);
    }

    // if time is less than 12 and doesnt equal 12
    else {

        printf("Equivalent 12-hour time: %d:%02d AM\n", hour, minute);
    }

}