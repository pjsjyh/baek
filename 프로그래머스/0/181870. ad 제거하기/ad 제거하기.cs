using System;
using System.Linq;
public class Solution {
    public string[] solution(string[] strArr) {
        string[] answer = new string[] {};
        var newlist = strArr.Where(a=>!a.Contains("ad")).ToArray();
        return newlist;
    }
}