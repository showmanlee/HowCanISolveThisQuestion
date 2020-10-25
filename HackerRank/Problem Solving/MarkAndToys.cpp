// Mark and Toys
// https://www.hackerrank.com/challenges/mark-and-toys/

int maximumToys(vector<int> prices, int k) {
    int sum = 0;
    sort(prices.begin(), prices.end());
    for (int i = 0; i < prices.size(); i++){
        sum += prices[i];
        if (sum > k)
            return i;
    }
    return prices.size();
}

// 가진 돈로 살 수 있는 장난감의 최대 수 구하기