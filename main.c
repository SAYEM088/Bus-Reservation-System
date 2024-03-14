/*
sayem 1279                                          14.03.24
Bus Reservation System
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int i;
struct busTicket
{
    char nameFrom[20];
    char nameTo[20];
    int totalTicket;
} cart;
struct person{
     int phoneNumber;
    char name[20];
}p;
int logIn();
int signIn();
void display()
{
    FILE *cartInfo = fopen("cart-Info.txt", "r");
    printf("You have purchase\n\n");
    printf("From: %s \n To: %s\n NO of ticket :%d\n", cart.nameFrom, cart.nameTo, cart.totalTicket);
    printf("\nAnd Total Bill is : %d",(rand() % 100 + 1)%10,(rand() % 100 + 1/ cart.totalTicket*15));
    fclose(cartInfo);
}
// to see route info: 3ta route
void seeInfo()
{
    printf("we are offering\n");
    printf("Route 1 : Dhanmondi to New Market \n Route 2 : Abdullahpur to Victoria \n Route 3 : Mirpur to Gulistan\n");
}
// buy ticket : no paying system:
void buyTicket()
{
    char cartInfoFile[] = "cart-Info.txt";
    FILE *cartInfo;
    cartInfo = fopen(cartInfoFile, "a");
     printf("Please provide Journey info : \n");
    printf("Enter From: ");
    scanf("%s", cart.nameFrom);
    printf("Enter To: ");
    scanf("%s", cart.nameTo);
    printf("No of ticket : ");
    scanf("%d", &cart.totalTicket);
    fprintf(cartInfo, "%s %s %d\n", cart.nameFrom, cart.nameTo, cart.totalTicket);
    fclose(cartInfo);
    display();
    exit(0);
}
// account:

void account()
{
    printf("press 1: log in\n press 2: register\n");
    int accountNo;
    scanf("%d", &accountNo);
    do
    {
        switch (accountNo)
        {
        case 1:
            logIn();
            break;
        case 2:
            signIn();
            break;
        case 3:
            exit(0);
            break;

        default:
            break;
        }
    } while (accountNo != 3);

    printf("Enter Your account No :");
}
int logIn()
{
    printf("enter your id no: ");
    int idNo;
    int phoneNumberNow;
    scanf("%d", &idNo);
    char cartInfoFile[] = "cart-Info.txt";
    FILE *cartInfo;
    cartInfo = fopen(cartInfoFile, "r");
    int found=0;
    while (fscanf(cartInfo,"%d %s",&p.phoneNumber,p.name)!=EOF)
    {
        if (p.phoneNumber==idNo)
        {
            printf("Welcome %s\n Your ID: %d\n\n",p.name,p.phoneNumber);
            found++;
            break;
        }
        
    }
    if(!found){
        printf("Not found");
        exit(0);
    }
    buyTicket();
}
int signIn(){
    printf("please fill up some info and sign In\n");
    char cartInfoFile[] = "cart-Info.txt";
    FILE *cartInfo;
    cartInfo = fopen(cartInfoFile, "a");
    printf("Enter Your Phone Number:");
    scanf("%d",&p.phoneNumber);
    char name;
    printf("Enter your name : ");
    scanf("%s",p.name);
    fprintf(cartInfo,"\n%d \n %s\n",p.phoneNumber,p.name);
    printf("Registration Successful\n\n");
    fclose(cartInfo);
    account();
}

int main()
{
    printf("---Welcome to SAYEM PoriBahan---\n");
    int press;
    do
    {
        printf("\n\nMenu:\n\n press 1: To See routes info \n press 2: To Buy Ticket \n press 3: To Exit\n : ");
        scanf("%d", &press);
        switch (press)
        {
        case 1:
            seeInfo();
            break;
        case 2:
            account();
            break;
        case 3:
            exit(0);
        default:
            break;
        }
    } while (press != 3);
    return 0;
}