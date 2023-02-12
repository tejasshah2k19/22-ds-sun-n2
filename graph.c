#include<stdio.h>
#include<stdlib.h>

struct edge
{
    int src, dest, cost;
};

struct graph
{
    int totalVertex; // 5
    // 1 2 3 4 5
    int totalEdges;
    struct edge *e;
};
 
int main()
{
    struct graph g; // total tota
    int i, s, d, c;
    printf("\nEnter total vertex");
    scanf("%d", &g.totalVertex); // 4
    printf("\nEnter total Edges");
    scanf("%d", &g.totalEdges);                                      // 4
    g.totalEdges = g.totalEdges * 2;                                 // 8
    g.e = (struct edge *)malloc(sizeof(struct edge) * g.totalEdges); // 8

    for (i = 0; i < g.totalEdges ; i=i+2)
    {
        printf("\nEnter Src Desc And Cost");
        scanf("%d%d%d", &s, &d, &c);//10 20 4 
        g.e[i].src = s;
        g.e[i].dest = d;
        g.e[i].cost = c;

        g.e[i+1].src = d;
        g.e[i+1].dest = s;
        g.e[i+1].cost = c;
        
         
    }

    printf("\nEnter Node :-> ");
    scanf("%d",&s); 
    // 
     for (i = 0; i < g.totalEdges ; i++)
    {
        if(g.e[i].src == s){
            printf("\n %d(%d)",g.e[i].dest,g.e[i].cost); 
        }
    }

    return 0;
}
