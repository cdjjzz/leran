//
// Created by Administrator on 2022/11/21.
//

#include "binarySearch.h"
/**
 * 二分查找 要求 a是有序
 * @param a
 * @param x
 * @param n
 * @return
 */
int binarySearch(const int * a,int x,int n){
    int low,mid,height;
    low=0,height=n-1;
    while (low<=height){
        mid=(low+height)/2;
        if(a[mid]<x){
            low=mid+1;
        }else if(a[mid]>x){
            height=mid-1;
        } else{
            return mid;
        }
    }
    return -1;
}

/**
 * 最大公约数
 * @param m
 * @param n
 * @return
 */
unsigned int Gcd(unsigned int m,unsigned int n){
    unsigned int rem;
    while (n>0){
        rem=m/n;
        m=n;
        n=rem;
    }
    return m;
}

/**
 * 判断是否是素数   素数定义 只有 被 1 和本身整除
 * @param x
 * @return 1 true  0  false
 */
int isPrime(int x){
    int ret=1;      //ret含义与之前的变量IsPrime相同
    if(x==1||(x!=2&&x%2==0))
        ret=0;
    for(int i=3;i<sqrt(x);i+=2)       //循环到sqrt(x)
    {
        if(x%i==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}
/**
 * 暴力求幂
 * @param x
 * @param y
 * @return
 */
long long power(int base,int p){
    int num=1;
    for(int i=1;i<=p;i++){
        num*=base;
    }
    return num;
}

/**
 * 二进制求幂
 * @param x
 * @param y
 * @return
 */
long long qpow(int base,int p){
    int ans = 1, tmp = base;//从底数开始乘，不停自乘
    while (p != 0) //指数不是0
    {

        if (p & 1)//如果当前二级制位是1则乘之前的数
        {
            ans= (ans * tmp);
        }
        tmp = (tmp * tmp);//为什么是tmp的平方：因为每>>一次 相当于base_number^2，
        p = p >> 1;//向后访问一位
    }
    return ans;
}