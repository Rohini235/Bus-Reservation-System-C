/* C Program to generate an online bus reservation program */
#include <stdio.h>
#include <string.h>

void cust_Details();
void Vacant_seats();
void Generate_ticket();
void printline();
void SingleTicket();

int n, A = 0, B = 0, C = 0;
int a = 50, b = 50, c = 50, TotalCharges = 0, m = 0;
char name[50], Date[10];

struct customer_Details {
    char cust_name[50];
    char source[50];
    char destination[50];
    int charge;
    char gender[10];
    char date[10];
};

struct customer_Details cus[100];

int main() {
    int s = 0;
    char ch;

    printline();
    printf("\n\t\t\t********** Welcome to Online Bus Reservation **********\n\n");
    printline();

    cust_Details();

    if (n != 1 && m != 1) {
        printf("1. Do you want a single ticket\n\tOr\n2. Separate ticket for each person: ");
        scanf("%d", &s);
    }

    printf("Do You Want to check the vacant Seats? (Y/N): ");
    scanf(" %c", &ch);

    switch (ch) {
        case 'y':
        case 'Y':
            Vacant_seats();
            if (s == 1 || m == 1)
                Generate_ticket();
            else
                SingleTicket();
            break;
        case 'n':
        case 'N':
            if (s == 1 || m == 1)
                Generate_ticket();
            else
                SingleTicket();
            break;
        default:
            printf("Invalid Entry\n");
    }

    return 0;
}

void cust_Details() {
    int i, choice;
    printf("\nEnter the name of the person booking the ticket: ");
    scanf("%s", name);

    printf("Enter the number of tickets to be booked: ");
    scanf("%d", &n);

    if (n != 1) {
        printf("Is the source, destination and date of travel same for everyone? (1. Same / 2. Different): ");
        scanf("%d", &m);
    }

    if (m == 2) {
        for (i = 0; i < n; i++) {
            printf("Enter the name of traveller %d: ", i + 1);
            scanf("%s", cus[i].cust_name);

            printf("Choose the source and destination of traveller %d (Type 1/2/3):\n", i + 1);
            printf("1. City A to City B (Bus No. 101)\n2. City C to City D (Bus No. 102)\n3. City E to City F (Bus No. 103)\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    strcpy(cus[i].source, "City A");
                    strcpy(cus[i].destination, "City B");
                    A++;
                    cus[i].charge = 100;
                    break;
                case 2:
                    strcpy(cus[i].source, "City C");
                    strcpy(cus[i].destination, "City D");
                    B++;
                    cus[i].charge = 500;
                    break;
                case 3:
                    strcpy(cus[i].source, "City E");
                    strcpy(cus[i].destination, "City F");
                    C++;
                    cus[i].charge = 200;
                    break;
                default:
                    printf("Invalid entry. Please re-enter.\n");
                    i--; // repeat this iteration
                    continue;
            }

            printf("Enter the gender of traveller %d: ", i + 1);
            scanf("%s", cus[i].gender);

            printf("Enter the date of travel (dd-mm-yyyy) for traveller %d: ", i + 1);
            scanf("%s", cus[i].date);

            TotalCharges += cus[i].charge;
        }
    } else {
        printf("Choose the source and destination (Type 1/2/3):\n");
        printf("1. City A to City B (Bus no. 101)\n2. City C to City D (Bus no. 102)\n3. City E to City F (Bus no. 103)\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(cus[0].source, "City A");
                strcpy(cus[0].destination, "City B");
                TotalCharges = 100 * n;
                A = n;
                break;
            case 2:
                strcpy(cus[0].source, "City C");
                strcpy(cus[0].destination, "City D");
                TotalCharges = 500 * n;
                B = n;
                break;
            case 3:
                strcpy(cus[0].source, "City E");
                strcpy(cus[0].destination, "City F");
                TotalCharges = 200 * n;
                C = n;
                break;
            default:
                printf("Invalid entry. Please re-enter.\n");
                return cust_Details();
        }

        printf("Enter the date of travel (dd-mm-yyyy): ");
        scanf("%s", Date);
    }
}

void Vacant_seats() {
    int choice;
    printf("Enter the bus number (101/102/103): ");
    scanf("%d", &choice);

    switch (choice) {
        case 101:
            printf("Booked Seats: %d\nVacant Seats: %d\n", A, a - A);
            break;
        case 102:
            printf("Booked Seats: %d\nVacant Seats: %d\n", B, b - B);
            break;
        case 103:
            printf("Booked Seats: %d\nVacant Seats: %d\n", C, c - C);
            break;
        default:
            printf("Invalid entry. Please re-enter.\n");
    }
}

void Generate_ticket() {
    printline();
    printf("\t\t\t\t\tMARUTI TRAVELS\n");
    printline();
    printf("Name: %s\n", name);
    printline();
    if (A != 0) printf("No of tickets from City A to City B: %d\n", A);
    if (B != 0) printf("No of tickets from City C to City D: %d\n", B);
    if (C != 0) printf("No of tickets from City E to City F: %d\n", C);
    printline();
    if (m == 1) {
        printf("Date of Travel: %s\n", Date);
        printline();
    }
    printf("Total charges: %d\n", TotalCharges);
    printline();
    printf("\t\t\t\t\tHAPPY JOURNEY\n");
    printline();
}

void printline() {
    printf("------------------------------------------------------------------------------------\n");
}

void SingleTicket() {
    for (int i = 0; i < n; i++) {
        printline();
        printf("\t\t\t\t\tMARUTI TRAVELS\n");
        printline();
        printf("Name: %s\n", cus[i].cust_name);
        printline();
        printf("Source: %s\n", cus[i].source);
        printf("Destination: %s\n", cus[i].destination);
        printline();
        printf("Gender: %s\n", cus[i].gender);
        printline();
        printf("Date of Travel: %s\n", cus[i].date);
        printline();
        printf("Charge: %d\n", cus[i].charge);
        printline();
        printf("\t\t\t\t\tHAPPY JOURNEY\n");
        printline();
        printf("\n");
    }
}
