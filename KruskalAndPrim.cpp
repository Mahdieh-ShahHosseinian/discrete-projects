//a

#include <stdio.h>

#include <windows.h>

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

struct info
{
    int weight;
    int iPos;
    int jPos;
};

int kruskal(int *array , int N , int weight);

void arraySort(struct info arr[] , int nArr);

int prim(int *array , int N , int weight , int in);

void Sort(int arr[] , int nArr);

int dijkstra();

void SetColor(int ForgC);

int main()
{
    system("COLOR F0");

    printf("my matrix is:\n");

    int N = 4;

    int array[4][4] = {{0,5,6,8},
                       {5,0,9,9},
                       {6,9,0,4},
                       {8,9,4,0}};

    printf("     %c\t\t %c\n     %c  0 5 6 8  %c\n     %c  5 0 9 9  %c\n     %c  6 9 0 4  %c\n     %c  8 9 4 0  %c\n     %c\t\t %c\n",
           218, 191, 179, 179, 179, 179, 179, 179, 179, 179, 192, 217);


//        int N = 5;

//        int array[5][5] = {{0,2,3,3,0},
//                           {2,0,4,5,4},
//                           {3,4,0,1,1},
//                           {3,5,1,0,2},
//                           {0,4,1,2,0}};

//        printf("     %c\t\t   %c\n     %c  0 2 3 3 0  %c\n     %c  2 0 4 5 4  %c\n     %c  3 4 0 1 1  %c\n     %c  3 5 1 0 2  %c\n     %c  0 4 1 2 0  %c\n     %c\t\t   %c\n",
//               218, 191, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 192, 217);

//    int N = 5;

//    int array[5][5] = {{0,2,1,2,0},
//                       {2,0,3,0,4},
//                       {1,3,0,3,1},
//                       {2,0,3,0,2},
//                       {0,4,1,2,0}};
//    printf("     %c\t\t   %c\n     %c  0 2 1 2 0  %c\n     %c  2 0 3 0 4  %c\n     %c  1 3 0 3 1  %c\n     %c  2 0 3 0 2  %c\n     %c  0 4 1 2 0  %c\n     %c\t\t   %c\n",
//           218, 191, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 192, 217);


    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196
           , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
           ,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    printf("\n");
    printf("by Kruskal algorithm:\n\n");
    printf("twe now have our ");
    SetColor(12);
    printf("MST!");
    SetColor(0);
    printf("\n");
    int weightK = 0;
    printf("Weight of ");
    SetColor(12);
    printf("M");
    SetColor(0);
    printf("inimum ");
    SetColor(12);
    printf("S");
    SetColor(0);
    printf("panning ");
    SetColor(12);
    printf("T");
    SetColor(0);
    printf("ree = %d", kruskal((int*) array , N , weightK));
    //    int weightP = 0;
    //    printf("\n%d", prim((int*) array , N , weightP , 1));
    printf("\n\n\n");
    return 0;
}

int kruskal(int *array , int N , int weight)
{
    int nArr = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            if(*(array + (i * N) + j) != 0)
            {
                nArr++;
            }
        }
    }
    struct info arr[nArr];
    for(int k = 0; k < nArr; )
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = i; j < N; j++)
            {
                if(*(array + (i * N) + j) != 0)
                {
                    arr[k].weight = *(array + (i * N) + j);
                    arr[k].iPos = i;
                    arr[k].jPos = j;
                    k++;
                }
            }
        }
    }
    arraySort(arr , nArr);
