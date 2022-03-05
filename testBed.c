#include <stdio.h>
#include <stdlib.h>
#include "greyson-functions.h"


int main(){
    Trip trip1;
    trip1.day[0].milesDriven = 5;
    trip1.day[1].milesDriven = 7;
    trip1.day[2].milesDriven = 9;
    float totalMiles = getMilesDriven(&trip1);
    setMilesDriven(&trip1, 10);
    printf("Total miles driven: %f", totalMiles);
    return 0;
}