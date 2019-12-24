#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
int level = 0; //sea level
int last_level = 0;
int valleys = 0;

for (int i=0; i<n; i++)
{
    last_level = level;
    if (s[i]=='D')  //step down
        level += -1;
    else            // step up
        level += 1;
    
    if (level==0 && last_level<level)
        valleys ++;
}
return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
