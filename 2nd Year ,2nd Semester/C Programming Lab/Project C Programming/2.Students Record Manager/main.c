/*Student Name: ABID ALI
  Student Roll: 2019380141
  Email       : abiduu354@gmail.com
  Assignment 2
  Student management system
 */
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>



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
    printf("STUDENT RECORD SYSTEM");
    gotoxy(20,3);
    printf("Northwestern Polytechnical University");
    gotoxy(31,4);
    printf("Created by-ABID ALI");
    gotoxy(5,5);
    SetColor(17);

}

struct student
{
    int rollno;
    char fName[20];
    char lName[20];
    double marks;
//int pf for pass or fail boolean value
    int pf;
//Grade Letter Will be auto selected based on marks
    char gradeLetter;
};


int isRunning=1;
struct student st[200];
int sizeOfArray = sizeof(st) / sizeof(st[0]);
int xsize=0;
int passedCount=0;
int failedCount=0;


//A function used along with insert and update options to check and prevent duplicate roll no inputs
int duplicateChecker(int nroll)
{
    int xindex=0;
    int rchk=0;
    for (xindex=0; xindex<=sizeOfArray; xindex++)
    {
        if(nroll==st[xindex].rollno)
        {
            rchk=2;
            break;
        }
        else
        {
            rchk=1;
        }
    }
    return rchk;
}

//The function for Grade Letter Auto Selection
char gradeSelector(double nmarks)
{
    if (nmarks>=90 && nmarks <=100)
    {
        return 'A';
    }
    else if (nmarks>=80 && nmarks <=89)
    {
        return 'B';
    }
    else if (nmarks>=70 && nmarks <=79)
    {
        return 'C';
    }
    else if (nmarks>=60 && nmarks <=69)
    {
        return 'D';
    }
    else if (nmarks<=50)
    {
        return 'F';
    }
    return 'I';
}




//The function for Option 1
void xinput(int nsize)
{
    //A if statement to check if we are running out of space in out Array
    if(xsize-2==sizeOfArray)
    {
        printf("%s","Only 2 Available Space Left Of Array\n Please Copy Array Then Modify Array Size");
    }
    int xinputChecker=1;
    while (xinputChecker==1)
    {
        printf("\nEnter Rollno: ");
        int rno;
        scanf("%d",&rno);
        int chk=duplicateChecker(rno);
        if (chk==1)
        {
            st[nsize].rollno=rno;
            printf("\nEnter First Name: ");
            scanf("%s",st[nsize].fName);
            printf("\nEnter Last Name: ");
            scanf("%s",st[nsize].lName);
            printf("\nEnter Marks in PERCENTAGE: ");
            scanf("%lf",&st[nsize].marks);
            if(st[nsize].marks>=50)
            {
                st[nsize].pf=1;
                passedCount++;
            }
            else if(st[nsize].marks<50)
            {
                st[nsize].pf=0;
                failedCount++;
            }
            st[nsize].gradeLetter=gradeSelector(st[nsize].marks);

            printf("\n");
            printf("%s \n","===================");
            printf("%s \n","Input Successful");
            printf("%s \n","===================");
            printf("\n");
            break;
        }
        else if (chk==2)
        {
            printf("Duplicate Entry Entered...Please Input Non Duplicate Input");
            continue;
        }
    }
    xsize++;
}


//The function for Option 2
void xprint(xsize)
{
    int i;
    for(i=0; i<xsize; i++)
    {
        printf("%s \n","Printing Results ");
        printf("\n");
        printf("Roll No: %d \n",st[i].rollno);
        printf("First Name: %s \n",st[i].fName);
        printf("Last Name: %s \n",st[i].lName);
        printf("Student Marks: %.2lf \n",st[i].marks);
        if(st[i].pf==1)
        {
            printf("Passed OR Failed:  %s \n","Passed");
        }
        else if (st[i].pf==0)
        {
            printf("Passed OR Failed: %s \n","Failed");
        }
        printf("Letter Grade: %c \n",st[i].gradeLetter);
        printf("%s \n","===================");
    }
    printf("%s \n","===================");
    printf("%s \n","ALL RECORDS PRINTED");
    printf("%s \n","===================");
}

