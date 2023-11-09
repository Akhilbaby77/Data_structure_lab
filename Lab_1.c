#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

struct vehicleRental {
    char vehicle_name[25];
    int availability[ROWS][COLS];
};

struct vehicleRental vehicles;

void insertDisplay();
int deleteAvailability(int row, int col);
void displayAvailability();
int searchAvailability(int value);
void addMatrix();
void multiplyMatrix();

int main() {
    int choice, value, row, col;
    int count = ROWS * COLS;
    int continueMenu = 1;

    while (continueMenu) {
        printf(" Vehicle Rental Management \n");
        printf("Enter your Choice:\n");
        printf("1: Add Vehicle Availability\n");
        printf("2: Remove Availability\n");
        printf("3: Display Availability\n");
        printf("4: Search Availability\n");
        printf("5: Add Matrices\n");
        printf("6: Multiply Matrices\n");
        printf("0: Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Vehicle Name: ");
                scanf("%s", &vehicles.vehicle_name);
                printf("Enter the availability count for the last %d days:\n", count);
                insertDisplay();
                break;
            case 2:
                printf("Enter the Row and Column of the availability: ");
                scanf("%d %d", &row, &col);
                deleteAvailability(row - 1, col - 1);
                break;
            case 3:
                displayAvailability();
                break;
            case 4:
                printf("Enter the availability value to be searched: ");
                scanf("%d", &value);
                searchAvailability(value);
                break;
            case 5:
                printf(" Availability Matrix Addition \n");
                addMatrix();
                break;
            case 6:
                printf(" Availability Matrix Multiplication \n");
                multiplyMatrix();
                break;
            case 0:
                continueMenu = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addMatrix() {
    int i, j;
    int sum[3][3];

    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            sum[i][j] = vehicles.availability[i][j] + vehicles.availability[i][j];
        }
    }

    printf("Matrix Addition Result:\n");
    for (i = 0; i < ROWS; i++) {
        printf(" ");
        for (j = 0; j < COLS; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix() {
    int i, j;
    int product[3][3];

    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            product[i][j] = vehicles.availability[i][j] * vehicles.availability[i][j];
        }
    }

    printf("Matrix Multiplication Result:\n");
    for (i = 0; i < ROWS; i++) {
        printf(" ");
        for (j = 0; j < COLS; j++) {
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }
}

void displayAvailability() {
	int i,j;
    printf(" Vehicle Availability Matrix \n");
    for ( i = 0; i < ROWS; i++) {
        printf(" ");
        for ( j = 0; j < COLS; j++) {
            printf("%d\t", vehicles.availability[i][j]);
        }
        printf("\n");
    }
}

void insertDisplay() {
	int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            scanf("%d", &vehicles.availability[i][j]);
        }
    }

    printf(" Availability of %s \n", vehicles.vehicle_name);
    
    for ( i = 0; i < ROWS; i++) {
        printf(" ");
        for ( j = 0; j < COLS; j++) {
            printf("%d\t", vehicles.availability[i][j]);
        }
        printf("\n");
    }
}

int deleteAvailability(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        vehicles.availability[row][col] = -1;
        printf("Availability deleted\n");
        return 1;
    }

    printf("Availability not found\n");
    return 0;
}

int searchAvailability(int value) {
    printf(" Searching for Availability \n");
int i,j;
    for (
	 i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            if (vehicles.availability[i][j] == value) {
                printf("Availability value %d is found\n", value);
                return 1;
            }
        }
    }

    printf("Availability value is not found\n");
    return 0;
}

