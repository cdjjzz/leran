#include "cursor.h"
#include <stdlib.h>
#include "fatal.h"

/* Place in the interface file */
// 元素的结构体
struct Node
{
    ElementType Element; // int
    Position Next; // PtrToNode
};

struct Node CursorSpace[SpaceSize]; // SpaceSize 100

/* START: fig3_31.txt */
static Position CursorAlloc(void) // 从下面可以推断出，这里是分配空间给新的元素，并且取内存的地方是下面初始化的那块有100个元素大小的区域
{
    Position P; // 这里的Position是int类型的别名

    P = CursorSpace[0].Next; // 最开始时这里是1，也就是第一次取出的内存是0后面的那一块
    CursorSpace[0].Next = CursorSpace[P].Next; // 然后管理内存的头节点就要往后挪一位，当所有的内存被分配完了之后，CursorSpace[ 0 ]会指向它自身，即其Next值为0

    return P; // 返回取出的那一块内存
}

// 释放一个节点的内存
static void CursorFree(Position P) // P就代表了索引，根据这个索引可以找到其元素
{
    // 下面这两行代码就是根据内存的头节点0，将归还的内存放到freelist的最前面
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P; // 释放并归还内存，从放到CursorSpace[0]这一处可以看出，但是问题是如何使用这块归还的内存是一个问题，有一点模糊！！！--> 在测试函数中添加了几个测试部分，分析内存的摆放情况之后就清晰多了！
}
/* END */
// cursorSpace的初始化
// 这里相当于是取出一块内存，所以并没有往里面存数据
// cursorSpace数组里面存放的是Node节点，里面有Element和Next两个成员
// 这里只是初始化Next这一个成员，取内存的时候则是根据数组的索引来
static void InitializeCursorSpace(void)
{
    int i;

    for (i = 0; i < SpaceSize; i++)
        CursorSpace[i].Next = i + 1;
    CursorSpace[SpaceSize - 1].Next = 0;
}

static List MakeEmpty(List L)
{
    if (L != -1)
        DeleteList(L);
    L = CursorAlloc();
    if (L == 0)
        FatalError("Out of memory!");
    CursorSpace[L].Next = 0; // 空链表的头节点指向0，同样指向0的还有内存的最后一块，还有非空链表的最后一个元素
    return L;
}

/* START: fig3_32.txt */
/* Return true if L is empty */
// 判断链表是否为空，判断的方法是看链表的头节点是否指向0
static int IsEmpty(List L)
{
    return CursorSpace[L].Next == 0;
}
/* END */

/* START: fig3_33.txt */
/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
// 判断是否到了表的尽头
static int IsLast(Position P, List L)
{
    return CursorSpace[P].Next == 0; // Next指向了0代表遍历到了表的尽头
}
/* END */

/* START: fig3_34.txt */
/* Return Position of X in L; 0 if not found */
/* Uses a header node */
// 返回表L中的X的位置
static Position Find(ElementType X, List L)
{
    Position P;

/* 1*/      P = CursorSpace[L].Next;
/* 2*/      while (P && CursorSpace[P].Element != X)
/* 3*/          P = CursorSpace[P].Next;

/* 4*/      return P; // 返回的Position P有何用处？其用处就是作为索引，它本身也是通过上一个元素的Next找到的
}
/* END */

/* START: fig3_35.txt */
/* Delete from a list */
/* Assume that the position is legal */
/* Assume use of a header node */

static void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L))  /* Assumption of header use */
    {                      /* X is found; delete it */
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell); // 删除，和普通的链表类似，这里释放内存的方式有些区别
    }
}
/* END */

/* If X is not found, then Next field of returned value is 0 */
/* Assumes a header */

static Position FindPrevious(ElementType X, List L) // 这里根据ElementType来找前一个元素，那么，如果有重复的现象，那么就返回第一次找到的结果
{
    Position P;

/* 1*/      P = L;
/* 2*/      while (CursorSpace[P].Next &&
                   CursorSpace[CursorSpace[P].Next].Element != X)
/* 3*/          P = CursorSpace[P].Next;

/* 4*/      return P;
}

