#include<iostream>
#include<cstring>
using namespace std;
//高精度加法
int main() {
    char c1[100], c2[100];//存储输入的数字字符串 
    int a1[100], a2[100], a[100];//c1,c2转存为数字数组a1,a2,结果保存在a3中 
    //把数组元素全部置为0 
    memset(a, 0, sizeof(a));
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    //输入加数和被加数 
    gets(c1);
    gets(c2);
    //获取两个加数的字符串长度 
    int c1len = strlen(c1);
    int c2len = strlen(c2);
    //把两个字符串数组转化成数字数组,把c1和c2的右侧放到数字数组的前面 
    for(int i = 0; i < c1len; ++i) {
        a1[i] = c1[c1len-1-i] - '0';
    }
    for(int i = 0; i < c2len; ++i) {
        a2[i] = c2[c2len-1-i] - '0';
    }
    //x保存进位,alen保存结果数组a的长度 
    int x = 0;
    int alen = 0;
    for(; alen < (c1len > c2len ? c1len : c2len); ++alen) {
        a[alen] = a1[alen] + a2[alen] + x;
        x = a[alen] / 10;
        a[alen] = a[alen] % 10;
    }
    //处理最后一个进位,如果进位大于零,让a数组最后一位为x
    //否则的话长度减一 
    if(x>0) {
        a[alen] = x;
    } else {
        alen--;
    }

    //按数组的倒序输出数字 
    for(int j = alen; j >= 0; --j) {
        cout << a[j];
    }
    cout << endl;
} 
