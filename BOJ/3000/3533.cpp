// Explicit Formula
// https://www.acmicpc.net/problem/3533

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<bool> v(10);
    int res = 0;
    for (int i = 0; i < 10; i++) {
        int p;
        cin >> p;
        v[i] = (p == 1);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (v[i] || v[j]) {
                res++;
            }
            for (int k = j + 1; k < 10; k++) {
                if (v[i] || v[j] || v[k]) {
                    res++;
                }
            }
        }
    }
    cout << (res % 2) << '\n';
}

// 0이나 1이 10개 주어질 때, 그 중 2개를 골라 만든 순서쌍과 3개를 골라 만든 순서쌍을 OR 연산한 결과가 1인 경우가 홀수인지 짝수인지 출력하기

// 시키는 대로 하면 됩니다 - 복잡하게 조건식이 쓰여 있지만 윗줄을 보면 돼요