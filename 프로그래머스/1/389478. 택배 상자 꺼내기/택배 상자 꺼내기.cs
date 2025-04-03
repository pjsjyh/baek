using System;

public class Solution {
    public int solution(int n, int w, int num) {
        int answer = 0;
        int topsize = n/w+1;
        int [,] cage = new int[topsize,w];
        bool isRight = true;
        int totalnum=0;
        for(int i=0;i<topsize;i++){

            if(isRight){
                 for(int j=0;j<w;j++){
                     if(totalnum>=n) break;
                    cage[i,j] = 1;
                     totalnum++;
                }
                isRight = false;
            }
            else{
                for(int j=w-1;j>=0;j--){
                     if(totalnum>=n) break;
                    cage[i,j] = 1;
                     totalnum++;
                    
                }
                isRight = true;
            }
           
        }
        int nowtop = num<w ? 0 : (num-1)/w;
        int nowwidth = nowtop%2==0 ? (num-1)%w : w-((num-1)%w)-1;
        for(int i=nowtop;i<topsize;i++){
            if(cage[i,nowwidth]!=0){
                answer++;
            }
        }
        return answer;
    }
}