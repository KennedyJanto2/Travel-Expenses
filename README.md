Travel Expenses Calculator

                                                             

CODE IMPLEMENTATION

gcc travel_expense.c travelexpenses.h greyson-functions.c kennedy-functions.c -o expense

./expense



PROGRAM DETAIL

This program is designed and written by a team of students.

It calculates and displays the total travel expenses of a businessperson on a 
trip. The program should have functions that ask for and return the following: 


• The total number of days spent on the trip 

• The time of departure on the first day of the trip, and the time of arrival back home on the last 
day of the trip 

• The amount of any round-trip airfare 

• The amount of any car rentals 

• Miles driven, if a private vehicle was used. Calculate the vehicle expense as $0.27 per mile 
driven 

• Parking fees (The company allows up to $6 per day. Anything more than this must be paid by 
the employee.) 

• Taxi fees, if a taxi was used anytime during the trip (The company allows up to $10 per day, 
for each day a taxi was used. Anything more than this must be paid by the employee.) 

• Conference or seminar registration fees 

• Hotel expenses (The company allows up to $90 per night for lodging. Anything more than this 
must be paid by the employee.) 

• The amount of each meal eaten. 


On the first day of the trip, breakfast is allowed as an expense if the time of departure is before 7 
a.m. 

Lunch is allowed if the time of departure is before 12 noon. 

Dinner is allowed on the first day if the time of departure is before 6 p.m. 

On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m. 

Lunch is allowed if the time of arrival is after 1 p.m. 

Dinner is allowed on the last day if the time of arrival is after 7 p.m. 


The program should only ask for the amounts of allowable meals. (The company allows up to $9 
for breakfast, $12 for lunch, and $16 for dinner. Anything more than this must be paid by the 
employee.) 

The program should calculate and display: 

the total expenses incurred by the businessperson, 
the total allowable expenses for the trip, 
the excess that must be reimbursed by the businessperson, if any.
The amount saved by the businessperson if the expenses were under the total allowed. 


Input Validation: 

Do not accept negative numbers for any dollar amount or for miles driven in a private vehicle. 

Do not accept numbers less than 1 for the number of days. 

Only accept valid times for the time of departure and the time of arrival.



