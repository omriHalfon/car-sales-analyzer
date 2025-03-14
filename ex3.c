/******************
Name:
ID:
Assignment: ex3
*******************/

#include <stdio.h>

#define NUM_OF_BRANDS 5
#define BRANDS_NAMES 15
#define NUM_OF_TYPES 4
#define TYPES_NAMES 10
#define DAYS_IN_YEAR 365
#define addOne  1
#define addAll  2
#define stats  3
#define print  4
#define insights  5
#define deltas  6
#define done  7
// Array storing the names of the brands
char brands[NUM_OF_BRANDS][BRANDS_NAMES] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"};
// Array storing the names of the car types
char types[NUM_OF_TYPES][TYPES_NAMES] = {"SUV", "Sedan", "Coupe", "GT"};
// Function to print the car type based on the given index
void PrintCarType(int index) {
    for (int j = 0; j < TYPES_NAMES; j++) {
        if (types[index][j] == '\0') {
            break; // Stop printing once we reach the end of the Array
        }
        if(types[index][j] >= 32 && types[index][j] <= 126) {
            printf("%c", types[index][j]); // Print each character of the car type
        }
    }
}
// Function to print the brand name based on the given index
void PrintBrand(int index) {
    for (int j = 0; j < BRANDS_NAMES; j++) {
        if (brands[index][j] == '\0') {
            break; // Stop printing once we reach the end of the array
        }
        if(brands[index][j] >= 32 && brands[index][j] <= 126) {
            printf("%c", brands[index][j]);// Print each character of the brand name
        }
    }
}
// Function to check if there is any value equal to 0 in the given array
int checkCounter(int counter[NUM_OF_BRANDS]) {
    // Loop through all elements in the array
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        // If any element is 0, return 1 (indicating there is at least one zero)
        if (counter[i] == 0) {
            return 1;
        }
    }
    // If no elements are 0, return 0 (indicating all elements are non-zero)
    return 0;
}
// Function to calculate and print the total sales for a given day
void getDaySaleData(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int day) {
    int daySale = 0; // Holds the total sales for the day
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        for (int j = 0; j < NUM_OF_TYPES; j++) {
            daySale += cube[day][i][j]; // Accumulate sales data
        }
    }
    printf("The sales total was %d\n", daySale); // Print total sales for the day
}
// Function to print the best-selling brand across a given day
void printBestSaleBrand(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    int sumBrand = 0; // Holds the total sales for each brand
    int maxBrand = 0; // Holds the maximum sales found
    int brandIndex[NUM_OF_BRANDS] = {0}; // Tracks brands with maximum sales

    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        for (int j = 0; j < NUM_OF_TYPES; j++) {
            sumBrand += cube[dayCounter][i][j]; // Calculate total sales for the brand
        }
        if (sumBrand > maxBrand) {
            maxBrand = sumBrand; // Update maximum sales
            brandIndex[i] = maxBrand; // Mark this brand
        }
        sumBrand = 0; // Reset sales sum for the next brand
    }

    // Print the best-selling brand(s)
    printf("The best sold brand with %d sales was ", maxBrand);
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        if (brandIndex[i] == maxBrand) {
            PrintBrand(i); // Print the brand name
            printf(" ");
        }
    }
}
// Function to print the best-selling car types for a given day
void printBestSaleTypes(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    int sumTypes = 0; // Holds total sales for each type
    int maxTypes = 0; // Holds the maximum sales found
    int typesIndex[NUM_OF_TYPES] = {0}; // Tracks types with maximum sales

    for (int i = 0; i < NUM_OF_TYPES; i++) {
        for (int j = 0; j < NUM_OF_BRANDS; j++) {
            sumTypes += cube[dayCounter][j][i]; // Calculate total sales for the type
        }
        if (sumTypes > maxTypes) {
            maxTypes = sumTypes; // Update maximum sales
            typesIndex[i] = maxTypes; // Mark this type
        }
        sumTypes = 0; // Reset sales sum for the next type
    }

    // Print the best-selling type(s)
    printf("\nThe best sold type with %d sales was ", maxTypes);
    for (int i = 0; i < NUM_OF_TYPES; i++) {
        if (typesIndex[i] == maxTypes) {
            PrintCarType(i); // Print the type name
            printf(" ");
        }
    }
}
//Function to print the best sold brand overall
void printBestBrandOverall(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    int sumBrandOverall = 0; // Total sales for each brand over all days
    int maxBrandOverall = 0; // Maximum sales found
    int brandIndex[NUM_OF_BRANDS] = {0}; // Tracks brands with maximum sales

    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        for (int j = 0; j < dayCounter; j++) {
            for (int k = 0; k < NUM_OF_TYPES; k++) {
                sumBrandOverall += cube[j][i][k]; // Calculate total sales for the brand
            }
        }

        // Update the best-selling brand if needed
        if (sumBrandOverall > maxBrandOverall) {
            maxBrandOverall = sumBrandOverall;
            brandIndex[i] = maxBrandOverall;
        }
        sumBrandOverall = 0; // Reset sales sum for the next brand
    }

    // Print the best-selling brand overall
    printf("The best-selling brand overall is");
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        if (brandIndex[i] == maxBrandOverall) {
            printf(" ");
            PrintBrand(i); // Print the brand name
        }
    }
    printf(": %d$\n", maxBrandOverall); // Print the total sales of the best brand
}
//Function to print the best sold type overall
void printBestTypeOverall(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    int sumTypeOverall = 0; // Total sales for each type over all days
    int maxTypeOverall = 0; // Maximum sales found
    int typesIndex[NUM_OF_TYPES] = {0}; // Tracks types with maximum sales
    for (int i = 0; i < NUM_OF_TYPES; i++) {
        for (int j = 0; j < dayCounter; j++) {
            for (int k = 0; k < NUM_OF_BRANDS; k++) {
                sumTypeOverall += cube[j][k][i]; // Calculate total sales for the type
            }
        }

        // Update the best-selling type if needed
        if (sumTypeOverall > maxTypeOverall) {
            maxTypeOverall = sumTypeOverall;
            typesIndex[i] = maxTypeOverall;
        }
        sumTypeOverall = 0; // Reset sales sum for the next type
    }

    // Print the best-selling type overall
    printf("The best-selling type of car is");
    for (int i = 0; i < NUM_OF_TYPES; i++) {
        if (typesIndex[i] == maxTypeOverall) {
            printf(" ");
            PrintCarType(i); // Print the type name
        }
    }
    printf(": %d$\n", maxTypeOverall); // Print the total sales of the best type
}
//Function to print the best sale day overall
void printBestDayOverall(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    int sumDayOverall = 0; // Total sales for each day
    int maxDayOverall = 0; // Maximum sales found
    int typesIndex[DAYS_IN_YEAR] = {0}; // Tracks days with maximum sales

    for (int i = 0; i < dayCounter; i++) {
        // Sum sales for each day across all brands and types
        for (int j = 0; j < NUM_OF_BRANDS; j++) {
            for (int k = 0; k < NUM_OF_TYPES; k++) {
                sumDayOverall += cube[i][j][k];
            }
        }

        // Update the most profitable day if needed
        if (sumDayOverall > maxDayOverall) {
            maxDayOverall = sumDayOverall;
            typesIndex[i] = maxDayOverall;
        }
        sumDayOverall = 0; // Reset sales sum for the next day
    }

    // Print the most profitable day(s)
    printf("The most profitable day was day number");   if (dayCounter == 0) { // if the user didn't enter any data
        printf(" %d",1);
    }
    for (int i = 0; i < dayCounter; i++) {
        if (typesIndex[i] == maxDayOverall) {
            printf(" %d", (i + 1)); // Print the day number
        }
    }
    printf(": %d$\n", maxDayOverall); // Print the total sales of the best day
}
//return the sum of sales for specific day and brand
double brandSum(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int day, int brandIndex) {
    double sumBrand=0;
    for (int j = 0; j < NUM_OF_TYPES; j++) {
        sumBrand += cube[day][brandIndex][j];
    }
    return sumBrand;
}
void case_addAll(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int day) {
    int counter[NUM_OF_BRANDS] = {0}; // Array to track which brands have been filled
    int index = 0; // Variable to hold the brand index provided by the user

    // Loop until all brands have data (no zeros in the counter array)
    while (checkCounter(counter)) {
        printf("No data for brands "); // Notify the user of missing data
        for (int i = 0; i < NUM_OF_BRANDS; i++) {
            if (counter[i] == 0) { // Check for brands with no data
                PrintBrand(i); // Print the name or identifier of the brand
                printf(" ");
            }
        }
        printf("\nPlease complete the data\n");

        // Read the brand index from the user
        scanf("%d", &index);

        // Validate the entered brand index
        if (index < 0 || index >= NUM_OF_BRANDS || counter[index] == 1) {
            printf("This brand is not valid\n"); // Error message for invalid input
            continue; // Skip the rest of the loop and prompt again
        }

        // Read data for all types of the selected brand
        for (int i = 0; i < NUM_OF_TYPES; i++) {
            scanf("%d", &cube[day][index][i]);
        }

        counter[index] = 1; // Mark the brand as completed
    }
}
void case_stats(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    // Case 3: Provide daily stats (best-selling brand and type)

    int day; // Variable to store the day to analyze
    printf("What day would you like to analyze?\n");
    scanf("%d", &day); // Read user input for the day to analyze

    // Validate the input day
    while ((day < 1 || day > dayCounter)&&dayCounter!=0) {
        printf("Please enter a valid day.\n"); // Prompt for valid input
        printf("What day would you like to analyze?\n");
        scanf("%d", &day);
    }

    printf("In day number %d:\n", day); // Print the day being analyzed
    if(day>0) {
        day--; // Adjust to zero-based index for array access
    }
    getDaySaleData(cube, day); // Function to calculate and print total sales for the day
    printBestSaleBrand(cube, day); // Function to find and print the best-selling brand
    printBestSaleTypes(cube, day); // Function to find and print the best-selling types
}
void case_print(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    // Case 4: Print all data for each brand over all days
    printf("*****************************************\n");
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        printf("Sales for ");
        PrintBrand(i);
        printf(":\n");
        for (int j = 0; j < dayCounter; j++) {
            printf("Day %d- ", (j + 1));
            for (int k = 0; k < NUM_OF_TYPES; k++) {
                PrintCarType(k);
                printf(": %d ", cube[j][i][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("*****************************************\n");
}
void case_insights(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    // Case 5: Provide overall insights (best-selling brand, type, day)
    printBestBrandOverall(cube, dayCounter); // Print the best-selling brand
    printBestTypeOverall(cube, dayCounter);  // Print the best-selling type
    printBestDayOverall(cube, dayCounter);   // Print the most profitable day
}
void case_deltas(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int dayCounter) {
    double brandSums[DAYS_IN_YEAR][NUM_OF_BRANDS];  // Array to store brand sums for each day
    double changes[NUM_OF_BRANDS];  // Array to store the average change for each brand

    // Calculate the brand sums for each day up to dayCounter
    for (int i = 0; i < dayCounter; i++) {
        for (int j = 0; j < NUM_OF_BRANDS; j++) {
            brandSums[i][j] = brandSum(cube, i, j);  // Calculate the sum for the current brand and day
        }
    }

    // Calculate the average change (delta) for each brand over the days
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        for (int j = 0; j < (dayCounter - 1); j++) {
            changes[i] += brandSums[j + 1][i] - brandSums[j][i];  // Calculate daily change
        }
        if(dayCounter>1) {
            changes[i] /= (dayCounter - 1);  // Average the changes over the days
        }
    }

    // Print the results (average delta for each brand)
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        printf("Brand: ");
        PrintBrand(i);  // Print brand name or identifier
        printf(", Average Delta: %lf\n", changes[i]);  // Print the average change for the brand
    }
}
void printMenu() {
    printf("Welcome to the Cars Data Cube! What would you like to do?\n"
        "1.Enter Daily Data For A Brand\n"    // Option to input data for a specific brand
        "2.Populate A Day Of Sales For All Brands\n"  // Option to enter sales data for all brands
        "3.Provide Daily Stats\n"  // Option to display daily statistics
        "4.Print All Data\n"  // Option to print all collected data
        "5.Provide Overall (simple) Insights\n"  // Option to view overall insights
        "6.Provide Average Delta Metrics\n"  // Option to display average delta metrics
        "7.exit\n");  // Option to exit the program
}
int main() {
    int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES];  // 3D array to store data for each brand, type, and day
    int dayCounter = 0;  // Counter to track the number of days
    int choice;  // Variable to store the user's menu choice
    printMenu();  // Display the menu options
    scanf("%d", &choice);  // Read the user's menu choice

    // Initialize the cube array, setting all values to -1
    for(int i = 0; i < DAYS_IN_YEAR; i++) {
        for(int j = 0; j < NUM_OF_BRANDS; j++) {
            for(int k = 0; k < NUM_OF_TYPES; k++) {
                cube[i][j][k] = -1; // Initialize all values to -1
            }
        }
    }

    // Main loop continues until the user selects 'done'
    while (choice != done) {
        switch (choice) {
            case addOne: {  // Option to add data for a single brand
                int brandIndex;
                printf("Enter brandIndex: ");
                scanf("%d", &brandIndex);  // Read the brand index
                if (brandIndex >= NUM_OF_BRANDS || brandIndex < 0) {
                    continue;  // Skip if the brand index is out of range
                }
                for (int i = 0; i < NUM_OF_TYPES; i++) {
                    scanf("%d", &cube[dayCounter][brandIndex][i]);  // Read the data for the specified brand and type
                }
                dayCounter++;  // Increment the day counter after adding the data
                break;
            }
            case addAll: {  // Option to add data for all brands
                if(dayCounter<DAYS_IN_YEAR) {
                    case_addAll(cube, dayCounter);  // Call function to add data for all brands
                    dayCounter++;  // Increase the day counter after adding data for all brands
                }
                break;
            }
            case stats: {  // Option to show statistics
                case_stats(cube, dayCounter);  // Call function to display statistics
                break;
            }
            case print: {  // Option to print the data
                case_print(cube, dayCounter);  // Call function to print the data
                break;
            }
            case insights: {  // Option to show insights
                case_insights(cube, dayCounter);  // Call function to display insights
                break;
            }
            case deltas: {  // Option to show delta changes
                case_deltas(cube, dayCounter);  // Call function to calculate and display deltas
                break;
            }
            default: {  // Invalid choice handling
                printf("Invalid input\n");  // Print error message for invalid input
                break;
            }
        }
        printf("\n");
        printMenu();  // Display the menu again for the next choice
        scanf("%d", &choice);  // Read the user's next choice
    }
    printf("Goodbye!\n");  // Print goodbye message when done
    return 0;
}



