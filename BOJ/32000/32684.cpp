// 장기
// https://www.acmicpc.net/problem/32684

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v(12);
    for (int i = 0; i < 12; i++) {
        cin >> v[i];
    }
    float a = v[0] * 13 + v[1] * 7 + v[2] * 5 + v[3] * 3 + v[4] * 3 + v[5] * 2;
    float b = v[6] * 13 + v[7] * 7 + v[8] * 5 + v[9] * 3 + v[10] * 3 + v[11] * 2 + 1.5;
    cout << (a > b ? "cocjr0208" : "ekwoo") << '\n';
}

// 장기말 개수에 따른 점수 산정 방식이 주어졌을 때 높은 사이드 구하기 