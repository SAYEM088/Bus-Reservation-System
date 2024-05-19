#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include <unistd.h>
#include<time.h>
//console handle code
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, text_color | (bg_color << 4));
}
//text color(ANSI) in marcos
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

//customer and bus admin structure
struct customer{
   long long int ID;
    char name[20];
    char pass[6];
}customer;
struct admin{
    int ID;
    char name[20];
    char pass[6];
}admin;
//global variable
char storedName[20];
long long int storedID;
//functions:
void landingPage();
void signIn();
void signUp();
void mainMenuBar();
void routeInfo();
void routeA_P();
void routeS_G();
void routeM_A();
void buyTicket();
void myBus();
int passwordChecker(FILE *fileName, char infoFile[50], struct admin st);
void carDesign(int x);
void waitSpin();
void cart_route();
void showCusInfo();
void cartA_P();
void cartS_G();
void cartM_A();
void printBill(int x);
//main code
int main(){
    landingPage();
    getch();
    return 0;
}
void landingPage(){
    system("color 0B");
    gotoxy(70, 5);
    printf(" .---------------------------.\n");
    gotoxy(70, 6);
    printf("/\"\"\"\"/\"\"\"\"/|\"\"|'|\"\"||\"\"|   ' \\.\n");
    gotoxy(70, 7);
    printf("/    /    / |__| |__||__|      |\n");
    gotoxy(70, 8);
    printf("/----------=====================|\n");
    gotoxy(70, 9);
    printf("| \\  /V\\  /    _.               |\n");
    gotoxy(70, 10);
    printf("|()\\ \\W/ /()   _            _   |\n");
    gotoxy(70, 11);
    printf("|   \\   /     / \\          / \\  |-(sam)\n");
    gotoxy(70, 12);
    printf("=C========C==_| ) |--------| ) _/==] _\n");
    gotoxy(70, 13);
    printf(" \\_\\_/__..  \\_\\_/_ \\_\\_/ \\_\\_/.-.-.\n");

   printf("\n\n\n");
   gotoxy(65, 17);
   printf("\033[1;33m");
     printf("WELCOME TO THE SAM BUS TICKET RESERVATION SYSTEM");
    printf("\033[0m");
     printf("\033[36m");
   gotoxy(73, 20);
   printf("Developed by :-");
    gotoxy(80, 22);
    printf("MD ABU SAYEM SARKER");
    gotoxy(80, 23);
    printf("ID: 024231005341279");
    printf("\033[0m");
     gotoxy(65, 25);
    printf("\033[1;44m\033[97m");
    printf("Enter Any Key to Start.....");
    printf("\033[0m");
     getch();
     system("cls");
     mainMenuBar();
}
void carDesign(int x){
    gotoxy(x, 10);
    printf("    _________________________   \n");
    gotoxy(x, 11);
    printf("   |   |     |     |    | |  \\  \n");
    gotoxy(x, 12);
    printf("   |___|_____|_____|____|_|___\\ \n");
    gotoxy(x, 13);
    printf("   |                    | |    \\\n");
    gotoxy(x, 14);
    printf("  ``--(o)(o)--------------(o)--'  \n");
    gotoxy(x, 15);
    printf("``````````````````````````````````````\n");
}
void waitSpin(){
    system("cls");
    system("color 0B");
    carDesign(45);
    usleep(500000);

    system("cls");
    carDesign(50);
    usleep(500000);

    system("cls");
    carDesign(55);
    usleep(500000);

    system("cls");
    carDesign(60);
    system("cls");
    system("color 0B");
}

