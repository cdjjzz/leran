//
// Created by Administrator on 2023/9/11.
//
/******************************************
 *						      			  *
 * 文件夹: ▲03 栈和队列\01 SequenceStack *
 * 							    		  *
 * 文件名: SequenceStack.h    			  *
 * 							  			  *
 * 内  容: 顺序栈相关操作列表 			  *
 *                            			  *
 ******************************************/
#ifndef C_MATHSTATUS_SEQUENCESTACK_H
#define C_MATHSTATUS_SEQUENCESTACK_H
#include "Status.h"
/* 宏定义 */
#define STACK_INIT_SIZE	3				//顺序栈存储空间的初始分配量
#define STACKINCREMENT	2 				//顺序栈存储空间的分配增量
/* 顺序栈类型定义 */
/*在迷宫、表达式、二叉树二叉链表、孩子兄弟树等算法中，此类型需要重新定义*/
#if !defined C_MATHSTATUS_MAZE_H &&\
    !defined EXPRESSION_H &&       \
    !defined EXPRESSION_C
typedef int SElemType_Sq;
#endif
typedef struct
{
    SElemType_Sq *base;				//在栈构造之前和销毁之后，base的值为NULL
    SElemType_Sq *top;				//栈顶指针
    int mallsize;//申请数量
    int stacksize;					//当前已分配的存储空间，以元素为单位,使用数量
}SqStack;
/* 顺序栈函数列表 */
Status InitStack_Sq(SqStack *S);
/*━━━━━━━━┓
┃(01)构造空栈S。 ┃
┗━━━━━━━━*/

Status DestroyStack_Sq(SqStack *S);
/*━━━━━━┓
┃(02)销毁S。 ┃
┗━━━━━━*/

Status ClearStack_Sq(SqStack *S);
/*━━━━━━┓
┃(03)置空S。 ┃
┗━━━━━━*/

Status StackEmpty_Sq(SqStack S);
/*━━━━━━━━━━┓
┃(04)判断S是否为空。 ┃
┗━━━━━━━━━━*/

int StackLength_Sq(SqStack S);
/*━━━━━━━━━━┓
┃(05)返回S元素个数。 ┃
┗━━━━━━━━━━*/

Status GetTop_Sq(SqStack S, SElemType_Sq *e);
/*━━━━━━━━━━━┓
┃(06)用e获取栈顶元素。 ┃
┗━━━━━━━━━━━*/

Status Push_Sq(SqStack *S, SElemType_Sq e);
/*━━━━━━━━┓
┃(07)元素e进栈。 ┃
┗━━━━━━━━*/

Status Pop_Sq(SqStack *S, SElemType_Sq *e);
/*━━━━━━━━┓
┃(08)元素e出栈。 ┃
┗━━━━━━━━*/

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq));
/*━━━━━━┓
┃(09)访问栈。┃
┗━━━━━━*/
#endif //C_MATHSTATUS_SEQUENCESTACK_H
