

//____________Adjancy Matrix _____

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

// int a, b, u, v, i, j, ne = 1, n;
// int vis[10] = {0}, mini, mincost = 0, cost[10][10];
int cost[100][100], visi[10000], x, y, n, ne = 1, mincost = 0, i, j;
int main()
{

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        visi[i] = 0;
    }
    visi[1] = true;
    printf("\n");

    while (ne < n)
    {
        long long x, y, mi = 99999;
        for (int i = 1; i <= n; i++)
        {
            if (visi[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!visi[j] && cost[i][j] && cost[i][j] < mi)
                    {
                        mi = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        //    printf("edge %d:(%d %d) cost:%d\n", ne++, x, y, mini);
        printf("(%lld %lld):%lld\n", x, y, mi);
        mincost += mi;
        visi[y] = true;
        ne++;
    }
    printf("MinimumCost:%d\n", mincost);
}
/*
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    vis[1] = 1;
    while (ne < n)
    {
        for (i = 1, mini = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < mini)
                {
                    if (vis[i] != 0)
                    {
                        mini = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (vis[u] == 0 || vis[v] == 0)
        {
            printf("edge %d:(%d %d) cost:%d\n", ne++, a, b, mini);
            mincost += mini;
            vis[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999; // undirected so duitarei change kore disi
    }
    printf("minimum cost :%d", mincost);
}


 */

//         Adjancy list

/*
#include <stdio.h>
#include <conio.h>
int a, b, u, v, V, e, i, j, ne = 1, n;
int vis[10] = {0}, mini, mincost = 0, cost[10][10];
int main()
{
    scanf("%d %d", &V, &e);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cost[i][j] = 999;
        }
    }
    for (int j = 0; j < e; j++)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        // scanf("%d", &cost[m][n]);
        int wt;
        scanf("%d", &wt);
        cost[m][n] = cost[n][m] = wt;

        // printf("%d\n ",cost[m][n]);
    }
    // printf("%d \n",cost[0][1]);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
    vis[0] = 1;

    while (ne < V)
    {

        for (i = 0, mini = 999; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (cost[i][j] < mini)
                {
                    // printf("cost %d \n",cost[i][j]);
                    if (vis[i] != 0)
                    {
                        mini = cost[i][j];
                        a = u = i;
                        b = v = j;
                        //  printf("%d %d %d \n",u,v,cost[u][v]);
                    }
                }
            }
        }
        //printf("\n u=%d %d ... v=%d %d\n", u, vis[u], v, vis[v]);
        if (vis[u] == 0 || vis[v] == 0)
        {
            printf("edge %d:(%d %d) cost:%d\n", ne++, a, b, mini);
            mincost += mini;
            vis[v] = 1;
            //	printf("mini %d ___ minicost %d\n", mini, mincost);
            // printf("visss %d  %d:\n",b,vis[b]);
        }
        cost[a][b] = cost[b][a] = 999;
        // printf("%d %d %d \n",a,b,cost[a][b]);
        //	printf("ne %d %d\n",ne,v);
    }

    printf("minimum :%d", mincost);
}
*/

/*
#include<stdio.h>
#include<stdbool.h>

#define INF 9999999

int G[1001][1001];

int main()
{
    int no_edge;
    int V;
    printf("Enter the number of nodes: ");
    scanf("%d", &V);

    int E;
    int x;
    int y;
    printf("Enter the weights of the edges: (Enter '0' if there is no edge.\n");

    int i, j, w;
    for (i=0; i<V-1; i++)
    {
        for (j=i+1; j<V; j++)
        {
            printf("Weight of (%d,%d): ", i+1, j+1);
            scanf("%d", &w);
            G[i][j] = w;
            G[j][i] = w;
        }
    }

    int selected[V];

    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;

    printf("Edge : Weight\n");

    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }

    return 0;
}

*/