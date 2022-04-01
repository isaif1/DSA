class Solution {
public:
    //upper bound
    int upper(vector<int>& nums,int n,int tg){
    int l=0,r=n-1;
    while(l<r){
       int mid = (l+r)/2+1; //doing because devision is floor and less biased

       if(nums[mid]>tg)r=mid-1;
        else l=mid;
    }
        //break to tabhi hoga jb both are equal
    return nums[r]==tg ? r:-1;   //check for l because r to negetive ho skta hai and gives runtime error
    }
    
    //for lower bound
    int lower(vector<int>& nums,int n,int tg){
        int l=0,r=n-1;
        while(l<r){
            int mid = (l+r)/2;
            
           if(nums[mid]>=tg)r=mid;
            else l=mid+1;
        }
        return nums[l]==tg ? l:-1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(n==0)return {-1,-1};
        
        int l=lower(nums,n,target);
        int r=upper(nums,n,target);
        if(l<0)return {-1,-1};
        return {l,r};
    }
};