/**
 * desc: 选择排序算法 
 * author: yinsuhu
 * date: 2019.11.11
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
    int N, i, j , k, tmp;
    //输入数据量大小N
    cin >> N;
    int a[N];
    //循环读入N个数到数组 
    for(i = 0; i < N; i++) {
        cin >> a[i];
    }
    //每次i循环找到最小的数放到i位置上 
    //k变量记录每次最小值的坐标
    //j循环负责找到最小的数 
    for(i = 0; i < N - 1; i++) {
        k = i;
        for(j = i + 1; j < N; j++) {
            if(a[j] < a[k]) {
                k = j; 
            }
        }
        //如果k和i不相等,说明找到了新的最小值并交换下 
        if(k != i) {
            tmp = a[i];
            a[i] = a[k];
            a[k] = tmp;
        }
    }
    //输出结果 
    for(i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
} 
