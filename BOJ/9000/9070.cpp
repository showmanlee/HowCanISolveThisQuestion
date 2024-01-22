// 장보기
// https://www.acmicpc.net/problem/9070

#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, double> pr;

bool compare(pr& a, pr& b){
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        vector<pr> v;
        for (int i = 0; i < n; i++) {
            double a, b;
            cin >> a >> b;
            v.push_back({b, a / b});
        }
        sort(v.begin(), v.end(), compare);
        cout << v[0].first << '\n';
    }
}

// 맛살의 무게와 가격이 주어질 때, 가장 저렴하게 많은 양을 구입할 수 있는 경우의 가격 구하기

// 무게 / 가격으로 구해봅시다