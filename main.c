#include <stdio.h>
#include <string.h>
#include "validation.h"

#define MAX_USERS 100

typedef struct {
    int id;
    char password[20];
    float balance;
} Account;

Account users[MAX_USERS];
int user_count = 0;

// -------- FILE STORAGE --------

void load_data()
{
    FILE *fp = fopen("accounts.dat", "rb");
    if (fp != NULL)
    {
        fread(&user_count, sizeof(int), 1, fp);
        fread(users, sizeof(Account), user_count, fp);
        fclose(fp);
    }
}

void save_data()
{
    FILE *fp = fopen("accounts.dat", "wb");
    fwrite(&user_count, sizeof(int), 1, fp);
    fwrite(users, sizeof(Account), user_count, fp);
    fclose(fp);
}

// -------- HISTORY --------

void log_transaction(int id, char action[], float amount)
{
    FILE *fp = fopen("history.dat", "a");
    fprintf(fp, "ID:%d %s %.2f\n", id, action, amount);
    fclose(fp);
}

// -------- UTIL --------

int find_user(int id)
{
    for (int i = 0; i < user_count; i++)
        if (users[i].id == id)
            return i;
    return -1;
}

// -------- CREATE ACCOUNT --------

void create_account()
{
    int id = get_account_id();

    if (find_user(id) != -1)
    {
        printf("Account exists\n");
        return;
    }

    printf("Set password: ");
    scanf("%s", users[user_count].password);

    users[user_count].id = id;
    users[user_count].balance = 0;
    user_count++;

    save_data();
    printf("Account created\n");
}

// -------- USER MENU --------

void user_menu(int index)
{
    int choice;
    float amount;

    while (1)
    {
        printf("\n1.Deposit 2.Withdraw 3.Balance 4.Logout\n");

        choice = get_choice();

        switch (choice)
        {
            case 1:
                amount = get_amount();
                users[index].balance += amount;
                log_transaction(users[index].id, "DEPOSIT", amount);
                save_data();
                break;

            case 2:
                amount = get_amount();
                if (amount > users[index].balance)
                    printf("Insufficient balance\n");
                else
                {
                    users[index].balance -= amount;
                    log_transaction(users[index].id, "WITHDRAW", amount);
                    save_data();
                }
                break;

            case 3:
                printf("Balance: %.2f\n", users[index].balance);
                break;

            case 4:
                return;
        }
    }
}

// -------- LOGIN --------

void login()
{
    int id = get_account_id();
    int index = find_user(id);

    if (index == -1)
    {
        printf("Account not found\n");
        return;
    }

    char pass[20];
    printf("Enter password: ");
    scanf("%s", pass);

    if (strcmp(pass, users[index].password) != 0)
    {
        printf("Wrong password\n");
        return;
    }

    printf("Login success\n");
    user_menu(index);
}

// -------- MAIN --------

int main()
{
    load_data();

    int choice;

    while (1)
    {
        printf("\n1.Create Account 2.Login 3.Exit\n");

        choice = get_choice();

        switch (choice)
        {
            case 1: create_account(); break;
            case 2: login(); break;
            case 3: return 0;
        }
    }
}