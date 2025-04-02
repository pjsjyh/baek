using System;

public class Example
{
    public static void Main()
    {
        String s;

        Console.Clear();
        s = Console.ReadLine();
        String newword="";
        for(int i=0;i<s.Length;i++){
            char c = s[i];
            if (c >= 'A' && c <= 'Z')
            {
                c = (char)(c + ('a' - 'A'));
            }
            else if (c >= 'a' && c <= 'z')
            {
                c = (char)(c - ('a' - 'A'));
            }
            newword+=c;
        }
        Console.WriteLine(newword);
    }
}