/**
 * 高精度除以低精度
 * author: yinsuhu
 * date: 2019.11.05
 */
#include<iostream>
#include<cstring>
using namespace std;
//高精度除以低精度求商和余数运算
int main() {
    char a1[100];//最多100位数字用char字符数组存储
    int a[100],  c[100], lena, i, x = 0, lenc, b;
    memset(a, 0, sizeof(a));//将转存数组置零
    memset(c, 0, sizeof(c));//将结果数组置零
    gets(a1);//输入长字符串数字存入a1
    cin >> b;//除数由于不是高精度，直接用标准输入
    lena = strlen(a1);//字符串的长度
    for(i = 0; i < lena; i++) {
        a[i] = a1[i] - 48;//将字符转化成数字
        c[i] = (x * 10 + a[i]) / b;//得到每次的商
        x = (x * 10 + a[i]) % b;//得到每次的余数
    }
    lenc = 0;//记录结果数字c的长度
    while(c[lenc] == 0 && lenc < lena - 1) {
        lenc++;//记录前面多余的零的个数
    }
    //输出结果
    cout << "商为:";
    for(i = lenc; i < lena; i++) {
        cout << c[i];
    }
    cout << " 余数为:" << x;
    cout << endl;
}
