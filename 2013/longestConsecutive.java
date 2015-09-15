public class Solution {
    public int longestConsecutive(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        HashSet<Integer> set = new HashSet<Integer>();
        int sum=1;
        for(int i=0;i<num.length;i++)  {
            set.add(num[i]);
        }
        for(int i=0;i<num.length;i++)
        {
            if(set.contains(num[i])) 
            {
                int temp = 1;
                set.remove(num[i]);
                temp += search(set,num[i]+1,true);
                temp += search(set,num[i]-1,false);
                sum = temp > sum ? temp : sum;
            }
        }
        return sum;
    }
    private int search(HashSet<Integer> set, int cur, boolean increase)
    {
        int count =0;
        while(set.contains(cur)){
             set.remove(cur);
             count++;
             if(increase) cur++;
             else cur--;
        }
        return count;
    }
}