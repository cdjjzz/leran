//
// Created by Administrator on 2023/9/6.
//
/**********************************
 *                                *
 * 文件夹: ▲01 绪论              *
 *                                *
 * 文件名: Status.h               *
 *                                *
 * 内  容: 相关状态码及宏函数列表 *
 *                                *
 **********************************/
#ifndef C_MATHSTATUS_STATUS_H
#define C_MATHSTATUS_STATUS_H
#include "stdio.h"
#include <stdlib.h>				//提供malloc、realloc、free、exit原型

/* 状态码 */
#define	TRUE		1			//真
#define	FALSE		0			//假
#define YES			1			//是
#define NO          0			//否
#define	OK			1			//通过
#define	ERROR		0			//错误
#define SUCCESS		1			//成功
#define UNSUCCESS	0			//失败
#define	INFEASIBLE	-1			//不可行

#ifndef _MATH_H_ 				//系统中已有此状态码定义，要避免冲突
#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢
#define UNDERFLOW   -4          //
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

/* 状态码识别类型 */
typedef int Status;

typedef int LElemType;
/* 函数原型 */
Status CmpGreater(LElemType e, LElemType data);	//判断data是否大于e //若data大于e，返回TRUE
void PrintElem(LElemType e);						//测试函数，打印整型


/*宏函数*/
//函数暂停一段时间
#define Wait(x)\
 {\
	double _Loop_Num_;\
	for(_Loop_Num_=0.01; _Loop_Num_<=100000.0*x; _Loop_Num_+=0.01)\
		;\
 }//设立一个空循环
//摁Enter键继续
#define PressEnter\
 {                \
    setbuf(stdout,NULL); \
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }

#endif //C_MATHSTATUS_STATUS_H

