#include<bits/stdc++.h>
using namespace std;

int longest_consecutive(vector<int>& arr, int n) { // for this time complexity is O(nlogn + n) and space complexity is O(1)
    int longest = 0;
    int cnt = 0;
    int lastsmall = INT_MIN;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(arr[i] - 1 == lastsmall) {
            cnt++;
            lastsmall = arr[i];
        }
        else if(arr[i] - 1 != lastsmall) {
            cnt = 1;
            lastsmall = arr[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int longestConsecutive(vector<int>& nums) { // for this time complexity is O(n) + O(2n) = O(3n) and space complexity is O(n)
        unordered_set<int> set;
        for(int i : nums){
            set.insert(i);
        }
        int longest = 0;
        for(int i : nums){
            if(set.find(i-1) == set.end()){
                int currentNumber = i;
                int currentConsecutiveSequence = 1;
                while(set.find(currentNumber+1) != set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longest = max(longest, currentConsecutiveSequence);
            }
        }
        return longest;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << longestConsecutive(arr); 

}