// Yangjojang of The Year
// https://www.acmicpc.net/problem/11557

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        vector<pr> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].second >> v[i].first;
            v[i].first *= -1;
        }
        sort(v.begin(), v.end());
        cout << v[0].second << '\n';
    }
}

// 술을 가장 많이 마시는 학교 구하기
// pair 정렬 - 기준이 되는 곳을 first로
// 내림차순 정렬이니 -로 받아서 정렬합시다