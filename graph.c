#include<stdio.h>
#include<stdlib.h>

struct node
{
    int dest;
    struct node* next;
};

struct AdjList
{
    struct node *head; 
};
 
struct Graph
{
    int v;
    struct AdjList* array;
};

struct node* newnode(int dest)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int v)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->v = v;
 
    graph->array = (struct AdjList*) malloc(v * sizeof(struct AdjList));
 
    int i;
    for (i = 0; i < v; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest){
	struct node* newNode = newnode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newnode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph)
{
    int x;
    for (x = 0; x < graph->v; ++x)
    {
        struct node* pCrawl = graph->array[x].head;
        printf("\n Adjacency list of vertex %d\n head ", x);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main(){
	int size = 5;
	struct Graph *graph = createGraph(size);
	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
	return 0;
}