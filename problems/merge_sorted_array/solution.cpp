class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if (n==0) return ;
        m--,n--; 
        int i = m+n+1;
        while (i>=0 && m>=0 && n>=0){
            if (nums1[m] > nums2[n]){
                nums1[i--] = nums1[m--];
            }
            else
                nums1[i--] = nums2[n--];
        }
        while(n>=0){
            nums1[i--] = nums2[n--];
        }
        return ;
    }
};