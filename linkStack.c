#include <stdlib.h>
#include <stdio.h>
#include <sys/malloc.h>
#include <time.h>
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OK 1
typedef int SElemType; //数据元素类型,当前设为int型
typedef int Status; //Status是函数的类型，当前设为int型，其结果是函数结果的状态代码， True代表1 ，False代表0
//栈的链式存储
/*定义一个结点类型结构*/
typedef struct StackNode
{
    SElemType data; //存储节点的数据域
    struct StackNode *next; //存储节点的指针域，值为下一个节点的地址
}StackNode, *LinkStackPtr; //LinkStackPtr是一个指向结点的指针，标记每个结点
/*定义一个链栈的结构 有栈顶指针和链栈的长度构成*/
typedef struct LinkStack
{
    LinkStackPtr top; //top是栈顶指针
    int count;
}LinkStack;
//进栈操作
/*先创建一个结点，放元素值，再把这个新结点连到链栈中*/
Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr p =(LinkStackPtr)malloc(sizeof(StackNode)); 
    p->data = e;

    p->next = S->top;//将当前栈顶元素赋值给新结点的直接后继
    S->top = p; //将新的结点p赋值给栈顶指针
    S->count++;
    return OK;
}
//出栈操作
/*若栈不空，则删除栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
/*假设变量p用来存储要删除的栈顶结点，将栈顶指针向下移动一位，最后释放p即可*/
Status Pop(LinkStack *S, SElemType *e)
{
    if(S == NULL )//栈为空
    {
        return ERROR ;
    }
    LinkStackPtr p;
    p = S->top ; //将栈顶结点赋值给p
    *e = p->data; //存储栈顶结点的值
    S->top = p->next; //是得栈顶指针指向栈顶结点的后一结点
    free(p); //释放栈顶结点
    S->count--; //链栈的长度减1
    return OK;

}

