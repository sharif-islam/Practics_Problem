#include<bits/stdc++.h>

#define  pf                  printf
#define  sc                  scanf
#define  PI                  2*acos(0.0)
#define  fast                ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define  mem(a,b)            memset(a, b, sizeof(a) )
#define  gcd(a,b)            __gcd(a,b)
#define  lcm(a,b)            (a*(b/gcd(a,b)))
#define  MAX                 1234567899
#define  mod                 1000000007
#define  all(v)              (v).begin(),(v).end()
#define  vSort(v)            sort(all(v))
#define  maxSort(v)          sort(all(v),greater<int>())
#define  Unique(v)           v.erase(unique(all(v)),v.end())
#define  sqr(x)              ((x)*(x))
#define  qube(x)             ((x)*(x)*(x))
#define  deci(n)             cout<<fixed<<setprecision(n)
#define  sci(n)              sc("%d",&(n))
#define  scii(x,y)           sc("%d %d",&(x),&(y))
#define  scl(x)              sc("%lld",&(x))
#define  scll(x,y)           sc("%lld %lld",&(x),&(y))
#define  vi                  vector<int>
#define  hi                  pf(" HI \n")
#define  pp                  pair<int,int>
#define  pb(x)               push_back(x)
#define  mp(x,y)             make_pair(x,y)
#define  F                   first
#define  S                   second
#define  check(n,pos)        (n & (1<<(pos)))
#define  biton(n,pos)        (n  (1<<(pos)))
#define  bitoff(n,pos)       (n & ~(1<<(pos)))
typedef  long long int       lli;
typedef  unsigned long long int ulli;
int dx4[] = { 0, 0, -1, 1 } ;
int dy4[] = { -1, 1, 0, 0 } ;
bool valid( int r, int c, int x, int y )
{
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ;
    return 0 ;
}

using namespace std;

bool mark[10000];
lli factor[10000];
vi prime;

void primee(int n)
{
    prime.pb(2);
    for(int i=4; i<=n; i+=2)
        mark[i]=1;
    for(int i=3; i<=sqrt(n); i+=2)
    {
        if(mark[i]==0)
        {
            for(int j=(i*i); j<=n; j+=(2*i))
                mark[j]=1;
        }
    }
}

string call(string a,lli p)
{
    int carry=0;
    for(int i=0;i<a.size();i++)
    {
        carry+=(a[i]-48)*p;
        a[i]=((carry%10)+48);
        carry/=10;
    }
    while(carry)
    {
        a+=((carry%10)+48);
        carry/=10;
    }

    return a;
}

int main ()
{
    int t;
    primee(10000);

    for(int i=3; i<=10000; i+=2)
        if(mark[i]==0)
            prime.pb(i);


    sci(t);
    lli tot;
    for(int cs=1; cs<=t; cs++)
    {
        int num;
        sci(num);
        int a[num];
        for(int k=0; k<num; k++)
        {
           scl(tot);
            lli n=tot;
            lli ans;

            for(int i=0; i<prime.size() && (prime[i]*prime[i])<=n; i++)
            {
                ans=1;
                int p=prime[i];
                while(n%p==0)
                {
                    ans*=p;
                    n/=p;
                }
                factor[i]=max(factor[i],ans);
              //  cout << ans << " ans "<<endl;
            }
            if(mark[n]==0)
            {
                int ppp=lower_bound(prime.begin(),prime.end(),n)-prime.begin();
                factor[ppp]=max(factor[ppp],n);
              //  cout << factor[ppp]<< " lower "<<endl;

            }


        }
        string lcm="1";
        for(int i=0; i<prime.size(); i++)
        {
            if(factor[i]!=0)
            {

                lcm=call(lcm,factor[i]);
               // cout << lcm <<endl;
            }
        }
       // cout << lcm << " lcm "<<endl;
        int p=lcm.length();
        char LCM[1000000];
        for(int i=p-1,j=0;i>=0;i--,j++)
            LCM[j]=lcm[i];
        LCM[p]='\0';
       pf("Case %d: %s\n",cs,LCM);
        mem(factor,0);



    }

    return 0;
}
