//
// Created by yangzidemuou on 2023/12/20.
//
/*
题目描述

    小明刚刚看完电影《第39级台阶》，离开电影院的时候，他数了数礼堂前的台阶数，恰好是39级！站在台阶前，他突然又想着一个问题：
    如果我每一步只能迈上1个或2个台阶，先迈左脚，然后左右交替，最后一步是迈右脚，也就是说一共要走偶数步。那么，上完39级台阶，有多少种不同的上法呢？
    请你利用计算机的优势，帮助小明寻找答案。要求提交的是一个整数。

题目分析

    这题使用递归算法
    递归的终止条件：当步数达到39时候，终止递归
    递归的两个入口：单步上台阶，和两步上台阶

 */
#include "iostream"
using namespace std;
//num表示一共的台阶数
//time表示走了多少次

int DFS(int num,int time)
{
    if(num>39)
    {
        return 0;
    }
    if(num==39)
    {
        if(time%2==0)
        {
            return 1;
        }
        return 0;
    }
    //     单步跨            两步跨
    return DFS(num+1,time+1)+DFS(num+2,time+1);

}
int main(){
    int ans = DFS(1,1)+DFS(2,1);
    cout << ans;
    return 0;
}