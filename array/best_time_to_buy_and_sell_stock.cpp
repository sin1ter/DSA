#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n) {
    if(n == 0 or n == 1) return 0;
    int minimum_price = arr[0];
    int maximum_profit = 0;
    for(int i = 0; i < n; i++) {
        minimum_price = min(minimum_price, arr[i]);
        int profit = abs(minimum_price - arr[i]);
        maximum_profit = max(maximum_profit, profit);
    }
    return maximum_profit;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxProfit(arr, n) << '\n';
}
