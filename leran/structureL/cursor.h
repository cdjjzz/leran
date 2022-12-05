// 链表游标实现的声明
#ifndef LERAN_CURSOR_H
#define LERAN_CURSOR_H

#define SpaceSize 100
typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

static void InitializeCursorSpace( void );

static List MakeEmpty( List L );
static int IsEmpty( const List L );
static int IsLast( const Position P, const List L );
static Position Find( ElementType X, const List L );
static void Delete( ElementType X, List L );
static Position FindPrevious( ElementType X, const List L );
static void Insert( ElementType X, List L, Position P );
static void DeleteList( List L );
static Position Header( const List L );
static Position First( const List L );
static Position Advance( const Position P );
static ElementType Retrieve( const Position P );

static Position getFirstMemory();

int test();

#endif
