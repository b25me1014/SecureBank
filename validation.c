#include <stdio.h>
#include "validation.h"

int get_choice(void)
{
    int choice;
    while (1)
    {
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }
        if (choice >= 1 && choice <= 6)
            return choice;
        printf("Choose between 1–6\n");
    }
}

float get_amount(void)
{
    float amount;
    while (1)
    {
        printf("Enter amount: ");
        if (scanf("%f", &amount) != 1)
        {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }
        if (amount > 0)
            return amount;
        printf("Amount must be > 0\n");
    }
}

int get_account_id(void)
{
    int id;
    while (1)
    {
        printf("Enter Account ID: ");
        if (scanf("%d", &id) != 1)
        {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }
        if (id > 0)
            return id;
        printf("Invalid ID\n");
    }
}