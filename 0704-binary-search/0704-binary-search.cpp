class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
       int mid=low+(high-low)/2;
       if(target==nums.at(mid)){
        return mid;
       } 
       else if(target>nums.at(mid)){
         low=mid+1;
       }
       else{
        high=mid-1;
       }
        }
        return -1;
        
    }
};