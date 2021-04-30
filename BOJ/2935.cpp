// 소음
// https://www.acmicpc.net/problem/2935

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string a, o, b;
	cin >> a >> o >> b;
	if (a.length() < b.length())
		swap(a, b);
	if (o == "*") {
		cout << 1;
		for (int i = 0; i < a.length() + b.length() - 2; i++)
			cout << 0;
	}
	else {
		if (a.length() == b.length()) {
			cout << 2;
			for (int i = 0; i < a.length() - 1; i++)
				cout << 0;
		}
		else {
			cout << 1;
			for (int i = 0; i < a.length() - b.length() - 1; i++)
				cout << 0;
			cout << 1;
			for (int i = 0; i < b.length() - 1; i++)
				cout << 0;
		}
	}
	cout << '\n';
}

// 10의 제곱 꼴인 자연수를 곱하거나 더한 결과는?
// 일단 수는 문자열로 받아주기 - 어차피 길이 제한 때문에 정수로는 못받음
// 기본적으로 더하기인 경우 긴 수 사이에 1을 넣고, 곱하기인 경우 두 수에 나오는 0의 개수를 서로 더한다
// 곱하기의 경우 처음에 1을 적은 후 두 자연수 길이 - 2(1 자리)만큼 0을 찍어준다
// 더하기의 경우 처음에 1을 찍고, a 길이 - b 길이 - 1(1 자리)만큼 0을 찍어 a의 10...을 찍고, 1을 다시 찍고 b 길이 - 1(1 자리)만큼 0을 찍어 b를 찍는다
// 단, 여기서 a와 b의 길이가 같은 경우 답이 20...이 되어야 함 - 그리고 이 상황일 때 위의 알고리즘으로는 무한 0이 찍힘
// 따라서 길이가 같은 경우를 따로 생각해주기