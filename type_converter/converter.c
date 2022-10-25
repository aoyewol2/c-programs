//This program converts types - created by Ashley Oyewole (SN: 251233783)

#include <stdio.h>
#include <ctype.h>

char inputChar;
int inputType;

void kg_pounds(), hec_acres(), litres_gallons(), km_miles(); // declare conversion functions

int main() {
    
    printf("Copyright © 2022 Ashley Oyewole \n\n");
    printf("Welcome to Type Converter! \n----\n");

    printf(
        
        "Enter 1 to convert kilograms to pounds\n"
        "Enter 2 to convert hectares to acres\n"
        "Enter 3 to convert litres to gallons\n"
        "Enter 4 to convert kilometres to miles\n"
        "Enter 5 to quit: ");

    scanf(" %d", &inputType);

    if (inputType == 1) {
        kg_pounds(); // calls kg --> pounds function
    }
    else if (inputType == 2) {
        hec_acres(); // calls hectares --> acres function
    }
    else if (inputType == 3) {
        litres_gallons(); // calls litres --> gallons function
    }
    else if (inputType == 4) {
        km_miles(); // calls km --> miles function
    }

    else if (inputType == 5) {
        printf("Program complete.\n"); // terminate program
        return 0;
    }
    else {
        printf("Invalid input!\n"); // calls main() after invalid input
        main();
    }
}

// kg --> pounds (1 kilogram = 2.20462 pounds)
void kg_pounds() {

    float kg, pounds;

    printf("Enter 'K' for kg to pounds or 'P' for pounds to kg: ");
    scanf(" %c", &inputChar);

    if (toupper(inputChar) == 'K') {
        
        printf("\nEnter kilogram(s): ");
        scanf(" %f", &kg);

        pounds = kg * 2.20462;
        printf("%1.0f kilogram(s) is equal to %f pound(s)\n\n", kg, pounds);
        main();
    }

    else if (toupper(inputChar) == 'P') {

        printf("\nEnter pound(s): ");
        scanf(" %f", &pounds);

        kg = pounds / 2.20462;
        printf("%1.0f pound(s) is equal to %f kilogram(s)\n\n", pounds, kg);
        main();
    }

    else {
        printf("Invalid input!\n");
        kg_pounds();
    }
}

// hectares --> acres (1 hectare = 2.47105 acres)
void hec_acres() {
    
    float hec, acres;

    printf("Enter 'H' for hectares to acres or 'A' for acres to hectares: ");
    scanf(" %c", &inputChar);

    if (toupper(inputChar) == 'H') {
        
        printf("\nEnter hectare(s): ");
        scanf(" %f", &hec);

        acres = hec * 2.47105;
        printf("%1.0f hectares(s) is equal to %f acre(s)\n\n", hec, acres);
        main();
    }

    else if (toupper(inputChar) == 'A') {

        printf("\nEnter acre(s): ");
        scanf(" %f", &acres);

        hec = acres / 2.47105;
        printf("%1.0f acre(s) is equal to %f hectare(s)\n\n", acres, hec);
        main();
    }

    else {
        printf("Invalid input!\n");
        hec_acres();
    }
}

// litres --> gallons (1 litre = 0.264172 gallons)
void litres_gallons() {
    
    float litres, gallons;

    printf("Enter 'L' for litres to gallons or 'G' for gallons to litres: ");
    scanf(" %c", &inputChar);

    if (toupper(inputChar) == 'L') {
        
        printf("\nEnter litre(s): ");
        scanf(" %f", &litres);

        gallons = litres * 0.264172;
        printf("%1.0f litres(s) is equal to %f gallon(s)\n\n", litres, gallons);
        main();
    }

    else if (toupper(inputChar) == 'G') {

        printf("\nEnter gallon(s): ");
        scanf(" %f", &gallons);

        litres = gallons / 0.264172;
        printf("%1.0f gallon(s) is equal to %f litre(s)\n\n", gallons, litres);
        main();
    }

    else {
        printf("Invalid input!\n");
        litres_gallons();
    }
}

// kilometer --> mile (1 kilometre = 0.621371 miles)
void km_miles() {

    float km, miles;

    printf("Enter 'K' for kilometers to miles or 'M' for miles to kilometers: ");
    scanf(" %c", &inputChar);

    if (toupper(inputChar) == 'K') {
        
        printf("\nEnter kilometer(s): ");
        scanf(" %f", &km);

        miles = km * 0.621371;
        printf("%1.0f kilometer(s) is equal to %f mile(s)\n\n", km, miles);
        main();
    }

    else if (toupper(inputChar) == 'M') {

        printf("\nEnter mile(s): ");
        scanf(" %f", &miles);

        km = miles / 0.621371;
        printf("%1.0f mile(s) is equal to %f kilometer(s)\n\n", miles, km);
        main();
    }

    else {
        printf("Invalid input!\n");
        km_miles();
    }
}
