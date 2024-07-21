// 온데간데없을뿐더러
// https://www.acmicpc.net/problem/31833

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    long long a, b;
    for (int i = 0; i < n; i++) {
        string p;
        cin >> p;
        s += p;
    }
    a = stoll(s);
    s = "";
    for (int i = 0; i < n; i++) {
        string p;
        cin >> p;
        s += p;
    }
    b = stoll(s);
    cout << (a < b ? a : b) << '\n';
}

// 주어진 1~2자릿수 n개 조합을 주어진 대로 모두 붙여서 썼을 때 더 작은 수 구하기