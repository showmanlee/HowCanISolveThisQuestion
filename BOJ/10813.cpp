// 공 바꾸기
// https://www.acmicpc.net/problem/10813

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> ball(n + 1);
    for (int i = 1; i <= n; i++)
        ball[i] = i;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        swap(ball[a], ball[b]);
    }
    for (int i = 1; i <= n; i++)
       cout << ball[i] << ' ';
    cout << '\n';
}

// 1~n번이 적힌 공들의 위치를 바꿀 때, 최종 결과는?
// swap