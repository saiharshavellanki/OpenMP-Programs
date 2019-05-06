#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<float> > a,l,u,a_copy;
vector<float> b;

//For upper hessenberg matrix,lower bandwidth=1
void mylu()
{
	int k,l,i,j;
	for(k=0;k<n-1;k++)
	{
		l=k+1;

		//Here only a[l][k] has some value 
		a[l][k] = a[l][k]/a[k][k];
		//Here i can be only k+1
		i=k+1;
		for(j=k+1;j<n;j++)
			a[i][j]=a[i][j]-a[i][k]*a[k][j];
	}
}

int main()
{
	//let us consider upper hessenberg matrix
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

	return 0;
}
