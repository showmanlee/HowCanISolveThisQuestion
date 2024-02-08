// 선 그리기
// https://www.acmicpc.net/problem/16396

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<bool> v(10001);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++) {
            if (!v[j]) {
                v[j] = true;
                res++;
            }
        }
    }
    cout << res << '\n';
}

// 1차원 좌표 공간에서 그어진 선분들을 직선 좌표에 투영한 길이 출력하기

// 직선 좌표계에 그어진 선의 길이 구하기 - 배열에 직접 그어가며 확인 가능