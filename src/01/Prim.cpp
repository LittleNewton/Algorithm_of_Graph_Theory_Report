/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Prim.cpp
* 文件标识：见配置管理计划书
* 摘 要：Prim算法
*
* 当前版本：1.0
* 作 者：刘鹏
* 创建日期：2018年6月25日
* 完成日期：2018年6月26日
*
* 取代版本：
* 原作者 ：刘鹏
* 完成日期：
*/

/*
* A function based on Prim Algorithm to find the minimal spanning tree
* of a undirected graph.
*/

#include "Graph.h"

// Get the Minimal Spanning Tree of a connected graph.
// If the graph is not connected, exception would be raised.
Graph *MST_Prim_Jarnik(Graph *g, Vertex start, Function f) {
    map_t arg;      // make up the parameters hashmap_get fuc needing
    if (MAP_MISSING == hashmap_get(g, (char *)start, &arg)) {
        printf("fatal Error: bad input!\n");
        return NULL;
    }

    Graph *ans = Graph_init(false);             // the answer of this algorithm
    Dynamic_Array *V = Dynamic_Array_init();    // set of vertices have been found

    Dynamic_Array_append(V, (any)start);
    Graph_insert_vertex(ans, start);

    int i;
    int j;
    int Length_of_Graph_in = hashmap_length(g->outgoing);
    Vertex temp;
    map_t temp_map;
    Dynamic_Array *temp_Edge = Dynamic_Array_init();        // set of edges connected with V

    // Generally, loop will stop while len(V) = len(g).
    // If g is not connected, error will be raised.
    while (V->n < Length_of_Graph_in) {
        for (i = 1; i <= V->n; i++) {
            temp = (Vertex)Dynamic_Array_get_Element(V, i);
            temp_map = Graph_get_adjacent_Vertices(g, temp);        // submap
            Dynamic_Array *index = hashmap_used_index(temp_map);    // used slots of the submap

            Edge *tmp;
            int change_memo = temp_Edge->n;
            for (j = 1; j <= index->n; j++) {
                int addr = (int)Dynamic_Array_get_Element(index, j);
                tmp = (Edge *)hashmap_select(temp_map, addr);

                // only if the destination of Edge(tmp) is not 
                // included in the map(G), the appending
                // operation can be done.
                if (hashmap_get(ans->outgoing, (char *)tmp->destination, (void **)&arg) 
                    == MAP_MISSING) {
                    Dynamic_Array_append(temp_Edge, (any)tmp);
                }
            }
        }

        // find the minimal value
        int min_location = Dynamic_Array_min(temp_Edge, f_get_double);
        Edge *min = (Edge *)Dynamic_Array_get_Element(temp_Edge, min_location);
        temp = min->destination;
        Dynamic_Array_append(V, temp);
        Graph_insert_vertex(ans, temp);
        Graph_insert_edge(ans, min->origin, temp, min->element);
    }
    return ans;
}