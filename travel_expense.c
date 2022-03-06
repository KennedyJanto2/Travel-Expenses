/* 
CS2600 Project2: Travel Expenses
Liangjie Shen
2/7/2022
*/

#include <stdio.h> // input/output library
#include <string.h> // string library including strlen()
#include <ctype.h> // isdigit()
#include <stdbool.h> // boolean function

// function declaration
bool timeFormat(char[]);

// glotbal variable
int max = 10;

int main()
{
    int day = 0;
    char departTime[max];
    char arrivalTime[max];
    int count=0;
    char x;
    char y;

    printf("Welcome to Travel Expense Calculator!\n");
    printf("Please enter the following information for the trip:!\n\n");

    while(day < 1){
        printf("The total number of days spent on the trip[1 or more]: ");
        scanf("%d", &day);
        if(day < 1)
            printf("Number of days cannot be less than 1! Try again!\n");
    }

    getchar();

    while(true){
        printf("The time of departure on the first day of the trip:[##:## AM/PM] ");
        count = 0;
        while((x = getchar()) != '\n'){
            departTime[count] = x;
            count++;
        }

        if(timeFormat(departTime)!=1)
         
            printf("Wrong depart time format!\n");

        else
            break;
        
    }

    while(true){
        printf("The time of arrival back home on the last day of the trip:[##:## AM/PM] ");

        count = 0;

        while((y = getchar()) != '\n'){
            arrivalTime[count] = y;
            count++;
        }
        
        if(timeFormat(arrivalTime)!= 1)
            printf("Wrong arrival time format!\n");
        
        else
            break;

    }

}

bool timeFormat(char validTime[]){
    
    int counter = 0;
    if(isdigit(validTime[counter])){ 

        if(validTime[counter] == '1'){
            counter++;
            if(isdigit(validTime[counter]))
                counter++;
            
        }
        else if(isdigit(validTime[counter]))
            counter=1;

        else    
            return false;

        if(validTime[counter] == ':'){
            counter++;
            if(isdigit(validTime[counter]) && isdigit(validTime[counter+1])){
                counter+=3;
                if((validTime[counter] == 'A' || validTime[counter] == 'P') && validTime[counter+1] == 'M')
                    return true;
            }
        }
    }

    return false;


}