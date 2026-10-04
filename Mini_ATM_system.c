#include <stdio.h>

int create_account(int pin[], long long int bal[], int total_accounts);
int deposit(int pin[], long long int bal[], int total_accounts);
int withdraw_amount(int pin[], long long int bal[], int total_accounts);
int check_balance(int pin[], long long int bal[], int total_accounts);

int main() {
    int pin[100];
    long long int bal[100];
    int total_accounts = 0;
    int run = 1, option;

    while (run == 1) {
        printf("\n|======= MINI ATM SYSTEM =======|");
        printf("\n1. Create an Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\n|===============================|");
        printf("\nChoose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                total_accounts = create_account(pin, bal, total_accounts);
                break;
            case 2:
                deposit(pin, bal, total_accounts);
                break;
            case 3:
                withdraw_amount(pin, bal, total_accounts);
                break;
            case 4:
                check_balance(pin, bal, total_accounts);
                break;
            case 5:
                printf("\nThank you for using the ATM System!\n");
                run = 0;
                break;
            default:
                printf("\nInvalid Option!\n");
        }
    }

    return 0;
}

int create_account(int pin[], long long int bal[], int total_accounts) {
    printf("\nEnter a 4-digit security PIN: ");
    scanf("%d", &pin[total_accounts]);

    bal[total_accounts] = 0;  // initial balance
    total_accounts++;

    printf("\nAccount Successfully Created!");
    printf("\nYour Account Number is: %d\n", total_accounts);

    return total_accounts;
}

int deposit(int pin[], long long int bal[], int total_accounts) {
    long long int amount = 0;
    int account_number, pin_num;

    printf("\nEnter Your Account Number: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > total_accounts) {
        printf("\nInvalid Account Number!");
        return 0;
    }

    printf("Enter Your Security PIN: ");
    scanf("%d", &pin_num);

    if (pin_num == pin[account_number - 1]) {
        printf("\nSuccessfully Logged In!");
        printf("\nEnter Amount to Deposit: ");
        scanf("%lld", &amount);

        bal[account_number - 1] += amount;
        printf("\nDeposit Successful! New Balance = %lld\n", bal[account_number - 1]);
    } else {
        printf("\nIncorrect PIN!\n");
    }

    return 0;
}

int withdraw_amount(int pin[], long long int bal[], int total_accounts) {
    long long int amount = 0;
    int account_number, pin_num;

    printf("\nEnter Your Account Number: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > total_accounts) {
        printf("\nInvalid Account Number!");
        return 0;
    }

    printf("Enter Your Security PIN: ");
    scanf("%d", &pin_num);

    if (pin_num == pin[account_number - 1]) {
        printf("\nSuccessfully Logged In!");
        printf("\nEnter Amount to Withdraw: ");
        scanf("%lld", &amount);

        if (bal[account_number - 1] >= amount) {
            bal[account_number - 1] -= amount;
            printf("\nWithdrawal Successful! Remaining Balance = %lld\n", bal[account_number - 1]);
        } else {
            printf("\nInsufficient Balance!\n");
        }
    } else {
        printf("\nIncorrect PIN!\n");
    }

    return 0;
}

int check_balance(int pin[], long long int bal[], int total_accounts) {
    int account_number, pin_num;

    printf("\nEnter Your Account Number: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > total_accounts) {
        printf("\nInvalid Account Number!");
        return 0;
    }

    printf("Enter Your Security PIN: ");
    scanf("%d", &pin_num);

    if (pin_num == pin[account_number - 1]) {
        printf("\nSuccessfully Logged In!");
        printf("\nYour Current Balance = %lld\n", bal[account_number - 1]);
    } else {
        printf("\nIncorrect PIN!");
    }

    return 0;
}