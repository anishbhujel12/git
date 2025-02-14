#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int account_number;
    char name[100];
    float balance;
};

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

FILE *fp1;
FILE *fp2;

int main() {
    int choice;
    do {
        printf("\nBanking System\n");
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To clear newline from input buffer

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("Thank you!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}

// Function to create a new account
void create_account() {
    struct account acc;
    printf("Enter account number: ");
    scanf("%d", &acc.account_number);
    getchar(); // Consume newline character

    printf("Enter name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter balance: ");
    scanf("%f", &acc.balance);

    fp1 = fopen("account.txt", "a");
    if (fp1 != NULL) {
        fprintf(fp1, "%d %s %f\n", acc.account_number, acc.name, acc.balance);
        fclose(fp1);
        printf("Account created successfully!\n");
    } else {
        printf("Error opening file\n");
    }
}

// Function to deposit money
void deposit_money() {
    struct account acc;
    int account_number, found = 0;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount: ");
    scanf("%f", &amount);

    fp1 = fopen("account.txt", "r");
    fp2 = fopen("temp.txt", "w");

    if (fp1 != NULL && fp2 != NULL) {
        while (fscanf(fp1, "%d %s %f\n", &acc.account_number, acc.name, &acc.balance) != EOF) {
            if (acc.account_number == account_number) {
                acc.balance += amount;
                found = 1;
                printf("Deposit successful! New balance: %.2f\n", acc.balance);
            }
            fprintf(fp2, "%d %s %.2f\n", acc.account_number, acc.name, acc.balance);
        }
        fclose(fp1);
        fclose(fp2);
        remove("account.txt");
        rename("temp.txt", "account.txt");

        if (!found) {
            printf("Account not found\n");
        }
    } else {
        printf("Error opening file\n");
    }
}

// Function to withdraw money
void withdraw_money() {
    struct account acc;
    int account_number, found = 0;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    fp1 = fopen("account.txt", "r");
    fp2 = fopen("temp.txt", "w");

    if (fp1 != NULL && fp2 != NULL) {
        while (fscanf(fp1, "%d %s %f\n", &acc.account_number, acc.name, &acc.balance) != EOF) {
            if (acc.account_number == account_number) {
                if (acc.balance >= amount) {
                    acc.balance -= amount;
                    printf("Withdrawal successful! New balance: %.2f\n", acc.balance);
                    found = 1;
                } else {
                    printf("Insufficient balance\n");
                }
            }
            fprintf(fp2, "%d %s %.2f\n", acc.account_number, acc.name, acc.balance);
        }
        fclose(fp1);
        fclose(fp2);
        remove("account.txt");
        rename("temp.txt", "account.txt");

        if (!found) {
            printf("Account not found\n");
        }
    } else {
        printf("Error opening file\n");
    }
}

// Function to check balance
void check_balance() {
    struct account acc;
    int account_number, found = 0;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    fp1 = fopen("account.txt", "r");
    if (fp1 != NULL) {
        while (fscanf(fp1, "%d %s %f\n", &acc.account_number, acc.name, &acc.balance) != EOF) {
            if (acc.account_number == account_number) {
                printf("Account Holder: %s\n", acc.name);
                printf("Current Balance: %.2f\n", acc.balance);
                found = 1;
                break;
            }
        }
        fclose(fp1);

        if (!found) {
            printf("Account not found\n");
        }
    } else {
        printf("Error opening file\n");
    }
}