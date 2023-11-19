#include<bits/stdc++.h>
using namespace std;

int maximum(vector<int> arr){
        int ans = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            ans = max(ans,arr[i]);
        }
        return ans;
}

long long banana(vector<int>& arr, int mid){
    long long int total = 0;
    for(int i=0; i<arr.size(); i++){
        int y = ceil( arr[i] / (double)mid );
        total += y;
    }
    return total;
}

int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        int start = 1;
        int end = maximum(arr);
        
        while(start <= end){
            int mid = start + (end-start)/2;
            long long int hours = banana(arr,mid);

            if(hours <= h){
                end = mid-1;
            }
            else start = mid+1;
        }
        return start;
    }

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = minEatingSpeed(arr, h);
    cout << ans << "\n";
}