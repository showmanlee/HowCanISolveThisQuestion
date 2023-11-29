// 악수
// https://www.acmicpc.net/problem/8394

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<float, float> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = v[1] = 1;
    for (int i = 2; i <= n; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 10;
    }
    cout << v[n] << '\n';
}

// 일렬로 선 사람들이 양옆의 사람 중 한 명과 악수를 할 수 있을 때, 악수하는 경우의 수 출력하기

// 악수는 하지 않을 수도 있음 - 따라서 악수를 하지 않는 경우도 카운트해줘야 함
// 이렇게 경우의 수를 나열해보면 1, 2, 3, 5, 7, 13... - 피보나치가 나옴
// 따라서 이 문제는 피보나치 % 10하는 문제