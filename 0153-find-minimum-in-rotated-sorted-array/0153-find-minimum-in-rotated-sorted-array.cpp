class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mid>0 && mid<n && arr[mid]<=arr[mid-1] && arr[mid]<=arr[mid+1]){
                return arr[mid];
            }
            else if(arr[mid]>arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return arr[low];
    }
};