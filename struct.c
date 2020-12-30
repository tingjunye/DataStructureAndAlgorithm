#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//关于结构体的使用
/*情景： 图书馆里的书 有四个属性
1， Title
2， Author
3， Subject
4， Book ID*/

//结构体的定义
/*

struct tag{
    member-list
    member-list
    member-list
    ...
}variable-list;
tag 是结构体的标签
member-list是标准的变量定义， 比如 int/float 或者其他有效的变量定义
variable-list 结构变量，定义在结构体的末尾，最后一个分号之前，可以指定一个或多个结构变量
一般来说，tag/member-list/variable-list这三部分至少要出现两个。
*/
typedef struct
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
    int data[10];
    int length;
}books;

void printBook(books *book)
{
    printf("Book Titile:%s\n",book->title);
    printf("Book author :%s\n", book->author);
    printf("Book Subject :%s\n", book->subject);
    printf("Book ID:%d\n", book->book_id);
}

int main()
{
    books book1;
    //strcpy(book1.title,"C语言");
    //strcpy(book1.author,"谭");
    //strcpy(book1.subject,"编程基础");
    //book1.book_id = 1;
    //printBook(&book1);
    int i;
    for (i = 0; i < 10;i++)
    {
        book1.data[i]=i+1;
    }
    book1.length=i;
    for(i=0;i<book1.length;i++)
    {
        printf("%d ",book1.data[i]);
        
    }
    printf("\n");
   
    return 0;
}