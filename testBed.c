#include <stdio.h>
#include <stdlib.h>
#include "travelexpenses.h"


int main(){
    Trip trip1;

    //Test car rentals
    setCarRentals(&trip1, 100);
    printf("Car rental cost total: %f\n", getCarRentals(&trip1));

    //Test days spent
    setDaysSpent(&trip1, 3);
    int daysspent = getDaysSpent(&trip1);
    printf("Days spent: %i\n", daysspent);

    //Test miles driven
    setMilesDriven(&trip1.day[0], 10);
    setMilesDriven(&trip1.day[1], 3);
    setMilesDriven(&trip1.day[2], 5);
    float totalMiles = getMilesDriven(&trip1);
    printf("Total miles driven: %f\n", totalMiles);

    //Test parking cost
    setParkingCost(&trip1.day[0], 10);
    setParkingCost(&trip1.day[2], 13);
    setParkingCost(&trip1.day[1], 15);
    printf("Parking cost total: %f \n", getParkingCost(&trip1));

    //Test taxi cost
    setTaxiCost(&trip1.day[0], 5.4);
    setTaxiCost(&trip1.day[1], 3.0);
    printf("Taxi cost total: %f \n", getTaxiCost(&trip1));

    //Test meal cost
    setMealExpenses(&trip1.day[0], 10, 12, 13);
    setMealExpenses(&trip1.day[1], 1, 2, 4);


    //Printing each meal for each day
    for(int day=0; day<trip1.daysSpent; day++){
        float *meals = getMealExpenses(&trip1.day[day]);
        printf("Day %i Meals: \n B:%.2f \n L:%.2f \n D:%.2f\n", day +1, meals[0], meals[1], meals[2]);
    }
    //Get total meal cost for trip
    printf("Total meal cost: %f\n", getMealTotal(&trip1));

    return 0;
}