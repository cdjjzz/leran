//
// Created by Administrator on 2022/11/23.
//

#ifndef LERAN_LISTNODE_H
#define LERAN_LISTNODE_H
struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;



static List MakeEmpty(List l);
static int isEmpty(List l);
static int isLast(List l,Position p);
static Position Find(List l,int x);
static void Delete(List l,int x);
static Position FindPrevious(List l,int x);
static void Insert(List l,int x,Position p);
static void DeleteList(List l);
static Position Header(List l);
static Position First(List l);
static Position Advance(Position p);
static int Retrieve(Position p);

static void PrintList(List l);

void testList();




//*********************************//
typedef PtrToNode Stack;
static int isEmpty_S(Stack stack);
static Stack CreateStack();
static void DisposeStack(Stack stack);
static void MakeStack(Stack stack);
static void Push(Stack stack,int x);
static int Top(Stack stack);
static void Pop(Stack stack);

void testStack();

#endif