//The function for Option 3
void xupdate()
{
    int xrollno;
    int xUpdateChecker=1;
    int xFoundChecker=0;
    while (xUpdateChecker==1)
    {
        printf("Enter Roll To Be Updated: ");
        scanf("%d",&xrollno);
        for(int i=0; i<=sizeOfArray; i++)
        {
            if(xrollno==st[i].rollno)
            {
                printf("\n Record Found For Update \n");
                // perform Update
                printf("\nEnter Updated Roll no: ");
                int rno;
                scanf("%d",&rno);
                int chk=duplicateChecker(rno);
                int dupchecker=1;
                while (dupchecker==1)
                {
                    if (chk==1)
                    {
                        st[i].rollno=rno;
                        printf("\nEnter Updated First Name: ");
                        scanf("%s",st[i].fName);
                        printf("\nEnter Updated Last Name: ");
                        scanf("%s",st[i].lName);
                        printf("\nEnter Updated Marks In PERCENTAGE: ");
                        scanf("%lf",&st[i].marks);
                        int xpf=st[i].pf;
                        if(xpf==1 && st[i].marks>=50)
                        {
                            st[i].pf=1;
                        }
                        else if(xpf==1 && st[i].marks<50)
                        {
                            st[i].pf=0;
                            passedCount--;
                            failedCount++;
                        }
                        else if(xpf==0 && st[i].marks<50)
                        {
                            st[i].pf=0;
                        }
                        else if(xpf==0 && st[i].marks>=50)
                        {
                            st[i].pf=1;
                            passedCount++;
                            failedCount--;
                        }

                        st[i].gradeLetter=gradeSelector(st[i].marks);

                        printf("\n");
                        printf("%s \n","===================");
                        printf("%s \n","UPDATE Successful");
                        printf("%s \n","===================");
                        printf("\n");
                        xFoundChecker=1;
                        xUpdateChecker=0;
                        break;
                    }
                    else if (chk==2)
                    {
                        printf("Cannot Set Updated Roll number Same As Old Roll number....Try Again");
                        break;
                    }
                }
            }
        }
        if(xFoundChecker==0)
        {
            printf("Entry With This Roll NOT FOUND...\n");
        }
    }
}


//The function for Option 4
void xdelete()
{
    int xdeleteroll;
    int xdeleteindex;
    int recordfound=0;
    int xdeletechecker=1;
    while (xdeletechecker==1)
    {
        printf("\n Enter Rollno To Delete: \n");
        scanf("%d",&xdeleteroll);
        for(int i=0; i<sizeOfArray; i++)
        {
            if(xdeleteroll==st[i].rollno)
            {
                printf("%s \n","===================");
                printf("Record Found...Continuing to Delete");
                xdeleteindex=i;
                recordfound=1;
                break;
            }
        }
        if(recordfound==1)
        {
            //delete record
            for(int j=xdeleteindex; j<sizeOfArray; j++)
            {
                st[j]=st[j+1];
            }
            printf("\n");
            printf("%s \n","===================");
            printf("%s \n","Record DELETED Successful");
            printf("%s \n","===================");
            printf("\n");
            xsize--;
            break;
        }
        else if(recordfound==0)
        {
            printf("No Such Record Found....Try Again");
        }
    }
}


//The function for Option 5
void xsearchprint()
{
    int xindex;
    int xroll;
    int xfound=0;
    int xfoundcheckerrunner=1;
    while(xfoundcheckerrunner==1)
    {
        printf("\n Enter Rollno To Find: \n");
        scanf("%d",&xroll);
        for(int i=0; i<sizeOfArray; i++)
        {
            if(xroll==st[i].rollno)
            {
                xfound=1;
                xindex=i;
                break;
            }
        }
        if(xfound==1)
        {
            printf("Record Found...\n");
            printf("%s \n","Printing Results");
            printf("Roll No: %d \n",st[xindex].rollno);
            printf("First Name: %s \n",st[xindex].fName);
            printf("Last Name: %s \n",st[xindex].lName);
            printf("%.2lf \n",st[xindex].marks);
            if(st[xindex].pf==1)
            {
                printf("%s Passed OR Failed: \n","Passed");
            }
            else if (st[xindex].pf==0)
            {
                printf("%s Passed OR Failed: \n","Failed");
            }
            printf("Letter Grade %c \n",st[xindex].gradeLetter);
            printf("%s \n","===================");
            printf("%s \n","Record Found And Printed Successful");
            printf("%s \n","===================");
            break;
        }
        if(xfound==0)
        {
            printf("No Record Found....Try Again...");
        }
    }
}

