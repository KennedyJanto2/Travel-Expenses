#include <stdio.h>
#include <stdlib.h>
#include "greyson-functions.h"


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

    return 0;
}