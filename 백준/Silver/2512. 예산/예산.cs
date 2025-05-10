using System;
using System.Linq;
namespace MyCompiler {
    class Program {
        static int FindValue(int n, int[] arr, int distance){
            int left=0;
            int right = arr.Max();
            int answer=0;
            while(left<=right){
                int mid = (left+right)/2;
                int total=0;
                foreach(int a in arr){
                    if(mid-a>=0){
                        total+=a;
                    }
                    else{
                        total+=mid;
                    }
                }
                if(total<=distance){
                    left = mid+1;
                    answer = mid;
                }
                else{
                    
                    right = mid-1;
                }
            }
            return answer;
        }
        public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());

        int[] arr = Console.ReadLine()
                          .Split()
                          .Select(int.Parse)
                          .ToArray();

        int distance = int.Parse(Console.ReadLine());

            int answer = FindValue(n, arr, distance);
            Console.WriteLine(answer);
        }
    }
}