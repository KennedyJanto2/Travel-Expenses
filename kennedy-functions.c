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

float totalAllowableExpenses(struct Trip *trip){
    float total = 0;

    //first day, breakfast allowed before 7am
    if(getDepartTime(trip) < 7){
        total += 9;
    }
    //first day, breakfast allowed before 12 noon
    if(getDepartTime(trip) < 12){
        total += 12;
    }
    //first day, dinner allowed before 6pm
    if(getDepartTime(trip) < 18){
        total += 16;
    }

    //last day, breakfast allowed after 8am
    if(getArrivalTime(trip) > 8){
        total += 9;
    }
    //last day, lunch allowed after 1pm
    if(getArrivalTime(trip) > 13){
        total += 12;
    }
    //last day, dinner allowed after 7pm
    if(getArrivalTime(trip) > 19){
        total += 16;
    }

    //every other day
    for(int i = 0; i < daysSpent - 2; i++){
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


