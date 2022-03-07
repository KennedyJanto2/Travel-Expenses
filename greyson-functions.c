#include "travelexpenses.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float getCarRentals(Trip *trip){
    return trip->rentalCost;
}

void setCarRentals(Trip *trip, float cost){
    if (cost < 0){
        return;
    }
    trip->rentalCost = cost;
}

int getDaysSpent(Trip *trip){
    return trip->daysSpent; 
}

void setDaysSpent(Trip *trip, int days){
    trip->daysSpent = days;
}

float getMilesDriven(Trip *trip){
    return trip->milesDriven;
}

void setMilesDriven(Trip *trip, float miles){
    trip->milesDriven = miles;
}

float getParkingCost(Trip *trip){
    return trip->parkingCost;
}

void setParkingCost(Trip *trip, float cost){
    trip->parkingCost = cost;
}

float getTaxiCost(Trip *trip){
    return trip->taxiCost;
}

void setTaxiCost(Trip *trip, float cost){
    trip->taxiCost = cost;
}

float ReimbursableExpenses(Trip *trip){
    float spent = TotalExpenses(trip);
    float allowed = totalAllowableExpenses(trip);
    if (spent > allowed){
        return spent - allowed;
    }
    return 0;
}

void setMealExpenses(Trip *trip, float total){
    trip->mealCost = total;
}

float getMealTotal(Trip *trip){
    return trip->mealCost;
}

float AmountSaved(Trip *trip){
    float spent = TotalExpenses(trip);
    float allowed = totalAllowableExpenses(trip);

    if(spent < allowed){
        return allowed - spent;
    }
    return 0;
}

void printTrip(Trip *trip){
    printf("\nDays spent: %i \n", getDaysSpent(trip));
    printf("Round trip airfare: $%.2f\n", getRoundTripAirfare(trip));
    printf("Depart time: %i \n", getDepartTime(trip));
    printf("Arrival time: %i\n", getArrivalTime(trip));
    printf("Car rentals: $%.2f \n", getCarRentals(trip));
    printf("Miles driven: %.2f mi \n", getMilesDriven(trip));
    printf("Parking cost: $%.2f \n", getParkingCost(trip));
    printf("Taxi cost: $%.2f \n", getTaxiCost(trip));
    printf("Registration fees: $%.2f \n", getRegistrationFees(trip));
    printf("Hotel expenses: $%.2f\n", getHotelExpenses(trip));
    printf("Total allowable expenses: $%.2f \n", totalAllowableExpenses(trip));
    printf("Total expenses: $%.2f \n", TotalExpenses(trip));
    printf("Reimbursable expenses: $%.2f \n", ReimbursableExpenses(trip));
    printf("Amount saved: $%.2f \n", AmountSaved(trip));
}

int timeToInt(char *str){
    int hours;
    int minutes;
    char *p = strpbrk(str, " ") + 1;
    char *end;
    hours = strtol(str, &end, 10) * 100;
    minutes = strtol(end+1, NULL, 10);
    if (*p == 'P'){
        hours += 1200;
    }

    return hours + minutes;
}