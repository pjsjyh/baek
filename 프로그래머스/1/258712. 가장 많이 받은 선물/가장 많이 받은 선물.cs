using System;
using System.Collections.Generic;
using System.Linq;
public class Solution {
    public int solution(string[] friends, string[] gifts) {
        int answer = 0;
        int friendslen = friends.Length;
        int[][] giftarr = new int[friendslen][];
        for (int i = 0; i < friendslen; i++) {
            giftarr[i] = new int[friendslen];
        }
        int[] peopleget = new int[friendslen];
        Dictionary<string, int> newdic = friends.Select((x, index)=>new {x, index}).ToDictionary(x=>x.x, x=>x.index);
        
        for(int i=0;i<gifts.Length;i++){
            string[] people = gifts[i].Split();
            giftarr[newdic[people[0]]][newdic[people[1]]]+=1;
        }
         int[] give = new int[friendslen];
        int[] receive = new int[friendslen];
        for (int i = 0; i < friendslen; i++) {
            for (int j = 0; j < friendslen; j++) {
                give[i] += giftarr[i][j];
                receive[i] += giftarr[j][i];
            }
        }
        
        for(int i=0;i<friendslen;i++){
            for(int j=i+1;j<friendslen;j++){
                if(giftarr[i][j]>giftarr[j][i]){
                    peopleget[i]++;
                }
                else if(giftarr[i][j]<giftarr[j][i]){
                    peopleget[j]++;
                }
                else{
                   int first = give[i]-receive[i];
                    int second = give[j]-receive[j];
                    if(first>second){
                        peopleget[i]++;
                    }
                    else if(first<second) peopleget[j]++;
                }
            }
        }
        return peopleget.Max();
    }
}