using System;
using System.Collections.Generic;
public class Solution {
    public string[] solution(string my_string) {
        string[] answer = new string[] {};
        List<string> newlist = new List<string> ();
        for(int i=0;i<my_string.Length;i++){
            newlist.Add(my_string.Substring(i));
        }
        newlist.Sort();
        answer  = newlist.ToArray();
        return answer;
    }
}