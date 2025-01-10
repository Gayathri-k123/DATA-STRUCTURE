#include<stdio.h>
int n,graph[10][10],visited[10]={10},indegree[10],i;
void dfs(int node)
{
    printf("%d",node);
    visited[node]=1;
    for(i=1;i<=n;i++)
        
        {
            if(graph[node][i]==1 && !visited[i])
            {
                dfs(i);
            }
        }
   
}
void bfs() {
    int queue[10], front = 0, rear = 0;
    for (int start = 1; start <= n; start++) { // Handle disconnected nodes
        if (!visited[start]) {
            visited[start] = 1;
            queue[rear++] = start;

            while (front < rear) {
                int node = queue[front++];
                printf("%d ", node);

                for (int i = 1; i <= n; i++) {
                    if (graph[node][i] == 1 && !visited[i]) {
                        visited[i] = 1;
                        queue[rear++] = i;
                    }
                }
            }
        }
    }
}
    void topologicalSort()
    {
    int stack[10], top = -1;
    
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            stack[++top] = i;
        }
    }

    while (top != -1)
    {
        int node = stack[top--];
        printf("%d ", node);

        for (int i = 1; i <= n; i++)
        {
            if (graph[node][i] == 1)
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main()
    {
    int i, j, choice;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = 999;  
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }
    while(1)
      {
        printf("\nChoose an algorithm to run:\n");
        printf("1. Depth First Search (DFS)\n");
        printf("2. Breadth First Search (BFS)\n");
        printf("3. Topological Sort\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
               
                printf("Depth First Search (DFS):\n");
                for (i = 1; i <= n; i++) {
                    visited[i] = 0;
                }
                for (i = 1; i <= n; i++) {
                    if (!visited[i]) {
                        dfs(i);
                    }
                }
                printf("\n");
                break;
            case 2:
                printf("Breadth First Search (BFS):\n");
                for (i = 0; i <= n; i++)
                    visited[i] = 0;
                bfs();
                break;
            case 3:
                printf("Topological Sort:\n");
                topologicalSort();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}
    
    
    
    
