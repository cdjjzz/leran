//
// Created by Administrator on 2023/9/12.
//

#include "stack/Conversion.h"
void conversion(int i)
{
    SqStack S;

    InitStack_Sq(&S);

    printf("十进制数 %d 转换为八进制数后为：0", i);

    while(i)
    {
        Push_Sq(&S, i%8);				//进栈时从低位到高位
        i = i/8;
    }
    LElemType e;
    while(!StackEmpty_Sq(S))
    {
        Pop_Sq(&S, &e);					//出栈时从高位到低位
        printf("%d", e);
    }
}