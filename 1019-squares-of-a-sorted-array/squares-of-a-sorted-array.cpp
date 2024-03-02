class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> n(nums.size(),0);
        int i=0;
        int j=nums.size()-1;
        int k=nums.size()-1;
        while(i<=j){
            int a=nums[i]*nums[i];
            int b=nums[j]*nums[j];
            if(a>b){
                n[k]=a;
                i++;
            }
            else{
                n[k]=b;
                j--;
            }
            k--;
        }
        return n;
    }
};