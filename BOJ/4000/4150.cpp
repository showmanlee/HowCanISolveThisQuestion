// 피보나치 수
// https://www.acmicpc.net/problem/4150

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string adder(string a, string b){
    string res = "";
    if (a.length() < b.length())
		swap(a, b);
	int al = a.length();
	int bl = al - b.length();
	bool up = false;
	for (int i = al - 1; i >= 0; i--) {
		int n = 0;
		if (i - bl >= 0)
			n += (a[i] - '0') + (b[i - bl] - '0');
		else
			n += (a[i] - '0');
		if (up)
			n++;
		up = n >= 10;
		n %= 10;
		res = to_string(n) + res;
	}
	if (up)
		res = "1" + res;
    return res;
}

int main(void) {
    int n;
    cin >> n;
    vector<string> pib(n + 1);
    pib[0] = "0";
    pib[1] = "1";
    for (int i = 2; i <= n; i++)
        pib[i] = adder(pib[i-1], pib[i-2]);
    cout << pib[n] << '\n';
}

// 결과값이 1000자리 이하인 것을 찾는 피보나치 수
// 예전에 만들어두었던 문자열로 더하기를 써보자