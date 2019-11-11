/**
 * desc: 冒泡排序算法
 * author: yinsuhu
 * date: 2019.11.11
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
    //定义变量,N代表数组个数,i,j遍历变量,tmp交换时临时变量 
    int N, i, j, tmp;
    //输入N 
    cin >> N;
    int a[N];
    //读入待排序数组 
    for(i = 0; i < N; i++) {
        cin >> a[i];
    }
    //外层循环遍历N-1次,最后一个元素无需比较 
    for(i = N - 1; i > 0; i--) {
        //内层循环遍历0-i次,每次比较相邻两个元素,如果前面元素较大,则交换两个数组的值 
        for(j = 0; j < i; j++) {
            if(a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    //输出结果 
    for(i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
