// Arrays: Left Rotation
// https://www.hackerrank.com/challenges/ctci-array-left-rotation/

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> n;
    for(int i = 0; i < a.size(); i++){
        n.push_back(a[(i + d) % a.size()]);
    }
    return n;
}

// 배열 a의 원소들을 d만큼 왼쪽으로 이동