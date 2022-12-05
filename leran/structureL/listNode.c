//
// Created by Administrator on 2022/11/23.
//
#include <stdio.h>
#include <malloc.h>
#include "listNode.h"
#include "fatal.h"


struct Node{
    int element;
    PtrToNode next;
};

static List MakeEmpty(List l){
    if(l!=NULL)
        DeleteList(l);
    l=malloc(sizeof (struct Node));
    if(l==NULL)
        FatalError("out of memory");
    l->next=NULL;
    return l;
}

static int isEmpty(List l){
    return l->next==NULL;
}

static int isLast(List l,Position p){
    return p->next==NULL;
}

static Position Find(List l,int x){
    Position  p=l->next;
    while(p!=NULL&&p->element!=x)
        p=p->next;
    return p;
}


static Position FindPrevious(List l,int x){
    Position p=l;
    while(p->next!=NULL&&p->next->element!=x)
        p=p->next;
    return p;
}

static void Delete(List l,int x){
    Position p= FindPrevious(l,x);
    if(!isLast(l,p)){
       Position  freeP=p->next;
       p->next=freeP->next;
       free(freeP);
    }
}
static void Insert(List l,int x,Position p){
    Position addP= malloc(sizeof(struct Node));
    if(addP==NULL){
        printf("space is out");
    }
    addP->element=x;
    addP->next=p->next;
    p->next=addP;
}

static void DeleteList(List l){
    Position p=l->next;
    Position Tmp;
    l->next=NULL;
    while(p!=NULL){
        Tmp=p->next;
        free(p);
        p=Tmp;
    }
}
static Position Header(List l){
    return l;
}

static Position First(List l){
    return l->next;
}

static Position Advance(Position p){
    return p->next;
}

static int Retrieve(Position p){
    return p->element;
}


static void PrintList(List l){
    PtrToNode copyL=l;
    if(copyL->next==NULL){
        printf("当前链表为空\n");
        return;
    }
    printf("打印链表开始\n");
    while (copyL->next!=NULL){
        copyL=copyL->next;
        printf("%d\n",copyL->element);
    }
    printf("打印链表结束\n");
}
void testList(){
    // 初始化表
    List L = (List) malloc(sizeof(struct Node));
    L->element = -1;
    L->next = NULL;
    // 测试打印空表
    PrintList(L);
    fflush(stdout);
    // 往链表中添加数据，从开头插入
    Insert( L,11, L);
    Insert( L,22, L);
    Insert( L,33, L);
    Insert( L,44, L);
    // 打印链表
    PrintList(L);

    // 从中间插入数据
    PtrToNode InsertAfter33 = L->next->next; // 把33这个位置给取出来
    Insert(L, 31, InsertAfter33);
    // 打印链表
    PrintList(L);

    // 删除31这个元素
    Delete(L, 31);
    // 打印链表
    PrintList(L);

    // 查找22这个数的位置
    Position position = Find(L, 22);
    printf("查找到的值为：%d", position->element);
}




//********************************************************************************************//

static int isEmpty_S(Stack stack){
    return stack->next==NULL;
};
static Stack CreateStack(){
    Stack s= malloc(sizeof (struct Node));
    if(s==NULL)
        FatalError("space out memory");
    s->next=NULL;
    MakeStack(s);
    return s;
};
static void MakeStack(Stack stack){
    if(stack==NULL){
        Error("MUST APPLY stack");
    }else{
        while (!isEmpty_S(stack))
            Pop(stack);
    }
};
//处理掉这个栈，即清空所有元素并释放头节点
static void DisposeStack(Stack stack){
    MakeStack(stack);
    free(stack);
};
static void Push(Stack stack,int x){
    PtrToNode pushNode= malloc(sizeof (struct Node));
    if(pushNode==NULL){
        FatalError("out space memory");
    }else{
        pushNode->element=x;
        pushNode->next=stack->next;
        stack->next=pushNode;
    }
};

static int Top(Stack stack){
    if(!isEmpty_S(stack)){
        return stack->next->element;
    }
    return -1;
};
static void Pop(Stack stack){
    PtrToNode popNode;
    if(isEmpty_S(stack)){
        Error("stack is empty");
        return;
    }else{
        popNode=stack->next;
        stack->next=stack->next->next;
        free(popNode);
    }
};


void testStack(){
    Stack S;
    int i;

    S = CreateStack();
    // 添加元素 0 ~ 9
    for (i = 0; i < 10; i++)
        Push(S, i);

    while (!isEmpty_S(S))
    {
        printf("%d\n", Top(S));
        Pop(S);
    }

    DisposeStack(S);
};




