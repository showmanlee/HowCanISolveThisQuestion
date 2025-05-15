// Keys, Phone, Wallet
// https://www.acmicpc.net/problem/33643

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	bool keys = false, phone = false, wallet = false;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "keys") {
			keys = true;
		} else if (s == "phone") {
			phone = true;
		} else if (s == "wallet") {
			wallet = true;
		}
	}
	if (!keys) {
		cout << "keys\n";
	}
	if (!phone) {
		cout << "phone\n";
	}
	if (!wallet) {
		cout << "wallet\n";
	}
	if (keys && phone && wallet) {
		cout << "ready\n";
	}
}

// keys, phone, wallet이 주어진 문자열 안에 있는지 확인하기