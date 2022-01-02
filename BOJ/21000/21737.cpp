// SMUPC 계산기
// https://www.acmicpc.net/problem/21737

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	bool printed = false;
	char op = 'a';
	string digit;
	int res = 0;
	for (char c : s) {
		if (c >= '0' && c <= '9')
			digit += c;
		else {
			if (op != 'a') {
				int opp = stoi(digit);
				if (op == 'S')
					res -= opp;
				else if (op == 'M')
					res *= opp;
				else if (op == 'U')
					res /= opp;
				else if (op == 'P')
					res += opp;
			}
			else
				res = stoi(digit);
			if (c == 'C') {
				printed = true;
				cout << res << ' ';
			}
			else 
				digit = "";
			op = c;
		}
	}
	if (!printed)
		cout << "NO OUTPUT";
	cout << '\n';
}

// S는 뺄셈, M은 곱셈, U는 나눗셈, P는 덧셈, C는 출력으로 구성된 수식(앞에서부터 계산)에서 결과 출력하기

// 수식은 모두 붙어서 나오고, C가 여러번 나올 수 있고(공백으로 구분), 음수가 나올 수 없으나 수가 0으로 시작할 수는 있다
// 그리고 그 외의 내용은 모두 유효한 식임이 보장된다(부호가 연속으로 등장하지 않고, 부호 다음 C가 바로 나오지 않고, C 다음에는 알파벳이 나오는 등)
// 수식의 문자를 순회하며 우리가 저장해줘야 할 것들은 마지막으로 등장한 기호, 지금까지 쌓인 숫자, 현재까지의 결과값
// 거기에 NO OUTPUT을 표시하기 위해 출력 여부 변수도 생성

// 수식 문자 순회 중에는 숫자가 등장한 경우 숫자를 계속 쌓아둔다
// 알파벳이 나온 경우에는 그에 맞는 연산을 하면 되는데, 알파벳이 처음 등장한 경우에는 쌓인 숫자를 결과값에 대입한다
// 그렇지 않다면 지난 기호에 따라 결과값에 쌓인 숫자를 연산한다
// 이후 출력한다면 결과값을 출력하고, 그렇지 않다면 지금까지 쌓인 수를 비워준다 - 그리고 지난 기호를 저장한다
// 이 과정을 반복하면서 출력한 글자를 한 줄 안에 출력하기