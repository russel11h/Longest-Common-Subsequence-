#include <iostream>
using namespace std;

const int MAX = 100;


int lcs(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();


    int dp[MAX][MAX] = {0};


    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }


    string lcsStr = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcsStr = s1[i - 1] + lcsStr;
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "LCS: " << lcsStr << endl;


    return dp[m][n];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "Length of LCS: " << lcs(s1, s2) << endl;
    return 0;
}

