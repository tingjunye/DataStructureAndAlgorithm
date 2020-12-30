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
typedef int ElemType; //数据元素类型,当前设为int型
typedef int Status; //Status是函数的类型，当前设为int型，其结果是函数结果的状态代码， True代表1 ，False代表0
//线性表的顺序存储--一维数组实现
typedef struct  
{
    /* data */
    ElemType data[MAXSIZE]; //用数组存储数据元素，最大值为MAXSIZE
    int length; //线性表的当前长度
}seqList;
/*顺序存储结构的三个属性：
1，存储空间的起始位置：数组data，它的存储位置就是存储空间的存储位置
2，线性表的最大存储容量：数组长度MAXSIZE
3，线性表的当前长度：length */
// 查找---将线性表L中的第i个位置的元素值返回给e
Status GetElem(seqList L, int i, ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)//健壮性：线性表的长度，下标i的控制【1，i】
    {
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;

}
//插入---将线性表L中第i个位置插入元素e 【i，n】位置的所有元素都要往后移动一位
/*思路：
1， 如果插入位置不合理， 抛出异常
2， 如果线性表长度大于数组长度，则抛出异常或动态增加容量
3， 从最后一个元素开始向前遍历到第i个元素，分别将它们往后移动一个位置
4， 将新元素填入位置i处  */
/*插入条件：顺序表已经存在，1《i《ListLength（L）*/
/*操作结果：在L中第i个位置之前插入新的数据元素e 且L的长度增加1*/
Status ListInsert(seqList *L, int i , ElemType e)
{
    int k;
    if (L->length == MAXSIZE) //线性表装满了
    {
        return ERROR;
    }
    if (i<1 || i>L->length+1) //i=length+1的意思是在线性表的最后插入，这种情况是允许的
    {
        return ERROR;

    }
    if (i<=L->length) //插入的值不在表尾
    {
        for(k=L->length;k>=i-1;k--)//从线性表的最后一个到i位置（下标是i-1）的元素都要向后移动一位
        {
            L->data[k+1] = L->data[k]; //把k位置的元素值都给k+1位置的值

        }
    } 
   L->data[i]= e;// 将新元素插入
   L->length++;
   return OK;
}
//删除-----
/*思路：
1，如果删除位置不合理，抛出异常
2，取出删除元素
3，从删除位置元素开始遍历到最后一个元素位置，分别都向前移动一个位置
4，表的长度减1*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
Status ListDelete(seqList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0)
    {
        return  ERROR;
    }
    if (i<1 || i>L->length)
    {
        return ERROR;
    
    }
    *e = L->data[i-1];//第i个元素的下标是i-1
    if(i<L->length)//删除的不是最后位置
    {
        for(k=i;k<L->length;k++)
        {
            L->data[k-1]= L->data[k];
        }
   }
   L->length--;
   return OK;
}
int main()
{
    printf("hello Sequence List\n");
    seqList L;
    ElemType e;
    ListInsert(&L,1,1);
    GetElem(L,1,&e);
    printf("%d\n", e); 

    return 0;
}
