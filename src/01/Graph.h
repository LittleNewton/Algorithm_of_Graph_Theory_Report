/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Graph.h
* 文件标识：见配置管理计划书
* 摘 要：Graph的头文件。
*
* 当前版本：1.0
* 作 者：刘鹏
* 创建日期：2018年6月20日
* 完成日期：2018年6月日
*
* 取代版本：0.9
* 原作者 ：刘鹏
* 完成日期：
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "HashMap.h"
#include "Dynamic_Array.h"
#include "func.h"

#ifndef __GRAPH_H_
#define __GRAPH_H__

typedef double(*Function_graph)(any);

// Lightweight vertex structure for a graph
// All it contained is pointer.
typedef any Vertex;

// Lightweight edge structure for a graph.
// Do not call constructor directly. Use Graph's insert_edge(u, v, x)
typedef struct _Edge {
    Vertex origin;          // trans pointer
    Vertex destination;     // trans pointer
    any element;          // arbitary datatype
} Edge;

// Representation of a simple graph using an adjacency map.
typedef struct _Graph {
    bool directed;          // diagraph or not
    map_t outgoing;         // only create second map for digraph
    map_t incoming;         // use alias for undirected
} Graph;

// Initialize a Vertex, a pointer need to be input.
extern Vertex Vertex_init(any vertex);

// Return the element associated with this vertex

// Initialize an Edge, 3 arguments are need
extern Edge *Edge_init(Vertex origin, Vertex destination, any element);

// Get the double-type elements stored in the edge
// Warning! This function can be called only when the element stored
// in the edge is a double type.
extern double Edge_get_element(any e);

// Initialize a Graph
extern Graph *Graph_init(bool directed);

// Return the vertex that is opposite v on this edge.
extern Vertex Vertex_opposite(Edge *e, Vertex v);

// Return true if this is a directed graph; false if undirected.
// Property is based on the original declaration of the graph, not its contents.
extern bool Graph_is_directed(Graph *g);

// Return the number of all vertices of the graph.

// Insert and return a new Vertex with element x.
extern void Graph_insert_vertex(Graph *g, Vertex v);

// Insert and return a new Edge from u to v with auxiliary element x.
extern void Graph_insert_edge(Graph *g, Vertex origin, Vertex destination, any element);

// Return the edge from u to v, or NULL if not adjacent.
extern Edge *Graph_get_edge(Graph *g, Vertex origin, Vertex destination);

// Get a submap which contains all the vertices connected with v.
extern map_t Graph_get_adjacent_Vertices(Graph *g, Vertex v);

// Return the number of vertices in the graph.
extern int Graph_vertex_count(Graph *g);

//Return the dynamic array of all vertices of the graph

// Return the number of edges in the graph.
extern int Graph_edge_count(Graph *g);

// Return the element stored in some Edge.
double f_get_double(any e) {
    Edge *temp = (Edge *)e;
    return *(double *)(temp->element);
}

#endif __GRAPH_H_