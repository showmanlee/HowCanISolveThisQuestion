// Staircase
// https://www.hackerrank.com/challenges/staircase/problem

void staircase(int n) {
    for (int i = 1; i <= n; i++){
        for (int j = n - i; j > 0; j--)
            cout << ' ';
        for (int j = 1; j <= i; j++)
            cout << '#';
        cout << '\n';
    }
}

// 오른쪽으로 올라가는 계단 모양으로 #찍기