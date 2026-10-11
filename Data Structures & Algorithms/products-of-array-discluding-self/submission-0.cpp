class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int>ans(nums.size(),1);
      //prefix
      int val=1;
      for(int i=1;i<nums.size();i++){
         
         val= nums[i-1]*val;
         ans[i]=val;
      }
       int val2=1;
      for(int j=nums.size()-2;j>=0;j--){
       val2=nums[j+1]*val2;
       ans[j]=val2*ans[j];
      }
      return ans;
    }
};
