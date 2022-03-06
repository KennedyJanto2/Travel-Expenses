#ifndef TRAVELEXPENSES_H
#define TRAVELEXPENSES_H

#define MAXTRIPLENGTH 30

typedef struct Day {
    float taxiCost;
    float milesDriven;
    float parkingCost;
    float meals[3]; //Breakfast = [0], Lunch = [1], Dinner = [2]
} Day;

typedef struct Trip {     //Allows use of Trip alone instead of struct Trip
    Day day[MAXTRIPLENGTH]; //Perhaps change to dynamically set size of array.
    float rentalCost;
    float airfareCost;
    int departTime;
    int arrivalTime;
    float hotelCost;        //Does this belong in day or trip?
    float eventCost;        //Does this belong in day or trip?
    int daysSpent;
} Trip;

float getCarRentals(Trip *trip);

void setCarRentals(Trip *trip, float cost);

int getDaysSpent(Trip *trip);

void setDaysSpent(Trip *trip, int days);

float getMilesDriven(Trip *trip);

void setMilesDriven(Day *day, float miles);

float getParkingCost(Trip *trip);

void setParkingCost(Day *day, float cost);

float getTaxiCost(Trip *trip);

void setTaxiCost(Day *day, float cost);

float ReimbursableExpenses(Trip *trip);

float AmountSaved(Trip *trip);

void setRegistrationFees(Trip *trip, int registrationFee);

float getRegistrationFees(Trip *trip);

void setArrivalTime(Trip *trip, int time);

int getArrivalTime(Trip *trip);

void setDepartTime(Trip *trip, int time);

int getDepartTme(Trip *trip);

void setHotelExpenses(Trip *trip, float hotelExpenses);

float getHotelExpenses(Trip *trip);

void setRoundTripAirfare(Trip *trip, float airCost);

float totalAllowableExpenses(Trip *trip);

float TotalExpenses(Trip *trip);

void setMealExpenses(Day *day, float breakfastCost, float lunchCost, float dinnerCost);

float *getMealExpenses(Day *day);

float getMealTotal(Trip *trip);

#endif
