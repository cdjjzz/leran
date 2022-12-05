//
// Created by Administrator on 2022/11/17.
//
#include "selectn2.h"
#include "stdlib.h"
#include "time.h"

int * createArray(int* a,int n){
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;i++){
        a[i]=rand() % 1000 + 1;
    }
    return a;
}
int getKMax(int *a ,int k){
    int b[k];
    for(int i=0;i<k*2;i++){
        int temp = a[i];
        if(i == 0){//模仿插入排序，保证其中新数组中必定含有1个元素
            b[i] = temp;
            continue;
        }
        if(i<k){
            b[i]=temp;
            //插入排序
            for(int j=i-1;j>=0&&b[j+1]>b[j];j--){
                int tmp=b[j];
                b[j]=b[j+1];
                b[j+1]=tmp;
            }
        }else{
            //如果往后的数大于第K个数，则与第K个数互换，再进行排序（倒序）；小于等于，则跳过。
            if(temp>b[k-1]){
                b[k-1]=temp;
                for(int j=k-1;j>0&&b[j]>b[j-1];j--){
                    int tmp=b[j-1];
                    b[j-1]=b[j];
                    b[j]=tmp;
                }
            }else{
                continue;
            }
        }
    }
    return b[k-1];
}