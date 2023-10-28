// 치즈버거 만들기
// https://www.acmicpc.net/problem/30017

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << (b * 2 + 1)  << '\n';
    } else {
        cout << (a * 2 - 1) << '\n';
    }
}

// 패티와 치즈 수가 주어지고, 치즈버거를 만들 때 패티 p개와 치즈 p-1개가 필요하다고 할 때, 치즈버거 하나에 넣을 수 있는 패티와 치즈의 합 구하기

// 패티가 많으면 치즈 수 + 1만큼 패티를 넣고, 치즈가 더 많으면 패티 수 - 1만큼 치즈를 넣는다