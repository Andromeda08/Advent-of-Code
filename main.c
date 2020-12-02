#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

int main(void) {
    /* Part selector
    * true = part_1 style verification
    * false = part_2 style verification
    */ bool part_1 = false;
    //Test for one password
    bool testing = false;
    //Program runtime
    clock_t begin = clock();
    //Console colored text output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    //Save current console attributes
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    /* Advent of Code 2020 | Day 2
     * Notes:
     * Input format: a-b c: password
     * "c" is a character that must appear atleast "a", and at most "b" times.
     * Extras in Part 2:
     * "c" must appear in exactly on of "a" or "b" positions.
     */
    //Hi
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("--- Advent of Code | Day 2: Password Philosophy ---\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    //Open input file
    char* file = "C:\\Dev\\CLion\\Advent-of-Code-2020\\input\\input-2.txt";
    FILE* passwords = fopen(file, "r");
    if(passwords==NULL){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("Couldn't open file \"%s\".", file);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        return 0;
    }
    //Amount of valid passwords
    int valid_passwords = 0;
    //Loop through all passwords
    for(int i = 0; i < 1000; i++) {
        int sc_l= 0, da_l = 0, sp_l = 0, count = 0;
        char read[50] = {'0'}, sc = ':', da = '-', sp = ' ';
        //Read line
        fgets(read, 50, passwords);
        //Trim read
        int length_read = strlen(read);
        char *check;
        check = (char*)malloc((length_read+1)*sizeof(char));
        strcpy(check, read);
        //Find index of :
        for(sc_l = 0; sc_l < strlen(check); sc_l++) {
            if(check[sc_l] == sc) {
                break;
            }
        }
        //Find index of -
        for(da_l = 0; da_l < strlen(check); da_l++) {
            if(check[da_l] == da) {
                break;
            }
        }
        //Find index of first space
        for(sp_l = 0; sp_l < strlen(check); sp_l++) {
            if(check[sp_l] == sp) {
                break;
            }
        }
        //Select character to be counted
        char findMe = check[sc_l - 1];
        //How many time does the character occur
        for(int j = (sc_l + 2); j < strlen(check); j++) {
            if(check[j] == findMe)
                count++;
        }
        //Minimum count
        char c_min[30] = {'0'};
        strncpy(c_min, check, da_l);
        int min;
        sscanf(c_min, "%d", &min);
        //Maximum count
        int length_max = sp_l-da_l-1;
        char *c_max;
        c_max = (char*)malloc((length_max +1) * sizeof(char));
        memcpy(c_max, check+da_l+1, length_max);
        c_max[length_max] = '\0';
        int max;
        sscanf(c_max, "%d", &max);
        //Counts first occurrence
        //max++;
        //Validation
        bool valid = false;
        int pos1 = sc_l+1+min, pos2 = sc_l+1+max;
        if(part_1) {
            if (count >= min) {
                if (count <= max) {
                    valid = true;
                    valid_passwords++;
                }
            } else {
                valid = false;
            }
        } else {
            if(check[pos1] == findMe) {
                if(check[pos2] != findMe) {
                    valid = true;
                    valid_passwords++;
                }
            } else if(check[pos2] == findMe){
                if(check[pos1] != findMe) {
                    valid = true;
                    valid_passwords++;
                }
            }
        }
        //Testing
        if(testing) {
            printf("ID: %d | Validating password: %s================================================\n", i, check);
            printf("Format parsing key locations:\n"
                   "{%c | %d} {%c | %d} {%c | %d}\n", sp, sp_l, sc, sc_l, da, da_l);
            printf("Conditions:\n{%c | %d} {min | %d} {max | %d}\n", findMe, count, min, max);
            printf("{check[min] = %c} {check[min] = %c}\n", check[pos1], check[pos2]);
            printf("================================================\n"
                   "This password is ");
            if(valid) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("valid");
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("invalid");
            }
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("!\n");
            break;
        }
    }
    //Results
    if(!testing) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        printf("Valid passwords: %d\n", valid_passwords);
    }
    //Execution time
    clock_t end = clock();
    double execution_time = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Execution time: %lf s.\n", execution_time);
    SetConsoleTextAttribute(hConsole, saved_attributes);

    system("pause");
    return 0;
}