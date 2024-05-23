#include <stdio.h>
#include <stdlib.h>
#include "ballsortpuzzle.h"
 
int main ()
{
    int rows, cols;
    printf("Enter rows: ");
    scanf("%d", &rows);
    propusk();
    printf("Enter cols: ");
    scanf("%d", &cols);
    propusk();
    char field[rows][cols];
    
    // call function
    generator(rows, cols, field);
    int x=0;
    int y=0;
     
    game_field(rows, cols, field);
    ball_sort_puzzle(rows, cols, field, x , y );
    
    

    
    
    
    
    
    
    return 0;
}