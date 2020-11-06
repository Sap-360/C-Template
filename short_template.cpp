#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define Mod 1000000007
//#define Mod 998244353
#define nl "\n" 
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define rf(i, a, b) for (ll i = a; i >= b; --i)
#define vll vector<ll>
#define pll pair<ll, ll>
#define mem(a, b) memset(a, b, sizeof(a))
#define printv(v) for(int i=0;i<v.size();i++) { cout<<v[i]<<" "; } cout<<nl;
using namespace std;
inline bool kthbit(ll n, int k) { return (n >> k) & 1; }
ll pw(ll a, ll b){ll c = 1, m = a;while (b){if (b & 1) c = (c * m);m = (m * m);b /= 2;}return c;}
//------------------------------------------------------------------------------------------------

int main()
{
    fast;
    ll T=1;
    //cin>>T; //comment for single test

    while(T--)
    {
        //code...
        string test,word;
        cin>>text>>word;
        int count[26];
        memset(count,0,sizeof(count));
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            count[word[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            count[text[i]-'a']++;   
        }
        if(check(count)==0)
            ans++;
        for(int i=n;i<text.length();i++)
        {
            count[]
        }
    }
    return 0;  
}