void mainMenuBar(){
    waitSpin();
    int press;
        gotoxy(70,10);
         printf("\033[1;4;33m");
        printf("Menu: ");
        printf("\033[0m");
        printf("\033[36m");
        gotoxy(70,12);
        printf("Press 1: To See Routes Info ");
         gotoxy(70,14);
        printf("Press 2: To Buy Ticket");
         gotoxy(70,16);
        printf("Press 3: MyBus");
         gotoxy(70,18);
         printf("Press 4: To Exit");
         gotoxy(70,20);
        printf(": ");
        scanf("%d", &press);
     do
    {
        switch (press)
        {
        case 1:
            routeInfo();
            break;
        case 2:
           buyTicket();
            break;
        case 3:
            myBus();
        case 4:
            exit(0);
        default:
            break;
        }
    } while (press != 4);
}
void routeInfo(){
    waitSpin();
    int number;
    printf("\033[1;4;33m");
    gotoxy(70,12);
    printf("Our Offering Routes:");
    printf("\033[0m");
    printf("\033[36m");
    gotoxy(50,15);
    printf("No:");
    gotoxy(60,15);
    printf("From:");
    gotoxy(70,15);
    printf("To:");
    gotoxy(50,17);
    printf("1");
    gotoxy(56,17);
    printf("Abdullahpur");
    gotoxy(70,17);
    printf("Paltan");
    gotoxy(50,19);
    printf("2");
    gotoxy(56,19);
    printf("Savar");
    gotoxy(70,19);
    printf("Gulistan");
    gotoxy(50,21);
    printf("3");
    gotoxy(56,21);
    printf("Mirpur 14");
    gotoxy(70,21);
    printf("Ashulia");
    gotoxy(50,23);
    printf("4");
    gotoxy(60,23);
    printf("Main Menu ");
    gotoxy(50,25);
    printf("Enter Number: ");
    scanf("%d",&number);
     do
    {
        switch (number)
        {
        case 1:
            routeA_P();
            break;
        case 2:
          routeS_G();
            break;
        case 3:
        routeM_A();
        break;
        case 4:
            mainMenuBar();
            break;
        default:
            break;
        }
    } while (number != 4);
}
void routeA_P(){
    waitSpin();
    gotoxy(60,10);
    printf("\033[1;4;33m");
    printf("The Routes We are offering :");
    printf("\033[0m");
    printf("\033[36m");
    gotoxy(50,14);
    printf("Route Name:");
    gotoxy(70,14);
    printf("Abdullahpur To Paltan");
    gotoxy(50,16);
    printf("Bus Name:");
    gotoxy(75,16);
    printf("Victor Classic");
    gotoxy(50,17);
    printf("Departure/Arrival");
    gotoxy(75,17);
    printf("Abdullahpur");
    gotoxy(50,18);
    printf("stoppage");
    gotoxy(75,18);
    printf("Airport");
    gotoxy(50,19);
    printf("stoppage");
    gotoxy(75,19);
    printf("Khilket");
    gotoxy(50,20);
    printf("stoppage");
    gotoxy(75,20);
    printf("Jamuna");
    gotoxy(50,21);
    printf("stoppage");
    gotoxy(75,21);
    printf("Badda");
    gotoxy(50,22);
    printf("stoppage");
    gotoxy(75,22);
    printf("Paltan");
    gotoxy(60,25);
    printf("main menu?");
    getch();
    mainMenuBar();
}
void routeS_G(){
      waitSpin();
    gotoxy(60,12);
    printf("\033[1;4;33m");
    printf("The Routes We are offering :");
    printf("\033[0m");
    printf("\033[36m");
    gotoxy(50,14);
    printf("Route Name:");
     gotoxy(70,14);
    printf("Savar to Gulishtan");
    gotoxy(50,16);
    printf("Bus Name:");
    gotoxy(75,16);
    printf("Gulistan-Dhamrai");
    gotoxy(50,17);
    printf("Departure/Arrival");
    gotoxy(75,17);
    printf("Savar");
    gotoxy(50,18);
    printf("stoppage");
    gotoxy(75,18);
    printf("Gabtoli");
    gotoxy(50,19);
    printf("stoppage");
    gotoxy(75,19);
    printf("Asad Gate");
    gotoxy(50,20);
    printf("stoppage");
    gotoxy(75,20);
    printf("Dhanmondi");
    gotoxy(50,21);
    printf("stoppage");
    gotoxy(75,21);
    printf("New Marker");
    gotoxy(50,22);
    printf("stoppage");
    gotoxy(75,22);
    printf("Gulistan");
    gotoxy(60,25);
    printf("main menu?");
    getch();
    mainMenuBar();
}
void routeM_A(){
      waitSpin();
    gotoxy(60,12);
    printf("\033[1;4;33m");
    printf("The Routes We are offering :");
    printf("\033[0m");
    printf("\033[36m");
    gotoxy(50,14);
    printf("Route Name:");
     gotoxy(70,14);
    printf("Mirpur To Ashulia");
    gotoxy(50,16);
    printf("Bus Name:");
    gotoxy(75,16);
    printf("Sotabdi");
    gotoxy(50,17);
    printf("Departure/Arrival");
    gotoxy(75,17);
    printf("Mirpur 14");
    gotoxy(50,18);
    printf("stoppage");
    gotoxy(75,18);
    printf("Mirpur 1");
    gotoxy(50,19);
    printf("stoppage");
    gotoxy(75,19);
    printf("Birulia");
    gotoxy(50,20);
    printf("stoppage");
    gotoxy(75,20);
    printf("Abdullahpur");
    gotoxy(50,21);
    printf("stoppage");
    gotoxy(75,21);
    printf("Ashulia");
    gotoxy(60,25);
    printf("main menu?");
    getch();
    mainMenuBar();
}
void buyTicket(){
    system("cls");
    int cs;
    gotoxy(70,10);
      printf("\033[1;4;33m");
     printf("To BOOK A Ticket : ");
    printf("\033[0m");
    printf("\033[36m");
    gotoxy(70,15);
    printf("Press 1: Sign In");
    gotoxy(70,17);
    printf("Press 2: Sign Up");
    gotoxy(70,21);
    printf("Press 3: Main Menu");
    gotoxy(70,23);
    printf(": ");
    scanf("%d",&cs);
   do{
     switch(cs){
    case 1:
        signIn();
        break;
    case 2:
        signUp();
        break;
    case 3:
       mainMenuBar();
        break;
    }
   }while(cs>3);
   mainMenuBar();
   getch();
}
void signUp(){
    system("cls");
    FILE *cartInfo;
    char name;
    char ch;
    char cartInfoFile[] = "sam-bus.txt";
    cartInfo = fopen(cartInfoFile, "a");
    gotoxy(70,10);
    printf("please fill up some info and sign up\n");
    gotoxy(73,12);
    printf("Enter Your Phone Number: +880 ");
    scanf("%lld",&customer.ID);
    gotoxy(75,13);
    printf("Enter your name : ");
    scanf("%s",customer.name);
    gotoxy(75,15);
    printf("Enter your pass : ");
    int i = 0;
    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            customer.pass[i] = ch;
            i++;
        }
    }
    customer.pass[i] = '\0';
    system("cls");
    waitSpin();
    gotoxy(72,15);
    printf("Congrats \" %s \"",customer.name);
    gotoxy(70,18);
     printf("\033[1;31m");
     printf("Registration Successful...!!\n");
    printf("\033[0m");
    printf("\033[36m");

    usleep(500000);
    system("cls");
    fprintf(cartInfo,"\n%lld \t %s \t %s\n",customer.ID,customer.name,customer.pass);
    fclose(cartInfo);
    mainMenuBar();
}
void signIn(){
    system("cls");
    gotoxy(70, 6);
    printf("\033[1;4;33m");
    printf("Sign In ");
    printf("\033[0m");
    printf("\033[36m");
    FILE *fileName;
    char infoFile[]="sam-bus.txt";

   long long int userID;
    int found = 0;
    char userName[20];
    char pass[6];
    char ch;
    int i = 0;

    gotoxy(70, 8);
    printf("Enter Your Info :");
    gotoxy(73, 9);
    printf(" Phone Number: +880 ");
    scanf("%lld", &userID);
    if(userID <9999999999 ){
        system("cls");
        system("color C7");
        gotoxy(70,20);
        printf("Wrong Input");
        gotoxy(70,22);
        printf("Try Again");
        getch();
        exit(0);
    }
    gotoxy(73, 10);
    printf("Name : ");
    scanf("%s", userName);
    gotoxy(73, 11);
    printf("Pass : ");

    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';

    fileName = fopen(infoFile, "r");
    if (fileName == NULL) {
        printf("Error opening file!\n");
        return ;
    }

    while (fscanf(fileName, "%lld %s %s", &customer.ID, customer.name, customer.pass) != EOF) {
        if (strcmp(customer.pass, pass) == 0 && customer.ID == userID && strcmp(customer.name, userName) == 0) {
            system("cls");
            waitSpin();
            gotoxy(70,10);
            printf("Welcome %s", customer.name);
            gotoxy(70,12);
            printf("Your ID: %lld", customer.ID);
            strcpy(storedName, customer.name);
            storedID = customer.ID;
            gotoxy(70,15);
            printf("Press any key to continue......");
            getch();
            system("cls");
            cart_route();
             getch();
            found = 1;
            break;
        }
    }

    fclose(fileName);

    if (!found) {
            system("cls");
    gotoxy(60,15);
    printf("\033[1;31m");
     printf("\nNot found\n");
    printf("\033[0m");
    printf("\033[36m");
       gotoxy(60,18);
       printf("Please Try Again");
        exit(0);
    }
    return ;
    getch();
}
void showCusInfo(){
     gotoxy(55,8);
    printf("\033[1;33m");
     printf("Name: %s    ID: %d\n", storedName, storedID);
    printf("\033[0m");
    printf("\033[36m");

}
void cart_route(){
    waitSpin();
     int num;
    gotoxy(60,10);
    showCusInfo();
    gotoxy(55,12);
    printf("\033[1;4;33m");
    printf("Select Your route : ");
    printf("\033[0m");
    printf("\033[36m");
    gotoxy(50,15);
    printf("No:");
    gotoxy(60,15);
    printf("From:");
    gotoxy(70,15);
    printf("To:");
    gotoxy(50,17);
    printf("1");
    gotoxy(56,17);
    printf("Abdullahpur");
    gotoxy(70,17);
    printf("Paltan");
    gotoxy(50,19);
    printf("2");
    gotoxy(56,19);
    printf("Savar");
    gotoxy(70,19);
    printf("Gulistan");
    gotoxy(50,21);
    printf("3");
    gotoxy(56,21);
    printf("Mirpur 14");
    gotoxy(70,21);
    printf("Ashulia");
    gotoxy(50,23);
    printf("4");
    gotoxy(60,23);
    printf("Main Menu ");
    gotoxy(60,25);
    printf("Enter Number: ");
    scanf("%d",&num);
     do
    {
        switch (num)
        {
        case 1:
            cartA_P();
            break;
        case 2:
          cartS_G();
            break;
        case 3:
        cartM_A();
        break;
        case 4:
            mainMenuBar();
            break;
        default:
            break;
        }
    } while (num != 4);

}
void printBill(int x){
     int random_number = rand() % 100 + 1;
    int total_bill = random_number / x * 15;
    printf("\nTotal Bill is: %d", total_bill);
}

