// Äpplen och päron
// https://www.acmicpc.net/problem/21354

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, p;
    cin >> a >> p;
    a *= 7;
    p *= 13;
    cout << (a == p ? "lika" : (a > p ? "Axel" : "Petra")) << '\n';
}

// a * 7과 p * 13의 대소관계 출력하기