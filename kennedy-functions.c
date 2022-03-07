#include "travelexpenses.h"
#include <stdio.h>

//Setters:

void setRegistrationFees(Trip *trip, int registrationFee){
    trip->eventCost = registrationFee;
}

void setArrivalTime(Trip *trip, int time){
    trip->arrivalTime = time;
}

void setDepartTime(Trip *trip, int time){
    trip->departTime = time;
}

void setHotelExpenses(Trip *trip, float hotelExpenses){
    trip->hotelCost = hotelExpenses;
}

void setRoundTripAirfare(Trip *trip, float airCost){
    trip->airfareCost = airCost;
}

//Getters:

float getRegistrationFees(Trip *trip){
    return trip->eventCost;
}

int getArrivalTime(Trip *trip){
    return trip->arrivalTime;
}

int getDepartTime(Trip *trip){
    return trip->departTime;
}

float getHotelExpenses(Trip *trip){
    return trip->hotelCost;
}

float getRoundTripAirfare(Trip *trip){
    return trip->airfareCost;
}

void setAllowableMealAmount(Trip *trip, float allowableMealsCount){
    trip->allowableMeals = allowableMealsCount;
}

float getAllowableMealAmount(Trip *trip){
    return trip->allowableMeals;
}

float totalAllowableExpenses(Trip *trip){
    float total = 0;
    float count = getAllowableMealAmount(trip);
    int days = trip->daysSpent;

    //first day, breakfast allowed before 7am
    if(getDepartTime(trip) < 7 && count > 0){
        total += 9;
        count--;
    }
    //first day, breakfast allowed before 12 noon
    if(getDepartTime(trip) < 12 && count > 0){
        total += 12;
        count--;
    }
    //first day, dinner allowed before 6pm
    if(getDepartTime(trip) < 18 && count > 0){
        total += 16;
        count--;
    }

    //last day, breakfast allowed after 8am
    if(getArrivalTime(trip) > 8 && count > 0){
        total += 9;
        count--;
    }
    //last day, lunch allowed after 1pm
    if(getArrivalTime(trip) > 13 && count > 0){
        total += 12;
        count--;
    }
    //last day, dinner allowed after 7pm
    if(getArrivalTime(trip) > 19 && count > 0){
        total += 16;
        count--;
    }

    //allowable meal cost
    while(count > 0){
        total += 9;         //breakfast
        count--;
        if(count <= 0)
            break;
        total += 12;        //lunch
        count--;
        if(count <= 0)
            break;
        total += 16;        //dinner
        count--;
        if(count <= 0)
            break;
    }

    //first and last day other fees
    if(days <= 1){
        total += 6;         //parking fees
        total += 10;        //taxi fee
        total += 90;        //hotel fee
    }
    else{
        total += 12;         //parking fees * 2
        total += 20;        //taxi fee * 2
        total += 180;        //hotel fee * 2
    }
    
    days = days - 2;
    //every other day
    for(int i = 0; i < days; i++){
        total += 6;         //parking fees
        total += 10;        //taxi fee
        total += 90;        //hotel fee
    }

    return total;
}

float TotalExpenses(Trip *trip){
    float total = 0;
 
    total += getParkingCost(trip);
    total += getTaxiCost(trip);
    total += getCarRentals(trip);
    total += getHotelExpenses(trip);
    total += getRegistrationFees(trip);
    total += getMealTotal(trip);
    total += getRoundTripAirfare(trip);
    total += getMilesDriven(trip) * 0.27;

    return total;
}

