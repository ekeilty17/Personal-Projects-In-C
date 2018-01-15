const int MAXV = 1000; /*maximum number of vertices*/

struct edgeNode {
    int y;                  /* adjacency info */
    int weight;             /* edge weight, if any */
    struct edgeNode *next;  /* next edge in list */
};
typedef struct edgeNode edgeNode;

struct graph {
    edgeNode *edges[MAXV+1];    /* adjacency info */
    int degree[MAXV+1];         /* outdegree of each vertex */
    int nvertices;              /* number of vertices in graph */
    int nedges;                 /* number of edges in graph */
    bool directed;              /* is the graph directed? */
};
typedef struct graph graph;

int init(graph *g, bool directed)
{
    int i = 0;
    if (g == NULL)
    {
        return -1;
    }
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    for (i=1; i<=MAXV; i++) 
    {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
    return 0;
}

int insert_edge(graph *g, int x, int y, bool directed)
{
    edgeNode *p = NULL;
    if (g == NULL)
    {
        return -1;
    }
    p = (edgeNode *)malloc(sizeof(edgeNode));
    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;
    g->degree[x] += 1;
    if (directed == FALSE)
    {
        insert_edge(g,y,x,TRUE);
    }
    else
    {
        g->nedges += 1;
    }
    return 0;
}

int read(graph *g, bool directed)
{
    int i = 0;
    int m = 0;      /* number of edges */
    int x = 0;      /* vertices in edge (x,y) */
    int y = 0;
    if (g == NULL)
    {
        return -1;
    }

    i=init(g, directed);
    scanf("%d %d",&(g->nvertices),&m);
    for (i=1; i<=m; i++)
    {
        scanf("%d %d",&x,&y);
        insert_edge(g,x,y,directed);
    }
}

int print_graph(graph *g)
{
    int i = 0;
    edgeNode *p = NULL;
    if (g == NULL)
    {
        return -1;
    }
    for (i=1; i<=g->nvertices; i++) 
    {
        printf("%d: ",i);
        p = g->edges[i];
        while (p != NULL) 
        {
            printf(" %d",p->y);
            p = p->next;
        }
        printf("\n");
    }
    return 0;
}
