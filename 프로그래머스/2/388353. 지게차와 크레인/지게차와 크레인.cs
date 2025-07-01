using System;
using System.Linq;
public class Solution {
    public void removeAll(char getc, string[] copyStorage){
        for(int i=0;i<copyStorage.Length;i++){
            char[] row = copyStorage[i].ToCharArray();   
            for(int j=0;j<row.Length;j++){
                if(row[j]==getc){
                    row[j] = '0';
                }
            }
            copyStorage[i] = new string(row);
        }
    }
    public bool bfs(int x, int y,string[] storage, string[] copyStorage, int width, int height, bool[,] isVisited){
        int[] dirx = new int[] {1,0,-1,0};
        int[] diry = new int[] {0,1,0, -1};
        isVisited[x, y] = true;
        bool touchesOutside = false;
        for(int i=0;i<4;i++){
            int newx = dirx[i]+x;
            int newy = diry[i]+y;
            
            if(newx<0 || newy<0 || newx>=height || newy>=width){
                touchesOutside = true;
                continue;
            }
            if(isVisited[newx,newy]) continue;
            if(storage[newx][newy]=='0'){
               if (bfs(newx, newy, storage,copyStorage, width, height, isVisited)) {
                    touchesOutside = true;
                }
            }
        }
        return touchesOutside;
    }
    public int solution(string[] storage, string[] requests) {
        int answer = 0;
        string[] copyStorage = new string[storage.Length];
        
        for (int i = 0; i < storage.Length; i++) {
            copyStorage[i] = String.Copy(storage[i]); 
        }
        
        for(int i=0;i<requests.Length;i++){
            if(requests[i].Length==2){
                removeAll(requests[i][0], copyStorage);
            }
            else{
                for(int k=0;k<storage.Length;k++){
                    char[] chars = storage[k].ToCharArray();
                    for(int j=0;j<storage[k].Length;j++){
                        if(storage[k][j]==requests[i][0]){
                            bool[,] isVisited = new bool[storage.Length,storage[0].Length];
                            
                            bool isa = bfs(k, j, storage, copyStorage, storage[0].Length, storage.Length, isVisited);
                            if(isa) chars[j] = '0';
                        }
                    }
                    copyStorage[k] = new string(chars);
                }
            }
            storage = copyStorage.ToArray();
        }
        foreach (var row in storage){
            foreach(var col in row){
                if(col!='0') answer++;
            }
        }
        foreach(var row in storage) Console.WriteLine(row);
        return answer;
    }
}