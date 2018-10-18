#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void visit(int *visited, int num) {
    visited[num] = 1;
    printf("%d ", num);
}

// 深度优先遍历算法
void DFS(int ph[][10], int *visited, int num) {
    // visited是一个数组，表示该节点有没有被访问
    if(!visited[num]) {
        visit(visited, num);
    }

    for(int i = num + 1; i < 10; i++) {
        if(ph[num][i] == 1) {
            if(!visited[i]) {
                visit(visited, i);
                DFS(ph, visited, i);
            }
        }
    }
}

int main() {
    int ph[10][10];
    int visited[10] = {0};
    int flag = 0;
    char ch;
    ifstream OpenFile("tu.txt");
    for(int j = 0; j < 10; j++) {
        for(int k = 0 ; k < 10; k++) {
            OpenFile.get(ch);
            ph[j][k] = (int)ch - 48;
        }
    }
    cout << "本图邻接矩阵为：" << endl;
    for(int j = 0; j < 10; j++) {
        for(int k = 0; k < 10; k++) {
            cout << ph[j][k] << "   ";
        }
        cout << endl;
    }
    cout << "本图的连通分支包含的节点如下：" << endl;
    for(int j = 0; j < 10; j++) {
        if(!visited[j]) {
            DFS(ph, visited, j);
            cout << endl;
            flag++;
        }
    }

    cout << "本图连通分支有 " << flag <<" 个。" << endl;

    OpenFile.close();
}