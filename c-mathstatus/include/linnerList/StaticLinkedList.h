//
// Created by Administrator on 2023/9/8.
//
/********************************
 *						        *
 * 文件夹: ▲02 linnerList          *
 * 							    *
 * 文件名: StaticLinkedList.h   *
 * 							    *
 * 内  容: 静态链表相关操作列表 *
 *                              *
 ********************************/

/*━━━━━━━━━━━━━━━━━━━━━━━━┓
★备注：                                          ┃
★1.为操作方便，特为申请到的空间段设一“头结点”。┃
★2.模拟系统动态申请空间过程。                    ┃
★3.个别操作会与严蔚敏数据结构课本有所差异。      ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/
#ifndef C_MATHSTATUS_STATICLINKEDLIST_H
#define C_MATHSTATUS_STATICLINKEDLIST_H
#include "Status.h"        //src/Status.h//


/* 宏定义 */
#define MAXSIZE 1000					//静态链表的最大长度
/* 静态链表类型定义 */
typedef struct
{
    LElemType data;
    int cur;							//cur是游标，做指针用，区别于数组下标
}Component;					//链表空间类型
//Component[MAXSIZE]   Component SPACE

/* 全局变量 */
Component SPACE[MAXSIZE];						//静态链表空间

/*	静态链表函数列表 */
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.14：将一维数组SPACE中各分量链成一个大的备用空间。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
void InitSpace_SL();
/*━━━━━━━━━━━━━━━━━┓
┃(02)算法2.15：为插入数据申请空间。┃
┗━━━━━━━━━━━━━━━━━*/
int Malloc_SL();
/*━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法2.16：将下标为k的空闲结点回收。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/
void Free_SL(int k);
/*━━━━━━━━━━━━━━━━┓
┃(04)初始化静态链表，建立头结点。┃
┗━━━━━━━━━━━━━━━━*/
int InitList_SL(LElemType *H);
/*━━━━━┓
┃(05)置空。┃
┗━━━━━*/
Status ClearList_SL(LElemType H);
/*━━━━━┓
┃(06)销毁。┃
┗━━━━━*/
void DestroyList_SL(LElemType *H);
/*━━━━━┓
┃(07)判空。┃
┗━━━━━*/
Status ListEmpty_SL(LElemType H);
/*━━━━━┓
┃(08)求长。┃
┗━━━━━*/
int ListLength_SL(LElemType H);
/*━━━━━┓
┃(09)取值。┃
┗━━━━━*/
Status GetElem_SL(LElemType H, int i, LElemType *e);
/*━━━━━━━━━━━━━━━━┓
┃(10)算法2.13：返回元素e的位序。 ┃
┗━━━━━━━━━━━━━━━━*/
int LocateElem_SL(LElemType H, LElemType e);
/*━━━━━┓
┃(11)前驱。┃
┗━━━━━*/
Status PriorElem_SL(LElemType H, LElemType cur_e, LElemType *pre_e);

/*━━━━━┓
┃(12)后继。┃
┗━━━━━*/
Status NextElem_SL(LElemType H, LElemType cur_e, LElemType *next_e);

/*━━━━━┓
┃(13)插入。┃
┗━━━━━*/
Status ListInsert_SL(LElemType H, int i, LElemType e);

/*━━━━━┓
┃(14)删除。┃
┗━━━━━*/
Status ListDelete_SL(LElemType H, int i, LElemType *e);

/*━━━━━┓
┃(15)访问。┃
┗━━━━━*/
Status ListTraverse_SL(LElemType H, void(Visit)(LElemType));


#endif //C_MATHSTATUS_STATICLINKEDLIST_H
