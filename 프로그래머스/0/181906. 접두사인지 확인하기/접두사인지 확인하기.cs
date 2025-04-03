using System;

public class Solution {
    public int solution(string my_string, string is_prefix) {
        int answer = 0;
        int wordlen = is_prefix.Length;
        if(wordlen>my_string.Length) return 0;
        string cutword = my_string.Substring(0,wordlen);
        if(cutword==is_prefix) return 1;
        return 0;
    }
}