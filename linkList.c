#include <stdlib.h>
#include <stdio.h>
#include <sys/malloc.h>
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OK 1
typedef int ElemType; //数据元素类型,当前设为int型
typedef int Status; //Status是函数的类型，当前设为int型，其结果是函数结果的状态代码， True代表1 ，False代表0
//线性表的链式存储
typedef struct Node
{
    /* data */
    ElemType data; //存储节点的数据域
    struct Node *next; //存储节点的指针域，值为下一个节点的地址
}Node;
typedef struct Node *LinkList; //定义 LinkList 它是一个Node类型的结构体指针 有成员->data ->next
/*假设p是指向线性比表第i个元素的指针，则该节点ai的数据域可以用p->data来表示，p->next是一个指针，指向第i+1个元素，
即指向ai+1de指针，也就是说，如果p->data=ai,那么p->next->data=ai+1
*/
//单链表的读取--获取第i 个元素的数据
/*思路：
1，声明一个结点p指向链表第一个结点，初始化j为1
2，当j<i时，就遍历链表，让p的指针向后移动，不断指向下一结点，j累加1
3，若到链表末尾p为空，则说明第i个元素不存在
4，否则就查找成功，返回结点p的数据
*/
/*初始条件：顺序线性表L已经存在 1《i《List Length（L）*/
/*操作结果：用e返回L中第i个数据元素的值*/
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p; //声明一个结点p
    p = L->next; //p指向链表L的第一个结点  ???那L就是链表的头结点？？？？？？？
    j = 1; //j 是计数器
    while(p && j<i)  //p不为空 或者计数器j还没有等于i时，循环继续
    {
        p = p->next; //p向后移 指向下一个结点
        ++j; //？？？先++ 即 先取j的值增加它的值，再把它放到寄存器
    }
    if( !p || j>i)
    {
        return ERROR; // 第i个元素不存在
    }
    *e = p->data;
    return OK;
}
/*时间复杂度是O（n） 由于单链表的结构中没有定义表长，所以事先不知道要循环多少次，也不方便用for循环*/
//插入操作---在位置i之前插入一个新的结点数据元素e
/*思路：
1，声明一结点p指向链表第一个结点，初始化j=1作为计数器
2，当j<i时就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1；
3，若到链表末尾p为空，说明第i个元素不存在
4，否则查找成功，****以上都是GetElem的操作******，在系统中生成一个空结点s
5，将数据元素e复制给s->data
6，单链表的标准插入语句 s->next=p->next;p-next=s;  ！！！！千万注意不能颠倒顺序
7,返回成功
*/
/*操作结果：在L中第i个位置插入新的数据元素e，L的长度增加1*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    while(p && j<i)   //寻找第i个结点
    {
        p = p->next;
        ++j;
    }
    if ( !p || j>i)
    {
        return ERROR;  //第i个元素不存在
    }

    s = (LinkList)malloc(sizeof(Node)); //生成新结点
    /*malloc 函数，生成一个新的结点，其类型与Node相同*/
    s->data = e;
    s->next = p->next; //将P的后继结点复制给s的后继
    p->next = s; //将s复制给p的后继
    return OK;
}
//删除结点-----
/*思路：
1，同上，设置一个工作指针p，找到第i个结点为p->next且赋值为q
2，单链表的标准删除语句 p->next = q-next
3, 将q结点中的数据赋值给e，作为返回
4，释放q结点，返回成功*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while(p->next && j<i)  //注意与前面的区别 因为这时候p是i前面的一个结点，p->next是最后一个结点
    {
        p = p->next;
        ++j;
    }
    if( !(p->next) || j>i)
    {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = p->data;
    free(q); //让系统回收此结点，释放内存
    return OK;

}














