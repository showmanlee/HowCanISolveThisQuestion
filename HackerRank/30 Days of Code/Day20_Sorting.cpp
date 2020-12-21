// Day 20: Sorting
// https://www.hackerrank.com/challenges/30-sorting/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }

    int swaped = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swaped++;
            }
        }
    }
    cout << "Array is sorted in " << swaped << " swaps.\n";
    cout << "First Element: " << a[0] << "\nLast Element: " << a[n-1] << '\n';
    return 0;
}

// 버블 정렬 구현하고 교체 횟수 구하기
