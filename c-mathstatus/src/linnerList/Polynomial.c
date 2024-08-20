//
// Created by Administrator on 2023/9/8.
//

#include "linnerList/Polynomial.h"
#include "math.h"

Status CreatPolyn(Polynomial *P, int m){
    *P=(Polynomial)malloc(sizeof(LNode));
    if(!(*P))
        exit(OVERFLOW);
    //尾插法
    Polynomial r=*P;
    printf("\t\t      系数 指数\n");
    scanf("%d %d",&(r->coef), &(r->expn));//输入各项系数和指数
    Polynomial s;
    for(int i=1; i<m; i++)					//依次录入n个非0项
    {
        s=(Polynomial)malloc(sizeof(LNode));
        if(!s)
            exit(OVERFLOW);
        printf("\t\t      系数 指数\n");
        scanf("%d %d",&(s->coef), &(s->expn));//输入各项系数和指数
        r->next=s;
        s->next=NULL;
        //将新的节点 设置为最后的节点标识
        r=s;
    }
    r->next=NULL;
    return OK;
}

void showPoly(Polynomial P){
    if(P){
        Polynomial node=P;
        while(node){
            if(node->next){
                printf("(%d)*[X^%d] + ",node->coef,node->expn);
            }else{
                printf("(%d)*[X^%d]",node->coef,node->expn);
            }
            node = node->next;
        }
    }
    printf("\r\n");
}
Status add_p(Polynomial P){
    int result=0;
    if(P){
        printf("\t\t      请输入x的值\n");
        int x;
        scanf("%d",&(x));//输入各项系数和指数
        Polynomial node=P;
        while(node){
            result+=node->coef* pow(x,node->expn);
            node = node->next;
        }
    }
    return result;
}
