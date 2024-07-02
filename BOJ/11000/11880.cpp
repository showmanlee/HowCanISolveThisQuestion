// 개미
// https://www.acmicpc.net/problem/11880

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long maxx = max(a, max(b, c));
        long long minn = 0;
        if (maxx == a) {
            minn = b + c;
        } else if (maxx == b) {
            minn = a + c;
        } else {
            minn = a + b;
        }
        cout << (maxx * maxx) + (minn * minn) << '\n';
    }
}

// 주어진 정육면체의 한쪽 끝에서 반대편 끝으로 겉면을 타고 이동할 때, 최단 거리 구하기

// 두 변을 하나로 이은 후 다른 변과 직각삼각형을 만들고 그 대각선 길이를 보면 될 것 - 피타고라스
// 이 경우 가장 긴 변을 하나로 두고, 나머지 두 변을 하나로 이어야 함 - 제곱이란게 원래 그렇지