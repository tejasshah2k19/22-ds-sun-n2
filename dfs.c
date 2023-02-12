#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int src, dest, cost;
};
struct vertex
{
    int value;
    int visited;
};
struct graph
{
    int totalVertex; // 5
    // 1 2 3 4 5
    int totalEdges;
    struct edge *e;
    struct vertex *v;
};

struct graph g;
int isVisit(int data)
{

    for (int i = 0; i < g.totalVertex; i++)
    {
        if (data == g.v[i].value && g.v[i].visited == 1)
        {
            return 1;
        }
    }
    return 0;
}
void markVisit(int data)
{
    for (int i = 0; i < g.totalVertex; i++)
    {
        if (data == g.v[i].value)
        {
            g.v[i].visited = 1;
        }
    }
}

void dfs(int d) //50 
{
    int i;
    if (isVisit(d) == 0)
    {
        printf("%d", d); //10 50 60 40 30 20 70
        markVisit(d);    // 10,50,60,40,30,20 70   
        for (i = 0; i < g.totalEdges; i++)
        {
            if (g.e[i].src == d)
            { //
                dfs(g.e[i].dest);//60
            }
        }
    }
}
int main()
{ // total tota
    int i, s, d, c;
    printf("\nEnter total vertex");
    scanf("%d", &g.totalVertex); // 4

    g.v = (struct vertex *)malloc(sizeof(struct vertex) * g.totalVertex);
    for (i = 1; i <= g.totalVertex; i++)
    {
        printf("\nEnter vertex value");
        scanf("%d", &g.v[i].value);
        g.v[i].visited = 0;
    }

    printf("\nEnter total Edges");
    scanf("%d", &g.totalEdges);                                      // 4
    g.totalEdges = g.totalEdges * 2;                                 // 8
    g.e = (struct edge *)malloc(sizeof(struct edge) * g.totalEdges); // 8
    int cnt = 0;
    for (i = 0; i < g.totalEdges; i = i + 2)
    {
        printf("\nEnter Src Desc And Cost");
        scanf("%d%d%d", &s, &d, &c); // 10 20 4
        g.e[i].src = s;
        g.e[i].dest = d;
        g.e[i].cost = c;

        g.e[i + 1].src = d;
        g.e[i + 1].dest = s;
        g.e[i + 1].cost = c;
    }

    printf("\nEnter Node :-> ");
    scanf("%d", &s);
    //
    for (i = 0; i < g.totalEdges; i++)
    {
        if (g.e[i].src == s)
        {
            printf("\n %d(%d)", g.e[i].dest, g.e[i].cost);
        }
    }

    printf("\nDFS");
    printf("%d", g.e->src); // 10
    markVisit(g.e->src);    // 10 1
    dfs(g.e[0].dest);

    return 0;
}
