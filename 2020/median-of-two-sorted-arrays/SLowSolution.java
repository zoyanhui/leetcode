import java.io.IOException;

/**
 * O(m+n)解法
 *
 * Created by zhouyanhui on 2020/6/9.
 */
public class SLowSolution {

    class Solution {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int total = nums1.length + nums2.length;
            boolean needTwo = (total & 0x1) == 0;
            int k = (total+1) / 2;
            int i = 0, j = 0, c = 0;
            double num = 0d;
            while(c < k){
                c++;
                if(i < nums1.length && j < nums2.length){
                    if(nums1[i] < nums2[j]){
                        num = nums1[i];
                        i++;
                    }else{
                        num = nums2[j];
                        j++;
                    }
                }else if(i < nums1.length){
                    num = nums1[i];
                    i++;
                }else{
                    num = nums2[j];
                    j++;
                }
            }
            if(needTwo){
                if(i < nums1.length && j < nums2.length){
                    if(nums1[i] < nums2[j]){
                        num += nums1[i];
                    }else{
                        num += nums2[j];
                    }
                }else if(i < nums1.length){
                    num += nums1[i];
                }else{
                    num += nums2[j];
                }
                num /= 2;
            }
            return num;
        }
    }

    public static void main(String[] args) throws IOException {
        SLowSolution sLowSolution = new SLowSolution();
        SLowSolution.Solution s = sLowSolution.new Solution();
        double medianSortedArrays = s.findMedianSortedArrays(new int[] {1, 2, 3}, new int[] {4, 5});
        System.out.println(medianSortedArrays);
    }
}
