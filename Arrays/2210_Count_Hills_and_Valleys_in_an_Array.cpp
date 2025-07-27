#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            int j = i-1;
            int k = i+1;
            bool flagleft = false;
            bool flagright = false;

           while(j>=0 && nums[i] == nums[j]){
            j--;
           }
           while(k<nums.size() && nums[i] == nums[k]){
            k++;
           }
            if(j>=0 && k<nums.size() && nums[j]<nums[i] && nums[k]<nums[i]){
                result++;
            }
            if(j>=0 && k<nums.size() && nums[j]>nums[i] && nums[k]>nums[i]){
                result++;
            }
        }
        return result;
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
  cout<<obj.countHillValley(nums);

  return 0;
}