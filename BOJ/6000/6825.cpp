// Body Mass Index
// https://www.acmicpc.net/problem/6825

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    double h, w;
    cin >> w >> h;
    double res = w / (h * h);
    if (res > 25.0) {
        cout << "Overweight";
    } else if (res < 18.5) {
        cout << "Underweight";
    } else {
        cout << "Normal weight";
    }
    cout << '\n';
}

// 몸무게와 키가 주어질 때, BMI 구해서 과체중/저체중 여부 판정하기

// 단순한 계산 문제