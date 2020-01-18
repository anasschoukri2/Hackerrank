#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define oo 100000000
#define MOD 1000000007
using namespace std;
vector<int> b;
int n;
long long int dp[100007][105];
long long int cnt(int i, int lastsum)
{
    if (i == b.size()) {
        return 0;
    }

    if (dp[i][lastsum] + 1)
        return dp[i][lastsum];
    long long int ans = 0;

    if (i) {
        ans = max(ans, abs(lastsum - b[i]) + cnt(i + 1, b[i]));
        ans = max(ans, abs(lastsum - 1) + cnt(i + 1, 1));
    }
    else {
        ans = max(ans, cnt(i + 1, b[i]));
        ans = max(ans, cnt(i + 1, 1));
    }

    return dp[i][lastsum] = ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ms(dp, -1);
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            b.push_back(a);
        }
        cout << cnt(0, 0) << endl;
        b.clear();
    }
    return 0;
}
