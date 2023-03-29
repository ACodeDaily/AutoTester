#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


void solve(){
    int n=1,p=0,q=0;
    string s;
    cin>>n>>p>>q>>s;
    string res=s;
    int orgp=0,orgq=q;
    multiset<int, greater<int> > ps,qs;


    
    for(int i=0;i<n;i++){
        int l=s[i]-'a';
        int r='z'-s[i]+1;
        if(s[i]=='a')   continue;
        // q would always be worth! p won't be if p<r... 
        if(p>=r){
            p-=r;
            res[i]='a';
            ps.insert(r);
        }
        else if(q>=l){
            q-=l;
            res[i]='a';
            qs.insert(l);
        }

        else{      // using p isn't advisable it's best to use q only!  
            while(q<100*l && qs.size() && p>=(26-*qs.begin())){
                    p-=(26-*qs.begin());
                    q+=*qs.begin();
                    ps.insert(*qs.begin());
                    qs.erase(qs.begin());
            }
            while(p<r && ps.size() && q>=(26-*ps.begin())){
                q-=(26-*ps.begin());
                p+=*ps.begin();
                
                qs.insert(*ps.begin());
                ps.erase(ps.begin());
                }
                
            if(p>=r){

                res[i]='a';
                ps.insert(r);
                p-=r;
            }
            else{     
                while(q<l && qs.size() && p>=(26-*qs.begin())){
                    p-=(26-*qs.begin());
                    q+=*qs.begin();
                    
                    ps.insert(*qs.begin());
                    qs.erase(qs.begin());
                }
                res[i]=s[i]-min(l,q);
                qs.insert(min(l,q));
                q-=min(l,q);
                
            }
        }
        
    }
    // cout<<p<<" "<<q<<"\n";
    cout<<res<<"\n";
    
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    
