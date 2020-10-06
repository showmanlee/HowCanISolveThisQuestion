// Simple Array Sum
// https://www.hackerrank.com/challenges/simple-array-sum

int simpleArraySum(vector<int> ar) {
    int sum = 0;
    for (int i = 0; i < ar.size(); i++)
        sum += ar[i];
    return sum;
}