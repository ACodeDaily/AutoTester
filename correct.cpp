#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll possible(const string &s, ll target, ll p, ll q) {
    vector<ll> ps, qs;
    for (ll i = 0; i <= target; i++) {
        qs.push_back(s[i] - 'a');
        ps.push_back(26 - (s[i] - 'a'));
    }
    sort(ps.begin(), ps.end());
    sort(qs.begin(), qs.end());
    ll completed = 0;
    for (ll i = 0; i <= target; i++) {
        if (ps[i] <= p) {
            p -= ps[i];
            completed++;
        } else {
            break;
        }
    }
    ll total = target + 1;
    ll remaining = total - completed;
    for (ll i = 0; i <= target; i++) {
        if (remaining == 0) {
            break;
        }
        q -= qs[i];
        remaining--;
    }
    return q;
}

ll possible2(const string &s, ll target, ll p) {
    vector<ll> ps;
    for (ll i = 0; i <= target; i++) {
        ps.push_back(26 - (s[i] - 'a'));
    }
    sort(ps.begin(), ps.end());
    ll completed = 0;
    for (ll i = 0; i <= target; i++) {
        if (ps[i] <= p) {
            p -= ps[i];
            completed++;
        } else {
            break;
        }
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n, p, q;
        cin >> n >> p >> q;
        string s;
        cin >> s;
        ll start = -1, end = n, mid;
        while (start < end - 1) {
            mid = start + (end - start) / 2;
            if (possible(s, mid, p, q) >= 0)
                start = mid;
            else
                end = mid;
        }
        ll remaining = possible(s, start, p, q);
        ll remaining_p = possible2(s, start, p);
        for (ll i = start + 2; i < n; i++) {
            if (remaining_p >= 26 - (s[i] - 'a')) {
                remaining_p -= (26 - (s[i] - 'a'));
                s[i] = 'a';
            }
        }
        if (start != n - 1)
            s[start + 1] = (char) (s[start + 1] - remaining);
        for (ll i = 0; i <= start; i++)
            s[i] = 'a';
        cout << s << endl;
    }
    return 0;
}
