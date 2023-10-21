


#include <bits/stdc++.h>

using namespace std;

vector<int> merge_array(int arr[], int brr[], int n, int m) {
    int left = 0;
    int right = 0;
    vector<int> temp;

    while (left < n && right < m) {
        if (arr[left] <= brr[right]) {
            if (temp.size() == 0 || temp.back() != arr[left]) 
                temp.push_back(arr[left]);
            left++;
        } 
        else {
            if (temp.size() == 0 || temp.back() != brr[right])
                temp.push_back(brr[right]);
            right++;
        }
    }

    while (left < n) {
        if (temp.size() == 0 || temp.back() != arr[left]) 
            temp.push_back(arr[left]);
        left++;
    }

    while (right < m) {
        if (temp.size() == 0 || temp.back() != brr[right])
            temp.push_back(brr[right]);
        right++;
    }

    return temp; 
}

int main()

{
  int n, m;
  cin >> n >> m;
  int arr1[n], arr2[m];
  for(int i = 0; i < n; i++) {
      cin >>arr1[i];
  }
  for(int i = 0; i < m; i++) {
      cin >> arr2[i];
  }
  
  vector < int > Union = merge_array(arr1, arr2, n, m);
  
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
