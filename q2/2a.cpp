#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<float> > a,l,u;
vector<float> b;

//computes lu and stores in a
void mylu()
{
	int k,l,i,j;
	for(k=0;k<n-1;k++)
	{
		for(l=k+1;l<n;l++)
			a[l][k] = a[l][k]/a[k][k];
		for(i=k+1;i<n;i++)
			for(j=k+1;j<n;j++)
				a[i][j]=a[i][j]-a[i][k]*a[k][j];
	}
}

//implements forward sweep
vector<float> forwardsweep(vector<vector<float> > l,vector<float> b)
{
	vector<float> y(b.size());
	for(int i=0;i<b.size();i++)
	{
		float val=0;
		for(int j=0;j<i;j++)
		{
			val+=l[i][j]*y[j];
		}
		y[i]=(b[i]-val)/l[i][i];
	}
	return y;
}

//implements backward sweep
vector<float> backwardsweep(vector<vector<float> > u,vector<float> b)
{
	vector<float> y(b.size());
	for(int i=b.size()-1;i>=0;i--)
	{
		float val=0;
		for(int j=b.size()-1;j>i;j--)
		{
			val+=u[i][j]*y[j];
		}
		y[i]=(b[i]-val)/u[i][i];
	}
	return y;
}
int main()
{
	int i,j;
	cin>>n;
	
	a.resize(n);
	for(i=0;i<n;i++)
		a[i].resize(n);
	l.resize(n);
	for(i=0;i<n;i++)
		l[i].resize(n);
	u.resize(n);
	for(i=0;i<n;i++)
		u[i].resize(n);
	b.resize(n);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>l[i][j];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>u[i][j];
	for(i=0;i<n;i++)
		cin>>b[i];

	//running lu on a
	mylu();
	cout<<"LU is\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	//Main algorithm by taking l,u as inputs
	vector<float> forw = forwardsweep(l,b);
	vector<float> back = backwardsweep(u,b);

	cout<<"Forward sweep for l and b\n";
	for(i=0;i<forw.size();i++)
		cout<<forw[i]<<" ";
	cout<<endl;

	cout<<"Backward sweep for u and b\n";
	for(i=0;i<back.size();i++)
		cout<<back[i]<<" ";
	cout<<endl;
	return 0;
}
