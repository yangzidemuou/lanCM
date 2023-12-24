//
// Created by yangzidemuou on 2023/12/24.
//
/*

题目描述
给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。

输入为 非空 字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "10"
输出: "101"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"


提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

 */



#include <algorithm>
#include "iostream"
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
            carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            ans.push_back((carry % 2) + '0');
            cout<<ans<<endl;
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution solution;
    cout<<solution.addBinary("111","11")<<endl;
    return 0;
}