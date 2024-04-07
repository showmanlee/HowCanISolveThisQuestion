// 이 별은 무슨 색일까
// https://www.acmicpc.net/problem/30676

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n < 425) {
        cout << "Violet";
    } else if (n < 450) {
        cout << "Indigo";
    } else if (n < 495) {
        cout << "Blue";
    } else if (n < 570) {
        cout << "Green";
    } else if (n < 590) {
        cout << "Yellow";
    } else if (n < 620) {
        cout << "Orange";
    } else if (n <= 780) {
        cout << "Red";
    }
    cout << '\n';
}

// 파장의 값이 주어질 때, 해당 파장의 색상 출력하기

// 범위 체크