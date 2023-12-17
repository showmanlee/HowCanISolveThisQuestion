// 웰컴 키트
// https://www.acmicpc.net/problem/30802

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, t, p;
    vector<int> v(6);
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    cin >> t >> p;
    int resa = 0;
    for (int i = 0; i < 6; i++) {
        if (v[i] > 0) {
            resa += ((v[i] - 1) / t) + 1;
        }
    }
    cout << resa << '\n';
    cout << (n / p) << ' ' << (n % p) << '\n';
}

// 티셔츠는 사이즈별로 t개씩 묶음으로만, 펜은 p개씩 묶음과 단품으로 살 수 있을 때, 최대한 남기지 않고 부족하지 않게 사는 티셔츠 묶음 수, 펜 묶음/개별 수 구하기

// 몫과 나머지