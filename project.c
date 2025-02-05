#include <stdio.h>
#include <stdlib.h>

float balance = 1000.0; // Initial balance

// Function prototypes
void menu();
void checkBalance();
void depositMoney();
void withdrawMoney();

// Function to display the menu
void menu() {
    printf("\n\nWelcome to the ATM\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

// Function to check the balance
void checkBalance() {
    printf("\nYour current balance is $%.2f\n", balance);
}

// Function to deposit money
void depositMoney() {
    float amount;
    printf("\nEnter the amount you want to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
    } else {
        balance += amount;
        printf("$%.2f has been deposited successfully!\n", amount);
        printf("Your new balance is $%.2f\n", balance);
    }
}

// Function to withdraw money
void withdrawMoney() {
    float amount;
    printf("\nEnter the amount you want to withdraw: $ ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
    } else if (amount > balance) {
        printf("Insufficient balance! Your current balance is: $%.2f\n", balance);
    } else {
        balance -= amount;
        printf("You have successfully withdrawn $%.2f\n", amount);
        printf("Your new balance is $%.2f\n", balance);
    }
}

int main() {
    int choice;
    while (1) {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                printf("Thank you for using our banking system. Have a good time!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
