using System;

public class Solution {
    public int solution(int[] schedules, int[,] timelogs, int startday) {
        int answer = 0;
        
        for(int i=0;i<schedules.Length;i++){
            int limittime = schedules[i]+10;
            string peopleLimit = limittime.ToString();
            int hour = int.Parse(peopleLimit.Substring(0,peopleLimit.Length-2));
            int time = int.Parse(peopleLimit.Substring(peopleLimit.Length-2));
            if(time>=60){
               hour+=1;
                time-=60;
                
            }
            int newtime=0;
            if(time<10){
                string retime = '0'+time.ToString();
                    newtime = int.Parse(hour.ToString()+retime);
                }
            else{
                newtime = int.Parse(hour.ToString()+time.ToString());
            }
            bool isok = true;
            Console.WriteLine(newtime);
            for(int j=0;j<7;j++){
                int nowday = (startday-1)%7;
                startday++;
                if(nowday==5 || nowday==6) continue;
                if(newtime<timelogs[i,j]){
                    isok = false;
                }
                
                    
            }
            if(isok) answer++;
        }
        return answer;
    }
}