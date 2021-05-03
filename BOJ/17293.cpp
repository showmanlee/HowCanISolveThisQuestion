// 맥주 99병
// https://www.acmicpc.net/problem/17293

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = n;
	while (p > 1) {
		cout << p << " bottles of beer on the wall, " << p << " bottles of beer.\n";
		p--;
		cout << "Take one down and pass it around, " << p << " bottle" << (p == 1 ? "" : "s") << " of beer on the wall.\n\n";
	}
	cout << "1 bottle of beer on the wall, 1 bottle of beer.\n";
	cout << "Take one down and pass it around, no more bottles of beer on the wall.\n\n";
	cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
	cout << "Go to the store and buy some more, " << n << " bottle" << (n == 1 ? "" : "s") << " of beer on the wall.\n";
}

// 유명한 맥주 99병 출력 문제
// 이 문제의 포인트는 "1 bottle"을 제대로 처리하는 것 - 어떠한 경우에도 "1 bottles"는 존재할 수 없음에 주의
// "1 bottle"이 등장하는 포인트 - 2병에서 한 병으로 줄은 순간, 1병을 마실 때, 1병만 있던 상황에서 맥주를 채우는 순간
// 따라서 반복문으로만으로는 풀 수 없고, 필연적으로 조건문이 등장할 수밖에 없음 - 사실상 이 문제의 존재 이유