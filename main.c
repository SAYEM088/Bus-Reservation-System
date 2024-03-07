/*Sayem 1279
Bus Ticket Reservation System*/
#include<stdio.h>
#include <conio.h>  
#include<stdlib.h>
int i;
struct busTicket
{
    char nameFrom[20];
    char nameTo[20];
    int totalTicket;
};

int main(){
    printf("---Welcome to SAYEM PoriBahan---\n");
    printf("How many Destination do you wanna go? : ");
    int num;
    scanf("%d",&num);
    struct busTicket cart[num];
    char cartInfoFile[]="cart_Info.txt";
    FILE *cartInfo;
    cartInfo =fopen(cartInfoFile,"a");
    
    printf("Enter From , To and Ticket Number: \n\n");
    for ( i = 0; i < num; i++)
    {   
        
        scanf("%s",cart[i].nameFrom);
        scanf("%s",cart[i].nameTo);
        scanf("%d",&cart[i].totalTicket);
    }
    for ( i = 0; i < num; i++)
    {
       fprintf(cartInfo,"%s %s %d\n",cart[i].nameFrom,cart[i].nameTo,cart[i].totalTicket);
    }
      fclose(cartInfo);
    struct busTicket readCart[num];
    cartInfo = fopen(cartInfoFile, "r");    
    for ( i = 0; i < num; i++)
    {
        fscanf(cartInfo,"%s",readCart[i].nameFrom);
        fscanf(cartInfo,"%s",readCart[i].nameTo);
        fscanf(cartInfo,"%d",&readCart[i].totalTicket);
    }
      fclose(cartInfo);
    for ( i = 0; i < num; i++)
    {
        printf("From %s to %s total km is %d and cost is : %d\n",readCart[i].nameFrom,readCart[i].nameTo,(rand() % 100 + 1)%10,(rand() % 100 + 1/readCart[i].totalTicket*15));
    }
    return 0;
    
}