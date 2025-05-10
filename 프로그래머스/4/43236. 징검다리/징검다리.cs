using System;
using System.Collections.Generic;
using System.Linq;
public class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        List<int> rockList = rocks.ToList();
        int right  = distance;
        int left =1;
        rockList.Add(distance);
        rockList.Sort();
        
        while(left<=right){
            List<int> distances = new List<int>();
            int mid = (right+left)/2;
            int count=0;
            int prev=0;
            
            foreach(int rock in rockList){
                int gap = rock - prev;
                if(gap<mid){
                    count++;
                }
                else{
                    prev = rock;
                    distances.Add(gap);
                }
                
              
            }
            if(count<=n){
                    left =mid+1;
                  int minGap = distances.Min();
    answer = Math.Max(answer, minGap);
                    
                }
                else{
                    right = mid-1;
                }  
        }
        return answer;
    }
}