#include<iostream>
#include<cstring>
using namespace std;
int main() {
    //定义输入c1,c2,临时c
    char c1[100], c2[100], c[100];
    //定义转换数字数组a1,a2,输出结果数组a
    int a1[100], a2[100], a[100];
    int c1len, c2len, clen;
    //初始化三个数字数组为0
    memset(a, 0, sizeof(a));
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    //两个输入
    cout << "input c1: ";
    cin >> c1;
    cout << "input c2: ";
    cin >> c2;
    c1len = strlen(c1);
    c2len = strlen(c2);
    //确保c1比c2大,总是用c1减去c2
    if(c2len > c1len || (c2len == c1len && strcmp(c2, c1) > 0)) {
        strcpy(c, c2);
        strcpy(c2, c1);
        strcpy(c1, c);
        cout << "-";
    }
    c1len = strlen(c1);
    c2len = strlen(c2);
    //把字符数组转化成数字数组
    for(clen = 0; clen < c1len; ++clen) {
        a1[clen] = c1[c1len - 1 - clen] - '0'; 
    }
    for(clen = 0; clen < c2len; ++clen) {
        a2[clen] = c2[c2len - 1 - clen] - '0'; 
    }
    //每位执行减法,不够减的话向高位借一位,高位同时减一
    clen = 0;
    for(; clen < c1len; ++clen) {
        if(a1[clen] < a2[clen]) {
            a1[clen] += 10;
            a1[clen+1]--;
        }
        a[clen] = a1[clen] - a2[clen];
    }
    //输出最后结果,z变量用于去除高位的0
    bool z = false;
    for(int i = clen-1; i >= 0; i--) {
        if(a[i] > 0) {
            cout << a[i];
            z = true;
        } else if(z) {
            cout << a[i];
        }
    }
    //如果没有输出,说明结果为0
    if(!z) {
        cout << 0;
    }

    cout << endl;
}
