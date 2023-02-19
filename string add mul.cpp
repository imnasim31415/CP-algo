#include<bits/stdc++.h>
#define pb push_back
using namespace std;
string add(string b, string c)
{
	if (b.size() > c.size()) swap(b, c);
	string str = "";
	int n1 = b.size(), n2 = c.size();
	int diff = n2 - n1;
	int carry = 0;
	for (int i=n1-1; i>=0; i--)
	{
		int sum=((b[i]-'0')+(c[i+diff]-'0')+carry);
		str.pb(sum%10 + '0');
		carry = sum/10;
	}
	for (int i=n2-n1-1; i>=0; i--)
	{
		int sum = ((c[i]-'0')+carry);
		str.pb(sum%10 + '0');
		carry = sum/10;
	}
	if (carry)  str.pb(carry+'0');
	reverse(str.begin(), str.end());
	return str;
}

string mul(string a, string b)
{
    LL q=0,p=0,l,i,j,s,t,k,la=a.size(),lb=b.size();
    string ans;
    if(la==0||lb==0)return "0";
    vector<LL>result(la+lb,0);
    for(i=la-1;i>=0;i--)
    {
        l=q=0,s=a[i]-'0';
        for(j=lb-1;j>=0;j--)
        {
            t=b[j]-'0';
            k=s*t+result[p+q]+l;
            result[p+q]=k%10;
            l=k/10,q++;
        }
        if(l>0)result[p+q]+=l;
        p++;
    }
    i=result.size()-1;
    while(i>=0&&result[i]==0)i--;
    if(i==-1)return "0";
    while(i>=0)
    {
        ans+=to_string(result[i--]);
    }
    return ans;
}

int main()
{
    string sa,sb;
    while(cin>>sa>>sb)
    {
        cout<<add(sa,sb)<<endl;
        cout<<mul(sa,sb)<<endl;
    }
}
