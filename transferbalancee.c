void fund_transfer(int fromnumber) {
    
    /*kushal part transfer balance*/
    int to_accnumber, pin;
    float amount;

    printf("Enter your 4-digit PIN: ");
    scanf("%d", &pin);

    
    int from_index = -1, to_index = -1;
    for (int i = 0; i < countcus; i++) {
        if (customer[i].accnumber == fromnumber) {
            from_index = i;
        }
        if (customer[i].accnumber == to_accnumber) {
            to_index = i;
        }
    }

    if (customer[from_index].pin != pin) {
        printf("Incorrect PIN! Transfer canceled.\n");
        return;
    }

    printf("Enter account number to transfer: ");
    scanf("%d", &to_accnumber);

    printf("Enter transfer amount: ");
    scanf("%f", &amount);

    for (int i = 0; i < countcus; i++) {
        if (customer[i].accnumber == to_accnumber) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Account not found.\n");
        return;
    }

    if (customer[from_index].balance >= amount) {
        customer[from_index].balance -= amount;
        customer[to_index].balance += amount;
        printf("Transfer successful. Transferred balance: %.2f\n", amount);
    } else {
        printf("Insufficient funds. Transfer failed.\n");
    }
}
