#include <string>
#include <vector>
#include <iostream>
using namespace std;

void checkthis(int& cu_h, int& cu_m, int op_h, int op_m, int end_h, int end_m){

    if (cu_h < op_h || cu_h > end_h) return;

    if (cu_h == op_h && cu_m < op_m) return;
    if (cu_h == end_h && cu_m >= end_m) return;

    cu_h = end_h;
    cu_m = end_m;
}
bool isin(int cu_h, int cu_m, int op_h, int op_m, int end_h, int end_m){
      if (op_h == end_h && cu_h == op_h) {
        return (cu_m >= op_m && cu_m < end_m);
    }
    if (cu_h >= op_h && cu_h <= end_h) {
        if ((cu_h == op_h && cu_m >= op_m) || (cu_h == end_h && cu_m < end_m)) {
            return true;
        }
    }
    return false;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
     size_t findt = pos.find(":");
        int cu_hour = stoi(pos.substr(0, findt));
        int cu_minu = stoi(pos.substr(findt+1));
        int op_hour = stoi(op_start.substr(0,findt));
        int op_minu = stoi(op_start.substr(findt+1));
        int end_hour = stoi(op_end.substr(0,findt));
        int end_minu = stoi(op_end.substr(findt+1));
        int video_hour = stoi(video_len.substr(0,findt));
        int video_minu = stoi(video_len.substr(findt+1));
        checkthis(cu_hour, cu_minu, op_hour, op_minu, end_hour, end_minu);

        for(int j=0;j<commands.size();j++){
            
            if(commands[j]=="next"){
                cu_minu+=10;
                
                if(cu_minu>=60){
                    
                    cu_hour+=1;
                    cu_minu-=60;
                }
                if(cu_hour>=video_hour){
                    if(cu_hour== video_hour){
                        if(cu_minu>video_minu){
                            cu_hour = video_hour;
                            cu_minu = video_minu;
                        }
                    }
                    else{
                        cu_hour = video_hour;
                        cu_minu = video_minu;
                    }
                }
                cout<<cu_hour<<" "<<cu_minu<<endl;
                if(isin(cu_hour, cu_minu, op_hour, op_minu, end_hour, end_minu)){
                    cu_hour = end_hour;
                    cu_minu = end_minu;
                }
            }
            else if(commands[j]=="prev"){
                cu_minu-=10;
                if(cu_minu<0){
                    cu_hour-=1;
                    cu_minu+=60;
                }
                if(cu_hour<0){
                    cu_hour=0;
                    cu_minu=0;
                }
                 if(isin(cu_hour, cu_minu, op_hour, op_minu, end_hour, end_minu)){
                    cu_hour = end_hour;
                    cu_minu = end_minu;
                }
            }
        }
    
    string minu, hour;
    if(cu_minu<=9){
        minu="0"+to_string(cu_minu);
    }
    else{
        minu = to_string(cu_minu);
    }
    if(cu_hour<=9){
        hour = "0"+to_string(cu_hour);
    }
    else{
        hour = to_string(cu_hour);
    }
    answer=hour+":"+minu;
    return answer;
}