using System;
using System.Linq;
public class Solution {
    public int solution(int[] arr1, int[] arr2) {
        int answer = 0;
         if (arr1.Length != arr2.Length)
            return arr1.Length > arr2.Length ? 1 : -1;
         int arr1sum = arr1.Sum(), arr2sum = arr2.Sum();
            if(arr1sum>arr2sum){
                answer = 1;
            }
            else if(arr1sum<arr2sum) answer = -1;
            else answer = 0;
        return answer;
    }
}