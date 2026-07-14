#include <iostream>
#include <string>
#include <algorithm>


// 415. 字符串相加
// string addStrings(string a, string b) {
//     string result = "";
//     int i = a.length() - 1; // 指向 string a 的末尾
//     int j = b.length() - 1; // 指向 string b 的末尾
//     int carry = 0;          // 进位标识

//     // 只要还有位没加完，或者最后还有一个进位没处理，就持续循环
//     while (i >= 0 || j >= 0 || carry > 0) {
//         int sum = carry; // 基础值等于上一轮的进位

//         if (i >= 0) {
//             sum += a[i] - '0'; // 字符转数字
//             i--;
//         }
//         if (j >= 0) {
//             sum += b[j] - '0'; // 字符转数字
//             j--;
//         }

//         carry = sum / 10;        // 计算新的进位（如 13 / 10 = 1）
//         result += to_string(sum % 10); // 取个位数拼接到结果字符串后面
//     }

//     // 因为是从个位开始往后拼接的，结果是反的（例如579算出来是"975"），需要翻转
//     reverse(result.begin(), result.end());
//     return result;
// }

// int main() {
//     string a = "123";
//     string b = "456";
//     cout << addStrings(a, b) << endl; // 输出: 579
//     return 0;
// }



using namespace std;

string addStrings(string a, string b) {
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >=0 || j >=0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
            
        if (j >= 0) {
            sum += b[j] - '0';
            j--;

        }

        carry = sum/10;
        result += to_string(sum % 10);
        }
    return result;
}

int main() {
    string a = "999";
    string b = "1";
    cout << addStrings(a, b) << endl;
    return 0;
}