#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
bool generate(string N, string S, string M, int ops, vector<int>& memo) {
    if (ops == 0) {
        return N == M;
    }
    if (memo[S.length()]!= -1) {
        return memo[S.length()];
    }
    bool res = false;
    if (generate(N + S[0], S.substr(1), M, ops - 1, memo)) {
        res = true;
    }
    if (generate(S[0] + N, S.substr(1), M, ops - 1, memo)) {
        res = true;
    }
    memo[S.length()] = res;
    return res;
}
int main() {
	IOS
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int L;
        cin >> L;
        string S, M;
        cin >> S >> M;
         vector<int> memo(L+1,-1);
        if (generate("", S, M, L, memo)) {
            cout << "Case " << i << ": YES\n";
        } else {
            cout << "Case " << i << ": NO\n";
        }
    }
    return 0;
}
