// Sim Card
// https://www.acmicpc.net/problem/15340

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        int a = n * 30 + m * 40;
        int b = n * 35 + m * 30;
        int c = n * 40 + m * 20;
        cout << min(a, min(b, c)) << '\n';
    }
}

// 통화/데이터에 다른 요금을 매기는 요금제 3개가 주어질 때, 주어진 통화/데이터 사용량에서 가장 낮은 비용 출력하기

// 계산하고 비교해봅시다