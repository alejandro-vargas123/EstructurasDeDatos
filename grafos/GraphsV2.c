#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 1005

struct edge
{
    int vertex;
/*    int weight; */
    struct edge *next;
};

struct graph
{
    int n_vertex;
    int n_edges;
    struct edge *Adj[MAXV];
};

struct graph *ReadGraph(int vertexes, int edges)
{
    int idVertex, idEdge, v, u;
    struct graph *G;
    struct edge *tempEdge;

    G = (struct graph *)malloc(sizeof(struct graph));

    G->n_vertex = vertexes;
    G->n_edges = edges;

    for(idVertex = 0; idVertex <= G->n_vertex; idVertex++)
    {
        G->Adj[idVertex] = NULL;
    }

    for(idEdge = 1; idEdge <= G->n_edges; idEdge++)
    {
        scanf("%d %d", &v, &u);

        tempEdge = (struct edge *)malloc(sizeof(struct edge));
        tempEdge->vertex = u;
        tempEdge->next = G->Adj[v];
        G->Adj[v] = tempEdge;

        if(v != u)
        {
            tempEdge = (struct edge *)malloc(sizeof(struct edge));
            tempEdge->vertex = v;
            tempEdge->next = G->Adj[u];
            G->Adj[u] = tempEdge;
        }
    }
    return G;
}

void PrintGraph(struct graph *G)
{
    int idVertex;
    struct edge *tempEdge;
    if(G != NULL)
    {
        printf("Representation for graph's adjacent lists: \n");
        for(idVertex=1; idVertex<=G->n_vertex; idVertex++)
        {
            printf("[%d]: ", idVertex);
            tempEdge = G->Adj[idVertex];
            while(tempEdge != NULL)
            {
                printf(" -> %d", tempEdge->vertex);
                tempEdge = tempEdge->next;
            }
            printf(" -> NULL\n");
        }
    }
    else
        printf("Empty Graph.\n");
}

struct graph *DeleteGraph(struct graph *G)
{
    int idVertex;
    struct edge *ActualEdge, *NextEdge;

    for(idVertex=1; idVertex<=G->n_vertex; idVertex++)
    {
        ActualEdge = G->Adj[idVertex];
        while(ActualEdge != NULL)
        {
            NextEdge = ActualEdge->next;
            free(ActualEdge);
            ActualEdge = NextEdge;
        }
    }
    free(G);
    G = NULL;
    return G;
}

int main()
{
    int vertexes, edges, idVertex, idEdge, v, u;
    struct graph *G;
    struct edge *tempEdge;

    while(scanf("%d %d", &vertexes, &edges) != EOF)
    {
        G = ReadGraph(vertexes, edges);
        PrintGraph(G);
        G = DeleteGraph(G);
        PrintGraph(G);
    }
    return 0;
}
