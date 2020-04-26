#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXW 25

struct point
{
    int coord_x;
    int coord_y;
};

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


void initializationMovements(struct point movements[])
{
    movements[0].coord_x = 0;
    movements[0].coord_y = 0;
    movements[1].coord_x = 0;
    movements[1].coord_y = -1;
    movements[2].coord_x = 0;
    movements[2].coord_y = 1;
    movements[3].coord_x = -1;
    movements[3].coord_y = 0;
    movements[4].coord_x = 1;
    movements[4].coord_y = 0;
}


int BFS_Maze(char Maze[][MAXW], int W, int H, int x_Source, int y_Source)
{
    struct point Queue[MAXW * MAXW], u, v, movements[5];
    int head = 1, tail = 1, kingdomSize = 1, idAdjacence;

    initializationMovements(movements);
    Maze[y_Source][x_Source] = '#';
    Queue[tail].coord_x = x_Source;
    Queue[tail].coord_y = y_Source;
    tail++;

    while(head < tail)
    {
        u = Queue[head];
        head++;
        for(idAdjacence=1; idAdjacence<=4; idAdjacence++)
        {
            v.coord_x = u.coord_x + movements[idAdjacence].coord_x;
            v.coord_y = u.coord_y + movements[idAdjacence].coord_y;

            if((v.coord_x >= 1 && v.coord_x <= W) &&
               (v.coord_y >= 1 && v.coord_y <= H) &&
               (Maze[v.coord_y][v.coord_x] == '.'))
            {
                Maze[v.coord_y][v.coord_x] = '#';
                Queue[tail] = v;
                tail++;
                kingdomSize++;
            }
        }
    }
    return kingdomSize;
}



int main()
{
    char kingdom[MAXW][MAXW];
    int  T, W, H, idCase, x_Source, y_Source, idRow, idColumn, result;
    scanf("%d", &T);
    for(idCase=1; idCase<=T; idCase++)
    {
        scanf("%d %d", &W, &H);
        ReadMaze(kingdom, W, H, &x_Source, &y_Source);
        result = BFS_Maze(kingdom, W, H, x_Source, y_Source);
        printf("Case %d: %d\n", idCase, result);
/*
        PrintMaze(kingdom, W, H);
*/
    }

    return 0;
}

