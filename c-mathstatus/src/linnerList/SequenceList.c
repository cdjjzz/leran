//
// Created by Administrator on 2023/9/6.
//

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C
#include "linnerList/SequenceList.h"  //**▲02 线性表头文件**//

/*初始化内存*/
Status InitList_Sq(SqList *L)
{
    //申请内存，内存大小 LIST_INIT_SIZE*sizeof(LElemType)
    L->elem = (LElemType*)malloc(LIST_INIT_SIZE*sizeof(LElemType));
    if(!(L->elem)){
        exit(OVERFLOW); 				//分配内存失败
    }
    L->length = 0;					//初始化顺序表长度为0
    L->listsize = LIST_INIT_SIZE;		//顺序表初始内存分配量
    return OK;							//初始化成功
}

/*清空*/
void ClearList_Sq(SqList *L)
{
    /*将当前长度设置为0，已占用的内存内容并没有清除，允许后续覆盖*/
    L->length = 0;
}

/*销毁，设置长度为0，并清空内存*/
void DestroyList_Sq(SqList *L)
{
    free(L->elem);
    L->elem = NULL;					//释放内存后置空指针
    L->length = 0;
    L->listsize = 0;
}
/*判断释放为空，L为结构体对象 */
Status ListEmpty_Sq(SqList L)
{
    return 	L.length==0 ? TRUE : FALSE;
}
/*返回线性表长度*/
int ListLength_Sq(SqList L)
{
    return L.length;
}
/*用e接收顺序表L中第i个元素，调用此方法后 e的值将变成i元素的值，这是指针 不需要返回 */
Status GetElem_Sq(SqList L, int i, LElemType *e)
{
    if(i<1 || i>L.length)
        return ERROR;					//i值不合法
    else
        *e = L.elem[i-1];

    return OK;
}
/*(07)算法2.6：返回顺序表L中首个与e满足Compare关系的元素位序
 * Compare 函数名，需要两个参数，函数返回int，可以用函数指针替代
 * */
int LocateElem_Sq(SqList L, LElemType e, Status(Compare)(LElemType, LElemType))
{
    int i = 1;							//i的初值为第一个元素的位序
    while(i<=L.length && !Compare(e, L.elem[i-1]))
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}
/*用pre_e接收cur_e的前驱*/
Status PriorElem_Sq(SqList L, LElemType cur_e, LElemType *pre_e)
{
    int i = 1;
    if(L.elem[0]!=cur_e)				//第一个结点无前驱
    {
        while(i<L.length && L.elem[i]!=cur_e)
            ++i;
        if(i<L.length)
        {
            *pre_e = L.elem[i-1];
            return OK;
        }
    }
    return ERROR;
}
/*用next_e接受cur_e的后驱节点*/
Status NextElem_Sq(SqList L, LElemType cur_e, LElemType *next_e)
{
    int i = 0;
    while(i<L.length && L.elem[i]!=cur_e)
        ++i;
    if(i<L.length-1)					//最后一个结点无后继
    {
        *next_e = L.elem[i+1];
        return OK;
    }
    return ERROR;
}

/*在顺序表L的第i个位置上插入e*/
Status ListInsert_Sq(SqList *L, int i, LElemType e)
{
    //q为要插入的节点
    LElemType *p, *q;
    if(i<1 || i>L->length+1){
        return ERROR;					//i值不合法
    }
    if(L->length >= L->listsize)	//若存储空间已满，需开辟新空间
    {
        /*newbase 新开辟的空间地址*/
        LElemType *newbase = (LElemType*)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(LElemType));
        if(!newbase)
            exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    //elem是int指针，+i 就是跳过i个int（sizeof (int) 64位系统默认为4字节） 大小空间，如 elem 初始地址0000，当i=0 q指向地址为0000，当i=1 q指向地址0004 ，当i为2 q指向 0008 通过连续地址 顺序存放，数组也是如此
    q = L->elem+i-1;				//q为插入位置
    for(p=L->elem+L->length-1; p>=q; --p){
        *(p+1) = *p;					//插入位置及之后的元素右移，此处用*是将原本位置p的内容设置到位置p+1 上面
    }
    *q = e;								//插入e
    L->length++;						//表长增1
    return OK;
}
/*删除元素*/
Status ListDelete_Sq(SqList *L, int i, LElemType *e)
{
    LElemType *p, *q;
    if(i<1 || i>L->length){
        return ERROR;					//i值不合法
    }
    p = L->elem-1;				//p为被删除元素的位置
    *e = *p;//改变值，不是地址
    q = L->elem+L->length-1; 		//表尾元素位置
    for(++p; p<=q; ++p){
        *(p-1) = *p;					//被删元素之后的元素左移
    }
    L->length--;						//表长减1
    return OK;
}
/*用visit函数访问顺序表L*/
Status ListTraverse_Sq(SqList L, void(Visit)(LElemType))
{
    int i;
    for(i=0; i<L.length; i++){
        Visit(L.elem[i]);
    }
    return OK;
}

/*求并集*/
void Union(SqList *La, SqList Lb)
{
    int La_len, Lb_len;
    int i;
    LElemType e;

    La_len = ListLength_Sq(*La);			//求顺序表长度
    Lb_len = ListLength_Sq(Lb);
    for(i=1; i<=Lb_len; i++)
    {
        GetElem_Sq(Lb, i, &e);//取Lb中第i个元素赋给e
        if(!LocateElem_Sq(*La, e, equal)){
            //若e不在La中则插入
            ListInsert_Sq(La, ++La_len, e);
        }
    }
}

Status equal(LElemType e1, LElemType e2)
{
    return e1==e2 ? TRUE : FALSE;
}

#endif
