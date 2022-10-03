//This program converts types - created by Ashley Oyewole (SN: 251233783)

#include <stdio.h>

void kg_pounds(), hec_acres(), litres_gallons(), km_miles();

char inputChar;
int inputType;

int main() {

    printf("Welcome to Type Converter! \n----\n");

    printf(
        
        "Enter 1 to convert kilograms to pounds\n"
        "Enter 2 to convert hectares to acres\n"
        "Enter 3 to convert litres to gallons\n"
        "Enter 4 to convert kilometres to miles\n"
        "Enter 5 to quit: ");

    scanf(" %d", &inputType);

    if (inputType == 1) {
        kg_pounds();
    }
    else if (inputType == 2) {
        hec_acres();
    }
    else if (inputType == 3) {
        litres_gallons();
    }
    else if (inputType == 4) {
        km_miles();
    }

    else if (inputType == 5) {
        printf("Program complete.\n");
        return 0;
    }
    else {
        printf("Invalid input!\n");
        main();
    }
}

// kg --> pounds (1 kilogram = 2.20462 pounds)
void kg_pounds() {

    float kg, pounds;

    printf("Enter 'K' for kg to pounds or 'P' for pounds to kg: ");
    scanf(" %c", &inputChar);

    if (toupper(inputChar) == 'K') {
        
        printf("\n Enter kilogram(s): ");
        scanf(" %f", &kg);

        pounds = kg * 2.20462;
        printf("%f kilogram(s) is equal to %f pounds\n\n", kg, pounds);
        main();
    }

    else if (toupper(inputChar) == 'P') {

        printf("\n Enter pound(s): ");
        scanf(" %f", &pounds);

        kg = pounds / 2.20462;
        printf("%f pound(s) is equal to %f kilograms\n\n", pounds, kg);
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
        
        printf("\n Enter hectare(s): ");
        scanf(" %f", &hec);

        acres = hec * 2.47105;
        printf("%f hectares(s) is equal to %f acres\n\n", hec, acres);
        main();
    }

    else if (toupper(inputChar) == 'A') {

        printf("\n Enter acre(s): ");
        scanf(" %f", &acres);

        hec = acres / 2.47105;
        printf("%f acre(s) is equal to %f hectare(s)\n\n", acres, hec);
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
        
        printf("\n Enter litre(s): ");
        scanf(" %f", &litres);

        gallons = litres * 0.264172;
        printf("%f litres(s) is equal to %f gallons\n\n", litres, gallons);
        main();
    }

    else if (toupper(inputChar) == 'G') {

        printf("\n Enter gallon(s): ");
        scanf(" %f", &gallons);

        litres = gallons / 0.264172;
        printf("%f gallon(s) is equal to %f litre(s)\n\n", gallons, litres);
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
        
        printf("\n Enter kilometer(s): ");
        scanf(" %f", &km);

        miles = km * 0.621371;
        printf("%f kilometer(s) is equal to %f mile(s)\n\n", km, miles);
        main();
    }

    else if (toupper(inputChar) == 'M') {

        printf("\n Enter mile(s): ");
        scanf(" %f", &miles);

        km = miles / 0.621371;
        printf("%f mile(s) is equal to %f kilometer(s)\n\n", miles, km);
        main();
    }

    else {
        printf("Invalid input!\n");
        km_miles();
    }
}
