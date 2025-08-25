


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void simple_tariff()
{
    printf("\nIn simple tariff per unit rate is fixed and consumers pay the charge as per unit rate\n");
    float units, total_bill;

    printf("Enter the number of units consumed: ");
    scanf("%f", &units);

    if (units <= 50)
    {
        total_bill = units *3.86;
    }
    else if (units <= 150)
    {
        total_bill = 50*3.86 +(units - 50)*5.53;
    }
    else if (units <= 250)
    {
        total_bill = 50*3.86+100*5.53 +(units-150)*6.97;
    }
    else
    {
        total_bill = 50*3.86 +100*5.53 +100*6.97+(units - 250)*9.60;
    }

    printf("Total bill amount: %.2f Taka\n", total_bill);

}
void  flate_rate_tariff()
{
    char load_type;
    float load_amount;
    float total_cost;
    float rate;

    printf("Enter load type ('h' for heavy or 'l' for light): ");
    scanf(" %c", &load_type);

    printf("Enter load amount: ");
    scanf("%f", &load_amount);

    if (load_type == 'h')
    {
        rate = 5.0;  // Flat tariff rate for heavy load
    }
    else if (load_type == 'l')
    {
        rate = 3.0;  // Flat tariff rate for light load
    }
    else
    {
        printf("Invalid load type. Please enter 'h' for heavy or 'l' for light.\n");
        return -1;  // Return -1 to indicate an error
    }

    total_cost = rate * load_amount;
    if (total_cost != -1)
    {
        printf("Total cost: %.2f Taka\n", total_cost);
    }
}
void block_rate_tariff()
{
    int n;                      // Number of blocks
    float x;                    // Watts per block
    float initialRate;          // Initial unit rate
    float discountPerBlock;     // Discount per block
    float totalCost = 0.0;      // Total cost of electricity

    printf("Enter the number of blocks: ");
    scanf("%d", &n);

    printf("Enter the watts per block: ");
    scanf("%f", &x);

    printf("Enter the initial unit rate: ");
    scanf("%f", &initialRate);

    int i;
    float currentRate = initialRate;
    float blockCost = currentRate * x;
    totalCost += blockCost;
    for (i =2; i <= n; i++)
    {
        printf("Enter for the discount %d  block: ",i);
        scanf("%f", &discountPerBlock);
        currentRate -= discountPerBlock;
        float blockCost = currentRate * x;
        totalCost += blockCost;
    }

    printf("Total cost of electricity: %.2f Taka\n", totalCost);
}
struct User
{
    char username[20];
    char password[20];
    float balance;
    float transactionHistory[100];
    int transactionCount;
};

int authenticateUser(struct User* user)
{
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, user->username) == 0 && strcmp(password, user->password) == 0)
    {
      return 1;
    }

    return 0;
}

float calculateBalance(float balance, float amount)
{
    return balance - amount;
}

void displayBalance(float balance)
{
    printf("\nCurrent Balance: $%.2f\n", balance);
}

// Function to store transaction in transaction history
void storeTransaction(struct User* user, float amount)
{
    user->transactionHistory[user->transactionCount] = amount;
    user->transactionCount++;
}

// Function to display transaction history
void displayTransactionHistory(struct User* user)
{
    printf("\nTransaction History:\n");
    for (int i = 0; i < user->transactionCount; i++)
    {
        printf("%.2f\n", user->transactionHistory[i]);
    }
    printf("Total  transaction count:%d",user->transactionCount);
}


void prepaid_billing_system()
{
    struct User user;
    strcpy(user.username, "admin");
    strcpy(user.password, "password");
    user.balance = 0.0;
    user.transactionCount = 0;

    float amount;

    if (!authenticateUser(&user))
    {
        printf("\nInvalid username or password. Exiting prepaid billing system.\n");
        return 0;
    }

    printf("\nAuthentication successful.\n");


    printf("\nEnter initial balance: $");
    scanf("%f", &user.balance);

    displayBalance(user.balance);


    while (1)
    {
      printf("\nEnter amount to deduct (0 to exit, -1 to view transaction history):");
        scanf("%f", &amount);

        if (amount == 0)
        {
            printf("\nExiting prepaid billing system.\n");
            break;
        }
        else if (amount == -1)
        {
            displayTransactionHistory(&user);
            continue;
        }
        else if (amount < 0)
        {
            printf("\nInvalid amount. Please enter a positive value.\n");
            continue;
        }
        else if (amount > user.balance)
        {
            printf("\nInsufficient balance. Please enter a lower amount.\n");
            continue;
        }

        user.balance = calculateBalance(user.balance, amount);
        displayBalance(user.balance);
        storeTransaction(&user, amount);
    }
}
int main()
{
    int no, ch, e;
    printf("In the context of electricity, a tariff refers to the rate or price structure\nthat determines how consumers are charged for the electricity they use.\n\nSome types of tariff are-\n");
    printf("\n 1 -Simple Tariff");
    printf("\n 2 - Flate Rate Tariff");
    printf("\n 3 - Block Rate Tariff");
    printf("\n 4 - Two part Tariff");
    printf("\n 5 - Three part Tariff");
    printf("\n 6 - Power Factor Tariff");
    printf("\n 7 - Maximum Demand Tariff");
    printf("\n 8 - Prepaid billing System");
     while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            simple_tariff();
            break;
        case 2:
            flate_rate_tariff();
            break;
        case 3:
            block_rate_tariff();
            break;
        case 4:
            //
            break;
        case 5:

        case 6:
            //
            break;
        case 7:
            //
            break;
        case 8:
              prepaid_billing_system();
            break;
        case 9:
              exit(0);
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

