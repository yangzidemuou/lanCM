//
// Created by yangzidemuou on 2023/12/23.
//
/*
 * 题目描述
    给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。



    注意：

    整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
    假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231−1]。本题中，如果除法结果溢出，则返回 231 − 1


    示例 1：

    输入：a = 15, b = 2
    输出：7
    解释：15/2 = truncate(7.5) = 7
    示例 2：

    输入：a = 7, b = -3
    输出：-2
    解释：7/-3 = truncate(-2.33333..) = -2
    示例 3：

    输入：a = 0, b = 1
    输出：0
    示例 4：

    输入：a = 1, b = 1
    输出：1
 */

#include "iostream"
using namespace  std;
class Solution {
public:
    int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (INT_MIN >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
};

int main(){
    Solution solution;
    cout<<solution.divide(15,2)<<endl;
    cout<<solution.divide(7,-3)<<endl;
    cout<<solution.divide(0,1)<<endl;
    cout<<solution.divide(1,1)<<endl;
    return 0;
}