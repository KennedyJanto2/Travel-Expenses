#include "greyson-functions.h"
#include <stdio.h>

typedef enum { false, true } bool;

void helloWorld(){
    printf("Hello world! This is the initial commit for Project 2 - CS2600 Spring '22.");
}

float getCarRentals(Trip *trip){
    return trip->rentalCost;
}

void setCarRentals(Trip *trip, float cost){
    trip->rentalCost = cost;
}

int getDaysSpent(Trip *trip){ //Awaiting testing, seems like a hacky way to implement
    return sizeof(trip->day)/(sizeof(trip->day[0]));
}

void setDaysSpent(Trip *trip){

}

float getMilesDriven(Trip *trip){
    float miles = 0;
    int daysSpent = getDaysSpent(trip);
    for (int day=0; day < daysSpent; day++){
        miles += trip->day[day].milesDriven;
    }
    return miles;
}

void setMilesDriven(Trip *trip, float miles){
    trip->day[0].milesDriven = miles;
}

float getParkingCost(Trip *trip){

}

void setParkingCost(Trip *trip){

}