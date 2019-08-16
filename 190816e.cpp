#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

class BTree{
public:
    int num;
    int key[4];
    BTree *child[4];
    BTree *father;
};

BTree* root;

void Initial(BTree* T) {
    T->num = 0;
    for (int i=0; i<4; i++) {
        T->child[i] = NULL;
        T->key[i] = 0;
    }
    T->father = NULL;
    return ;
}

int cmp(int a, int b) {
    return a<b;
}

void Add(BTree* T, int elem) {//add to leafnode
    int now = 0;
//    printf("!! %d %d\n",e
//    for (; now<T->num; now++) {
//        if (elem < T->key[now]) {
//            break;
//        }
//    }
//    for (int i0=T->num; i0>now; i0--) {
//        T->key[i0] = T->key[i0-1];
//    }
//    T->key[now] = elem;
    T->key[T->num++]=elem;
    sort(T->key, T->key+T->num, cmp);
    return;
}

BTree* Split(BTree* T) {//split the 4-node
    if (T->num < 3) return T;
    BTree* T1=(BTree*)malloc(sizeof(BTree)), 
    *T2=(BTree*)malloc(sizeof(BTree)), 
    *T0=(BTree*)malloc(sizeof(BTree));
    
    Initial(T1);
    Initial(T2);
    Initial(T0);
    
    
    T1->num = 1;
    T1->child[0] = T->child[0];
    if(T->child[0])T->child[0]->father=T1;
    T1->child[1] = T->child[1];
    if(T->child[1])T->child[1]->father=T1;
    T1->key[0] = T->key[0];
    
    
    T2->num = 1;
    T2->child[0] = T->child[2];
    if(T->child[2])T->child[2]->father=T2;
    T2->child[1] = T->child[3];
    if(T->child[3])T->child[3]->father=T2;
    T2->key[0] = T->key[2];
    
    
    T0->child[0] = T1;
    T1->father=T0;
    T0->child[1] = T2;
    T2->father=T0;
    T0->num = 1;
    T0->key[0] = T->key[1];
    if (T == root) {
        root = T0;
        T1->father = root;
        T2->father = root;
        return root;
    } else {
        BTree* fath = T->father;
        int now, elem=T->key[0];
        for (now=0; now<fath->num; now++) {
            if (elem < fath->key[now]) {
                break;
            }
        }
        for (int i0=fath->num+1; i0>now; i0--) {
            fath->child[i0] = fath->child[i0-1];
            fath->key[i0] = fath->key[i0-1];
        }
        fath->key[now] = T0->key[0];
        fath->child[now] = T0->child[0];
        fath->child[now+1] = T0->child[1];
        fath->num++;
        T1->father = fath;
        T2->father = fath;
        free(T0);
        return fath;
    }
}

void Insert(BTree* T, int elem, int h) {
    //printf("%016X %d\n",T,elem);
    if (T->num == 3 && h) {//split
        BTree* fath = Split(T);
        //printf("SPL %016X\n",fath);
        Insert(fath, elem, 0);
    } else {
        //printf("find %016X %016X\n",T,T->child[0]);
        if (T->child[0] == NULL) {
            Add(T, elem);
        } else {
            //insert to child
            int flag = 1;
            for (int i=0; i<T->num; i++) {
                if (elem < T->key[i]) {
                    //printf("--\n");
                    if (T->child[i] == NULL) continue;
                    Insert(T->child[i], elem, 1);
                    flag = 0;
                    break;
                }
            }
            if (flag ==1 ) {
                //printf("++\n");
                if (T->child[T->num] != NULL) Insert(T->child[T->num], elem, 1);
            }
        }
    }
    //printf("ret %016X\n",T);
    return;
}

void Print(BTree* T) {
    if (T->num == 0) return;
    for (int i=0; i<T->num; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", T->key[i]);
    }
    printf("\n");
    return;
}

void Travel(BTree* T) {
    if (T == NULL) return;
    Print(T);
    for (int i=0; i<=T->num; i++) {
        if (T == NULL) continue;
        Travel(T->child[i]);
    }
    return;
}

void F(BTree* T){
    if(T == NULL) return;
    for (int i=0; i<=T->num; i++) {
        F(T->child[i]);
    }
    free(T);
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d:\n",i);
        BTree rootnode;
        root = &rootnode;
        Initial(root);
        int n, k;
        scanf("%d", &n);
        for (int j=0; j<n; j++) {
            scanf("%d", &k);
//            k = j;
            Insert(root, k, 1);
        }
        //printf("--------------");
        Travel(root);
        //if (k == 4) printf("%d\n", root->child[1]->num);
    }
    return 0;
}

/*
3
4
4 3 2 1


3
19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21

3
16
6 3 5 7 1 10 2 9 4 8 11 12 13 14 15 16

3
8
6 3 5 7 1 10 2 9
*/
