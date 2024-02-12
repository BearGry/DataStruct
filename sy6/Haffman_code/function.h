//
// Created by xiaodian& on 2022/11/18.
//

#ifndef HAFFMAN_CODE_FUNCTION_H
#define HAFFMAN_CODE_FUNCTION_H

#include "iostream"
#include "fstream"
#define ENDLESS INT32_MAX

using namespace std;

typedef struct {
    int data;
    int weight;
    int parent,lchild,rchild;
}node;
typedef string haffmancode;

void find(int & min1, int & min2, node haffman[], int end);
void make_haffmancode(haffmancode code[], node haffman[], int node, char path[], int d);
void translate(const node *, const int &);

#endif //HAFFMAN_CODE_FUNCTION_H
