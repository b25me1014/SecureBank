#include "validation.h"
#include <stdio.h>

int validateAmount(float amount) {
    if (amount <= 0) {
        printf("\n[ERROR] Amount must be greater than 0!\n");
        return 0;
    }
    return 1;
}

int validateWithdrawal(float amount, float balance) {
    if (amount <= 0) {
        printf("\n[ERROR] Amount must be greater than 0!\n");
        return 0;
    }

    if (amount > balance) {
        printf("\n[ERROR] Insufficient balance! Current Balance: Rs %.2f\n", balance);
        return 0;
    }

    return 1;
}

int validateMenuChoice(int choice, int min, int max) {
    if (choice < min || choice > max) {
        printf("\n[ERROR] Invalid choice! Enter between %d and %d\n", min, max);
        return 0;
    }
    return 1;
}