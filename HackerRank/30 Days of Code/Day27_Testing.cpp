// Day 27: Testing
// https://www.hackerrank.com/challenges/30-testing/problem

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

class TestDataEmptyArray {
public:
    static vector<int> get_array() {
        return vector<int>();
    }

};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        vector<int> v;
        v.push_back(2);
        v.push_back(1);
        v.push_back(3);
        v.push_back(5);
        return v;
    }

    static int get_expected_result() {
        return 1;
    }

};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        vector<int> v;
        v.push_back(2);
        v.push_back(1);
        v.push_back(1);
        v.push_back(5);
        return v;
    }

    static int get_expected_result() {
        return 1;
    }

};


void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array();
        auto result = minimum_index(seq);
    } catch (invalid_argument& e) {
        return;
    }
    assert(false);
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}

// 단위 테스트를 위한 테스트 코드 작성하기
// 배열의 최솟값이 있는 인덱스를 알아내는 코드, 여기서 빈 배열이 들어간 경우(err), 모두 다른 값이 들어가있는 경우, 최솟값이 정확히 2개인 경우를 테스트하고자 한다
// #include <cassert> 삽입 후 assert(조건) 함수로 확인하기