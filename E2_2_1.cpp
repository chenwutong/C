#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE]; //存储顺序表中的元素
    int length;        //顺序表中含有的元素个数
} sqlist;
void creat(sqlist &L)
{
    int a;
    printf("请输入要创建的元素的个数:\t");
    scanf("%d", &a);
    for (int i = 0; i < a; i++)

    {
        printf("请输入第%d个元素\t", i + 1);
        scanf("%d", &L.data[i]);
        L.length++;
        
    }
}

void show(sqlist L)
{
    int i;
    printf("线性表中的元素为:\n");
    for (i = 0; i < L.length; i++)
        printf("%d\t", L.data[i]);
    printf("\n");
}
void min_del(sqlist &L){
 
    int min,log=0;
    if(L.length ==0){
        printf("出错");
    }
    min = L.data[0];
    for(int i=0;i<L.length;i++){//L.data 使用的是数组下标 只有个数减一个
        printf("%d",i);
        if(min>L.data[i]){
            min=L.data[i];
            log=i;
        }
    }
    printf(" %d %d",min,log);
    for(int i = log;i<L.length-1;i++){
        L.data[i]=L.data[i+1];
    }
    
}
int main()
{
    sqlist sq;
    int i, n, t;
    sq.length = 0;
    creat(sq);
    show(sq);
    min_del(sq);
    show(sq);
    return 0;
}
