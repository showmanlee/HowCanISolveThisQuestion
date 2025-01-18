// Gorivo
// https://www.acmicpc.net/problem/14065

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    cout << fixed;
	cout.precision(6);

    double d;
    cin >> d;
    d = 100.0 / (1.609344 / 3.785411784 * d);

    cout << d << '\n';
}

// gal/mile을 l/100km로 바꾸기