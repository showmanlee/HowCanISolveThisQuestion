// 스택 수열
// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	stack<int> st;
	string trail = "";
	int n, c = 0;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];
	
	for (int p : input){
		if (c <= p) {
			while (c < p) {
				c++;
				st.push(c);
				trail += "+";
			}
			st.pop();
			trail += "-";
		}
		else {
			if (st.top() == p) {
				st.pop();
				trail += "-";
			}
			else {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	for (char h : trail)
		cout << h << '\n';
}

// 숫자는 반드시 순서대로 들어감
// 숫자 카운터(c)와 입력된 숫자(p)를 비교,
// c <= p라면 스택에 n까지 넣은 뒤 스택에서 p을 반환
// c > p라면 스택 top과 n이 같으면 그거 뽑고, 아니면 NO