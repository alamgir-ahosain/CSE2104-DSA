


#include<stdio.h>
#include<stdlib.h>
struct edge
{
    int u,v,w;
};
void union_set(int x,int y,int parent[])
{
    parent[x]=y;
}
int find(int x,int parent[])
{
    if(parent[x]==-1)
    {
        return x;
    }
    else
    {
        return parent[x]=find(parent[x],parent);
    }
}
void sort_edge(struct edge e[],int ne)
{
    struct edge temp;
    for(int i=1; i<ne; i++)
    {
        for(int j=1; j<ne-i; j++)
        {
            if(e[j].w>e[j+1].w)
            {
                temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
}
void kruskal(struct edge e[],int ne)
{
    int parent[ne+1];
    for(int i=1; i<=ne; i++)
    {
        parent[i]=-1;
    }
    sort_edge(e,ne);
    int  min_cost=0;
    for(int i=1; i<ne; i++)
    {
        int x=find(e[i].u,parent);
        int y=find(e[i].v,parent);
        if(x!=y)
        {
            union_set( x, y, parent);
            min_cost+=e[i].w;
            printf("Edge %d is start from %d to %d and cost %d.\n",i,e[i].u,e[i].v,e[i].w);
        }
    }
    printf("Minimum cost: %d\n",min_cost);

}
int main()
{
    int nv,ne=0;
    scanf("%d",&nv);
    int g[nv+1][nv+1];
    for(int i=1; i<=nv; i++)
    {
        for(int j=1; j<=nv; j++)
        {
            scanf("%d",&g[i][j]);
            if(g[i][j]&&i!=j)
            {
                ne++;
            }
        }
    }
    ne/=2;
    struct edge e[ne+1];
    int k=1;
    for(int i=1; i<=nv; i++)
    {
        for(int j=1; j<=nv; j++)
        {
            if(g[i][j]&&i!=j)
            {
                e[k].u=i;
                e[k].v=j;
                e[k].w=g[i][j];
                g[j][i]=0;
                k++;
            }
        }
    }
    kruskal(e,ne);
}

/*#include <stdio.h>
#include <conio.h>
#define max 999
int cost[25][25], parent[25];
int find(int x)
{
    while (parent[x])

        {
        x = parent[x];
    }
    return x;
}
int Union(int x, int y)
{
    if (x != y)
    {
        parent[y] = x;
        return 1;
    }
    return 0;
}
int main()
{

    int n, min, MinimumCost = 0, u, v, FV, SV, NumberOfEdge = 1, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = max;
        }
    }
    while (NumberOfEdge< n)
    {
        for (i = 1, min = max; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                    FV=i;
                    SV=j;

                }
            }
        }
        // find Parent
        u = find(u);
        v = find(v);
        //Cycle Or Not
        if (Union(u, v)==1)
        {
            printf("(%d %d)=%d \n",FV,SV,min);
            MinimumCost += min;
            NumberOfEdge++;
        }
        cost[FV][SV] = cost[FV][SV] = max;
    }
    printf("MinimumCost :%d", MinimumCost);
}



*/




