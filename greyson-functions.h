#ifndef GREYSON-FUNCTIONS_H
#define GREYSON-FUNCTIONS_H

extern const MAXTRIPLENGTH = 30;

typedef struct Day {
    float taxiCost;
    float milesDriven;
    float parkingCost;
    float mealExpenses;
} Day;

typedef struct Trip {     //Allows use of Trip alone instead of struct Trip
    Trip day[MAXTRIPLENGTH]; //Perhaps change to dynamically set size of array.
    float rentalCost;
    float airfareCost;
    int departTime;
    int arrivalTime;
    float hotelCost;        //Does this belong in day or trip?
    float eventCost;        //Does this belong in day or trip?
} Trip;

void helloworld();
#endif
