// Pizza Pricing
// https://www.acmicpc.net/problem/4573

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<float, float> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cnt = 0;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        cnt++;
        vector<pr> v(n);
        for (int i = 0; i < n; i++) {
            float d, p;
            cin >> d >> p;
            float r = d / 2;
            float a = r * r * 3.14159;
            v[i] = {p / a, d};
        }
        sort(v.begin(), v.end());
        cout << "Menu " << cnt << ": " << ((int)v[0].second) << '\n';
    }
}

// 피자의 지름과 가격이 주어질 때, 가장 가성비가 좋은 피자의 지름 출력하기

// 지름이 주어지므로 넓이를 구하기 위해 반지름으로 만들어줘야 함
// 그것만 신경써준다면 가격 / 넓이 중 가장 작은 거 출력해주면 됨