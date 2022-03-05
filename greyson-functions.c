#include "travelexpenses.h"
#include <stdio.h>

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
    return trip->daysSpent; //(trip->day)/(sizeof(trip->day[0]));
}

void setDaysSpent(Trip *trip, int days){ //Not sure how to interpret this or whether to do
    if (days < 0){
        return;
    }
    trip->daysSpent = days;
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
    if (miles < 0){
        return;
    }
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
    if (cost < 0){
        return;
    }
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
    if (cost < 0){
        return;
    }
    day->taxiCost = cost;
}

float ReimbursableExpenses(Trip *trip){
    int spent = TotalExpenses(&trip);
    int allowed = TotalAllowableExpenses(&trip);
    if (spent > allowed){
        return spent - allowed;
    }
    return 0;
}

float AmountSaved(Trip *trip){
    int spent = TotalExpenses(&trip);
    int allowed = TotalAllowableExpenses(&trip);

    if (spent < allowed){
        return allowed - spent;
    }
    return 0;
}