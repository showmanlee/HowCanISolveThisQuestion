// Relax! It’s just a game
// https://www.acmicpc.net/problem/4903

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   while (true) {
	int a, b;
	cin >> a >> b;
	if (a == -1 && b == -1) {
		break;
	}
	bool res = (a == 1 || b == 1);
	cout << a << '+' << b << (res ? "=" : "!=") << (a + b) << '\n';
   }
}

// 두 팀이 각각 a점과 b점을 얻었을 때, 득점 순서의 경우의 수와 a + b가 동일한지 판정하기

// (a+b)! / a! / b! - 전체 순열에서 순서에 관계없는 a개 묶음과 b개 묶음 경우 나누기
// 다만 그림을 그려보면 알 수 있듯 둘 중 한 팀이 1점만 얻지 않는 이상 무조건 다름 - x:0인 경우에는 무조건 1가지만 나오고, 두 팀 다 2점 이상인 경우에는 무조건 달라짐
// 다만 한 팀 이상이 1점을 얻은 경우 수식은 (n+1)! / n! = n+1이 되어 정답이 된다