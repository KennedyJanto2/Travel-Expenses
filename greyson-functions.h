#ifndef GREYSON-FUNCTIONS_H
#define GREYSON-FUNCTIONS_H

#define MAXTRIPLENGTH 30

typedef struct Day {
    float taxiCost;
    float milesDriven;
    float parkingCost;
    float mealExpenses;
} Day;

typedef struct Trip {     //Allows use of Trip alone instead of struct Trip
    Day day[MAXTRIPLENGTH]; //Perhaps change to dynamically set size of array.
    float rentalCost;
    float airfareCost;
    int departTime;
    int arrivalTime;
    float hotelCost;        //Does this belong in day or trip?
    float eventCost;        //Does this belong in day or trip?
} Trip;

void helloworld(Trip *trip);

float getCarRentals(Trip *trip);

void setCarRentals(Trip *trip, float cost);

int getDaysSpent(Trip *trip);

void setDaysSpent(Trip *trip);

float getMilesDriven(Trip *trip);

void setMilesDriven(Trip *trip, float miles);

float getParkingCost(Trip *trip);

void setParkingCost(Trip *trip);
#endif
