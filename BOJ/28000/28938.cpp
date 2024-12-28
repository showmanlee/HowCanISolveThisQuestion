// Конвейер
// https://www.acmicpc.net/problem/28938

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        res += p;   
    }
    cout << (res == 0 ? "Stay" : (res < 0 ? "Left" : "Right")) << '\n';
}

// 1차원 공간에서 좌/우/정지 명령이 주어질 때, 최종적 위치 방향 출력하기 