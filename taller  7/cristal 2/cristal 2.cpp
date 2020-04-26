#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#define MAXW 50
#define NIL -5

using namespace std;
#define endl '\n'

struct point
{
    int coord_x;
    int coord_y;
};

void ReadMaze(char Maze[][MAXW], int W, int H, int resultados[][MAXW])
{
    char line[MAXW];
    int  idRow, idColumn;

    for(idRow=1; idRow<=H; idRow++)
    {
        scanf("%s", line);
        for(idColumn=1; idColumn<=W; idColumn++)
        {
            Maze[idRow][idColumn] = line[idColumn - 1];
            resultados[idRow][idColumn] = NIL;
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



void PrintMaze2(int Maze[][MAXW], int W, int H)
{
    int  idRow, idColumn;

    printf("\n");

    for(idRow=1; idRow<=H; idRow++)
    {
        for(idColumn=1; idColumn<=W; idColumn++)
        {
            printf("%d\t", Maze[idRow][idColumn]);
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
    int head = 1, tail = 1, kingdomSize = 1, idAdjacence, cont = 0;

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
               (Maze[v.coord_y][v.coord_x] == '.' || Maze[v.coord_y][v.coord_x] == 'C'))
            {
                if(Maze[v.coord_y][v.coord_x] == 'C') cont++;
                Maze[v.coord_y][v.coord_x] = '#';
                Queue[tail] = v;
                tail++;
                kingdomSize++;
            }
        }
    }
    return cont;
}









void BFS(char Maze[][MAXW], int W, int H, int x_Source, int y_Source, int resultados[][MAXW], int diamantes)
{
    struct point Queue[MAXW * MAXW], u, v, movements[5];
    int head = 1, tail = 1, kingdomSize = 1, idAdjacence, cont = 0;

    initializationMovements(movements);
    Maze[y_Source][x_Source] = '#';
    Queue[tail].coord_x = x_Source;
    Queue[tail].coord_y = y_Source;
    tail++;
    //resultados[y_Source][x_Source] = diamantes;

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
               (Maze[v.coord_y][v.coord_x] == '.' || Maze[v.coord_y][v.coord_x] == 'C'))
            {
                if(Maze[v.coord_y][v.coord_x] == 'C') cont++;
                Maze[v.coord_y][v.coord_x] = '#';
                resultados[u.coord_y][u.coord_x] = diamantes;
                Queue[tail] = v;
                tail++;
                kingdomSize++;
            }
        }
    }
}








int main()
{
    //fast i/o;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    char kingdom[MAXW][MAXW];
    char kingdom2[MAXW][MAXW]; //copia para conseguir la cantidad de diamantes
    char kingdom3[MAXW][MAXW];
    int resultados[MAXW][MAXW];
    int  T, W, H, idCase, x_Source, y_Source, idRow, idColumn, result,cont,puntos;
    scanf("%d", &T);
    for(idCase=1; idCase<=T; idCase++)
    {
        scanf("%d %d %d", &W, &H, &puntos);
        //ReadMaze(kingdom, H, W, &x_Source, &y_Source);  //Linea que no se usa
        ReadMaze(kingdom, H, W, resultados); //se manda resultados
        //PrintMaze2(resultados, H ,W); //////////////////////
        //result = BFS_Maze(kingdom, W, H, x_Source, y_Source);
        //printf("Case %d: %d\n", idCase, result);
        printf("Case %d:\n",idCase);
        for(int a=0; a<puntos; a++){
            scanf("%d %d", &x_Source, &y_Source);

            for(int idRow=1; idRow<=W; idRow++) //copiar la matriz original a una copia
            {
                for(int idColumn=1; idColumn<=H; idColumn++)
                {
                    kingdom2[idRow][idColumn] = kingdom[idRow][idColumn];
                    kingdom3[idRow][idColumn] = kingdom[idRow][idColumn];
                }
            }
            //llamar funcion BFS con los puntos que se quieren (modificar la funcion)
            if(resultados[y_Source][x_Source] == NIL){
                result = BFS_Maze(kingdom2, H, W, y_Source, x_Source); //SE TRUCO LOS VALORES (se obtiene la cantidad de diamantes)
                BFS(kingdom3, H, W, y_Source, x_Source, resultados, result);
            }
            //PrintMaze(kingdom2,H, W);
            //PrintMaze2(resultados,H, W);
            printf("%d\n",resultados[y_Source][x_Source]);
        }
        //PrintMaze(kingdom, H, W); //trucado por el ejercicio

    }
    return 0;
}

