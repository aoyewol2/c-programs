//This program converts types - created by Ashley Oyewole (251233783)

#include <stdio.h>
#include <ctype.h>

void kg_pounds();
void hec_acres();
void litres_gallons();
void km_miles();

int main() {

    int inputType;

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
        printf("Program complete.");
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
    char inputChar;

    printf("Enter 'K' for kg to pounds or 'P' for pounds to kg: ");
    scanf(" %c", &inputChar);

    if (toupper(inputChar) == 'K') {
        
        printf("\n Enter kilogram(s): ");
        scanf(" %f", &kg);

        pounds = kg * 2.20462;
        printf("%f kilograms is equal to %f pounds\n", kg, pounds);
        main();
    }

    else if (toupper(inputChar) == 'P') {

        printf("\n Enter pound(s): ");
        scanf(" %f", &pounds);

        kg = pounds / 2.20462;
        printf("%f pounds is equal to %f kilograms\n", pounds, kg);
        main();
    }

    else {
        printf("Invalid input!\n");
    }
}

// hectares --> acres (1 hectare = 2.47105 acres)
void hec_acres() {
    
    printf("slay");
}

// litres --> gallons (1 litre = 0.264172 gallons)
void litres_gallons() {
    
}

// kilometre and mile (1 kilometre = 0.621371 miles)
void km_miles() {

}