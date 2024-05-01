
#ifndef INPUTS_H
#define INPUTS_H

//-------------------------------------------------------------------------------------------------

// Number of seconds that the simulation will run for 
#define SECONDS_FOR_PROGRAM_TO_RUN 25.0f

// Maximum number of customers in each line
#define MAX_QUEUE_SIZE 20


//
// ---- Time between customer creations ----
//

// Number of seconds before a new time between customers will be calculated
#define SECONDS_BEFORE_A_NEW_TIME_IS_CALCULATED 1.0f

// This will be the initial percentage chance to create a new customer
#define DEFAULT_TIME_TO_CREATE_CUSTOMER 1.0f

//
// Formula to determine the amount of time to pass before checking to see of a new customer
// shall be created
//
//   ((Random Number % TIME_SPAN_TO_CREATE_CUSTOMER) / 10) + MIN_TIME_TO_CREATE_CUSTOMER
//
// Note: after the time has expired, the simulation has a percentage chance (see blow)
// of creating a new customer
//


// This is the minimum number of seconds between possible customer creations
#define MIN_TIME_TO_CREATE_CUSTOMER 0.04f

// This value will be used to calculate the random time
// This value needs to be a whole number, should be between 11 and 25
#define TIME_SPAN_TO_CREATE_CUSTOMER 11


//
// ---- Time needed to process a customer ----
//

//
// Calculation used to determine how much time is needed to check out:
// 
//   (Random Number % TIME_SPAN_TO_PROCESS_CUSTOMER) + MIN_TIME_TO_PROCESS_CUSTOMER
//

// This is the minimum time needed to process a customer
// This value should be a float value between 0.1f and 1.0f
#define MIN_TIME_TO_PROCESS_CUSTOMER 0.1f

// This value will be used to calculate the random time
// This value needs to be a whole number, should be between 2 and 7
#define TIME_SPAN_TO_PROCESS_CUSTOMER 2


//
// ---- Creating a new percentage of time a customer will be created ----

// Number of seconds before a new customer might be created
#define SECONDS_BEFORE_A_NEW_PERCENTAGE 0.1f

// This will be the initial percentage chance to create a new customer
#define DEFAULT_PERCENTAGE_TO_CREATE_CUSTOMER 10

//
// Calculation to determine when a new customer will be created:
//
//   (Random Number % PERCENTAGE_SPAN_TO_CREATE_CUSTOMER) + MIN_PERCENTAGE_TO_CREATE_CUSTOMER
//

// This is the minimum chance that a customer will be created
#define MIN_PERCENTAGE_TO_CREATE_CUSTOMER 35

// This value will be used to calculate the random percentage
// This value needs to be a whole number
// This value plus the min above should NOT total more than 100
#define PERCENTAGE_SPAN_TO_CREATE_CUSTOMER 1

//-------------------------------------------------------------------------------------------------

#endif