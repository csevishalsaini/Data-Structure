#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>

/*

leetcode 3487. Maximum Unique Subarray Sum After Deletion.cpp
Time Complexity: O(n)
- We traverse the array once and do constant-time operations (map insert/check) for each element.

Space Complexity: O(n)
- In the worst case, the unordered_map stores up to `n` unique numbers.
*/


class Solution {
public:
    int maxSum(vector<int>& nums) {
        int minimum = *max_element(nums.begin(), nums.end());
        int sum = 0;
        int flag = false;
        unordered_map<int,int>mp;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0 && mp.find(nums[i]) == mp.end()){
                flag = true;
                sum += nums[i];
            }   
            mp[nums[i]]++;

        }
        if(flag == false){
            return minimum;
        }
        return sum;
        return minimum;
    }
};

int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<obj.maxSum(arr);
    return 0;
}