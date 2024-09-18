// Dusa And The Yobis
// https://www.acmicpc.net/problem/32327

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int d;
    cin >> d;
    vector<int> v;
    int p;
    while (cin >> p) {
        v.push_back(p);
    }
    for (int i : v) {
        if (d > i) {
            d += i;
        } else {
            cout << d << '\n';
            break;
        }
    }
}

// 크기가 d인 몬스터가 차례로 들어오는 다른 몬스터를 먹는데 자신보다 크기가 작으면 먹고 아니면 도망갈 때, 최종 크기 구하기