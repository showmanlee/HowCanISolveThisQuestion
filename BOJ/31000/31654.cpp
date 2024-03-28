// Adding Trouble
// https://www.acmicpc.net/problem/31654

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b == c ? "correct!" : "wrong!") << '\n';
}

// a, b, c가 주어질 떄, a + b = c가 되는지 확인하기