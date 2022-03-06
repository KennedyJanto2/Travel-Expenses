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
bool timeFormat2(char[]);

int main()
{
    int day = 0;
    char departTime[6];
    char departTime1[6];
    char departTime2[2];
    char arrivalTime[6];
    char arrivalTime1[6];
    char arrivalTime2[2];

    printf("Welcome to Travel Expense Calculator!\n");
    printf("Please enter the following information for the trip:!\n\n");

    while(day < 1){
        printf("The total number of days spent on the trip[1 or more]: ");
        scanf("%d", &day);
        if(day < 1)
            printf("Number of days cannot be less than 1! Try again!\n");
    }

    while(true){
        printf("The time of departure on the first day of the trip:[##:## AM/PM] ");
        scanf("%s", departTime);
        strcpy(departTime1,departTime);

        bool rightFormat = timeFormat(departTime);
        scanf("%s", departTime2);

        if(rightFormat == 1 && timeFormat2(departTime2) == 1 ){ 
            break;
        }

        else
            printf("Wrong depart time format!\n");
        
    }

    while(true){
        printf("The time of arrival back home on the last day of the trip:[##:## AM/PM] ");
        scanf("%s", arrivalTime);
        strcpy(arrivalTime1,arrivalTime);
        bool rightFormat = timeFormat(arrivalTime);
        scanf("%s", arrivalTime2);

        if(rightFormat == 1 && timeFormat2(arrivalTime2) == 1 ){ 
            break;
        }

        else
            printf("Wrong depart time format!\n");
        
    }

    printf("\n\n%s %s",departTime1,departTime2);
    printf("\n\n%s %s",arrivalTime1,arrivalTime2);
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
            if(isdigit(validTime[counter]) && isdigit(validTime[counter+1]))
                return true;
        }
    }

    return false;


}

bool timeFormat2(char validTime2[]){
    int counter = 0;
    if((validTime2[counter] == 'A' || validTime2[counter] == 'P') && validTime2[counter+1] == 'M')
        return true;
    return false;
}