//        for(int i = 0; i < nArr; i++)
//        {
//            printf("[%d%d] = %d", arr[i].iPos, arr[i].jPos, arr[i].weight);
//        }
//        printf("\n\n");
    //********************** Kruskal **********************//
    int visitedN;
    if(N % 2 == 1)
    {
        visitedN = N - 1;
    }
    else
    {
        visitedN = N;
    }
    int i = 0;
    do
    {
        if(arr[i].iPos != -1 && arr[i].jPos != -1) // No CYCLE
        {
            weight += arr[i].weight;
            for(int m = 0; m < nArr; m++) // No CYCLE
            {
                if(arr[m].iPos == arr[i].iPos)
                {
                    arr[m].iPos = -1;
                }
                else if(arr[m].iPos == arr[i].jPos)
                {
                    arr[m].iPos = -1;
                }
                else if(arr[m].jPos == arr[i].iPos)
                {
                    arr[m].jPos = -1;
                }
                else if(arr[m].jPos == arr[i].jPos)
                {
                    arr[m].jPos = -1;
                }
            }
            visitedN--;
        }
        i++;
    } while (visitedN > 1);
    return weight;
}

int prim(int *array , int N , int weight , int in)
{
    int num = 0;
    int input[N];
    int nArr = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            if(*(array + (i * N) + j) != 0)
            {
                nArr++;
            }
        }
    }
    struct info arr[nArr];
    for(int k = 0; k < nArr; )
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = i; j < N; j++)
            {
                if(*(array + (i * N) + j) != 0)
                {
                    arr[k].weight = *(array + (i * N) + j);
                    arr[k].iPos = i;
                    arr[k].jPos = j;
                    k++;
                }
            }
        }
    }

    //    for(int i = 0; i < nArr; i++)
    //    {
    //        printf("%d%d ", arr[i].iPos, arr[i].jPos);
    //    }
    //    printf("\n");

    arraySort(arr , nArr);
    //********************** Prim **********************//
    int visitedN = N;
    int next = in;
    int check;
    do
    {
        check = 0;
        if(next != -1)
        {
            input[num] = next;
            num++;
        }
        Sort(input , num);
        //        printf("\n\n");
        //        for(int i = 0; i < nArr; i++)
        //        {
        //            printf("%d%d ", arr[i].iPos, arr[i].jPos);
        //        }
        //        printf("\n\n");
        for(int i = 0; i <= num; i++)
        {
            for(int k = 0; k < nArr; k++)
            {
                if(arr[k].iPos == input[i] || arr[k].jPos == input[i])
                {
                    weight += arr[k].weight;
                    visitedN--;
                    if(arr[k].iPos == input[i])
                    {
                        next = arr[k].jPos;
                        //                        printf("[[[]]]next=%d", next);
                        for(int m = 0; m < nArr; m++) // No CYCLE
                        {
                            if(arr[m].iPos == arr[k].iPos)
                            {
                                arr[m].iPos = -1;
                            }
                            else if(arr[m].jPos == arr[k].iPos)
                            {
                                arr[m].jPos = -1;
                            }
                        }
                        //arr[k].jPos = -1;
                        break;
                    }
                    else if(arr[k].jPos == input[i])
                    {
                        next = arr[k].iPos;
                        //                        printf("[[]]next=%d", next);
                        for(int m = 0; m < nArr; m++) // No CYCLE
                        {
                            if(arr[m].iPos == arr[k].jPos)
                            {
                                arr[m].iPos = -1;
                            }
                            else if(arr[m].jPos == arr[k].jPos)
                            {

                                arr[m].jPos = -1;
                            }
                        }
                        //arr[k].iPos = -1;
                        break;
                    }
                    check = 1;
                }
            }
            if(check) break;
        }
        //        printf("\n\n");
        //        for(int i = 0; i < nArr; i++)
        //        {
        //            printf("%d%d ", arr[i].iPos, arr[i].jPos);
        //        }
        //        printf("\n\n");
    } while (visitedN > 0);
    return weight;
}

void arraySort(struct info arr[] , int nArr)
{
    struct info temp;
    int i, j;
    for(i = 0; i < nArr; i++)
    {
        temp = arr[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(temp.weight < arr[j].weight)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

void Sort(int arr[] , int nArr)
{
    int temp;
    int i, j;
    for(i = 0; i < nArr; i++)
    {
        temp = arr[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(temp < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
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
