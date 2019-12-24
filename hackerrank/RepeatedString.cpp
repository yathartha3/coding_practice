#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n)
{
long a_in_limited_seq = 0;
long a_in_long_seq = 0;

for (long i=0; i<s.length(); i++)
{
    if (s[i]=='a')
        a_in_limited_seq++;
}
// we now know how many times it occurs in the repeating sequence

a_in_long_seq += (n/s.length())*a_in_limited_seq;

for (long i=0; i<(n%s.length()); i++)
{
    if (s[i]=='a')
        a_in_long_seq++;
}
return a_in_long_seq;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
