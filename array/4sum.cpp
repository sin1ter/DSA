#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int>& arr, int n, int target) {
    set<vector<int>> st;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            set<int> hashset;
            for(int k = j + 1; k < n; k++) {
                int l = target - (arr[i] + arr[j] + arr[k]);
                if(hashset.find(l) != hashset.end()) {
                    vector<int> temp{arr[i], arr[j], arr[k], l};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumOptimal(vector<int>& arr, int n, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        if(i > 0 and arr[i] == arr[i - 1]) continue;
        for(int j = i + 1; j < n; j++) {
            if(j > i + 1 and arr[j] == arr[j - 1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l) {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum == target) {
                    vector<int> temp{arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l and arr[k] == arr[k - 1]) k++;
                    while(k < l and arr[l] == arr[l + 1]) l--;
                }
                else if(sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = fourSumOptimal(nums, n, target);
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
