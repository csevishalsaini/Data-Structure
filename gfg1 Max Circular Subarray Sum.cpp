#include<iostream>
using namespace std;
#include<vector>


/*
Time Complexity: O(n)
- We iterate through the array twice (once for min subarray, once for max subarray).
- Each pass is linear.

Space Complexity: O(1)
- We use only constant extra space (a few variables), no extra data structures.
*/

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        
        
        int resultmin = arr[0];
        int total1 = arr[0];
        int size = arr.size();
        int mini = arr[0];
        
        
        for(int i = 1; i<size; i++){
            if(mini>0){
                mini = 0;
                
            }
            mini += arr[i];
            
            total1 += arr[i];
            resultmin =min(resultmin,mini);
        }
        
        int resultmax = arr[0];
        int maxi = arr[0];
        for(int i = 1; i<arr.size(); i++){
            if (maxi < 0) maxi = 0;
            maxi += arr[i];
            
            
            resultmax = max(maxi,resultmax);
        }
        
        
        if (resultmax < 0) return resultmax;
        
        return max(resultmax, total1-resultmin);
    }
};

int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int>nums(n);

    for(int i =0; i<n; i++){
        cin>>nums[i];
    }

    cout<<obj.maxCircularSum(nums);

    return 0;
}