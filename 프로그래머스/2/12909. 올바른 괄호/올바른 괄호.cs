using System;
using System.Collections.Generic;
public class Solution {
    public bool solution(string s) {
        bool answer = true;
        Stack<int> sl = new Stack<int>();
        for(int i=0;i<s.Length;i++){
            if(s[i]=='('){
                sl.Push(1);
            }
            else if(s[i]==')'){
                if(sl.Count==0){answer=false; break;}
                sl.Pop();
            }
        }
        if(sl.Count!=0) answer = false;
        return answer;
    }
}