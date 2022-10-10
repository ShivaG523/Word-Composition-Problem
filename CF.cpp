#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#include <chrono>
using namespace std::chrono;

typedef long long int  ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
#define nl '\n'
#define pb push_back


const ll mod = 1e9+7;
const ll p = 31; 
const ll m = 1e9 + 7;
unordered_map<ll , ll > mp;
vector<ll> p_pow;

ll rK(string & s) { //Rabin Karp Algorithm
    ll S = s.size() ;
  
    long long k = 0; 
    for (int i = 0; i < S; i++) {

        k = (k + ((s[i] - 'a' + 1) * p_pow[i]) % m)%m; 
    }
    return k;
}

int dp[30];

ll rec(ll i , string & s ){
    if(i == s.size()){
        return 1;
    }
    if(dp[i] != -1)
        return dp[i];
    int a = 0;
    ll c = 0;
    for(int k = i ,  j = 0 ; k < s.size() ; k++ , j++){

        c = ((c + (s[k] - 'a' + 1) * p_pow[j])% m)%m;
        if(mp.find(c) != mp.end() and (k - i + 1) != s.size() ){
            a |= rec(k + 1 , s );
        }
    }
    
    return dp[i] = a;

}

static bool lex(string &a , string &b){
    int sa = a.size();
    int sb = b.size();
    return sa < sb or (sa == sb and a > b);
}

void solve() {
    string s;
    vector<string > v;
    p_pow.assign(30 , 0);
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;
    while(getline(cin , s) ){
        v.pb(s);
        ll cur = rK(s);
        mp[cur] = 1;
    }
    sort(v.begin() ,v.end(), lex);
    int n = v.size();
    bool f = true;
    for(int i = n - 1 ; i >=0 ; i--){
        memset(dp , -1 ,sizeof(dp));
        ll check = rec(0 , v[i] );
        if(check){
            if(f){
                cout << "Longest Compound Word: " << v[i] <<" "<<endl;
                f = false;
            }
            else{
                cout << "Second Longest Compound Word: "<<v[i] <<" "<<endl;
                break;
            }
        }
    }

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout.tie(NULL);
  cout<<fixed<<setprecision(100);
  auto start = high_resolution_clock::now();

  solve();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout <<"Time: "<<duration.count() <<"ms"<< endl;
  return 0;
}