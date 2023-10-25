#include<bits/stdc++.h>
using namespace std;

bool two_sum(int arr[], int n, int t) {
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        int rem = t - arr[i];
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + (high - low)) / 2;
            if(arr[mid] == rem) return true;
            else if(arr[mid] > rem) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    }
    return false;
    // for this we can return if there is possible two sum in the array and we can't return the index
    // for this time complexity is O(n*log(n)) and space complexity is O(1)
}

vector<int> two_sum_usin_map(int arr[], int n, int t) {
    map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        int complement = t - arr[i];
        if(mpp.find(complement) != mpp.end()) {
            return {mpp[complement], i};
        }
        mpp[arr[i]] = i;
    }
    return {};
    //for this time complexity is O(n*logn) but if we use unordered the best and average case will be O(n) but worst case will be O(n^2)
    // space complexity is O(n)
}

vector<int> twosum_2pointer(int arr[], int n, int t) {
    sort(arr, arr + n);
    int left = 0, right = n - 1;
    for(int i = 0; i < n; i++) {
        int sum = arr[left] + arr[right];
        if(sum == t) {
            return{left, right};
        }
        else if(sum < t) left++;
        else right--;
    } 
    // using the two pointer it will not be possible to return the index without using extra time. 
    // first we have to store the index along with the element then sort the array and then we can return the index which will take more time then O(n*logn)
    // it is possible wheather there is the summation is there or not wihtout using he extra space like the map
    // the time complexity is O(n) + O(nlogn) for sorting the O(nlogn) and in the worst case O(n) for traversing the array from left and right
}

int main() {
    int n, t;
    cin >> n >> t;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = two_sum_usin_map(arr, n, t);
    if(!result.empty()) {
        cout << result[0] << ' ' << result[1] << '\n';
    }
    else {
        cout << "Nada" << '\n';
    }

    
}