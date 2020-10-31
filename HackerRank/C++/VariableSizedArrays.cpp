// Variable Sized Arrays
// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++){
        vector<int> vv;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++){
            int p;
            cin >> p;
            vv.push_back(p);
        }
        v.push_back(vv);
    }
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << v[a][b] << '\n';
    }
    return 0;
}

// C++의 동적 배열 vector
// 대충 2차원 vector<int>를 만들어서 값을 찾아내라는 말