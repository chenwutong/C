#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>

#define MaxSize 10
// typedef struct{
//     int data[MaxSize];
//     int front,rear;
// }SqQueue;

// void InitQueue(SqQueue &Q){
//     Q.rear=Q.front=0;
// }

// bool isEmpty(SqQueue Q){
//     if(Q.rear==Q.front)
//         return false;
//     else
//         return false;
// }
// bool EnQueue(SqQueue &Q,int x){
//     if((Q.rear+1)%MaxSize==Q.front){
//         return false;
//     }
//     Q.data[Q.rear]=x;
//     Q.rear=(Q.rear+1)%MaxSize;
//     return true;
// }
// bool DeQueue(SqQueue &Q,int &x){
//     if(Q.rear==Q.front){
//         return false;
//     }
//     x=Q.data[Q.front];
//     Q.front=(Q.front+1)%MaxSize;
//     return true;
// }

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
    LinkNode *front,*rear;
}LinkQueue;


void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    else 
        return false;
}

void EnQueue(LinkQueue &Q,int x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}

bool DeQueue(LinkQueue &Q,int x){
    if(Q.rear==Q.front){
        return false;
    }
    LinkNode *p =Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.front==p){
        Q.rear=Q.front;
    }
    free(p);
    return true;
}