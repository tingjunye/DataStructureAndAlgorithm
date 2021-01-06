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
/*两栈共享空间
通常是当两个栈的空间需求有相反关系的时候，也就是一个栈增长时另一个栈在缩短的情况，否则两个栈都在不停的增加，很快就会栈满
这是针对两个具有相同数据类型的栈的一个设计上的技巧，如果是不停数据类型的栈就不建议使用
*/
typedef struct 
{
    SElemType data[MAXSIZE];
    int top1; //栈1顶标记
    int top2; //栈2的栈顶标记
}SqDoubleStack;

/*对于两栈共享空间的PUSH方法，我妈除了要插入元素值参数外，还要一个判断是栈1 还是栈2 的栈号参数stackNumber*/
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if( S->top1+1 == S->top2)  //栈满标志
    {
        return ERROR;
    }
    if( stackNumber == 1)  //栈1有元素插入
    {
        S->data[++S->top1] = e; //top1先加1后给元素赋值
        //S->top1++;
        //S->data[S->top1] = e;
    }
    else if (stackNumber == 2)
    {
        S->data[--S->top2] = e; //top2先减1后给数组元素赋值
    }
    return OK;
    
}
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if(stackNumber == 1)
    {
        if(S->top1 == -1)  //栈1为空的标志
        {
            return ERROR;
        }
        *e = S->data[S->top1--];//将栈1的栈顶元素出栈
    }
    else if(stackNumber == 2)
    {
        if(S->top2 == MAXSIZE) //栈2为空的标志
        {
            return ERROR;
        }
        *e = S->data[S->top2++]; //将栈2的栈顶元素出栈
    }
    return OK;
}

