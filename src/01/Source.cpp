/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Source.cpp
* 文件标识：见配置管理计划书
* 摘 要：测试Prim算法
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

/*
* A unit test and example of how to use the simple C hashmap
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "HashMap.h"
#include "Graph.h"
#include "func.h"
#include "Dynamic_Array.h"

#define KEY_MAX_LENGTH (256)
#define KEY_COUNT (1024 * 1024)

int main(int argc, char *argv[]) {

    Graph *g = Graph_init(false);

    char a[] = "A";
    char b[] = "B";
    char c[] = "C";
    char d[] = "D";
    char e[] = "E";
    char f[] = "F";

    Graph_insert_vertex(g, a);
    Graph_insert_vertex(g, b);
    Graph_insert_vertex(g, c);
    Graph_insert_vertex(g, d);
    Graph_insert_vertex(g, e);
    Graph_insert_vertex(g, f);

    double A_B = 1.0;
    double A_C = 5.0;
    double A_D = 100.0;
    double B_C = 1.0;
    double B_F = 1.0;
    double C_E = 6.0;
    double D_E = 2.0;
    double E_F = 7.0;

    Graph_insert_edge(g, a, b, &A_B);
    Graph_insert_edge(g, a, c, &A_C);
    Graph_insert_edge(g, a, d, &A_D);
    Graph_insert_edge(g, b, c, &B_C);
    Graph_insert_edge(g, b, f, &B_F);
    Graph_insert_edge(g, c, e, &C_E);
    Graph_insert_edge(g, d, e, &D_E);
    Graph_insert_edge(g, e, f, &E_F);

    Edge *ans = Graph_get_edge(g, f, e);

    Vertex m = ans->origin;
    printf("The origin Vertex of E(f, e) is %s\n", (char *)m);
    printf("The weight of Edge(f, e) is %3.0f\n", *(double *)ans->element);
    map_t kk;
    hashmap_get(g->outgoing, a, (void **)&kk);

    Dynamic_Array *taken = hashmap_used_index(kk);
    char format = 'f';
    Dynamic_Array_print(taken, get_double, format);
    system("pause");
    return 0;
}