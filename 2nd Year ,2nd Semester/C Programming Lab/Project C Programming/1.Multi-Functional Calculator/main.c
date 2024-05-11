/*Student Name: ABID ALI
  Student Roll: 2019380141
  Email       : abiduu354@gmail.com
  Assignment 1
  Simple Calculator
 */
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#define KEY "Enter the calculator Operation you want to do:"


void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void power();
int factorial();
void sinop();
void cosop();
void tanop();
void logop();
void calculator_operations();


void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD coord = {0, 0};

    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );

        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}

COORD coord = {0,0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void clearWindow()
{
    int i,j;
    for(i = 37; i < 78; i++)
    {
        for(j = 7; j < 25; j++)
        {
            gotoxy(i,j);
            printf(" ");
        }
    }
    return;
}


void window()
{

    gotoxy(28,2);
    SetColor(35);
    printf("Multi-Function Calculator");
    gotoxy(20,3);
    printf("Northwestern Polytechnical University");
    gotoxy(31,4);
    printf("Created by-ABID ALI");
    gotoxy(6,6);
    SetColor(17);

}


void calculator_operations()
{

    printf("\n             Welcome to C calculator \n\n");

    printf("******* Press 'Q' or 'q' to quit ");
    printf("the program ********\n");
    printf("***** Press 'H' or 'h' to display ");
    printf("below options *****\n\n");
    printf("Enter 'C' to clear the screen and");
    printf(" display available option \n\n");

    printf("Enter + symbol for Addition \n");
    printf("Enter - symbol for Subtraction \n");
    printf("Enter * symbol for Multiplication \n");
    printf("Enter / symbol for Division \n");
    printf("Enter ? symbol for Modulus\n");
    printf("Enter ^ symbol for Power \n");
    printf("Enter ! symbol for Factorial \n");
    printf("Enter r symbol for Sqrt \n");
    printf("Enter s for trigonometric sin operation \n");
    printf("Enter c for trigonometric cos operation \n");
    printf("Enter t for trigonometric tan operation \n");
    printf("Enter L or l for logarithmic operation \n\n");

}

void addition()
{
    int n, total=0, k=0, number;
    printf("\nEnter the number of elements you want to add:");
    scanf("%d",&n);
    printf("Please enter %d numbers one by one: \n",n);
    while(k<n)
    {
        scanf("%d",&number);
        total=total+number;
        k=k+1;
    }
    printf("Sum of %d numbers = %d \n",n,total);
}

void subtraction()
{
    int a, b, c = 0;
    printf("\nPlease enter first number  : ");
    scanf("%d", &a);
    printf("Please enter second number : ");
    scanf("%d", &b);
    c = a - b;
    printf("\n%d - %d = %d\n", a, b, c);
}

void multiplication()
{
    int a, b, mul=0;
    printf("\nPlease enter first number   : ");
    scanf("%d", &a);
    printf("Please enter second number: ");
    scanf("%d", &b);
    mul=a*b;
    printf("\nMultiplication of entered numbers = %d\n",mul);
}

void division()
{
    int a, b;
    double d=0;
    printf("\nPlease enter first number  : ");
    scanf("%d", &a);
    printf("Please enter second number : ");
    scanf("%d", &b);
    d=a*(1.0)/b;
    printf("\nDivision of entered numbers=%.2lf\n",d);
}

void modulus()
{
    int a, b, d=0;
    printf("\nPlease enter first number   : ");
    scanf("%d", &a);
    printf("Please enter second number  : ");
    scanf("%d", &b);
    d=a%b;
    printf("\nModulus of entered numbers = %d\n",d);
}

void power()
{
    double a,num, p;
    printf("\nEnter two numbers to find the power \n");
    printf("number: ");
    scanf("%lf",&a);

    printf("power : ");
    scanf("%lf",&num);

    p=pow(a,num);

    printf("\n%lf to the power %lf = %lf \n",a,num,p);
}

int factorial()
{
    int i,fact=1,num;

    printf("\nEnter a number to find factorial : ");
    scanf("%d",&num);

    if (num<0)
    {
        printf("\nPlease enter a positive number to");
        printf(" find factorial and try again. \n");
        printf("\nFactorial can't be found for negative");
        printf(" values. It can be only positive or 0  \n");
        return 1;
    }

    for(i=1;i<=num;i++)
    fact=fact*i;
    printf("\n");
    printf("Factorial of entered number %d is:%d\n",num,fact);
    return 0;
}

void sqrtop()
{
    double i;
    printf("\nEnter a value to find sqrt : ");
    scanf("%lf",&i);
    double result;
    result = sqrt(i);
    printf("The value of sqrt(%lf) : %lf \n", i, result);
}



void sinop()
{
    float i;
    printf("\nEnter a value to find sin : ");
    scanf("%f",&i);
    float radian = i * (M_PI/180);
    float sin_value = sin(radian);
    printf("The value of sin(%f) : %f \n", i, sin_value);


}
void cosop()
{
    float i;
    printf("\nEnter a value to find cos : ");
    scanf("%f",&i);
    float radian = i * (M_PI/180);

    float cos_value = cos(radian);
    printf("The value of cos(%f) : %f \n", i, cos_value);


}
void tanop()
{
    float i;
    printf("\nEnter a value to find tan : ");
    scanf("%f",&i);
    float radian = i * (M_PI/180);
    float tan_value = tan(radian);
    printf("The value of tan(%f) : %f \n", i, tan_value);


}
void logop()
{
    float i;
    printf("\nEnter a value of x to find log(x) base 10 : ");
    scanf("%f",&i);
    float log_value = log10(i);
    printf("The value of log(%f) : %f \n", i, log_value);

}
int main()
{
    ClearConsoleToColors(17,15);
    SetConsoleTitle(" Simple Calculator");
    window();
    int X=1;
    char Calc_oprn;


    calculator_operations();

    while(X)
    {
        printf("\n");
        printf("%s : ", KEY);

        Calc_oprn=getche();
                                                          //We use Switch case to select addition,subtraction,multiplication
                                                          //We use Switch case,to select division, modulus,factorial,
        switch(Calc_oprn)
        {
            case '+': addition();                         //Addition operation is performed
                      break;

            case '-': subtraction();                      //Subtraction operation is addition
                      break;

            case '*': multiplication();                   //Multiplication operation is addition
                      break;

            case '/': division();                         //Division operation is addition
                      break;

            case '?': modulus();                          //Modulus operation is addition
                      break;

            case '!': factorial();                        //Factorial operation is addition
                      break;

            case '^': power();                            //Power operation is addition
                      break;

            case 'r': sqrtop();                           //Square root operation is addition
                      break;

            case 's': sinop();
                      break;

            case 'c': cosop();
                      break;

            case 't': tanop();
                      break;

            case 'L':
            case 'l': logop();
                      break;

            case 'H':
            case 'h': calculator_operations();
                      break;


            case 'Q':
            case 'q': exit(0);                            //Power operation is addition
                      break;

            case 'C': system("cls");
                      calculator_operations();
                      break;

            default : system("cls");

    printf("\n**********You have entered unavailable option");
    printf("***********\n");
    printf("\n*****Please Enter any one of below available ");
    printf("options****\n");
                      calculator_operations();
        }
    }
}