//The function for Option 6
void xprintsummary()
{
    if(xsize!=0)
    {
        int totalCount=passedCount+failedCount;
        double passedCountPercentage=((passedCount/totalCount)*100);
        double failedCountPercentage=((failedCount/totalCount)*100);
        printf("%s \n","===================");
        printf("Printing Summary\n");
        printf("Total Student Count %d \n",totalCount);
        printf("Total Passed Student Count: %d \n",passedCount);
        printf("Total Failed Student Count: %d \n",failedCount);
        printf("Passed Percentage: %.2lf ",passedCountPercentage);
        printf("%c \n", 37);
        printf("Failed Percentage: %.2lf ",failedCountPercentage);
        printf("%c \n", 37);
        printf("Summary Print Done \n");
        printf("%s \n","===================");
    }
    else if(xsize==0)
    {
        printf("%s \n","===================");
        printf("%s","No Record Currently Available...\n");
        printf("%s \n","===================");
    }
}

//The function for Option 7...also used in option 8
void xsort(int xop)
{
    for (int i = 0; i <sizeOfArray; i++)
    {
        for (int j = i + 1; j <sizeOfArray; j++)
        {
            if(st[i].marks < st[j].marks)
            {
                struct student temp;
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }

        }
    }
    if(xop==1)
    {
        printf("%s \n","===================");
        printf("%s","Sorting Done \nPrint Results to See sorted Record \n");

        printf("%s \n","===================");
    }
    else if (xop==2)
    {
    }
}

//The function for Option 8
void xpicktop()
{
    xsort(2);
    int xPickChecker=1;
    int xPick;
    while(xPickChecker==1)
    {
        printf("%s","Enter the nth position to be picked according to marks\n");
        scanf("%d",&xPick);
        xPick=xPick-1;
        if (xPick>=0 && xPick<=sizeOfArray && (strlen(st[xPick].fName) != 0) && (strlen(st[xPick].lName) != 0) )
        {
            printf("Record Found...\n");
            printf("%s \n","Printing Results");
            printf("Roll No: %d \n",st[xPick].rollno);
            printf("First Name: %s \n",st[xPick].fName);
            printf("Last Name: %s \n",st[xPick].lName);
            printf("%.2lf \n",st[xPick].marks);
            if(st[xPick].pf==1)
            {
                printf("%s Passed OR Failed: \n","Passed");
            }
            else if (st[xPick].pf==0)
            {
                printf("%s Passed OR Failed: \n","Failed");
            }
            printf("Letter Grade %c \n",st[xPick].gradeLetter);
            printf("%s \n","===================");
            printf("%s \n","Record Found And Printed Successful");
            printf("%s \n","===================");
            break;

        }
        else if (xPick<0 || xPick>sizeOfArray)
        {
            printf("%s","Please Enter Valid Input For n...Try Again\n");
        }
    }
}

void main_window()
{
    int choice;
    SetColor(28);
    int x = 2;


    while (isRunning==1)
    {
        printf("%s","Select Option i.e 1 or 2 or 3 or 4 or .....\n");
        printf("Enter New Entry --> 1 \n");
        printf("Print All Entry --> 2 \n");
        printf("Update Existing Entry --> 3 \n");
        printf("Delete Existing Entry --> 4 \n");
        printf("Search and Print Entry By Roll --> 5 \n");
        printf("Print Summary of Students --> 6 \n");
        printf("Sort Record According to Marks --> 7 \n");
        printf("Pick The Top nth Student Based On Marks --> 8 \n");
        printf("Exit Whole Program --> 0 \n");
        printf("\n");
        int testInput;
        scanf("%d",&testInput);
        if (testInput!=0||testInput!=1||testInput!=2||testInput!=3||testInput!=4||testInput!=5||testInput!=6||testInput!=7||testInput!=8)
        {
            //loop for currect input
        }
        if (testInput==0)
        {
            int confirmationint=0;
            printf("ARE YOU SURE?...ALL DATA WILL BE CLEARED....Input 1 IF YOU WOULD LIKE TO EXIT OR ELSE INPUT 0");
            printf("\n");
            scanf("%d",&confirmationint);
            if (confirmationint==1)
            {
                printf("%s","Exiting Program...Thank You... \n");
                isRunning=0;
            }
            else if (confirmationint==0)
            {
            }
        }
        if (testInput==1)
        {
            xinput(xsize);
        }
        if (testInput==2)
        {
            xprint(xsize);
        }
        if (testInput==3)
        {
            xupdate();
        }
        if (testInput==4)
        {
            xdelete();
        }
        if (testInput==5)
        {
            xsearchprint();
        }
        if (testInput==6)
        {
            xprintsummary();
        }
        if (testInput==7)
        {
            xsort(1);
        }
        if (testInput==8)
        {
            xpicktop();
        }

    }

}


int main()
{
    ClearConsoleToColors(17,15);
    SetConsoleTitle(" Student Management System");
    window();

    main_window();
    return 0;
}

