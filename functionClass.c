#include greyson-functions.h

//Setters:

void setRegistrationFees(struct Trip *trip, int registrationFee){
    trip->eventCost = registrationFee;
}

void setArrivalTime(struct Trip *trip, int time){
    trip->arrivalTime = time;
}

void setDepartTime(struct Trip *trip, int time){
    trip->departTime = time;
}

void setTaxiFees(struct Day *day, float taxiFee){
    day->taxiCost = taxiFee;
}

void setHotelExpenses(struct Day *day, float hotelExpenses){
    day->hotelCost = hotelExpenses;
}

void setRoundTripAirfare(struct Trip *trip, float airCost){
    trip->airfareCost = airCost;
}

//Getters:

float getRegistrationFees(struct Trip *trip){
    return trip->eventCost;
}

int getArrivalTime(struct Trip *trip){
    return trip->arrivalTime;
}

int getDepartTime(struct Trip *trip){
    return trip->departTime;
}

float getTaxiFees(struct Trip *trip){
    float taxiFee = 0;
    int daysSpent = getDaysSpent(trip);
    for(int day = 0; day < daysSpent; day++){
        taxiFee += trip->day[day].taxiCost;
    }
    return taxiFee;
}

float getHotelFees(struct Trip *trip){
    float hotelFee = 0;
    int daysSpent = getDaysSpent(trip);
    for(int day = 0; day < daysSpent; day++){
        hotelFee += trip->day[day].hotelCost;
    }
    return hotelFee;
}

float getRoundTripAirfare(struct Trip *trip){
    return trip->airfareCost;
}


