using System;

public class Solution {
    public string solution(string[] str_list, string ex) {
        string answer = "";
        int str_len = str_list.Length;
        for(int i=0;i<str_len;i++){
            if(!str_list[i].Contains(ex)){
                answer+=str_list[i];
            }
        }
        return answer;
    }
}