/**
 * desc: 桶排序算法
 * author: yinsuhu
 * date: 2019.11.11
 */
//把待排序数分别作为a数组的索引赋值给数组,每个数字对应的数组值+1
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[101], n, i, j, k;
    memset(a, 0, sizeof(a));
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> k;
        a[k]++;
    }
//直接按顺序输出结果即可,若有重复的数字则重复输出
    for(i = 0; i <= 100; i++) {
        while(a[i] > 0) {
            cout << i << " ";
            a[i]--;
        }
    }
    cout << endl;
}
