//a

#include <stdio.h>

#include <conio.h>

#include <math.h>

#include <windows.h>

#include <stdlib.h>

#include <dos.h>

#include <dir.h>

/*******************

Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15

*******************/

void SetColor(int ForgC);

void menu();

void featureAnalysis();

int isReflexive(const int *array , int N);

int isSymmetric(const int *array , int N);

int isTransitive(const int *array , int N);

/* Closures */

void reflexiveClosures(int *array , int N);

void symmetricClosures(int *array , int N);

void transitiveClosures(int *array , int N);

/* Calculations */

void addition(int *array1 , int *array2 , int *addArray , int N);

void subtraction(int *array1 , int *array2 , int *subArray , int N);

void multiplication(int *array1 , int *array2 , int *mulArray ,  int N);

int main()
{
    int choice;
    do
    {
        char chChoice;
        int check = 0;
        menu();
        do
        {
            if(check)
            {
                printf("Please enter correct order: ");
            }
            scanf(" %c", &chChoice);
            check++;
        } while (chChoice != '1' && chChoice != '2' && chChoice != '0');
        choice = chChoice - 48;
        switch (choice)
        {
        case 1:
            system("CLS");
            featureAnalysis();
            break;
        case 2:
            system("CLS");
            break;
        case 0:
            break;
        default:
            break;
        }
    } while(choice);
    return 0;
}

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi));
    {
        //Mask out all but the background attribute, and add in the forground color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void menu()
{
    system("COLOR F0");
    SetColor(2);
    printf("\t\t\3");
    SetColor(0);
    printf(" WELCOME ");
    SetColor(2);
    printf("\3\n\n");
    SetColor(0);
    printf("\t\t  _MENU_\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196
           , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
           ,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    printf("\n");
    printf("\t%c0 ", 240);
    SetColor(12);
    printf("Exit\n");
    SetColor(0);
    printf("\t%c1 Feature Analysis\n", 240);
    printf("\t%c2 Calculations {+ , - , x}\n", 240);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196
           , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
           ,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    printf("\nso what is your choice? ");
}

void featureAnalysis()
{
    // if user enter a character??
    /*
    char chN[2];
    int numN[2];
    int N = 0;
    printf("Enter size of matrix NxN: ");
    int test;
    int check = 0;
    do
    {
        getch();
        test = 0;
        if(check)
        {
            printf("\aWrong order!\ttry again:\n");
        }
        gets(chN);
        for(int i = 0; i < strlen(chN); i++)
        {
            if(chN[i] < 48 || chN[i] > 57)
            {
                test = 1;
                break;
            }
        }
        check++;
    } while(test);
    for(int i = 0; i < strlen(chN); i++)
    {
        chN[i] -= 48;
        numN[i] = chN[i];
        numN[i] *= pow( 10 , strlen(chN) - (i + 1));
        N += numN[i];
    }
    printf("%d", N);
    */
    int N;
    printf("Enter size of matrix NxN: ");
    scanf("%d", &N);
    int array[N][N];
    int copyArray1[N][N];
    int copyArray2[N][N];
    printf("\nEnter elments of matrix from set {0,1}\none by one %c%c ", 175, 175);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int check = 0;
            char element;
            do
            {
                if(check)
                {
                    printf("\aWrong order!\tEnter correct number:\n");
                }
                scanf(" %c", &element);
                check++;
            } while (element != '1' && element != '0');
            array[i][j] = element - 48;
            copyArray1[i][j] = array[i][j];
            copyArray2[i][j] = array[i][j];
        }
    }
    //system("CLS");
    printf("Ur matrix:\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196
           , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
           ,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    printf("\nIs Reflexive?");
    if(isReflexive((int*)array , N))
    {
        SetColor(2);
        printf("  YES \1\n");
        SetColor(0);
    }
    else
    {
        printf(" NO :(\n\n");
        printf("its closure:\n");
        reflexiveClosures((int*)array , N);
    }
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196
           , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
           ,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    printf("\nIs Symmetric?");
    if(isSymmetric((int*)copyArray1 , N))
    {
        SetColor(2);
        printf("  YES \1\n");
        SetColor(0);
    }
    else
    {
        printf(" NO :(\n\n");
        printf("its closure:\n");
        symmetricClosures((int*)copyArray1 , N);
    }
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196
           , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
           ,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    printf("\nIs Transitive?");
    if(isTransitive((int*)copyArray2 , N))
    {
        SetColor(2);
        printf(" YES \1\n");
        SetColor(0);
    }
    else
    {
        printf(" NO :(\n\n");
        printf("its closure:\n");
        transitiveClosures((int*)copyArray2 , N);
    }
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196
           , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
           ,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    printf("\n");
    printf("Press a key to continue ");
    printf("%c%c ", 175, 175);
    getch();
    system("CLS");
}

int isReflexive(const int *array , int N)
{
    int test = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j && *((array + (i * N)) + j))
            {
                test++;
            }
        }
    }
    if(test == N)
    {
        return 1;
    }
    return 0;
}

int isSymmetric(const int *array , int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i != j)
            {
                if(*((array + (i * N)) + j) != *((array + (j * N)) + i))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int isTransitive(const int *array , int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(*((array + (i * N) + j)))
            {
                for(int k = 0; k < N; k++)
                {
                    if(*((array + (j * N) + k)) && !(*((array + (i * N) + k))))
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void reflexiveClosures(int *array , int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j)
            {
                *((array + (i * N)) + j) = 1;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", *((array + (i * N)) + j));
        }
        printf("\n");
    }
}

void symmetricClosures(int *array , int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i != j)
            {
                if(*((array + (i * N)) + j) != *((array + (j * N)) + i))
                {
                    if(!*((array + (i * N)) + j))
                    {
                        *((array + (i * N)) + j) = 1;
                    }
                    else
                    {
                        *((array + (j * N)) + i) = 1;
                    }
                }
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", *((array + (i * N)) + j));
        }
        printf("\n");
    }
}

void transitiveClosures(int *array , int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(*((array + (i * N) + j)))
            {
                for(int k = 0; k < N; k++)
                {
                    if(*((array + (j * N) + k)) && !(*((array + (i * N) + k))))
                    {
                        if(!*((array + (j * N)) + k))
                        {
                            *((array + (j * N)) + k) = 1;
                        }
                        else
                        {
                            *((array + (i * N)) + k) = 1;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", *((array + (i * N)) + j));
        }
        printf("\n");
    }
}

void addition(int *array1 , int *array2 , int *addArray , int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(*(array1 + (i * N) + j) | *((array2 + (i * N) + j)))
            {
                *(addArray  + (i * N) + j) = 1;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", *((addArray + (i * N)) + j));
        }
        printf("\n");
    }
}

void subtraction(int *array1 , int *array2 , int *subArray , int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(*((array1 + (i * N)) + j))
            {
                *((subArray + (i * N)) + j) += (*((array1 + (i * N)) + j)) - (*((array2 + (i * N)) + j));
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", *((subArray + (i * N)) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void multiplication(int *array1 , int *array2 , int *mulArray , int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                if(!*((mulArray + (i * N)) + j))
                {
                    *((mulArray + (i * N)) + j) += (*((array1 + (i * N)) + k)) * (*((array2 + (k * N)) + j));
                }
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", *((mulArray + (i * N)) + j));
        }
        printf("\n");
    }
    printf("\n");
}
