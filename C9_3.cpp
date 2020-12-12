#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>

#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack &s){
    s.top=-1;
}

//判栈空
bool StackEmpty(SqStack S){
    if(S.top==-1){
        return true;
    }
    else{
        return false;
    }
}
//进栈
bool Push(SqStack &S,int x){
    if(S.top==MaxSize-1)
        return false;
    S.data[++S.top]=x;
    //等于 S.top =S.top+1;
    //    S.data[S.top]=x;
    return true;
}

//出栈
bool Pop(SqStack &S, int &x){
    if(S.top==-1){
        return false;
    }
    x=S.data[S.top--];
    return true;
}
//读栈顶元素
bool GetTop(SqStack S, int &x){
    if(S.top==-1)
        return false;
    x =S.data[S.top];
    return true;

}
//链式存储结构栈
 typedef struct StackNode //栈结构
{
	int data;
	struct StackNode *next;
}StackNode;

typedef struct LinkStack //链式结构
{
	StackNode *top;
	int count;
}LinkStack;

int Push(LinkStack *L, int e)						//链栈的入栈操作
{
	StackNode *s;
	s = (StackNode *)malloc(sizeof(StackNode));			//为新加入的元素分配空间
	s->data = e;									//将新加入的元素e赋值给s->data
	s->next = L->top;								//将原先的第一个节点赋值给新加入节点的next
	L->top = s;										//将新节点赋值给top指针
	L->count++;									//元素数量加一
	return 0;
}
int	Pop(LinkStack *L, int *e)					//链栈的出栈操作
{	
	if (L->count == 0)
	{
		printf("当前链栈为空！");					//如果没有元素，返回
		return 0;
	}
	StackNode *s;								//新创建一个节点指针
	s = L->top;									//将要删除的栈顶节点赋值给s
	L->top = s->next;							//将要删除栈顶节点的下一个节点赋值给top
	*e = s->data;
	free(s);								//释放要删除的节点s
	L->count--;							//元素数量减一
	return 0;
}
void Init_LinkStack(LinkStack *L)					//链栈的初始化
{
	L->count = 0;
	L->top = NULL;				//链栈不需要头节点，L->top = NULL 即代表空栈
}
int main(void){
    


    

}