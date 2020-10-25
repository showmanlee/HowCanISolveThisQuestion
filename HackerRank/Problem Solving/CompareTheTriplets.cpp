// Compare the Triplets
// https://www.hackerrank.com/challenges/compare-the-triplets/problem

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    vector<int> ret(2);
    for (int i = 0; i < 3; i++){
        if (a[i] > b[i])
            ret[0]++;
        else if (a[i] < b[i])
            ret[1]++;
    }
    return ret;
}

// a, b가 낸 3개의 숫자를 비교해 a가 더 크면 a 점수를 ++, b가 더 크면 b 점수를 ++