#include "greyson-functions.h"
#include <stdio.h>

typedef enum { false, true } bool;


float getCarRentals(Trip *trip){
    return trip->rentalCost;
}

void setCarRentals(Trip *trip, float cost){
    trip->rentalCost = cost;
}

int getDaysSpent(Trip *trip){ //Awaiting testing, seems like a hacky way to implement
    return sizeof(trip->day)/(sizeof(trip->day[0]));
}

void setDaysSpent(Trip *trip){ //Not sure how to interpret this or whether to do
    
}

float getMilesDriven(Trip *trip){
    float miles = 0;
    int daysSpent = getDaysSpent(trip);
    for (int day=0; day < daysSpent; day++){
        miles += trip->day[day].milesDriven;
    }
    return miles;
}

void setMilesDriven(Day *day, float miles){
    day->milesDriven = miles;
}

float getParkingCost(Trip *trip){
    float cost = 0;
    int daysSpent = getDaysSpent(trip);
    for (int day=0; day < daysSpent; day++){
        cost += trip->day[day].parkingCost;
    }
    return cost;
}

void setParkingCost(Day *day, float cost){
    day->parkingCost = cost;
}

float getTaxiCost(Trip *trip){
    float cost = 0;
    int daysSpent = getDaysSpent(trip);
    for (int day=0; day < daysSpent; day++){
        cost += trip->day[day].taxiCost;
    }
    return cost;
}

void setTaxiCost(Day *day, float cost){
    day->taxiCost = cost;
}
