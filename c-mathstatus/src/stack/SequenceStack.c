//
// Created by Administrator on 2023/9/11.
//

#include "stack/SequenceStack.h"

Status InitStack_Sq(SqStack *S)
{
    S->top = (SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
    if(!S->top)
        exit(OVERFLOW);
    //使用数量0
    (*S).stacksize = 0;
    //申请数量 STACK_INIT_SIZE
    (*S).mallsize=STACK_INIT_SIZE;
    //第一个默认为base
    S->base= S->top;
    return OK;
}

Status DestroyStack_Sq(SqStack *S)
{
    //从第一个地址释放
    free(S->base);
    S->top = NULL;
    S->base = NULL;
    S->stacksize = 0;
    S->mallsize = 0;
    return OK;
}

Status ClearStack_Sq(SqStack *S)
{
    //清空已使用的
    S->stacksize = 0;
    return OK;
}

Status StackEmpty_Sq(SqStack S)
{
    if(S.stacksize == 0)
        return TRUE;
    else
        return FALSE;
}

int StackLength_Sq(SqStack S)
{
    return S.stacksize;
}

Status GetTop_Sq(SqStack S, SElemType_Sq *e)
{
    if(S.stacksize == 0)
        return ERROR;
    //指针和数组 *(p+i) = p[i] = a[i] = *(a+i) ,但是 S 此处是结构体，不是指针，
    *e=*(S.top-1);
    return OK;

}
Status Push_Sq(SqStack *S, SElemType_Sq e)
{
    if(S->stacksize==S->mallsize)		//栈满，追加存储空间
    {
        // S->base 新的地址
        S->base = (SElemType_Sq *)realloc(S->base, (S->mallsize+STACKINCREMENT)*sizeof(SElemType_Sq));
        if(! S->top)
            exit(OVERFLOW);//存储分配失败
        S->mallsize += STACKINCREMENT;
        //从新的地址中+stacksize
        S->top=S->base+S->stacksize;
    }
    *(S->top) = e;								//进栈先赋值，栈顶指针再自增
    (S->top)++;
    S->stacksize=S->stacksize+1;
    return OK;
}

Status Pop_Sq(SqStack *S, SElemType_Sq *e)
{
    if(S->stacksize == 0)
        return ERROR;
    (S->top)--;									//出栈栈顶指针先递减，再赋值
    *e = *(S->top);
    S->stacksize=S->stacksize-1;
    return OK;
}

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{												//遍历不应该破坏栈
   for(int i=0;i<S.stacksize;i++){
       (S.top)--;
       Visit(*(S.top));
   }
    return OK;
}
