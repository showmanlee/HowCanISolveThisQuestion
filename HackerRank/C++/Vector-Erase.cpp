// Vector-Erase
// https://www.hackerrank.com/challenges/vector-erase/problem

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
    int r, a, b;
    cin >> r;
    v.erase(v.begin() + r - 1);
    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    return 0;
}

// vector에서 원소 지우기
// vector.erase(vector.begin() + ?) or (v.begin() + a, v.begin() + b);