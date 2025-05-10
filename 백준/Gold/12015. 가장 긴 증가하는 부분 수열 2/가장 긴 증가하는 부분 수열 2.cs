using System;
using System.Linq;
using System.Collections.Generic;
namespace MyCompiler {
    class Program {
        static int FindValue(int n, int[] arr){
            int answer=0;
             List<int> lis = new List<int>();

            for(int i=0;i<arr.Length;i++){
                if(lis.Count==0 || lis[lis.Count-1]<arr[i]){
                    lis.Add(arr[i]);
                }
                else{
                    int idx = BinarySearch(lis, arr[i]);
                    lis[idx] = arr[i];
                }
            }
            return lis.Count;
        }
        static int BinarySearch(List<int> list, int target){
            int left =0;
            int right = list.Count-1;

            while(left<=right){
                int mid = (left+right)/2;
                
                if (list[mid] >= target) {
                    right = mid-1;
                } else {
                    left = mid + 1;
                }
                
            }
             return left;
        }
        public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());

        int[] arr = Console.ReadLine()
                          .Split()
                          .Select(int.Parse)
                          .ToArray();

            int answer = FindValue(n, arr);
            Console.WriteLine(answer);
        }
    }
}