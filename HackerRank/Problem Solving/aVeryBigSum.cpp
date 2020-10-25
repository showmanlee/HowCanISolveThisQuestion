// a Very Big Sum
// https://www.hackerrank.com/challenges/a-very-big-sum/problem

long aVeryBigSum(vector<long> ar) {
    long res = 0;
    for (int i = 0; i < ar.size(); i++)
        res += ar[i];
    return res;
}

// int 범위를 벗어날 수 있는 수 최대 10개 더하기