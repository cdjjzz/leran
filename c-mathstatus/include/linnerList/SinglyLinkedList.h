//
// Created by Administrator on 2023/9/7.
//
/*******************************************
 *                                         *
 * 文件夹: ▲02 linnerList\04 SinglyLinkedList *
 *                                         *
 * 文件名: SinglyLinkedList.h              *
 *                                         *
 * 内  容: 单链表相关操作列表              *
 *                                         *
 *******************************************/
#ifndef C_MATHSTATUS_SINGLYLINKEDLIST_H
#define C_MATHSTATUS_SINGLYLINKEDLIST_H

#include "Status.h"        //src/Status.h//
/* 单链表类型定义 */
#ifndef BANKQUEUING_H			/*后续的模拟银行排队算法中，此类型需要重新定义*/
/* 单链表结构体 */
typedef struct LNode
{
    LElemType data;
    struct LNode* next;
}LNode,*LinkList;
#endif

/* 01初始化单链表 */
Status InitList_L(LinkList *L);
/*02 清除链表*/
Status ClearList_L(LinkList L);
/*03销毁链表*/
void DestroyList_L(LinkList *L);
/*04判断链表是否为空*/
Status ListEmpty_L(LinkList L);
/*05返回链表长度*/
int ListLength_L(LinkList L);
/*06获取第i个元素的值并赋值给e*/
Status GetElem_L(LinkList L, int i, LElemType *e);
/*(07)返回单链表L中第一个与e满足Compare关系的元素位序*/
int LocateElem_L(LinkList L, LElemType e, Status(Compare)(LElemType, LElemType));
/*(08)用pre_e接收cur_e的前驱*/
Status PriorElem_L(LinkList L, LElemType cur_e, LElemType *pre_e);
/*(09)用next_e接收cur_e的后继。*/
Status NextElem_L(LinkList L, LElemType cur_e, LElemType *next_e);
/*(10)算法2.9：在单链表L第i个位置之前插入e。*/
Status ListInsert_L(LinkList L, int i, LElemType e);
/*(11)算法2.10：删除单链表L第i个位置的值，并用e接收*/
Status ListDelete_L(LinkList L, int i, LElemType *e);
/*(12)用Visit函数访问单链表L。*/
Status ListTraverse_L(LinkList L, void(Visit)(LElemType));
/*(13)算法2.11：头插法建立单链表L(逆序输入)。*/
Status CreateList_HL(FILE *fp, LinkList *L, int n);
/*(14)尾插法建立单链表L(顺序输入)。*/
Status CreateList_TL(FILE *fp, LinkList *L, int n);
#endif //C_MATHSTATUS_SINGLYLINKEDLIST_H
