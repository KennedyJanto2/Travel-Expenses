#include greyson-functions.h

void setDaysSpent(struct Trip *trip, int days){
    trip->day.size() + 1;
}

void setCarRentals(struct Trip *trip, int price){
    trip->rentalCost = price;
}

void setParkingFees(struct Day *day, int parkingFee){
    day->parkingCost = parkingFee;
}

void setRegistrationFees(struct Trip *trip, int registrationFee){
    trip->eventCost = registrationFee;
}

void setMealExpenses(struct Day *day, int mealCost){
    day->mealExpenses = mealCost;
}

int getDaysSpent(){
    return trip->day;
}

float getCarRentals(){
    return trip->rentalCost;
}

float getParkingFees(){
    return day->parkingCost;
}

float getRegistrationFees(){
    return day->evenCost;
}

float getMealExpenses(){
    return day-> mealExpenses;
}

