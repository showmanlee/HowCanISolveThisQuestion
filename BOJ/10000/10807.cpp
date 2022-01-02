// 개수 세기
// https://www.acmicpc.net/problem/10807

#include <iostream>
using namespace std;

int main(){
    int n, v, count = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> v;
    for (int i = 0; i < n; i++)
        if (a[i] == v)
            count++;
    cout << count;
}