// class Solution {
// private:
//    void inc_exl_game(vector<int>nums,vector<int>output,vector<vector<int>> &ans,int index){
//         if(index >= nums.size()){
//            ans.push_back(output);
//            return;
//         }

//         //exclusion

//         inc_exl_game(nums,output,ans,index+1);

//         // inclusion
//         int incl = nums[index];
//         output.push_back(incl);
//         inc_exl_game(nums,output,ans,index+1);
//    }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> dummy;
//         vector<vector<int>> ans;
//         inc_exl_game(nums,dummy,ans,0);
//         return ans;
//     }
// };