#include<iostream>
using namespace std;
#include<vector>

/*
T(C) = O(N)
spae complexity = O(1) 
*/
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int ele1 = 0, ele2 =1;
        int count1 = 0, count2 = 0;
        
        for(int i = 0; i<arr.size(); i++){
            if(ele1 == arr[i]){
                count1++;
            }
            else if(ele2 == arr[i]){
                count2++;
            }
            else if(count1 == 0){
                ele1 = arr[i];
                count1 = 1;
            }
            else if(count2 == 0){
                ele2 = arr[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for(int num : arr) {
            if(num == ele1) count1++;
            else if(num == ele2) count2++;
        }

        vector<int> res;
        int n = arr.size();
        if(count1 > n/3) res.push_back(ele1);
        if(count2 > n/3) res.push_back(ele2);


        sort(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i<n; i++){
      cin>>nums[i];
    }
    vector<int>ans = obj.findMajority(nums);

    for(int i = 0; i<ans.size(); i++){
      cout<<ans[i]<<" ";
    }
    return 0;


}