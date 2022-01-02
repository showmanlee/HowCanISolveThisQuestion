// Which Alien?
// https://www.acmicpc.net/problem/6778

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int antenna, eye;
	cin >> antenna >> eye;
	if (antenna >= 3 && eye <= 4) {
		cout << "TroyMartian\n";
	}
	if (antenna <= 6 && eye >= 2) {
		cout << "VladSaturnian\n";
	}
	if (antenna <= 2 && eye <= 3) {
		cout << "GraemeMercurian\n";
	}
}

// 주어진 안테나 수와 눈 수를 보고 어떤 외계인인지 판별하기

// 안테나 3개 이상, 눈 4개 이하인 경우 TroyMartian, 안테나 6개 이하, 눈 2개 이상인 경우 VladSaturnian, 안테나 2개 이하, 눈 3개 이하인 경우 GraemeMercurian
// 이걸 보면서 조건문 걸로 출력하면 됨 - 없으면 아예 출력하지 않기