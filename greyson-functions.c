#include "travelexpenses.h"
#include <stdio.h>
#include <string.h>

float getCarRentals(Trip *trip){
    return trip->rentalCost;
}

void setCarRentals(Trip *trip, float cost){
    if (cost < 0){
        return;
    }
    trip->rentalCost = cost;
}

int getDaysSpent(Trip *trip){ //Awaiting testing, seems like a hacky way to implement
    return trip->daysSpent; 
}

void setDaysSpent(Trip *trip, int days){ //Not sure how to interpret this or whether to do
    trip->daysSpent = days;
}

float getMilesDriven(Trip *trip){
    /*float miles = 0;
    int daysSpent = getDaysSpent(trip);
    for (int day=0; day < daysSpent; day++){
        miles += trip->day[day].milesDriven;
    }
    return miles;*/
    return trip->milesDriven;
}

void setMilesDriven(Trip *trip, float miles){//Day *day, float miles){
   /* if (miles < 0){
        return;
    }
    day->milesDriven = miles;*/
    trip->milesDriven = miles;
}

float getParkingCost(Trip *trip){
    /*float cost = 0;
    int daysSpent = getDaysSpent(trip);
    for (int day=0; day < daysSpent; day++){
        cost += trip->day[day].parkingCost;
    }
    return cost;*/
    return trip->parkingCost;
}

void setParkingCost(Trip *trip, float cost){//Day *day, float cost){
    /*if (cost < 0){
        return;
    }
    day->parkingCost = cost;*/
    trip->parkingCost = cost;
}

float getTaxiCost(Trip *trip){
    /*float cost = 0;
    int daysSpent = getDaysSpent(trip);
    for (int day=0; day < daysSpent; day++){
        cost += trip->day[day].taxiCost;
    }
    return cost;*/
    return trip->taxiCost;
}

void setTaxiCost(Trip *trip, float cost){ //Day *day, float cost){
   /* if (cost < 0){
        return;
    }
    day->taxiCost = cost;*/
    trip->taxiCost = cost;
}

float ReimbursableExpenses(Trip *trip){
    int spent = TotalExpenses(trip);
    int allowed = totalAllowableExpenses(trip);
    if (spent > allowed){
        return spent - allowed;
    }
    return 0;
}

float AmountSaved(Trip *trip){
    int spent = TotalExpenses(trip);
    int allowed = totalAllowableExpenses(trip);

    if (spent < allowed){
        return allowed - spent;
    }
    return 0;
}

void setMealExpenses(Day *day, float breakfastCost, float lunchCost, float dinnerCost){
    day->meals[0] = breakfastCost;
    day->meals[1] = lunchCost;
    day->meals[2] = dinnerCost;
}

float *getMealExpenses(Day *day){
    return day->meals;
}

float getMealTotal(Trip *trip){
    float total = 0;
    for (int day = 0; day < trip->daysSpent; day++){
        total += trip->day[day].meals[0];
        total += trip->day[day].meals[1];
        total += trip->day[day].meals[2];
    }
    return total;
}

void printTrip(Trip *trip){
    printf("Days spent: %i \n", getDaysSpent(trip));
    printf("Round trip airfare: %.2f\n", getRoundTripAirfare(trip));
    printf("Depart time: %i \n", getDepartTime(trip));
    printf("Arrival time: %i\n", getArrivalTime(trip));
    printf("Car rentals %.2f \n", getCarRentals(trip));
    printf("Miles driven: %.2f \n", getMilesDriven(trip));
    printf("Parking cost: %.2f \n", getParkingCost(trip));
    printf("Taxi cost: %.2f \n", getTaxiCost(trip));
    printf("Registration fees: %.2f \n", getRegistrationFees(trip));
    printf("Hotel expenses: %.2f\n", getHotelExpenses(trip));
    printf("Total allowable expenses: %.2f \n", totalAllowableExpenses(trip));
    printf("Total expenses: %.2f \n", TotalExpenses(trip));
    printf("Reimbursable expenses: %.2f \n", ReimbursableExpenses(trip));
    printf("Amount saved: %.2f \n", AmountSaved(trip));
}