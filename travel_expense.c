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


int main()
{
    // variables and arrays declaration
    int day = 0, counter = 0,nightStayed = 0;
    char departTime[10] = "", arrivalTime[10] = "", departTimeChar, arrivalTimeChar, airfare;
    float airfareAmount,carRentalAmount,milesDriven,vehicleExpense,parkingFee,taxiFee,hotelExpenses,allowableMealAmount;

  
    // welcome message
    printf("Welcome to Travel Expense Calculator!\n");
    printf("Please enter the following information for the trip:!\n\n");

    // date input
    while(day < 1){
        // loop until the user input is not less than 1
        printf("The total number of days spent on the trip[1 or more]: ");
        scanf("%d", &day);
        if(day < 1)
            printf("Number of days cannot be less than 1! Try again!\n");
    }

    getchar();

    // departing time input
    while(true){
        // loop until the departing time format is right
        printf("The time of departure on the first day of the trip:[##:## AM/PM] ");
        counter = 0;
        while((departTimeChar = getchar()) != '\n'){
            departTime[counter] = departTimeChar;
            counter++;
        }

        if(timeFormat(departTime)!=1)
         
            printf("Wrong depart time format!\n");

        else
            break;
        
    }

    // Arrival time input

    while(true){
        // loop until the arrival time format is right
        printf("The time of arrival back home on the last day of the trip:[##:## AM/PM] ");

        counter = 0;

        while((arrivalTimeChar = getchar()) != '\n'){
            arrivalTime[counter] = arrivalTimeChar;
            counter++;
        }
        
        if(timeFormat(arrivalTime)!= 1)
            printf("Wrong arrival time format!\n");
        
        else
            break;

    }
    

    // Round trip fare if any

    printf("The amount of any round-trip airfare: $");
    scanf("%f",&airfareAmount);

    while(airfareAmount<0){
        printf("\nAmount cannot be negative!");
        printf("The amount of any round-trip airfare: $");
        scanf("%f",&airfareAmount);
    }

    // Amount of car rental if any
    printf("The amount of any car rentals: ");
    scanf("%f",&carRentalAmount);

    while(carRentalAmount<0){
        printf("\nAmount cannot be negative!");
        printf("\nThe amount of any car rentals: $");
        scanf("%f",&carRentalAmount);
    }

    // Private car driven miles
    printf("Miles driven, if a private vehicle was used: ");
    scanf("%f",&milesDriven);

    while(milesDriven<0){
        printf("\nAmount cannot be negative!");
        printf("\nMiles driven, if a private vehicle was used: ");
        scanf("%f",&milesDriven);
    }

    vehicleExpense = milesDriven*0.27;

    // Parking fee
    printf("Parking Fee: $");
    scanf("%f",&parkingFee);

    while(parkingFee<0){
        printf("\nAmount cannot be negative!");
        printf("\nParking Fee: $");
        scanf("%f",&parkingFee);
    }

    // Taxi fee
    printf("Taxi Fee: $");
    scanf("%f",&taxiFee);

    while(taxiFee<0){
        printf("\nAmount cannot be negative!");
        printf("\nTaxi Fee: $");
        scanf("%f",&taxiFee);
    }

    // Conference or seminar registration fees
    printf("Conference or seminar registration fees: $");
    scanf("%f",&registrationFee);

    while(registrationFee<0){
        printf("\nAmount cannot be negative!");
        printf("\nTaxi Fee: $");
        scanf("%f",&registrationFee);
    }

    // Hotel Expenses
    printf("Number of nights stayed in hotel:");
    scanf("%d",&nightStayed);

    while(nightStayed<0){
        printf("\nNumber of nights stayed cannot be negative!");
        printf("\nNumber of nights stayed in hotel: ");
        scanf("%d",&nightStayed);
    }

    // The amount of each meal eaten
    
    
    // The amounts of allowable meals
    printf("The amounts of allowable meals: $");
    scanf("%f",&allowableMealAmount);

    while(allowableMealAmount<0){
        printf("\nAmount cannot be negative!");
        printf("\nThe amounts of allowable meals: $");
        scanf("%f",&allowableMealAmount);
    }

    printf("\n%d",nightStayed);

    
    
}

bool timeFormat(char validTime[]){
    // return true if the format of time is correct, false otherwise
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