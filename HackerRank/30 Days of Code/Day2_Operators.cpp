// Day 2: Operators
// https://www.hackerrank.com/challenges/30-operators/problem

#include <bits/stdc++.h>

using namespace std;

void solve(double meal_cost, int tip_percent, int tax_percent) {
    double res = meal_cost + (tip_percent / 100.0 * meal_cost) + (tax_percent / 100.0 * meal_cost);
    cout << round(res) << endl;
}

int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}

// 고기 가격, 팁, 세금 비율이 주어졌을 때 최종 구매가를 반올림하여 출력하기
// 이 언어에서 round 함수를 쓰는 법을 아나요? - cmath에서 round 사용