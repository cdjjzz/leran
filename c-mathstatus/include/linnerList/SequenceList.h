//
// Created by Administrator on 2023/9/6.
//
/***************************************
 *                                     *
 * 文件夹: ▲02 linnerList\01 SequenceList *
 *                                     *
 * 文件名: SequenceList.h              *
 *                                     *
 * 内  容: 顺序表相关操作列表          *
 *                                     *
 ***************************************/

 /**在一个大的软件工程里面，可能会有多个文件同时包含一个头文件，当这些文件编译链接成一个可执行文件时，就会出现大量“重定义”的错误。在头文件中实用#ifndef #define #endif能避免头文件的重定义*/
#ifndef C_MATHSTATUS_SEQUENCELIST_H
#define C_MATHSTATUS_SEQUENCELIST_H
#include "Status.h"        //src/Status.h//

/* 宏定义 */
#define LIST_INIT_SIZE 100				//顺序表存储空间的初始分配量
#define LISTINCREMENT  10				//顺序表存储空间的分配增量
typedef struct
{
    LElemType *elem;					//存储空间基址（指向第一个结点的指针） int *elem
    int length;							//当前顺序表长度
    int listsize;						//当前分配的存储容量
}SqList;								//顺序表0号单元正常使用


/* 01初始化顺序表函数列表 */
Status InitList_Sq(SqList *L);
/* 02清空顺序表L*/
void ClearList_Sq(SqList *L);
/* 03销毁顺序表L*/
void DestroyList_Sq(SqList *L);
/* 04判断顺序表是否为空L*/
Status ListEmpty_Sq(SqList L);
/* 05返回顺序表L中元素个数*/
int ListLength_Sq(SqList L);
/* 06用e接收顺序表L中第i个元素*/
Status GetElem_Sq(SqList L, int i, LElemType *e);
/* (07)算法2.6：返回顺序表L中首个与e满足Compare关系的元素位序。*/
int LocateElem_Sq(SqList L, LElemType e, Status(*)(LElemType, LElemType));
/*(08)用pre_e接收cur_e的前驱。 */
Status PriorElem_Sq(SqList L, LElemType cur_e, LElemType *pre_e);
/*(09)用next_e接收cur_e的后继。 */
Status NextElem_Sq(SqList L, LElemType cur_e, LElemType *next_e);
/*10)算法2.4：在顺序表L的第i个位置上插入e。*/
Status ListInsert_Sq(SqList *L, int i, LElemType e);
/*(11)算法2.5：删除顺序表L上第i个位置的元素，并用e返回。*/
Status ListDelete_Sq(SqList *L, int i, LElemType *e);
/*(12)用visit函数访问顺序表L。*/
Status ListTraverse_Sq(SqList L, void (Visit)(LElemType));
/* (13)并集函数列表 */
void Union(SqList *La, SqList Lb);
/*14判断两元素是否相等*/
Status equal(LElemType e1, LElemType e2);


#endif //C_MATHSTATUS_SEQUENCELIST_H
