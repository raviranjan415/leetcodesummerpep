class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int left = 0, right = m;

        while(left <= right) {

            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            int nums1_left  = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right = (i == m) ? INT_MAX : nums1[i];

            int nums2_left  = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right = (j == n) ? INT_MAX : nums2[j];

            if(nums1_left <= nums2_right && nums2_left <= nums1_right) {

                if((m + n) % 2 == 0) {
                    return (max(nums1_left, nums2_left) + 
                            min(nums1_right, nums2_right)) / 2.0;
                } else {
                    return max(nums1_left, nums2_left);
                }
            }
            else if(nums1_left > nums2_right) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};