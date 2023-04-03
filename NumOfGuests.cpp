#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
    IOS
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<string> guests;
        for (int i = 0; i < n; i++) {
            string name, response;
            int k;
            cin >> name >> response;

            if (response == "yes"){
				guests.insert(name);
                cin >> k;
                for (int j = 0; j < k; j++) {
                    string guest;
                    cin >> guest;
                    guests.insert(guest);
                }
            }
        }
        cout << guests.size() << endl;
    }
    return 0;
}
