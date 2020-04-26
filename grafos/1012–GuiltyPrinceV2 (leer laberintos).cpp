#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXW 25

void ReadMaze(char Maze[][MAXW], int W, int H, int *x_Source, int *y_Source)
{
    char line[MAXW];
    int  idRow, idColumn;

    for(idRow=1; idRow<=H; idRow++)
    {
        scanf("%s", line);
        for(idColumn=1; idColumn<=W; idColumn++)
        {
            Maze[idRow][idColumn] = line[idColumn - 1];
            if(line[idColumn - 1] == '@')
            {
                *x_Source = idColumn;
                *y_Source = idRow;
                Maze[idRow][idColumn] = '.';
            }
        }
    }
}

void PrintMaze(char Maze[][MAXW], int W, int H)
{
    int  idRow, idColumn;

    printf("\n");

    for(idRow=1; idRow<=H; idRow++)
    {
        for(idColumn=1; idColumn<=W; idColumn++)
        {
            printf("%c", Maze[idRow][idColumn]);
        }
        printf("\n");
    }
}



int main()
{
    char kingdom[MAXW][MAXW];
    int  T, W, H, idCase, x_Source, y_Source, idRow, idColumn;
    scanf("%d", &T);
    for(idCase=1; idCase<=T; idCase++)
    {
        scanf("%d %d", &W, &H);
        ReadMaze(kingdom, W, H, &x_Source, &y_Source);
        PrintMaze(kingdom, W, H);
    }

    return 0;
}

