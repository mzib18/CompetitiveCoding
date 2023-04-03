#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
IOS
int t;
    cin >> t;
    while (t--) {
        int f, h, w;
        cin >> f >> h >> w;
        int * arr = new int[f+1];
        for (int i = 0; i < f; i++) {
            cin >> p[i];
        }
        p[f] = w;
        sort(p.begin(), p.end());
        int minArea = INT_MAX;
        for (int i = 0; i <= f; i++) {
            int l = (i==0) ? p[0] : p[i]-p[i-1];
            int area = l * h;
            if (area < minArea) {
                minArea = area;
            }
        }
        cout << minArea << "\n";
        delete [] arr;
    }
    return 0;
}

}
