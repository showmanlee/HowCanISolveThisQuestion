// 루미의 진정한™ 보라색 찾기
// https://www.acmicpc.net/problem/33663

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	float ha, hb, sa, sb, va, vb, r, g, b;
	cin >> ha >> hb >> sa >> sb >> va >> vb >> r >> g >> b;
	float m = min(min(r, g), b);
	float v = max(max(r, g), b);
	float s = 255 * ((float)v - m) / (float)v;
	float h = 0;
	if (v == r) {
		h = 60.f * (g - b) / ((float)v - m);
	} else if (v == g) {
		h = 60.f * (b - r) / ((float)v - m) + 120;
	} else {
		h = 60.f * (r - g) / ((float)v - m) + 240;
	}
	if (h < 0) {
		h += 360;
	}
	bool res = (ha <= h && h <= hb) && (sa <= s && s <= sb) && (va <= v && v <= vb);
	cout << "Lumi will " << (res ? "" : "not ") << "like it.\n";
}

// 주어진 RGB 값을 HSV 값으로 변환할 때, HSV가 범위 안으로 들어오는지 판정하기