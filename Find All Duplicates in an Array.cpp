class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int i=0;
        vector<int> res;
        // while(i<nums.size()){
            
            for(int i=0; i<nums.size(); i++){
                if (nums[abs(nums[i])-1] >= 0) 
                    nums[abs(nums[i])-1] = -nums[abs(nums[i])-1]; 
                else{
                    res.push_back(abs(nums[i]));
                }
            }
            
//             if(nums[i] == -1)
//                 i++;
//             else if(nums[nums[i]-1] == -1){
//                 cout<<"A ";
//                 if(find(res.begin(), res.end(), nums[i]) == res.end())
//                     res.push_back(nums[i]);
//                 i++;
                
//             }
//             else{
//                 int temp = nums[i];
//                 nums[i] = nums[nums[i]-1];
//                 nums[temp-1] = -1;
//                 cout<<"B ";
//             }
        // }
        return res;
    }
};
