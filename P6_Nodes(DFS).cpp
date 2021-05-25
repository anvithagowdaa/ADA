
#include<stdio.h>
int a[10][10],vis[10],n;
void dfsAlgo(int v)
{
    int i;
    vis[v]=1;
    printf("The vertex visited: %d\n",v);
    for(i=1;i<=n;i++)
    {
        if(a[v][i]==1 && vis[i]==0)
        {
            dfsAlgo(i);
        }
    }
}

void main()
{
    int i,j,src;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("\n\nEnter the adjacency matrix: \n");
    for(i=1;i<=n;i++)
    {
        printf("Enter the elements of row %d: ",i);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
        vis[i]=0;
    printf("Enter the source vertex: ");
    scanf("%d",&src);
    printf("\n\nThe vertices reachable from %d are: \n",src);
    dfsAlgo(src);
    for(i=1;i<=n;i++){
        if(vis[i]==0){
            printf("\nThe graph is not connected");
            return;
        }
    }
    printf("\nThe graph is connected\n");
}
