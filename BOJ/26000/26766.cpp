// Serca
// https://www.acmicpc.net/problem/26766

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << " @@@   @@@ \n";
		cout << "@   @ @   @\n";
		cout << "@    @    @\n";
		cout << "@         @\n";
		cout << " @       @ \n";
		cout << "  @     @  \n";
		cout << "   @   @   \n";
		cout << "    @ @    \n";
		cout << "     @     \n";
	}
}

// 주어진 수만큼 하트 출력하기

// 하면 되지요 - 빠른 출력 생각해서