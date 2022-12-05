//
// Created by Administrator on 2022/11/17.
//

#include "maxSubSum.h"

int maxSubSum_one(const int *a,int n){
    int thisSum,maxSum,i,j,k;
    maxSum=0;
    for(i=0;i<n;i++){
        for (j=i;j<n;j++){
            thisSum=0;
            for (k=i;k<=j;k++){
                thisSum+=a[k];
            }
            if(thisSum>maxSum){
                maxSum=thisSum;
            }
        }
    }
    return maxSum;
};
int maxSubSum_two(const int *a,int n){
    int thisSum,maxSum,i,j;
    maxSum=0;
    for(i=0;i<n;i++){
        thisSum=0;
        for (j=i;j<n;j++){
            thisSum+=a[j];
            if(thisSum>maxSum){
                maxSum=thisSum;
            }
        }
    }
    return maxSum;
};
int maxSubSum_three(const int *a,int left,int right){
    int maxLeftSum,maxRightSm;
    int maxLeftBorderSum,maxRightBorderSum;
    int leftBorderSum,rightBorderSum;
    int center,i;
    if(left==right){
        if(a[left]>0)
            return a[left];
        else
            return 0;
    }
    center=(left+right)/2;
    maxLeftSum=maxSubSum_three(a,left,center);
    maxRightSm= maxSubSum_three(a,center+1,right);

    maxLeftBorderSum=0;leftBorderSum=0;
    for(i=center;i>=left;i--){
        leftBorderSum+=a[i];
        if(leftBorderSum>maxLeftBorderSum)
            maxLeftBorderSum=leftBorderSum;
    }

    maxRightBorderSum=0;rightBorderSum=0;
    for(i=center+1;i<=right;i++){
        rightBorderSum+=a[i];
        if(rightBorderSum>maxRightBorderSum)
            maxRightBorderSum=rightBorderSum;
    }
    int sum=maxLeftBorderSum+maxRightBorderSum;
    return maxRightSm>=maxLeftSum ? sum>=maxRightSm ? sum:maxRightSm :sum>=maxLeftSum ? sum:maxLeftSum;
};
int maxSubSum_fore(const int *a,int n){
    int thisSum,maxSum,i;
    thisSum=maxSum=0;
    for(i=0;i<n;i++) {
        thisSum += a[i];
        if(thisSum>maxSum){
            maxSum=thisSum;
        } else if(thisSum<0){
            thisSum=0;
        }
    }
    return maxSum;
};