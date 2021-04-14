#include<atm_operations.h>

unsigned long balance=10000, PIN=1272;
int k;
char transaction = 'y';

void check_pin()
{
    unsigned long pin;
    
    printf("\n Enter PIN number : ");
    for(int i=0;i<3;i++) {
        scanf("%lu", &pin);
        if(pin == PIN)
        {
            transactions();
            exit(0);
        }
        else
        {
            if (i != 2){
                printf("\n Incorrect pin. Please Enter the correct pin : ");
            } else 
            {
                printf("\n Card blocked for transaction for 24 hours.\n");
                exit(1);
            }
        }
    }
    exit(1);
    // Failed for 3 times
}

void check_balance()
{
    printf("\n The balance is : %lu", balance);
}

void deposit_cash()
{
    unsigned long dep_amount;
    printf("\n Enter the amount to be deposited : ");
    scanf("%lu", &dep_amount);
    balance = balance + dep_amount;
    printf("\n The new balance is : %lu", balance);
}

void withdraw_cash()
{
    unsigned long wd_amount;
    printf("\n Enter the withdrawal amount : ");
    scanf("%lu", &wd_amount);
    if(wd_amount % 100 != 0)
    {
        printf("\n Enter the withdrawal amount in multiples of 100 : ");
    }
    else if(wd_amount > (balance-500))
    {
        printf("\n Insufficient balance.");
    }
    else
    {
        balance = balance - wd_amount;
        printf("\n Please collect cash. Thanks for banking with us.");
        printf("\n The new balance is : %lu", balance);
    }
}

void change_pin()
{
    unsigned long pin;
    printf("\n Enter the new ATM pin : ");
    scanf("%lu", &pin);
    if(pin != PIN)
        printf("\n ATM pin changed successfully.");
}

void transactions()
{
    int choice;
    do
    {
        printf("\n Press 1 for checking balance.");
        printf("\n Press 2 for depositing cash.");
        printf("\n Press 3 for withdrawing cash.");
        printf("\n Press 4 for changing pin.");
        printf("\n Press 5 to exit.");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:check_balance();
                   break;
            case 2:deposit_cash();
                   break;
            case 3:withdraw_cash();
                   break;
            case 4:change_pin();
                   break;
            case 5:exit(4);
                   break;
            default:printf("Invalid choice !!!");
                   break;
        }
        printf("\n Do you wish to have another transaction[y/n]?");
        fflush(stdin);
        scanf("%c", &transaction);
        if(transaction == 'n' || transaction == 'N')
            k = 1;
    }while(!k);
    printf("\n Thanks for using our ATM service.\n");
}

