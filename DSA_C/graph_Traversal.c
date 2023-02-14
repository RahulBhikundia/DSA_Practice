#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

/*
Create a node
    - data for node
    - pointer to next node
*/

struct node
{
    int vertex;
    struct node *next;
};

typedef struct node *NP;

/*
Create a Graph 
    - Number of Vertices
    - Adjacency matrix : Keeps a record of which node points to which node
    - visited array : this array helps in traversal of graphs
*/
struct Graph
{
    int numVertices;
    struct node **adjList;
    int *visited;
};

typedef struct Graph *graph;

NP createNode(int vertex)
{
    NP new = (NP)malloc(sizeof(struct node));
    new->vertex = vertex;
    new->next = NULL;
    return new;
}

graph createGraph(int vertex)
{
    graph new = (graph)malloc(sizeof(struct Graph));
    new->numVertices = vertex;
    new->adjList = (struct node **)malloc(vertex * sizeof(struct node*));
    new->visited = (int *)malloc(vertex * sizeof(int));
    for(int i=0;i<vertex;i++)
    {
        new->adjList[i] = NULL;
        new->visited[i] = 0;
    }
    return new;
}

/*
addEdge : Function to create adjacency matric foe the graph
input type : graph (struct Graph *) 
return type : void
*/
void addEdge(graph g,int a,int b)
{
    NP newNode = createNode(b);
    newNode->next = g->adjList[a];
    g->adjList[a] = newNode;        //make the already existing adjoining node as nest node of ll and insert the new adjoining node at front of ll
    newNode = createNode(a);
    newNode->next = g->adjList[b];
    g->adjList[b] = newNode;
}

/*
Time to make a Queue, which will be used in BFS taversal of Graph
*/
struct Queue
{
    int items[SIZE];
    int front;
    int rear;
};

typedef struct Queue *queue;

queue createQueue()
{
    queue q = (queue)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(queue q)
{
    if(q->rear == -1)
        return 1;
    else
            return 0;
}

void enqueue(queue q,int value)
{
    if(q->rear == SIZE-1)
        printf("\nQueue is Full!!");
    else
    {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(queue q)
{
    int item;
    if(isEmpty(q))
    {
        printf("Queue is Empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if(q->front>q->rear)
        {
            printf("Resetting Queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printq(queue q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("\nQueue Contains:\n");
        for(int i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->items[i]);
        }
    }
}

void bfs(graph g,int startv)
{
    queue q = createQueue();
    g->visited[startv] = 1;
    enqueue(q,startv);
    while(!isEmpty(q))
    {
        printq(q);
        int cur = dequeue(q);
        printf("Visited %d\n",cur);
        NP temp = g->adjList[cur];
        while(temp)
        {
            int adjvertex = temp->vertex;
            if(g->visited[adjvertex] == 0)
            {
                g->visited[adjvertex] = 1;
                enqueue(q,adjvertex);
            }
            temp = temp->next;
        }
    }
}

void dfs(graph g,int startv)
{
    struct node *adjlist = g->adjList[startv];
    struct node *temp = adjlist;

    g->visited[startv] = 1;
    printf("Visited %d \n",startv);

    while(temp)
    {
        int connectVertex = temp->vertex;
        if(g->visited[connectVertex] == 0)
        {
            dfs(g,connectVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    graph g = createGraph(6);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,2);
    addEdge(g,1,4);
    addEdge(g,1,3);
    addEdge(g,2,4);
    addEdge(g,3,4);
    printf("BFS Traversal:\n");
    bfs(g,0);
    for(int i=0;i<g->numVertices;i++)
    {
        g->visited[i] = 0;
    }
    printf("\nDFS Traversal:\n");
    dfs(g,0);
    return 0;
}