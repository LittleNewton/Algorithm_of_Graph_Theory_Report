所有Microsoft Word工程文件。

插图参考Figure文件夹，代码与实例参考src中给出的代码。

## All the algorithms

``` javascript
BFS search:                     SEARCH(G, s)    // s is the source node
Subgraphs:                      SUB-GRAPH(G)
Minimal K-tree:                 K-TREE(G, k)    // k is an integer
shortest path:                  PATH(G; s, t)   // default as weighted
shortest-path insert            HSCSP(G; s, t)
path insert (num)               SCSP(G; s, t)   // if weighted -> NP-hard
Eulerian circuit:               FLEURY(G)
Arch connectiviey:              AC(G)
Maximum flow:                   MAXFLOW(G; s, t)
Chinese postman problem:        POSTMAN-ROUTE(G)
Augmented path in bi-graph:     R(B, M)
```

## Algorithm format

``` javascript
Algorithm   ...
Input       ...

Output      ...

Begin

Step 1      ...

Step 2      ... // if the number of steps is more than 2
            ... // just add it recurisively

End
```