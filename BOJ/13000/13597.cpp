// Tri-du
// https://www.acmicpc.net/problem/13597

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << a << '\n';
    } else {
        cout << max(a, b) << '\n';
    }
}

// 3개의 숫자카드를 조합하는 게임에서 같은 카드 개수를 늘리는 게 더 강하고 그 중에서 높은카드 숫자를 만드는 게 더 강할 때, 미리 주어진 두 장의 카드를 보고 승리 확률을 최대로 높이는 카드 하나 고르기

// 두 카드 숫자가 다르다면 그 중 높은 숫자를 골라 페어 만들기
// 두 카드 숫자가 같다면 그 숫자를 골라 트리플 만들기