/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Dynamic_Array.h
* 文件标识：
* 摘 要：对动态数组类型进行创建，操作。
*
* 当前版本：1.0
* 作 者：刘鹏
* 完成日期：2018年5月5日
*
* 预期版本：加入切片器功能
*/

#pragma once

#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stdlib.h>
#include <stdio.h>

#include "func.h"

#define FIND_MISSING            -3          // No such element
#define DYNAMIC_ARRAY_FULL      -2          // Hashmap is full
#define DYNAMIC_ARRAY_OMEM      -1          // Out of Memory
#define DYNAMIC_ARRAY_OK         0          // OK

// Function_dynamic_array is a pointer to a function that can take one any arguments
// and return an integer represents the value of some member.
typedef double(*Function_dynamic_array)(any);

// dynamic array ,can rise ans shorten itself automatically
typedef struct Dynamic_Array {
    any *A;                     // low level pointer, array of poiners
    int capacity;               // whole capacity
    int n;                      // used capacity
} Dynamic_Array;

// Create a new empty dynamic array.
extern Dynamic_Array *Dynamic_Array_init();

// Get the element located in n.
// Take care, n is the natural location, so it need to minus 
// one during the locating process.
extern any Dynamic_Array_get_Element(Dynamic_Array *d, int n);

// Output this dynamic array as a normal array.
// Function_dynamic_array can get the value of some address,
// and c represents the output auguments, for example
// c is d represents "%d" and s represents "%s".
extern void Dynamic_Array_print(Dynamic_Array *d, Function_dynamic_array f, char c);

// double the capacity of this data structure.
extern void Dynamic_Array_resize(Dynamic_Array *D);

// Add one more element to the given dynamic array
extern void Dynamic_Array_append(Dynamic_Array *D, any e);

// Generate a new dynamic array to contain the answer, the source dynamic array
// won't be changed.
// The index of dynamic array begins from 1 rather zero.
extern Dynamic_Array *Dynamic_Array_quick_Sort(Dynamic_Array *a, Function_dynamic_array f);

// Find the minimum value's index.
extern int Dynamic_Array_min(Dynamic_Array *d, Function_dynamic_array f);

// Find the maximal value's index.
extern int Dynamic_Array_max(Dynamic_Array *d, Function_dynamic_array f);

// Return the element stored in a node of a dynamic array.
double get_double(any e) {
    return *(double *)e;
}

#endif __DYNAMIC_ARRAY_H__