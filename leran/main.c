#include "structureL/TNode.h"

#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

#define INITSIZE  20 //初始化数组长度为20
#define INCREMENT 10 //每次增量为10
#define MAXBUFFER 20 //最大缓存池
#define LEN  sizeof(Elemtype) // 获取Elemtype结构体的字节大小 并取别名LEN
struct Node{
    int value;
    char * name;
};
typedef struct Node * node;
void show(node n){
    n->value=10;
    n->name="罗盛丰";
    printf("%d\r\n",n->value);
    printf("%s\r\n",n->name);
}
int function(void){
    static int i,state = 0;//static 使function()函数内中的局部变量 变成全局变量，作用域从函数栈逃逸到全局静态区
    switch (state){
        case 0: /* start of function */
            for(i= 0;i<1; i++){
                state = 1; /* so we will come back to“case 1” */
                return i; /* resume control straight after the return */
                case 1:;
            }
        }
}
int main(){
   /* printf("%d\r\n",function());//*调用第一次
    printf("%d\r\n",function());//*调用第二次
    printf("%d\r\n",function());//*调用第三次
    printf("%d\r\n",function());//*调用第四次
    printf("%d\r\n",sizeof(short ));
    show(malloc(sizeof(node)));*/

   int a=65;
   int addr;
   addr=(int)&a;
   printf("%d",*(int*)addr);

}




