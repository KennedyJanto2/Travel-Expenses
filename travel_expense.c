/* 
CS2600 Project2: Travel Expenses
Liangjie Shen
2/7/2022
*/

#include <stdio.h> // input/output library
#include <string.h> // string library including strlen()

// function declaration
bool timeFormat(char[]);

int main()
{
    int day = 0;
    char departTime[8];
    char arrivalTime[8];

    printf("Welcome to Travel Expense Calculator!\n");
    printf("Please enter the following information for the trip:!\n\n");

    while(day < 1){
        printf("The total number of days spent on the trip[1 or more]: ");
        scanf("%d", &day);
        if(day < 1)
            printf("Number of days cannot be less than 1! Try again!\n");
    }

    while(timeFormat(departTime)){
        printf("The time of departure on the first day of the trip:[##:## AM/PM] ");
        scanf("%s", &departTime);
        
    }

    while(timeFormat(arrivalTime)){
        printf("The time of arrival back home on the last day of the trip:[##:## AM/PM] ");
        scanf("%s", &arrivalTime);
    }




}

bool timeFormat(char validTime[]){
    for(int i = 0; i < validTime.)
    if(validTime[0] >= '0' && validTime[0] <='9' && validTime[1] == ':' && validTime )
}