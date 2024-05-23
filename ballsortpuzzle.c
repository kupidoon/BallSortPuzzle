#include <stdio.h>
#include <stdlib.h>
#include "ballsortpuzzle.h"

void generator(const int rows, const int columns, char field[rows][columns])
{
    int spaceCol1 = rand() % columns;
    int spaceCol2 = rand() % columns;
    while (spaceCol1 == spaceCol2)
    {
        spaceCol2 = rand() % columns;
    }

    for (int i = 0; i < rows; i++)
    {
        field[i][spaceCol1] = ' ';
        field[i][spaceCol2] = ' ';
    }

    char symbols[10] = {'*', '+', '^', '@', '&', '#', '$', '%', '-', '='};
    int countArr[10];
    for (int i = 0; i < 10; i++)
    {
        countArr[i] = 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j == spaceCol1 || j == spaceCol2)
            {
                continue;
            }
            int index = rand() % (columns - 2);
            if (countArr[index] < rows)
            {
                countArr[index]++;
                field[i][j] = symbols[index];
            }
            else
            {
                while (1)
                {
                    index = rand() % (columns - 2);
                    if (countArr[index] < rows)
                    {
                        countArr[index]++;
                        field[i][j] = symbols[index];
                        break;
                    }
                }
            }
        }
    }
}

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y)
{
    // x == y
    // не выходить за границы
    // разные элементы
    // не остался висеть в воздухе
    // проверка на число
    if (x == y || x > columns || y > columns || x < 1 || y < 1) {
        // some error
        printf("Error");
    } else {
        int indexX = -1;
        char tmp = '\0';
        for (int i = 0; i < rows; i++) {
            if (field[i][x-1] != ' ') {
                printf("(%c)", field[i][x-1]);
                tmp = field[i][x-1];
                indexX = i;
                break;
            }
        }
        if (tmp == '\0') {
            printf("Column is empty");
        } else {
            if (field[rows-1][y-1] == ' ') {
                field[rows-1][y-1] = tmp;
                field[indexX][x-1] = ' ';
            } else {
                for (int i = 0; i < rows; i++) {
                    if (i == 0 && field[i][y-1] != ' ') {
                        printf("Column is full");
                        break;
                    }
                    if (field[i][y-1] == tmp) {
                        field[i-1][y-1] = tmp;
                        field[indexX][x-1] = ' ';
                    } else if (field[i][y-1] != ' ') {
                        printf("[%c-%c]", tmp, field[i][y-1]);
                        printf("Symbols not same");
                        break;
                    }
                }
            }
        }
    }
}


void propusk()
{
    for (int i = 0; i < 15; i++)
    {
        printf("\n");
    }
}

void game_field(const int rows, const int columns, char field[rows][columns])
{

    for (int i = 0; i < rows; i++)
    {
        if (i < rows)
        {
            printf(" %i |", i + 1);
        }

        for (int j = 0; j < columns; j++)
        {
            printf(" %c |", field[i][j]);
        }

        printf("\n");
        if (i == rows - 1)
        {
            int counter = 0;
            
            
            for (int j = 0; j < columns; j++)
            {

                if (counter < 1)
                {
                    printf("     %i", j + 1);
                }
                else
                {
                    printf("   %i", j + 1);
                }
                counter++;
            }
        }
    }
}

bool check(const int rows, const int columns, char field[rows][columns])
{
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows - 1; i++) {
            if (field[i][j] != field[i+1][j]) {
                return false;
            }
        }
    }
    return true;
}

void ball_sort_puzzle(const int rows, const int columns, char field[rows][columns],  int x,  int y)
{
    do{
    printf("\n");
    scanf("%d", &x);
    printf("\n");
    scanf("%d", &y);
    down_possible(rows, columns, field,  x,  y);
    propusk();
    game_field(rows, columns, field);
    
    }while(check(rows ,columns, field) != true);
}
