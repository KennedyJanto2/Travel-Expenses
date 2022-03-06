#include "travelexpenses.h"

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

float totalAllowableExpenses(Trip *trip){
    float total = 0;

    //first day, breakfast allowed before 7am
    if(getDepartTime(trip) < 7){
        total += 9;
    }
    //first day, breakfast allowed before 12 noon
    else if(getDepartTime(trip) < 12){
        total += 12;
    }
    //first day, dinner allowed before 6pm
    else if(getDepartTime(trip) < 18){
        total += 16;
    }

    //last day, breakfast allowed after 8am
    if(getArrivalTime(trip) > 8){
        total += 9;
    }
    //last day, lunch allowed after 1pm
    else if(getArrivalTime(trip) > 13){
        total += 12;
    }
    //last day, dinner allowed after 7pm
    else if(getArrivalTime(trip) > 19){
        total += 16;
    }

    int days = trip->daysSpend - 2;
    //every other day
    for(int i = 0; i < days; i++){
        total += 6;         //parking fees
        total += 10;        //taxi fee
        total += 90;        //hotel fee

        //allowable meal cost
        total += 9;         //breakfast
        total += 12;        //lunch
        total += 16;        //dinner
    }

    return total;
}

float TotalExpenses(Trip *trip){
    float total = 0;
    total += getParkingCost(&trip);
    total += getTaxiCost(&trip);
    total += getCarRentals(&trip);
    total += getHotelExpenses(&trip);
    total += getRegistrationFees(&trip);
    total += getMealExpenses(&trip);
    total += getRoundTripAirfare(&trip);

    return total;
}

