#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;


// void InitList_Sq(SqList *L,int maxsize=MaxSize){
//     L.data=(int *)malloc(maxsize*sizeof(int));
//     if(!L.data) exit(1);
//     L.length =0;
// }



bool ListInsert(SqList &L,int i ,int e){
    if(i<1||i>L.length+1) 
        return false;
    if(L.length>MaxSize)
        return false;
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
void PrintList(SqList *L){
    for (int i = 0; i < L->length; i++)
    {
        printf("%d",L->data[i]);
    }

}
int main(void){
    SqList MYL;
    char a='Y';
    ListInsert(MYL,1,2);
    

}   