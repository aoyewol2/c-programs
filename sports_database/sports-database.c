
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void mainMenu(), searchTeam(), newTeam(), updateTeam(), printTeam();
void teamName(), seeding(), kitColour();

int findTeam(int number);

int strcmp(const char *str1, const char *str2);
char *strcat(char *s1, const char *s2);

#define MAX_STORAGE 32

// define database structure
struct teamDB {

    int teamCodes;
    char teamNames[26];
    char seeding[3];
    char colours;
};

struct teamDB database[MAX_STORAGE];

int currentStorage = 0;

int main() {

    printf("\n* Sports Team Database *\n");

    printf("\nCommands:\ni - Enter new team data\ns - Search team data\nu - Update team data\np - Print team data\nq - Exit program\nh - Help/More Information\n");

    mainMenu();
}

void mainMenu() {

    char inputChar;

    printf("\nEnter operation code: ");
    scanf(" %c", &inputChar);
    while (getchar() != '\n');

    printf("\n");

    // new team
    if (toupper(inputChar) == 'I') {
        newTeam();
    }
    // search team
    else if (toupper(inputChar) == 'S') {
        searchTeam();
    }
    // update team
    else if (toupper(inputChar) == 'U') {
        updateTeam();
    }
    // print data
    else if (toupper(inputChar) == 'P') {
        printTeam();
    }

    else if (toupper(inputChar) == 'H') {

        printf("Commands:\ni - Enter new team data; create a new team\ns - Search team data; search all teams currently stored in database");

        printf("\nu - Update team data; update existing team information\np - Print team data; print all teams to the console\nq - Exit program; terminate program (all data will be lost)\n");

        mainMenu();
    }
    // exit program
    else if (toupper(inputChar) == 'Q') {

        char term;

        printf("Are you sure? All data will be lost (Y/N) ");
        scanf(" %c", &term);

        if (toupper(term) == 'Y') {

            printf("Exiting database ...\n");
            exit(0);
        }

        else if (toupper(term) == 'N') {
            mainMenu();
        }

        else {

            printf("Invalid command. ");
            mainMenu();
        }
    }

    else {
        printf("Invalid operation code. ");
        mainMenu();
    } 
}

// find existing team(s)
int findTeam(int number) {

    for (int i = 0; i < currentStorage; i++) {

        if (database[i].teamCodes == number) {
            return i;
        }
    }
    return -1;
}

void newTeam() {

    int teamCode;

    if (currentStorage == MAX_STORAGE) {
        printf("Database is currently full.\n");
    }

    printf("Enter team code (numeric values only): ");
    scanf("%d", &teamCode);

    // check if team exists
    if (findTeam(teamCode) >= 0) {
        printf("Team already exists.\n");
        newTeam();
    }

    if (teamCode < 0 || teamCode > 31) {

        printf("Value most be greater than 0 and less than 31\n");
        newTeam();
    }
    database[currentStorage].teamCodes = teamCode;
    teamName();
    }

void teamName() {

    printf("Enter team name: ");
    scanf("%s", &database[currentStorage].teamNames);

    char *inputName = database[currentStorage].teamNames;

    if (strlen(inputName) > 25) {
        printf("Only team names up to 25 letters are acceptable.\n");
        teamName();
    }

    // check if team name is stored in database
    for (int i = 0; i < currentStorage; i++) {

        char *dataCheck = database[i].teamNames;
        char *currCheck = database[currentStorage].teamNames;

        if (strcmp(dataCheck, currCheck) == 0){

            printf("Team name already exists.\n");
            teamName();
        }
    }
    seeding();
}

void seeding() {

    printf("Enter group seeding: ");
    scanf("%s", &database[currentStorage].seeding);

    char *currCheck = database[currentStorage].seeding;

    char first = currCheck[0];
    char second = currCheck[1];
    
    // seeding must be two values
    if (strlen(currCheck) > 2) {
        printf("Only groups A-H and seeds 1-4 are acceptable.\n");
        seeding();
    }

    // check if group seeding already exists
    for (int i = 0; i < currentStorage; i++) {

        char *dataCheck = database[i].seeding;

        if (strcmp(dataCheck, currCheck) == 0){

            printf("Group seeding already exists.\n");
            seeding();
        }
    }

    if ('A' <= first && first <= 'H') {
        if ('0' < second && second <= '4') {
            
            kitColour();
        }
        else {
            
        printf("Second value must be 1-4.\n");
        seeding();
        }
    }
    printf("First value must be A-H.\n");
    seeding();

}

void kitColour() {

    char temp;

    printf("Enter team colour: ");
    scanf(" %c", &temp);

    database[currentStorage].colours = temp;

    char colours[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    size_t sizeClr = sizeof(colours) / sizeof(colours[0]);

    // check if user input matches valid colours
    for (int i = 0; i < sizeClr; i++) {
        
        if (temp == colours[i]) {

        currentStorage++;
        mainMenu();
        }
    }

    // if user input is invalid
    printf("Only the values 'R', 'O', 'Y', 'G', 'B', 'I', 'V' are acceptable.\n");
    kitColour();
}

void searchTeam() {

    int searchCode;

    printf("Enter team code: ");
    scanf("%d", &searchCode);

    // search for team code in database
    int i = findTeam(searchCode);

    if (i >= 0) {

        printf("\nTeam Code    Team Name                   Group Seeding    Primary Kit Colour\n");

        printf("%-12d ", database[i].teamCodes);
        printf("%-27s ", database[i].teamNames);
        printf("%-16s ", database[i].seeding);

        // print full colour based on char input
        if (database[i].colours == 'R') {
            printf("Red");
        }
        else if (database[i].colours == 'O') {
            printf("Orange");
        }
        else if (database[i].colours == 'Y') {
            printf("Yellow");
        }
        else if (database[i].colours == 'G') {
            printf("Green");
        }
        else if (database[i].colours == 'B') {
            printf("Blue");
        }
        else if (database[i].colours == 'I') {
            printf("Indigo");
        }
        else if (database[i].colours == 'V') {
            printf("Violet");
        }

        printf("\n");
    }

    else {
        printf("Team not found.");
    }
    mainMenu();
}

void updateTeam() {

    int updateCode;

    printf("Enter team code: ");
    scanf("%d", &updateCode);

    // update team code in database
    int i = findTeam(updateCode);

    if (i >= 0) {

        printf("Enter team name: ");
        scanf("%s", &database[i].teamNames);

        printf("Enter group seeding: ");
        scanf("%s", &database[i].seeding);

        printf("Enter the kit colour: ");
        scanf(" %c", &database[i].colours);
    }
    else {
        printf("Team not found.");
    }

    mainMenu();
}

void printTeam() {

    printf("Team Code    Team Name                   Group Seeding    Primary Kit Colour\n");

    for (int i = 0; i < currentStorage; i++) {

        printf("%-12d ", database[i].teamCodes);
        printf("%-27s ", database[i].teamNames);
        printf("%-16s ", database[i].seeding);


        // print full colour based on char input
        if (database[i].colours == 'R') {
            printf("Red");
        }
        else if (database[i].colours == 'O') {
            printf("Orange");
        }
        else if (database[i].colours == 'Y') {
            printf("Yellow");
        }
        else if (database[i].colours == 'G') {
            printf("Green");
        }
        else if (database[i].colours == 'B') {
            printf("Blue");
        }
        else if (database[i].colours == 'I') {
            printf("Indigo");
        }
        else if (database[i].colours == 'V') {
            printf("Violet");
        }

        printf("\n");
    }

    mainMenu();
}
