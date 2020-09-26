// 숫자의 개수
// https://www.acmicpc.net/problem/2577

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	vector<int> count(10);
	int a, b, c;
	cin >> a >> b >> c;
	string s = to_string(a * b * c);
	for (int i = 0; i < s.length(); i++)
		count[s[i] - '0']++;
	for (int i = 0; i < 10; i++)
		cout << count[i] << endl;
}