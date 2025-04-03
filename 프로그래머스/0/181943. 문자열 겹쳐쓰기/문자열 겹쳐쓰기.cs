using System;

public class Solution {
    public string solution(string my_string, string overwrite_string, int s) {
        string answer = "";
        
        string first = my_string.Substring(0,s);
        string second = my_string.Substring(s+overwrite_string.Length);
        first+=overwrite_string;
        return first+second;
    }
}