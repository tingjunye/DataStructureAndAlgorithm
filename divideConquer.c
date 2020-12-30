#include <stdio.h>
// ordinary method to calculate the sum of an array
int sum(int a[], int len)
{
    int sum = 0;
    for(int i = 0; i<len; i++)
    {
        sum += a[i];
    }
    return sum;
}
// recurrerce to get the sum of an array
int sum_recur(int a[], int len)
{
    int sum = 0;
    if(len == 0) return sum;
    //sum = a[len]+sum_recur(a, len-1);
    return a[len-1]+sum_recur(a, len-1);
}
//二分法求和
int sum_two(int a[], int lo, int hi)
{
    int sum = 0;
    if(lo == hi) return a[lo];
    int mid = (lo + hi)/2;
    return sum_two(a, lo, mid) + sum_two(a, mid+1, hi);
}
//求max2  x1表示最大值下标 x2表示次大值下标 [lo, hi]
/* 直观想法 遍历数组得到最大值 然后再遍历数组得到除最大值以外的最大值 不管好坏情况 都会进行2n-3次比较*/
void maxTwo(int a[], int lo, int hi, int  *x1, int *x2)
{
    int i = 0;
    *x1 = lo; 
    for(i=lo+1;i<=hi;i++)
    {
        if(a[i]>a[*x1]) *x1 = i;
    }
    for(*x2=lo,i=lo+1;i<(*x1);i++) //找到最大值左边的最大值
    {
        if(a[i]>a[*x2]) *x2 = i;
    }
    for(i=(*x1)+1;i<hi;i++)//找到最大值右边的最大值
    {
        if(a[i]>a[*x2]) *x2 = i;
    }
}
/*进一步优化 起始就保留两个flag进行遍历 初始设置x1为最大值 x2为次大值 当其他数大于x2的时候才去跟x1比较 */
void maxTwo_update(int a[], int lo, int hi, int *x1, int *x2)
{
    int i = 0;
    if (a[lo] > a[lo + 1])
    {
        /* code */
        *x1 = lo;
        *x2 = lo + 1;
    }
    else
    {
        *x1 = lo+1;
        *x2 = lo;
    }
    for ( i = lo+2; i < hi; i++)
    {
        if (a[i] > a[*x2])
        {
            /* code */
            if (a[i] > a[*x1])
            {
                *x2 = *x1;
                *x1 = i;
            }
            else
            {
                *x2 = i;
            }
            
        }
        
    }
    
}
//reverse the array
void reverse(int a[], int low, int high)
{
    int temp = 0;
    if(low < high)
    {
        temp = a[low];
        a[low] = a[high];
        a[high] = temp; 
        reverse(a, low+1, high-1);
    }
        
}

int main()
{
    int a[6] = {1,2,3,4,5,6};
    int b[7] = {1,2,3,4,5,6,7};
    /* get sum */
    // int s1 = 0, s2 = 0;
    // s1 = sum(b, 7);
    // s2 = sum(b, 7);
    // printf("total sum %d or %d\n", s1, s2);
    // int s3 = sum_two(a, 0, 5);
    // int s4 = sum_two(b, 0, 6);
    // printf("total sum %d \n", s4);
    int x1 = 0, x2=0;//下标
    // maxTwo(a, 0, 5, &x1, &x2);
    maxTwo_update(a, 0, 5,&x1, &x2);
    printf("max value %d second value:%d\n", a[x1],a[x2]);

    /*reverse */
    // reverse(a, 0, 5);
    // for(int i = 0; i<6;i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // reverse(b, 0, 6);
    // for(int i = 0; i<7;i++)
    // {
    //     printf("%d ", b[i]);
    // }
    // printf("\n");

    return 0;
}