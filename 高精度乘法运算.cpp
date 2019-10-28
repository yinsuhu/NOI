/** 
 * 高精度乘法运算
 * author: yinsuhu
 * date: 2019.10.25
 */

#include<iostream>
#include<cstring>
using namespace std;

int main() {
    //定义两个输入字符串
    char c1[100], c2[100];
    //定义转换数字数组a1,a2和存放结果数字a
    int a1[100], a2[100], a[100];
    //定义各个数组长度
    int c1len, c2len, alen;
    //初始化三个数字数组所有元素为0
    memset(a, 0, sizeof(a));
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    //输入第一个数字字符串
    cout << "input c1: ";
    cin >> c1;
    //输入第二个数字字符串
    cout << "input c2: ";
    cin >> c2;
    //获取两个输入字符串的长度
    c1len = strlen(c1);
    c2len = strlen(c2);
    //将两个字符数组转化成数字数组并调换顺序
    for(int i = 0; i < c1len; ++i) {
        a1[i] = c1[c1len-1-i] - '0';
    }
    for(int i = 0; i < c2len; ++i) {
        a2[i] = c2[c2len-1-i] - '0';
    }
    //x变量存放每次进位
    int x;
    //乘法规律a[i+j]=a1[i]*a2[j]+x+a[i+j]
    for(int i = 0; i < c1len; i++) {
        //每次被乘数乘完将进位重置为0
        x = 0;
        //被乘数
        for(int j = 0; j < c2len; j++) {
            a[i+j] = a1[i] * a2[j] + x + a[i+j];
            x = a[i+j]/10;
            a[i+j] = a[i+j] % 10;
        }
        //处理一个被乘数乘完一轮后的进位
        a[i+c2len] = x;
    }
    //两数相乘最大长度为两个长度相加
    alen = c1len + c2len;
    //处理前缀0
    while(a[alen]==0 && alen > 1) {
        alen--;
    }
    //输出结果
    for(int i = alen; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}

