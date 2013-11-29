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

class LittleElephantAndString
{ 	 
	public:
		int getNumber(string A, string B)
		{
			int la = A.length();
			int cnt[30];
			memset(cnt,0,sizeof(cnt));
			
			for(int i=0; i<la; i++)
			{
				cnt[A[i]-'A']++;
				cnt[B[i]-'A']--;
			}
			for(int i=0; i<26; i++)
				if(cnt[i]!=0) return -1;
			
			int dp[60],ans = 0;
			memset(dp,0,sizeof(dp));
			
			if(A[la-1] == B[la-1]) 
			{
				dp[la-1] = 1;
				ans = 1;
			}
			else dp[la-1] = 0;
			
			
			for(int i=la-2; i>=0; i--)
			{
				for(int j=la-1; j>i; j--)
				{
					int tmp;
					if(A[i] == B[la-dp[j]-1])
						tmp = dp[j]+1;
					else
						tmp = 0;
					if(tmp > dp[i]) dp[i] = tmp;
					if(tmp > ans) ans = tmp;
				}
			}
			return la-ans;
		}
};

int main()
{

}





