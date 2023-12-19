//
// Created by yangzidemuou on 2023/12/19.
//
/*
 第一题：高斯日记（4分）
    题目描述

    大数学家高斯有个好习惯：无论如何都要记日记。他的日记有个与众不同的地方，他从不注明年月日，
    而是用一个整数代替，比如：4210。后来人们知道，那个整数就是日期，它表示那一天是高斯出生后的第几天。
    这或许也是个好习惯，它时时刻刻提醒着主人：日子又过去一天，还有多少时光可以用于浪费呢？
    高斯出生于1777年4月30日，在高斯发现的一个重要定理的日记上标注着5343，因此可算出那天是1791年12月15日。
    高斯获得博士学位的那天日记上标着8113，请你算出高斯获得博士学位的年月日。

    提交答案的格式是：yyyy-mm-dd，例如：1980-03-21

    题目分析

    首先确定发生事件的年份，就是用总的天数减去每年天数
    然后确定在该年的月份以及日期。
 * */

#include<iostream>

using namespace std;

//判断闰年平年 闰年返回true;
bool jude(int year)
{
    return year%400==0 || ((year%100) && year%4==0);

}
int main()
{
    int n;
    cin >> n;
    //这里减一表示出生那天也算
    int sumDay = n + 31 + 28 + 31 + 30 - 1;

    int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year = 1777,month = 4,day = 30;
    int m;
    //确定年份
    while(1)
    {
        int yearday = 0;
        if(jude(year))
            yearday = 366;
        else
            yearday = 365;
        if(sumDay<yearday)
        {
            break;
        }
        sumDay -= yearday;
        year++;
    }

    if(jude(year))
        days[2] = 29;
    else
        days[2] = 28;
    //确定日期
    for(int i =1; i < 13; i++)
    {
        if(sumDay<=days[i])
        {
            //输出格式注意
            cout << year<<"-" ;
            if(i<10)
                cout << "0";
            cout << i;
            if(sumDay<0)
                cout <<"0";
            cout << "-"<<sumDay;
            return 0;
        }
        sumDay -= days[i];
    }
    return 0;
}