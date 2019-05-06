#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,j,k,l,i;
	cin>>m>>n;
	vector<vector<float> > a(m,vector<float>(n));
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	vector<float> tau(n,0);
	float normx=0,s,u1;
	for(j=0;j<n;j++)
	{
		normx=0;
		for(k=j;k<m;k++)
		{
			normx+=a[k][j]*a[k][j];
		}
		normx = sqrt(normx);
		if(a[j][j]>0)
			s=-1;
		else if(a[j][j]==0)
			s=0;
		else
			s=1;
		u1=a[j][j]-s*normx;

		vector<float> w(m-j);
		for(k=j;k<m;k++)
			w[k]=a[k][j]/u1;
		w[0]=1;
		for(k=j+1;k<m;k++)
			a[k][j]=w[k-j];
		a[j][j]=s*normx;
		tau[j]=-s*u1/normx;


		vector<vector<float> > mul(w.size(),vector<float>(w.size())),a_crop(m-j,vector<float>(n-j-1));
		vector<vector<float> > sub_a_crop(m-j,vector<float>(n-j-1,0));
		for(i=0;i<w.size();i++)
		{
			for(k=0;k<w.size();k++)
				mul[i][k]=tau[j]*w[i]*w[k];
		}
		for(i=j;i<m;i++)
			for(k=j+1;k<n;k++)
				a_crop[i-j][k-j-1]=a[i][k];

		for(i=0;i<mul.size();i++)
			for(k=0;k<mul[0].size();k++)
				for(l=0;l<a_crop[0].size();l++)
					sub_a_crop[i][l]+=mul[i][k]*a_crop[k][l];

		for(i=0;i<m-j;i++)
			for(k=0;k<n-j-1;k++)
				a_crop[i][k]-=sub_a_crop[i][k];
		for(k=j;k<m;k++)
			for(l=j+1;l<n;l++)
				a[k][l] = a_crop[k-j][l-j-1];
		
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
