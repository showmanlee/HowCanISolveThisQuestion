// Functions
// https://www.hackerrank.com/challenges/c-tutorial-functions/problem

int max_of_four(int a, int b, int c, int d){
    int great = a;
    if (great < b)
        great = b;
    if (great < c)
        great = c;
    if (great < d)
        great = d;
    return great;
}

// 언제나 만드는 함수