#include "Day1.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

int day1() {
    //Program runtime
    clock_t begin = clock();
    //Console colored text output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    //Save current console attributes
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    //Advent of Code | Day 1
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("--- Advent of Code | Day 1: Report Repair ---\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    //Open file
    char* file = "C:\\Dev\\CLion\\Advent-of-Code-2020\\input\\input-1.txt";
    FILE* input = fopen(file, "r");
    if(input == NULL) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("Couldn't open file \"%s\".", file);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        return 1;
    }
    //Read file
    int expenses[200] = {0};
    for(int i = 0; i < 200; i++) {
        fscanf(input, "%d", &expenses[i]);
    }
    //Numbers for solution
    int a, b, c;
    //Part 1
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("Solution for Part 1:\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    for(int i = 0; i < 200; i++) {
        a = expenses[i];
        for (int j = 0; j < 200; j++) {
            b = expenses[j];
            if (a + b == 2020) {
                printf("a = %d | b = %d | a+b = %d | a*b = %d\n", a, b, a + b, a*b);
                break;
            }
        }
    }
    //Part 2
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Solution for Part 2:\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    for(int i = 0; i < 200; i++) {
        a = expenses[i];
        for (int j = 0; j < 200; j++) {
            b = expenses[j];
            for (int k = 0; k < 200; k++) {
                c = expenses[k];
                if(a+b+c == 2020) {
                    printf("a = %d | b = %d | c = %d | a+b+c = %d | a*b*c = %d\n", a, b, c, a+b+c, a*b*c);
                }
            }
        }
    }
    //Execution time
    clock_t end = clock();
    double execution_time = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Execution time: %lf s.\n", execution_time);
    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}