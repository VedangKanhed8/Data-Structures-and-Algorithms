/*
    Time Complexity = O (log(min(N,M)))
    Space Complexity = O(1)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int N = nums1.size();
        int M = nums2.size();
        
        int low = 0;
        int high = N;
        while(low <= high) {
            int cut1 = (low+high) >> 1LL;
            int cut2 = ((N+M+1) >> 1LL) - cut1;
            
            int left1 = (cut1==0) ? INT_MIN : nums1[cut1-1];
            int left2 = (cut2==0) ? INT_MIN : nums2[cut2-1];
            int right1 = (cut1==N) ? INT_MAX : nums1[cut1];
            int right2 = (cut2==M) ? INT_MAX : nums2[cut2];
            
            if(left1<=right2 and left2<=right1) {
                if((N+M)&1) return max(left1,left2);
                return (max(left1,left2)+min(right1,right2))/2.0;
            }
            else if(left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};