void cartA_P(){
    int noOfTicket,start,end;
    system("cls");
    waitSpin();
    showCusInfo();
    gotoxy(55,10);
    printf("Route : Abdullahpur-Paltan");
    gotoxy(50,12);
    printf("Departure/Arrival: 1");
    gotoxy(75,12);
    printf("Abdullahpur");
    gotoxy(50,13);
    printf("stoppage: 2");
    gotoxy(75,13);
    printf("Airport");
    gotoxy(50,14);
    printf("stoppage: 3");
    gotoxy(75,14);
    printf("Khilket");
    gotoxy(50,15);
    printf("stoppage: 4");
    gotoxy(75,15);
    printf("Jamuna");
    gotoxy(50,16);
    printf("stoppage: 5");
    gotoxy(75,16);
    printf("Badda");
    gotoxy(50,17);
    printf("stoppage: 6");
    gotoxy(75,17);
    printf("Paltan");
    gotoxy(55,20);
    printf("Enter Starting and arrival stoppage number: ");
    scanf("%d %d",&start,&end);
    gotoxy(55,23);
    printf("Enter NO of Ticket: ");
   scanf("%d",&noOfTicket);
   gotoxy(55,26);
   printBill(noOfTicket);
getch();
}
void cartS_G(){
  int noOfTicket,start,end;
    system("cls");
    waitSpin();
    showCusInfo();
    gotoxy(55,10);
    printf("Route : Savar-Gulistan");
    gotoxy(50,12);
    printf("Departure/Arrival: 1");
    gotoxy(75,12);
    printf("Savar");
    gotoxy(50,13);
    printf("stoppage: 2");
    gotoxy(75,13);
    printf("Gabtoli");
    gotoxy(50,14);
    printf("stoppage: 3");
    gotoxy(75,14);
    printf("Asad Gate");
    gotoxy(50,15);
    printf("stoppage: 4");
    gotoxy(75,15);
    printf("Dhanmondi");
    gotoxy(50,16);
    printf("stoppage: 5");
    gotoxy(75,16);
    printf("New Marker");
    gotoxy(50,17);
    printf("stoppage: 6");
    gotoxy(75,17);
    printf("Gulistan");
    gotoxy(55,20);
    printf("Enter Starting and arrival stoppage number: ");
    scanf("%d %d",&start,&end);
    gotoxy(55,23);
    printf("Enter NO of Ticket: ");
   scanf("%d",&noOfTicket);
   gotoxy(55,26);
   printBill(noOfTicket);
getch();
}
void cartM_A(){
int noOfTicket,start,end;
    system("cls");
    waitSpin();
    showCusInfo();
    gotoxy(55,10);
    printf("Route : Abdullahpur-Paltan");
    gotoxy(50,17);
    printf("Departure/Arrival");
    gotoxy(75,17);
    printf("Mirpur 14");
    gotoxy(50,18);
    printf("stoppage");
    gotoxy(75,18);
    printf("Mirpur 1");
    gotoxy(50,19);
    printf("stoppage");
    gotoxy(75,19);
    printf("Birulia");
    gotoxy(50,20);
    printf("stoppage");
    gotoxy(75,20);
    printf("Abdullahpur");
    gotoxy(50,21);
    printf("stoppage");
    gotoxy(75,21);
    printf("Ashulia");
    gotoxy(55,20);
    printf("Enter Starting and arrival stoppage number: ");
    scanf("%d %d",&start,&end);
    gotoxy(55,23);
    printf("Enter NO of Ticket: ");
   scanf("%d",&noOfTicket);
   gotoxy(55,26);
   printBill(noOfTicket);
getch();
}
int passwordChecker(FILE *fileName, char infoFile[50], struct admin st)  {
    int userID, found = 0;
    char userName[20];
    char pass[6];
    char ch;
    int i = 0;

    gotoxy(70, 8);
    printf("Enter Your Info :");
    gotoxy(73, 9);
    printf(" ID:");
    scanf("%d", &userID);
    gotoxy(73, 10);
    printf("Name :");
    scanf("%s", userName);
    gotoxy(73, 11);
    printf("Pass :");

    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';

    fileName = fopen(infoFile, "r");
    if (fileName == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    while (fscanf(fileName, "%d %s %s", &st.ID, st.name, st.pass) != EOF) {
        if (strcmp(st.pass, pass) == 0 && st.ID == userID && strcmp(st.name, userName) == 0) {
            printf("\nWelcome %s\nYour ID: %d\n\n", st.name, st.ID);
            found = 1;
            break;
        }
    }

    fclose(fileName);

    if (!found) {
        printf("\nNot found\n");
        exit(0);
    }
    return 0;
}
void myBus(){
    system("cls");
    waitSpin();
    FILE *adminInfo;
    char adminInfoFile[]="admin-info.txt";
    passwordChecker(adminInfo, adminInfoFile, admin);
}
