#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE]; //�洢˳����е�Ԫ��
    int length;        //˳����к��е�Ԫ�ظ���
} sqlist;
void creat(sqlist &L)
{
    int a;
    printf("������Ҫ������Ԫ�صĸ���:\t");
    scanf("%d", &a);
    for (int i = 0; i < a; i++)

    {
        printf("�������%d��Ԫ��\t", i + 1);
        scanf("%d", &L.data[i]);
        L.length++;
        
    }
}

void show(sqlist L)
{
    int i;
    printf("���Ա��е�Ԫ��Ϊ:\n");
    for (i = 0; i < L.length; i++)
        printf("%d\t", L.data[i]);
    printf("\n");
}
void min_del(sqlist &L){
 
    int min,log=0;
    if(L.length ==0){
        printf("����");
    }
    min = L.data[0];
    for(int i=0;i<L.length;i++){//L.data ʹ�õ��������±� ֻ�и�����һ��
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
