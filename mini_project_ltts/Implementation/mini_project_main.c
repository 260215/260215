#include<atm_operations.h>


unsigned long balance=10000, PIN=0272;
int k;
char transaction = 'y';


void check_pin();
void check_balance();
void deposit_cash(unsigned long);
void withdraw_cash(unsigned long);
void change_pin();
void transactions();


void check_pin()
{
    unsigned long pin, count=1,i;
    printf("\n Enter PIN number : ");
    scanf("%lu\n", &pin);
    if(pin != PIN)
    {
        for(i=1;i<3;i++)
        {
            printf("\n Re-Enter PIN : ");
            scanf("%lu\n",&pin);
        }
    }
    else
        transactions();
}


void check_balance()
{
    printf("\n The balance is : %lu", balance);
}


void deposit_cash(unsigned long dep_amt)
{
    balance = balance + dep_amt;
    printf("\n The new balance is : %lu", balance);
}


void withdraw_cash(unsigned long wd_amt)
{
    if(wd_amt % 100 != 0)
    {
        printf("\n Enter the withdrawal amount in multiples of 100 : ");
    }
    else if(wd_amt > (balance-500))
    {
        printf("\n Insufficient balance.");
    }
    else
    {
        balance = balance - wd_amt;
        printf("\n Please collect cash. Thanks for banking with us.");
        printf("\n The new balance is : %lu", balance);
    }
}

void change_pin()
{
    unsigned long pin;
    printf("\n Enter the new ATM pin : ");
    scanf("%lu\n", &pin);
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
        scanf("%d\n", &choice);
        switch(choice)
        {
            case 1:check_balance();
                   break;
            case 2:deposit_cash(dep_amt);
                   break;
            case 3:withdraw_cash(wd_amt);
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
    printf("\n Thanks for using our ATM service.");
}

int main()
{
    unsigned long dep_amt, wd_amt;
    printf("\n Enter the amount to be deposited : ");
    scanf("%lu\n", &dep_amt);
    printf("\n Enter the amount to be withdrawn : ");
    scanf("%lu\n", &wd_amt);
    check_pin();
    transactions();
    return 0;
}