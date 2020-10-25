// Apple and Orange
// https://www.hackerrank.com/challenges/apple-and-orange/problem

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int countA = 0, countO = 0;
    for (int i = 0; i < apples.size(); i++){
        int v = a + apples[i];
        if (v >= s && v <= t)
            countA++;
    }
    for (int i = 0; i < oranges.size(); i++){
        int v = b + oranges[i];
        if (v >= s && v <= t)
            countO++;
    }
    cout << countA << '\n' << countO << '\n';
}

// 직선 공간에서 사과나무가 a, 오렌지나무가 b에 있고, 떨어진 과일의 나무와의 거리가 주어졌을 때, s~t 위치에 떨어진 사과와 오렌지의 수 구하기