/* START: fig3_36.txt */
/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
/**
 * 插入操作
 * @param X 要插入的元素值
 * @param L 表的头节点
 * @param P 表示现存的表中的一个节点的位置，这里就是将新插入的值插在P的后面
 */
static void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    // 先取出一块内存，也就是分配空间
/* 1*/      TmpCell = CursorAlloc();
/* 2*/      if (TmpCell == 0) // 如果TemCell为0，则意味着当初分配的空间为SpaceSize用到了尽头
/* 3*/          FatalError("Out of space!!!");

/* 4*/      CursorSpace[TmpCell].Element = X;
/* 5*/      CursorSpace[TmpCell].Next = CursorSpace[P].Next;
/* 6*/      CursorSpace[P].Next = TmpCell;
}
/* END */


/* Correct DeleteList algorithm */
// 删除整个表，删除之后头节点变成了空头，头节点里本身的Element的是是没有赋的
static void DeleteList(List L)
{
    Position P, Tmp;

/* 1*/      P = CursorSpace[L].Next;  /* Header assumed */ // 先将第一个节点取出来
/* 2*/      CursorSpace[L].Next = 0; // 然后将链表头归零
    // 循环，把整个表给删除
/* 3*/      while (P != 0)
    {
/* 4*/          Tmp = CursorSpace[P].Next; // 这里并没有把Element给清零，虽然最后并没有什么影响
/* 5*/          CursorFree(P);
/* 6*/          P = Tmp;
    }
}

// 返回头节点，即L这个节点本身
static Position Header(List L)
{
    return L;
}

// 返回第一个节点，即头节点指向的第一个节点
static Position First(List L)
{
    return CursorSpace[L].Next;
}

// 相当于指针往后移动一位
static Position Advance(Position P) // 这里P是任意节点，这个函数的作用就是取出节点的下一个节点，相当于游标往后移动一位，例如，P是L的情况下，CursorSpace[ P ].Next就是取出第一个元素的Position
{
    return CursorSpace[P].Next;
}

// 取出数据
static ElementType Retrieve(Position P)
{
    return CursorSpace[P].Element;
}

// 为了测试，自己后加的函数
static Position getFirstMemory()
{
    return CursorSpace[0].Next;
}




/*****************************测试使用*********************************************/
// 打印表
void
PrintList(const List L)
{
    Position P = Header(L);

    if (IsEmpty(L))
        printf("Empty list\n");
    else
    {
        do
        {
            P = Advance(P);
            printf("%d ", Retrieve(P));
        } while (!IsLast(P, L));
        printf("\n");
    }
}

int test()
{
    List L; // List如果只是证明而不赋值就是NULL
    /*if (L == NULL)
    {
        printf("List为空\n");
    }*/
    Position P;
    int i;

    InitializeCursorSpace();
    L = MakeEmpty(-1); // 不传参也代表NULL
    P = Header(L);
    PrintList(L);

    for (i = 10; i < 20; i++)
    {
        Insert(i, L, P); // L是头节点
        PrintList(L);
        P = Advance(P);
    }
    for (i = 10; i < 20; i += 2) // 隔开一位进行删除，并且删除的都是偶数
    {
        Delete(i, L);
        // 测试删除后释放的内存是否放到正确的位置
        printf("第一块内存：%d \n", getFirstMemory());
    }

    for (i = 10; i < 20; i++)
        if ((i % 2 == 0) == (Find(i, L) !=-1)) // 条件成立的情况： 1. 偶数 && 能找到这个数，然而，上面已经将所有偶数给删除了，所以是不可能为true的；2. 奇数 && 找不到这个数，然而，奇数时可以找到的，所以这个条件也是不成立的
            printf("Find fails\n");

    printf("Finished deletions\n");

    PrintList(L);

    // 测试一下归还后的内存的使用
    Insert(21, L, P);
    PrintList(L);
    Position position = Find(21, L);
    printf("新插入的内存是 %d \n", position);

    DeleteList(L);

    PrintList(L);

    return 0;
}

