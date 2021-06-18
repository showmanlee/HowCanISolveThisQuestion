// 선린인터넷고등학교 교가
// https://www.acmicpc.net/problem/21964

#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = n - 5; i < n; i++)
		cout << s[i];
	cout << '\n';
}

// 주어진 문자열에서 마지막 5글자 출력하기

// 문자열의 길이도 같이 주어지므로 n-5~n-1을 출력하면 됨 - n은 5 이상임이 보장됨