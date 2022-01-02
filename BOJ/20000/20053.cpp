// 최소, 최대 2
// https://www.acmicpc.net/problem/20053

#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, min = 1000001, max = -1000001;
        cin >> n;
        for (int i = 0; i < n; i++){
            int p;
            cin >> p;
            if (p < min)
                min = p;
            if (p > max)
                max = p;
        }
        cout << min << ' ' << max << '\n';
    }
}

// BOJ에서는 이렇게 입력 데이터가 무식하게 많은 경우가 많으니 저 2개 붙이는 걸 생활화합시다