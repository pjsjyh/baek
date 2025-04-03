using System;
using System.Linq;
public class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        int[] answer = new int[] {};
        
        var newlist = arr.Where(x=>!delete_list.Contains(x)).ToArray();
        return newlist;
    }
}