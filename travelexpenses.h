#ifndef TRAVELEXPENSES_H
#define TRAVELEXPENSES_H

#define MAXTRIPLENGTH 30
/*
typedef struct Day {
    float meals[3]; //Breakfast = [0], Lunch = [1], Dinner = [2]
} Day;
*/
typedef struct Trip {     //Allows use of Trip alone instead of struct Trip
    //Day day[MAXTRIPLENGTH]; //Perhaps change to dynamically set size of array.
    float mealCost;
    float parkingCost;
    float milesDriven;
    float rentalCost;
    float taxiCost;
    float airfareCost;
    int departTime;
    int arrivalTime;
    float hotelCost;        //Does this belong in day or trip?
    float eventCost;        //Does this belong in day or trip?
    int daysSpent;
    float allowableMeals;
} Trip;

float getCarRentals(Trip *trip);

void setCarRentals(Trip *trip, float cost);

int getDaysSpent(Trip *trip);

void setDaysSpent(Trip *trip, int days);

float getMilesDriven(Trip *trip);

void setMilesDriven(Trip *trip, float miles);

float getParkingCost(Trip *trip);

void setParkingCost(Trip *trip, float cost);

float getTaxiCost(Trip *trip);

void setTaxiCost(Trip *trip, float cost);

float ReimbursableExpenses(Trip *trip);

float AmountSaved(Trip *trip);

void setRegistrationFees(Trip *trip, int registrationFee);

float getRegistrationFees(Trip *trip);

void setArrivalTime(Trip *trip, int time);

int getArrivalTime(Trip *trip);

void setDepartTime(Trip *trip, int time);

int getDepartTime(Trip *trip);

void setHotelExpenses(Trip *trip, float hotelExpenses);

float getHotelExpenses(Trip *trip);

void setRoundTripAirfare(Trip *trip, float airCost);

float getRoundTripAirfare(Trip *trip);

float totalAllowableExpenses(Trip *trip);

float TotalExpenses(Trip *trip);

void setMealExpenses(Trip *trip, float totalMealExpense);

void setAllowableMealAmount(Trip *trip, float allowableMeals);

float getAllowableMealAmount(Trip *trip);

float getMealExpenses(Trip *trip);

float getMealTotal(Trip *trip);

void printTrip(Trip *trip);

#endif
