#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXW 25

struct points{
    int x;
    int y;
};



/*void BFS(struct graph *G, int s, int color[], int d[], int pi[])
{
    struct edge *tempEdge;
    int idVertex, u, v, Queue[MAXV], head=1, tail=1;

    color[s] = GRAY;
    d[s] = 0;
    Queue[tail] = s;
    tail++;

    while(head < tail)
    {
        u = Queue[head];
        head++;
        tempEdge = G->Adj[u];
        while(tempEdge != NULL)
        {
            v = tempEdge->vertex;
            if(color[v] == WHITE)
            {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                pi[v] = u;
                Queue[tail] = v;
                tail++;
            }
            tempEdge = tempEdge->next;
        }
        color[u] = BLACK;
    }
}*/





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






void BFS(char Maze[][MAXW], int W, int H, int x_Source, int y_Source){
    int head=1, tail=1, cont=1;
    struct points vec[MAXW*MAXW];
    vec[tail].x = x_Source;
    vec[tail].y = y_Source; //X = columna      Y = Fila
    tail++;
    while(head < tail){
        x_Source = vec[head].x;
        y_Source = vec[head].y;
        Maze[y_Source][x_Source] = '#';
        PrintMaze(Maze, W, H);
        //printf("Punto X: %d\n", x_Source);
        //printf("Punto Y: %d\n", y_Source);
        printf("\n");
        head++;
        if((x_Source - 1) >= 1){ //LADO IZQUIERDO
            if(Maze[y_Source][x_Source - 1] == '.'){
                vec[tail].x = x_Source - 1;
                vec[tail].y = y_Source;
                tail++;
                cont++;
            }
        }
        if((x_Source + 1) <= W){ //LADO DERECHO
            if(Maze[y_Source][x_Source + 1] == '.'){
                vec[tail].x = x_Source + 1;
                vec[tail].y = y_Source;
                tail++;
                cont++;
            }
        }
        if((y_Source - 1) >= 1){ //ARRIBA
            if(Maze[y_Source - 1][x_Source] == '.'){
                vec[tail].x = x_Source;
                vec[tail].y = y_Source - 1;
                tail++;
                cont++;
            }
        }
        if((y_Source + 1) <= H){ //ABAJO
            if(Maze[y_Source + 1][x_Source] == '.'){
                vec[tail].x = x_Source;
                vec[tail].y = y_Source + 1;
                tail++;
                cont++;
            }
        }
    }
    printf("%d\n", cont);
}








int main()
{
    char kingdom[MAXW][MAXW];
    int  T, W, H, idCase, x_Source, y_Source, idRow, idColumn;
    scanf("%d", &T);
    for(idCase=1; idCase<=T; idCase++)
    {
        scanf("%d %d", &W, &H); //W columnas    H Filas
        ReadMaze(kingdom, W, H, &x_Source, &y_Source);
        PrintMaze(kingdom, W, H);
        printf("\n\n\n");
        printf("Numero de tierra\n");
        BFS(kingdom, W, H, x_Source, y_Source);
        //printf("\n%d %d\n", x_Source, y_Source);
    }

    return 0;
}

