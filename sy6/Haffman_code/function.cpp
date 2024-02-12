//
// Created by xiaodian& on 2022/11/18.
//
#include "function.h"
//找现有的结点中权值最小的且没有双亲的两个结点的函数
void find(int & min1, int & min2, node haffman[], int end)
{
    //假设两个最小的为endless便于初始化
    min1 = min2 = ENDLESS;
    int i;
    //在可找范围内找出头两个没有双亲的作为假使最小和次小
    for(i=0; i<=end; i++){
        node t = haffman[i];
        if(t.parent == -1){
            if(min1 == ENDLESS){
                min1 = i;
                continue;
            }
            if(min2 == ENDLESS){
                min2 = i;
                break;
            }
        }
    }
    if(haffman[min1].weight > haffman[min2].weight)
        swap(min1,min2);

    //接着遍历，遇到比最小还小的更新最小和次小，仅比次小小的更新次小
    //这种寻找的复杂度为O（n）
    for(i++; i<=end; i++){
        node t = haffman[i];
        if(t.parent == -1){
            if(t.weight <= haffman[min1].weight){
                min2 = min1;
                min1 = i;
            }
            else if(t.weight < haffman[min2].weight)
                min2 = i;
        }
    }
}

void make_haffmancode(haffmancode code[], node haffman[], int node, char path[], int d)
{
    if(haffman[node].lchild == -2){
        path[d] = '\0';
        code[haffman[node].data] = path;
        return;
    }
    path[d] = '0';
    make_haffmancode(code,haffman,haffman[node].lchild,path,d+1);
    path[d] = '1';
    make_haffmancode(code,haffman,haffman[node].rchild,path,d+1);
}

void translate(const node * haffman, const int & num_ch){
    //从文件b译码，写入文件c
    ifstream fin_b;
    fin_b.open("C:\\Users\\xiaodian&\\Desktop\\Experiment\\exp_coding\\sy6\\Haffman_code\\b");
    ofstream fout_c;
    fout_c.open("C:\\Users\\xiaodian&\\Desktop\\Experiment\\exp_coding\\sy6\\Haffman_code\\c");
    char a;
    int t;
    int root = 2*num_ch-2;
    node p = haffman[root];
    while(fin_b>>a){
        if(a == '0')
            t = p.lchild;
        else
            t = p.rchild;
        p = haffman[t];
        if(p.lchild == -2){
            fout_c<<char(p.data+'a');
            p = haffman[root];
        }
    }
    fin_b.close();
    fout_c.close();
}
