#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long
#define ld long double
#define ull unsigned long long

#define INF 0x3f3f3f3f
#define Mod 1000000007
//#define Mod 998244353

#define nl "\n" 
#define sp " "
#define mid(s,e) (s+(e-s)/2)
#define bpc(a) __builtin_popcount(a)

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

#define pb push_back
#define ins insert
#define er erase
 
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define rf(i, a, b) for (ll i = a; i >= b; --i)


#define lb lower_bound
#define ub upper_bound
#define mxe max_element
#define mne min_element

#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vb vector<bool>
#define vst vector<string>
#define vpii vector<pii>
#define vpll vector<pll>
 
#define srt(v) sort(all(v))
#define rsrt(v) \
    srt(v);     \
    reverse(all(v))
 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define gcd(n,m) __gcd(n, m)

#define mem(a, b) memset(a, b, sizeof(a))

#define printv(v) for(int i=0;i<v.size();i++) { cout<<v[i]<<" "; } cout<<nl;
using namespace std::chrono;
using namespace std;
ll mul(ll a, ll b, ll m=Mod) 
{ 
    ll res = 0; 
    a = a % m; 
    while (b > 0) 
    { 
        if (b % 2 == 1) 
            res = (res + a) % m; 
  
        a = (a * 2) % m; 
  
        b /= 2; 
    } 
    return res % m; 
}
ll expMod(ll a, ll b, ll m=Mod) 
{
  ll x = 1, y = a;
  while(b) 
  {
    if (b%2==1) 
    {
      x = mul(x, y, m);
    }
    y = mul(y, y, m);
    b=b/2;
  }
  return x;
}
ll pw(ll a, ll b)
{
    ll c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m);
        m = (m * m);
        b /= 2;
    }
    return c;
}
ll pwmd(ll a, ll b)
{
    ll c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m) % Mod;
        m = (m * m) % Mod;
        b /= 2;
    }
    return c;
}
ll mmi(ll a)
{ 
    ll inverse = pwmd(a, Mod-2);
    return inverse ;
}
ll nCrModp(ll n, ll r)
{
    ll C[r+1];mem(C,0);C[0] = 1; 
    f(i,1,n+1)rf(j,min(i, r),1)C[j]=(C[j]+C[j-1])%Mod;
    return C[r];
}
int my_log(ll n, int b)
{
    ll i = 1;
    int ans = 0;
    while (1)
    {
        if (i > n)
        {
            ans--;
            break;
        }
        if (i == n)
            break;
        i *= b;
        ans++;
    }
    return ans;
}
bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}
inline bool kthbit(ll n, int k) { return (n >> k) & 1; }
inline ll setkthbit(ll n, int k) { return n | (1ll << k); }
inline ll unsetkthbit(ll n, int k) { return n & ~(1ll << k); }
inline ll flipkthbit(ll n, int k) { return n ^ (1ll << k); }

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<char> capl={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
vector<char> sml={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//Sieve of Eratosthenes
/*
vll primes;
vll p[n+1];  //define n (p[i] contains prime factors of i)
void seive(ll n)
{
    vll p[n+1];
    primes.pb(1);
    f(i,2,n+1)
    {
        if((ll)p[i].size())continue;
        primes.pb(i);
        for(ll j=i;j<=n;j+=i)p[j].pb(i);
    }
}
*/

//NcR
/*
const int Maxn = 1e6 + 1;
int fact[Maxn],inv[Maxn],ifact[Maxn];
template<typename T, typename T1>
T mod(T x, T1 p) {
    x %= p;
    if (x < 0)
        x += p;
    return x;
}
template<typename T>
T inverse(T x, T p) {
    x = mod(x, p);
    if (x == 1)
        return x;
    return mod((1LL * (-p / x) * (inv[p % x] % p)) , p); 
}
void pre()
{
    fact[0] = 1;
    for(int i = 1; i < Maxn; i++) 
    {
        fact[i] = 1LL * fact[i - 1] * i % Mod;
    }
    ifact[0] = 1;
    for(int i = 1; i < Maxn; i++) 
    {
        inv[i] = inverse(i, Mod);
        ifact[i] = (1LL * ifact[i - 1] * inv[i]) % Mod;
    }
}
int NcR(int n, int r) {
    int ret = (1LL * ifact[n - r] * ifact[r]) % Mod ;
    ret = (1LL * ret * fact[n]) % Mod;
    return ret;
}
*/
//declare pre() in main()...

void solve(){
    ll n;
    cin>>n;
    vll v(n);
    f(i,0,n)
    {
        cin>>v[i];
    }
    stack<ll> s;
    ll mx=v[0];
    ll ans=0;
    f(i,1,n){
        if(v[i] < mx) s.push(v[i]);
        if(v[i] >= mx){
            ll c=0;
            while(s.size()){
                ll tp=s.top();
                s.pop();
                if(s.size()==0){
                    ans+=mx-(tp+c);
                    break;
                }
                if(tp < s.top()) ans+=(s.top()-(tp+c));
                else{
                    ans+=mx-(tp+c);
                    c+=mx-(tp+c);
                }
                if(s.top() > tp) c=0;
            }
            s.push(v[i]);
            mx=v[i];
        }
    }
    ll c=0;
     while(s.size()){
                ll tp=s.top();
                s.pop();
                if(s.size()==0){
                    ans+=mx-(tp+c);
                    break;
                }
                if(tp < s.top()) ans+=(s.top()-(tp+c));
                else{
                    ans+=mx-(tp+c);
                    c+=mx-(tp+c);
                }
                if(s.top() > tp) c=0;
            }
    cout<<ans<<nl;
}

int main()
{
    fast;
    /*
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    */
    auto start = high_resolution_clock::now(); 
    ll T=1;
    //cin>>T; //comment for single test
    while(T--)
    {
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: "
         << duration.count() / 1000000.0 << "seconds" << nl;
    return 0;  
}