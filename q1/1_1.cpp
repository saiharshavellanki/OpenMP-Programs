#include<bits/stdc++.h>
using namespace std;

int main()
{
	float a[100][100],b[100][100],c[100][100];
	int n,m,p,i,j,k;

	//n*m is size of matrix a and m*p is size of matrix b
	cin>>n>>m;

	//scanning matrix a
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>a[i][j];

	int m1;
	cin>>m1>>p;
	if(m!=m1)
	{
		cout<<"Cannot multiply those matrices\n";
		return 0;
	}
	//scanning matrix b
	for(i=0;i<m;i++)
		for(j=0;j<p;j++)
			cin>>b[i][j];

	//initialise values in matrix c to 0
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			c[i][j]=0;

	//a[i][j]*b[j][k] gets added to c[i][k]	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<p;k++)
				c[i][k]+=a[i][j]*b[j][k];
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
