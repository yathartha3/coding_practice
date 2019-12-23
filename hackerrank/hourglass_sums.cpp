#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
vector<vector<int>> mask = {{1,1,1},{0,1,0},{1,1,1}};
vector<int> hourglass_sums;
int n_rows = arr.size();
bool flag = true;
int max;

for (int row=0; row<n_rows; row++)
{
    for (int col=0; col<n_rows; col++)
    {
        if (((row+3)>n_rows) || ((col+3)>n_rows))
            continue;
        else
        {   int sum = 0;
            for (int i=0; i<3; i++)
            {
                for (int k=0; k<3; k++)
                {
                    sum += mask[i][k]*arr[row+i][col+k];
                    hourglass_sums.push_back(sum);
                    if (flag)
                    {
                        max = sum;
                        flag = false;
                    }
                    if (sum>max)
                        max = sum;
                }
            }
        }
    }
}
return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
