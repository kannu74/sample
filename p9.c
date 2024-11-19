#include <stdio.h>
#include <stdlib.h>

void bfs(int v);
void dfs(int v);
int a[50][50], n, visited[50];
int q[20], front = -1, rear = -1;
int s[20], top = -1, count;

void creategraph()
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}

void bfs(int v)
{
    int i, cur;
    front = rear = -1;
    visited[v] = 1;
    q[++rear] = v;
    printf("Nodes reachable from %d: ", v);
    while (front != rear)
    {
        cur = q[++front];
        for (i = 1; i <= n; i++)
        {
            if (a[cur][i] == 1 && visited[i] == 0)
            {
                q[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void dfs(int v)
{
    int i;
    visited[v] = 1;
    s[++top] = v;
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    }
}

int main()
{
    int ch, start, i;
    creategraph();
    do
    {
        printf("\n1. BFS\n2. DFS\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (i = 1; i <= n; i++)
                visited[i] = 0;
            printf("Enter starting vertex: ");
            scanf("%d", &start);
            bfs(start);
            for (i = 1; i <= n; i++)
            {
                if (!visited[i])
                    printf("\nThe vertex not reachable is %d", i);
            }
            break;
        case 2:
            count = 0;
            for (i = 1; i <= n; i++)
                visited[i] = 0;
            printf("Enter starting vertex: ");
            scanf("%d", &start);
            dfs(start);
            printf("Nodes reachable from %d: ", start);
            for (i = 1; i <= count; i++)
                printf("%d ", s[i]);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 3);

    return 0;
}
