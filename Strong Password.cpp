#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    if(n < 6){
        if(n <= 3) return 6-n;
        bool isUpperChar = false;
        bool isLowerChar = false;
        bool isDigit = false;
        bool isSpecial = false;
        int strong_pass = 0, cnt = 0;
        for(int i = 0; i < n; i++)
        {
        if(isupper(password[i])) isUpperChar = true;
        else if(islower(password[i])) isLowerChar = true;
        else if(isdigit(password[i])) isDigit = true;
        else if(!isupper(password[i]) && !islower(password[i]) && !isdigit(password[i])) isSpecial = true;
        }
        if(isUpperChar) cnt++;
        if(isLowerChar) cnt++;
        if(isDigit) cnt++;
        if(isSpecial) cnt++;
        // cout << cnt << endl;
        return (4-cnt <= 1) ? 6-n : 4-cnt; 
    }else{
        bool isUpperChar = false;
        bool isLowerChar = false;
        bool isDigit = false;
        bool isSpecial = false;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(isupper(password[i])) isUpperChar = true;
            else if(islower(password[i])) isLowerChar = true;
            else if(isdigit(password[i])) isDigit = true;
            else if(!isupper(password[i]) && !islower(password[i]) && !isdigit(password[i])) isSpecial = true;
        }
        if(!isUpperChar) cnt++;
        if(!isLowerChar) cnt++;
        if(!isDigit) cnt++;
        if(!isSpecial) cnt++;
        return cnt;
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
