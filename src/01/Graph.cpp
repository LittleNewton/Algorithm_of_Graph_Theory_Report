#include "Graph.h"

// Initialize a Vertex, a pointer need to be input.
Vertex Vertex_init(any vertex) {
    Vertex ans = vertex;

    return ans;
}

// Return the element associated with this vertex

// Initialize an Edge, 3 arguments are need
Edge *Edge_init(Vertex origin, Vertex destination, any element) {
    Edge *ans = (Edge *)calloc(1, sizeof(Edge));
    if (!ans) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }

    ans->origin = origin;
    ans->destination = destination;
    ans->element = element;

    return ans;
}

// Get the double-type elements stored in the edge
double Edge_get_element(any e) {
    Edge *temp = (Edge *)e;
    return *(double *)temp->element;
}

// Initialize a Graph
Graph *Graph_init(bool directed) {
    Graph *ans = (Graph *)calloc(1, sizeof(Graph));
    if (!ans) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }
    ans->directed = directed;

    // if directed, incoming not equal to outgoing
    if (directed) {
        ans->incoming = hashmap_new();
        ans->outgoing = hashmap_new();
    }
    else {
        ans->directed = directed;
        ans->outgoing = hashmap_new();
        ans->incoming = ans->outgoing;
    }

    return ans;
}

// Return the vertex that is opposite v on this edge.
Vertex Vertex_opposite(Edge *e, Vertex v) {
    if (v == e->origin) {
        return e->destination;
    }

    return e->origin;
}

// Return true if this is a directed graph; false if undirected.
// Property is based on the original declaration of the graph, not its contents.
bool Graph_is_directed(Graph *g) {
    return g->directed;
}

// Return the number of all vertices of the graph.

// Insert and return a new Vertex with element x.
void Graph_insert_vertex(Graph *g, Vertex v) {
    map_t bucket = hashmap_new();
    hashmap_put(g->outgoing, (char *)v, (void *)bucket);
    if (g->directed == true) {
        map_t bucket_in = hashmap_new();
        hashmap_put(g->incoming, (char *)v, (void **)&bucket_in);
    }
}

// Insert and return a new Edge from u to v with auxiliary element x.
// origin and destination should have been added into the graph.
// Testification of existence has been done in function hashmap_get,
// if cannot find the key, MAP_MISSING would be raisen.
void Graph_insert_edge(Graph *g, Vertex origin, Vertex destination, any element) {
    Edge *e = Edge_init(origin, destination, element);

    map_t tmp;
    hashmap_get(g->outgoing, (char *)origin, (void **)&tmp);

    hashmap_put(tmp, (char *)destination, e);

    // undirected graph just need one step,

    // undirected graph need one more reverse step
    if (!g->directed) {
        Edge *e2 = Edge_init(destination, origin, element);
        map_t tmp2;
        hashmap_get(g->outgoing, (char *)destination, (void **)&tmp2);

        hashmap_put(tmp2, (char *)origin, e2);
    }
}

// Return the edge from u to v, or NULL if not adjacent.
Edge *Graph_get_edge(Graph *g, Vertex origin, Vertex destination) {
    map_t ans;        // pointer to map
    Edge *ans2;       // pointer to edge
    hashmap_get(g->outgoing, (char *)origin, (void **)&ans);
    hashmap_get(ans, (char *)destination, (void **)&ans2);

    return ans2;
}

// Get a submap which contains all the vertices connected with v.
map_t Graph_get_adjacent_Vertices(Graph *g, Vertex v) {
    map_t ans = hashmap_new();

    if (hashmap_get(g->outgoing, (char *)v, (void **)&ans) == MAP_MISSING) {
        return NULL;
    }

    return ans;
}

// Return the number of vertices in the graph.
int Graph_vertex_count(Graph *g) {
    return hashmap_length(g->outgoing);
}

//Return the dynamic array of all vertices of the graph


// Return the number of edges in the graph.
int Graph_edge_count(Graph *g) {
    if (g->directed == false) {
        int ans_count = 0;
        Dynamic_Array *a = hashmap_used_index(g->outgoing);

        int i = 0;
        for (; i < a->n; i++) {
            int index = (int)Dynamic_Array_get_Element(a, i + 1);

            map_t temp = hashmap_select(g->outgoing, index);

            ans_count += hashmap_length(temp);
        }

        ans_count /= 2;

        return ans_count;
    }

    // directed graph needed one more implementation
}