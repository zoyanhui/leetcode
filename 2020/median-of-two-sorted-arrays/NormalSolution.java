/**
 * Created by zhouyanhui on 2020/6/9.
 */
public class NormalSolution {
    class Solution {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int total = nums1.length + nums2.length;
            boolean needTwo = (total & 0x1) == 0;
            if(needTwo){
                return (findKthSortedArrays(nums1, 0, nums1.length - 1, nums2, 0, nums2.length - 1, total / 2) + findKthSortedArrays(nums1, 0, nums1.length - 1, nums2, 0, nums2.length - 1, total / 2 + 1))/2.0;
            }else{
                return findKthSortedArrays(nums1, 0, nums1.length - 1, nums2, 0, nums2.length - 1, total / 2 + 1);
            }
        }
        private int findKthSortedArrays(int[] nums1, int b1, int e1, int[] nums2, int b2, int e2, int k){
            if(b1 > e1){
                return nums2[b2 + k - 1];
            }
            if(b2 > e2){
                return nums1[b1 + k - 1];
            }
            if(k == 1){
                return nums1[b1] > nums2[b2] ? nums2[b2] : nums1[b1];
            }
            int half = k / 2;
            int nb1 = Math.min(b1 + half - 1, e1);
            int nb2 = Math.min(b2 + half - 1, e2);
            if(nums1[nb1] <= nums2[nb2]){
                return findKthSortedArrays(nums1, nb1+1, e1, nums2, b2, e2, k - nb1 + b1 - 1);
            }else{
                return findKthSortedArrays(nums1, b1, e1, nums2, nb2+1, e2, k - nb2 + b2 - 1);
            }
        }
    }
}
