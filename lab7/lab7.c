#include "lab7.h"

struct Node * insertBST(struct Node * r, struct Data d){
    if(r == NULL){
        struct Node * res = (struct Node *)malloc(sizeof(struct Node));
        res->d = d;
        res->lChild = NULL;
        res->rChild = NULL;
        r = res;
        return r;
    }
    else if(r->lChild == NULL && d.data < r->d.data){
        struct Node * res = (struct Node *)malloc(sizeof(struct Node));
        res->d = d;
        res->lChild = NULL;
        res->rChild = NULL;
        r->lChild = res;
        return r;
    }
    else if(r->rChild == NULL && d.data > r->d.data){
        struct Node * res = (struct Node *)malloc(sizeof(struct Node));
        res->d = d;
        res->lChild = NULL;
        res->rChild = NULL;
        r->rChild = res;
        return r;
    }
    else if(d.data > r->d.data){
        insertBST(r->rChild, d);
        return r;
    }
    else if(d.data < r->d.data){
        insertBST(r->lChild, d);
        return r;
    }
}

void printInOrder(struct Node * r){
    if(r == NULL) return;
    printInOrder(r->lChild);
    printf("%d ", r->d.data);
    printInOrder(r->rChild);
    return;
}

void deleteTree(struct Node * r){
    if(r == NULL) return;
    deleteTree(r->lChild);
    deleteTree(r->rChild);
    free(r);
    return;
}

void reverseOrder(struct Node * r, struct Stack * s){
    if(r == NULL) return;
    reverseOrder(r->rChild, s);
    push(s, r);
    reverseOrder(r->lChild, s);
    return;
}

void printBSTs(struct Node * r1, struct Node * r2){
    struct Stack * stk1 = initializeStack();
    struct Stack * stk2 = initializeStack();
    struct Stack * stk3 = initializeStack();
    struct Node * tempnode1;
    struct Node * tempnode2;
    struct Node * tempnode3;
    reverseOrder(r1, stk1);
    reverseOrder(r2, stk2);
    tempnode1 = pop(stk1);
    tempnode2 = pop(stk2);
    while(isEmpty(stk1) == 0 && isEmpty(stk2) == 0){
        if(tempnode1->d.data > tempnode2->d.data){
            push(stk3, tempnode2);
            tempnode2 = pop(stk2);
        }
        else if(tempnode1->d.data < tempnode2->d.data){
            push(stk3, tempnode1);
            tempnode1 = pop(stk1);
        }
    }
    if(tempnode1->d.data > tempnode2->d.data){
        push(stk3, tempnode2);
        push(stk3, tempnode1);
    }
    else{
        push(stk3, tempnode1);
        push(stk3, tempnode2);
    }
    while(isEmpty(stk1) == 0) push(stk3, pop(stk1));
    while(isEmpty(stk2) == 0) push(stk3, pop(stk2));
    while(isEmpty(stk3) == 0){
        tempnode3 = pop(stk3);
        printf("%d ", tempnode3->d.data);
    }
}