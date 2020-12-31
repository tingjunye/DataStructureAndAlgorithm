#include <stdlib.h>
#include <stdio.h>
#include <sys/malloc.h>
#include <time.h>
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
/*初始条件：线性表L已经存在*/
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
    *e = q->data;
    free(q); //让系统回收此结点，释放内存
    return OK;

}
/*关于线性表的创建，顺序存储结构的创建就是一个数组的初始化，而创建单链表的过程是一个动态生成链表的过程，
即，从空表的初始状态起，依次建立各元素结点，并逐个插入链表*/

/*思路：
1， 声明一个结点p和计数器变量j
2， 初始化一个空链表L
3， 让L的头结点的指针指向NULL，即建立一个带头结点的单链表
4， 循环：
    1）生成一个新结点赋值给p
    2）随机生成一数字赋值给p的数据域p->data
    3)将p插入到头结点与前一结点之间
*/
/*随机产生n个元素的值，建立带表头结点的单链线性表L
（头插法） 始终让新结点在第一的位置*/
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0)); //初始化随机数种子
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL; //建立一个带头结点的单链表
    for(i=0;i<n;i++)
    {
        p = (LinkList)malloc(sizeof(Node)); //生成一个新结点
        p->data = rand()%100+1; //随机生成100以内的数字
        //插入到表头 插入的标准语句
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
/*尾插法---把每次的新结点插在终端结点的后面*/
void CreateListTail(LinkList *L, int n)
{
    LinkList p,r;
    int i;
    srand(time(0));
    (*L) = (LinkList)malloc(sizeof(Node));
    r = *L; //r为指向尾部的结点
    for(i=0;i<n;i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p; //将表尾终端结点的指针指向新结点
        r = p;  //将当前的新结点重新赋值给r 让r保持为终端结点

    }
    //循环结束了，插入的也结束了，最终的表尾结点的最后一个结点的指针域也要置空
    r->next = NULL; //表示当前链表结束
}
//整表删除
/*思路：
1， 声明一个结点p和q
2， 将第一个结点赋值给p
3， 循环：
    1）将下一结点赋值给q；
    2）释放p；
    3）将q赋值给p
*/
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p = (*L)->next; //p指向第一个结点
    while(p) //没到表尾
    {
        q = p->next; 
        free(p);
        p = q;
    }
    (*L)->next = NULL; //头结点的指针域为空
    return OK;
}
void printLinkList(LinkList L)
{
    LinkList p;
    p = L->next; //p指向第一个结点
    while(p) //没到表尾
    {
        printf("%d ",p->data);        
        p = p->next;
    }
    printf("\n");
}
int main()
{
    printf("Helllo Link List\n");
    LinkList L;
    CreateListTail(&L, 10);
    printLinkList(L);
    ElemType e,d;
    GetElem(L, 1, &e);
    printf("get the first data is %d\n", e);
    ListInsert(&L, 1, 20);
    printLinkList(L);
    ListDelete(&L, 1, &d);
    printf("get the delete data is %d\n", d);
    printLinkList(L);
    ClearList(&L);
    
    return 0;
}
























