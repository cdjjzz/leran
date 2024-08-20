//
// Created by Administrator on 2023/9/7.
//
#include "Status.h"


//回调函数原型 CmpGreater
Status CmpGreater(LElemType e, LElemType data)
{
    return data>e ? TRUE : FALSE;
}
//回调函数原型 PrintElem
void PrintElem(LElemType e)
{
    printf("%d ", e);
}