#include <iostream>
#include <string>
using namespace std;
int main() {

    int input;
    cin >> input;
    string* li = new string[input];
    for (int i = 0; i < input; i++) {
        cin >> li[i];
    }
    
    for (int i = 0; i < input; i++) {
        int j = 0;
        int renum = 0;
        int numli[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        while (true) {
            if (li[i][j] == '\0')
                break;
            renum = int((li[i][j]) - '0');
            numli[int((li[i][j]) - '0')] = -1;
            j++;
        }
        numli[renum] = renum;
        int count = 0;
        for (int k = 0; k < 10; k++) {
            if (numli[k] == -1)
                count++;
        }
        cout << count+1 << endl;
    }

    delete[] li;
    return 0;
}