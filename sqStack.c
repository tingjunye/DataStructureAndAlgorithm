#include <stdlib.h>
#include <stdio.h>
#include <sys/malloc.h>
//#define LITS_INIT_SIZE 100
#define MAXSIZE 20
#define LISTINCREMENT 10
#define TRUE 1
#define OK 1
#define ERROR 0
#define FALSE 0
typedef int SElemType; //数据元素类型,当前设为int型
typedef int Status; //Status是函数的类型，当前设为int型，其结果是函数结果的状态代码， True代表1 ，False代表0
typedef struct 
{
    SElemType data[MAXSIZE];
    int top; //栈顶标记
}SqStack;

//进栈操作PUSH 输入元素e为新的栈顶元素
Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAXSIZE-1)   //栈满
    {
        return ERROR;
    }
    S->top++; //栈顶标记增加1
    S->data[S->top] = e; //将新插入元素赋值给栈顶空间
    return OK;
}

//出栈操作POP
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == -1)
        return ERROR;
    *e = S->data[S->top]; //将栈顶元素赋值给e
    S->top--; //栈顶标记减1
    return OK;
}