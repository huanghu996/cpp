#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct bign{
    int l;
    short int w[2000];
    bign(){l=1;memset(w,0,sizeof(w));}

    bign(int x){
        l=0;memset(w,0,sizeof(w));
        while(x){
            w[l]=x%10,x/=10;
            l++;
        }
    }

    bool operator >(bign x){
        if(l>x.l)return 1;
        if(l==x.l){
            for(int i=l-1;i>=0;i--){
                if(w[i]<x.w[i])return 0;
                if(w[i]>x.w[i])return 1;
            }
        }
        return 0;
    }

    bign operator +(const bign& x){
        bign ans;
        ans.l=max(l,x.l);

        for(int i=0;i<ans.l;i++){
            ans.w[i]+=w[i]+x.w[i];
            ans.w[i+1]+=ans.w[i]/10;
            ans.w[i]%=10;
        }

        if(ans.w[ans.l])ans.l++;
        return ans;
    }

    bign operator *(const bign& x){
        bign ans;
        ans.l=l+x.l;

        for(int i=0;i<l;i++){
            for(int j=0;j<x.l;j++){
                ans.w[i+j]+=w[i]*x.w[j];
                ans.w[i+j+1]+=ans.w[i+j]/10;
                ans.w[i+j]%=10;
            }
        }

        if(ans.w[ans.l-1]==0)ans.l--;
        return ans;
    }

    bign operator *(int x){
        bign ans(x);
        return operator*(ans);
    }
    void write(){
        if(l==0)printf("0");
        for(int i=l-1;i>=0;i--)printf("%d",w[i]);
    }

};
bign c[500][500];
int main(){
	int n;
	freopen("virus5.in","r",stdin);
	freopen("virus5.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=n;j++)
		{
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{ 
		c[n][i].write();
	}
}
