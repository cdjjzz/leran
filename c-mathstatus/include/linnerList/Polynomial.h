//
// Created by Administrator on 2023/9/8.
//
/*************************************
 *						             *
 * 文件夹: ▲02 linnerList\11 Polynomial *
 * 							         *
 * 文件名: Polynomial.h              *
 * 							         *
 * 内  容: 一元多项式相关操作列表    *
 *                                   *
 *************************************/
#ifndef C_MATHSTATUS_POLYNOMIAL_H
#define C_MATHSTATUS_POLYNOMIAL_H
#include "Status.h"

typedef struct LNode{
    int 	coef;						//系数
    int		expn;						//指数
    struct LNode *next;
}LNode,*Polynomial;

/* 一元多项式函数列表 */
Status CreatPolyn(Polynomial *P, int m);
/*输出多项式*/
void showPoly(Polynomial P);
/*多项式加法*/
Status add_p(Polynomial p);
#endif //C_MATHSTATUS_POLYNOMIAL_H
