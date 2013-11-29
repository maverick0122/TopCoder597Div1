#include<string>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

#define SWAP(x,y,t) (t)=(x),(x)=(y),(y)=(t)

const int mod = 1000000007;
const int maxn = 1000011;
int f[maxn],df[maxn],inv[maxn];


int multi(int x,int y)
{
	int tmp;
	if(x<y) SWAP(x,y,tmp);
	
	if(y==0) return 0;
	if(y==1) return x%mod;
	
	int half = multi(x,y/2)%mod;
	int ans = (half+half)%mod;
	
	if(y%2==0) return ans;
	else return (ans+x)%mod;
}

int mc(int a,int b)
{
	int tmp;
	if(b>a) SWAP(a,b,tmp);
	if(b<0) return 0;
	return (((long long)f[a]*df[b])%mod * df[a-b])%mod;
}

class LittleElephantAndBoard
{ 	 
	public:		
		int getNumber(int M, int R, int G, int B)
		{
			if(R>M || R<M/2 || G>M || G<M/2 || B>M || B<M/2)
				return 0;
			
			inv[1] = 1;
			for(int i=2; i<maxn; i++)
				inv[i] = ((long long)inv[mod%i] * (mod-mod/i))%mod;
			f[0] = df[0] = 1;
			for(int i=1; i<=maxn; i++)
			{
				f[i] = ((long long)f[i-1]*i)%mod;
				df[i] = ((long long)df[i-1]*inv[i])%mod;
			}
			
			int x,y,z,tmp;
			
			x = (G+R-B)/2;
			y = (G-R+B)/2;
			z = (R-G+B)/2;
			
			if(x<y) SWAP(x,y,tmp);
			if(x<z) SWAP(x,z,tmp);
			if(y<z) SWAP(y,z,tmp);
						
			int ans = 0;
			
			for(int i=-1; i<=1; i++)
			{
				int x1,y1,z1,ansx;
				x1 = x+i;
				y1 = y;
				if(x1==0) continue;
				if(x1<y1) y1=x1;
				
				ansx = 0;
				
				for(; ; y1--)
				{
					int y2,z2;
					z1 = x1-y1;
					y2 = y-y1;
					z2 = z-z1;
					
					if(y2>z2) break;
					
					int t1,t2,t3;
					t1 = mc(x1,y1)%mod;
					t2 = mc(y1+y2-1,y1-1)%mod;
					t3 = mc((y1+y1)%mod,z2-y2)%mod;
					t1 = multi(t1,t2)%mod;
					t1 = multi(t1,t3)%mod;
					ansx = (ansx + t1) % mod;
					
					//printf("x1 %lld y1 %lld z1 %lld y2 %lld z2 %lld t1 %lld t2 %lld t3 %lld\n",
					//	x1,y1,z1,y2,z2,t1,t2,t3);
				}
				
				ans = (ans+ansx)%mod;
				if(i==0) ans = (ans+ansx)%mod;
				ans %= mod;
			}
			ans = (ans+ans)%mod;
			return (int)ans;
		}
};

int main()
{
	//cout<<mc(1000000,500)<<endl;
	LittleElephantAndBoard t;
	cout<<t.getNumber(474, 250, 300, 398)<<endl;
	//cout<<t.getNumber(10,7,7,6)<<endl;
	//cout<<t.getNumber(3,1,2,3)<<endl;
}





