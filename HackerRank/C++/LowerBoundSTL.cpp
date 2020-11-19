// Lower Bound - STL
// https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int p;
        cin >> p;
        auto l = lower_bound(v.begin(), v.end(), p);
        cout << (*l == p ? "Yes " : "No ") << (l - v.begin() + 1) << '\n';
    } 
    return 0;
}

// lower_bound(begin(), end(), n);
// 정렬된 배열 안에서 이분탐색으로 해당 값(보다 바로 큰 값)을 찾아 iterator를 반환
// iterator - v.begin() = 해당 인덱스값, *iterator = 찾아낸 값
// 바로 큰 값을 찾아내려면 upper_bound를 사용