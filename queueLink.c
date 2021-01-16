#include <stdlib.h>
#include <stdio.h>
#include <sys/malloc.h>
#include <time.h>
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OK 1
typedef int QElemType; //数据元素类型,当前设为int型
typedef int Status; //Status是函数的类型，当前设为int型，其结果是函数结果的状态代码， True代表1 ，False代表0
//队列的链式结构--单链表但是只能尾进头出
typedef struct QNode{
    QElemType data;
    struct QNode *next; 
    
}QNode, *QueuePtr; //队列的链表结构

typedef struct 
{
    QueuePtr front,rear; //队头队尾指针，队头指向莲队列的头结点，队尾指针指向终端结点
}LinkQueue;
//插入元素e为Q的新的队尾元素
Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if(!s) //存储分配失败
        exit(0);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s; //把新结点s赋值给原队尾结点的后继；
    Q->rear = s; //把当前的是设置为队尾结点，rear指向s
    return OK;
}

//出队操作，头结点的后继结点出队，将头结点的后继结点改为它后面的结点，若链表除头结点外只剩一个元素时，则需要将rear指向头结点
Status DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear)//队列为空
        return ERROR;
    p = Q->front->next; //将欲删除的队列头结点暂存给p
    *e = p->data;
    Q->front->next = p->next; //将原队头结点的后继p-》next赋值给头结点的后继
    if(Q->rear == p)//若队列中只有一个元素
        Q->rear = Q->front;
    free(p);
    return OK;
}

