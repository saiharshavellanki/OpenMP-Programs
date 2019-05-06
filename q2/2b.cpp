#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<float> > a,l,u,a_copy;
vector<float> b;

//implements lu by overwriting in a
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

//check whether the solutions satisfies equations with min error
bool checksol(vector<vector<float> > a_copy,vector<float> y,vector<float> b)
{
	vector<float> val(n,0);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			val[i]+=a_copy[i][j]*y[j];
	float c=0;
	for(i=0;i<n;i++)
	{
		val[i]=b[i]-val[i];
		c+=(val[i]*val[i]);
	}
	c=sqrt(c);
	return (c<=0.001);
}
int main()
{
	int i,j;
	cin>>n;
	
	a.resize(n);
	for(i=0;i<n;i++)
		a[i].resize(n);
	a_copy.resize(n);
	for(i=0;i<n;i++)
		a_copy[i].resize(n);
	l.resize(n);
	for(i=0;i<n;i++)
		l[i].resize(n);
	u.resize(n);
	for(i=0;i<n;i++)
		u[i].resize(n);
	b.resize(n);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
			a_copy[i][j]=a[i][j];
			l[i][j]=0;
			u[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
		cin>>b[i];

	//run lu on a
	mylu();
	cout<<"LU is\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	//l has diagonally ones and lower part of a
	for(i=0;i<n;i++)
		l[i][i]=1;
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			l[i][j]=a[i][j];

	//u has upper part of a including diagonal
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			u[i][j]=a[i][j];


	//Main algorithm to solve
	vector<float> t = forwardsweep(l,b);
	vector<float> y = backwardsweep(u,t);

	cout<<"Solution\n";
	for(i=0;i<y.size();i++)
		cout<<y[i]<<" ";
	cout<<endl;

	//checking solution
	if(checksol(a_copy,y,b))
		cout<<"Correct solution\n";
	else
		cout<<"Incorrect solution\n";
	return 0;
}
