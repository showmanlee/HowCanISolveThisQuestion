// 쌍의 합
// https://www.acmicpc.net/problem/5217

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cout << "Pairs for " << p << ": ";
        for (int j = 1; j <= p / 2; j++) {
            if (j == (p - j)) {
                break;
            }
            if (j > 1) {
                cout << ", ";
            }
            cout << j << ' ' << (p - j);
        }
        cout << '\n';
    }
}

// 중복 없이 합으로 주어진 수를 나타낼 수 있는 수의 쌍 구하기

// 구하는 건 쉬운데 출력이 까다로운 편 - 구하는 거야 반복문만 잘 만들어주면 됨
// 출력 방식은 java 코드 예시를 보며 적절히 이식하기