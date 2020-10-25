// Sorting: Bubble Sort
// https://www.hackerrank.com/challenges/ctci-bubble-sort/

void countSwaps(vector<int> a) {
    int count = 0;
    for (int i = 0; i < a.size(); i++){
        for (int j = 1; j < a.size(); j++){
            if (a[j - 1] > a[j]){
                swap(a[j - 1], a[j]);
                count++;
            }
        }
    }
    cout << "Array is sorted in " << count << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size() - 1] << endl;
}

// 버블 정렬을 구현하고, 스왑 횟수와 처음 원소, 끝 원소를 출력하라