#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    string thisn = to_string(num);
    int i=0;
    while(true){
        if(i>=thisn.length()) {answer = -1; break;}
        if(thisn[i]==(k + '0')){
            answer = i+1;
            break;
            
        }
        i++;
    }
    return answer;
}