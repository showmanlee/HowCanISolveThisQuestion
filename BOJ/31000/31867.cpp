// 홀짝홀짝
// https://www.acmicpc.net/problem/31867

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        int p = s[i] - '0';
        if (s[i] % 2 == 1) {
            o++;
        } else {
            e++;
        }
    }
    cout << (o == e ? -1 : (o < e ? 0 : 1)) << '\n';
}

// 주어진 수의 자릿수별 홀짝 여부를 판정하여 홀수와 짝수 중 누가 더 많은지 출력하기