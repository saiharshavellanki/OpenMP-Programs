#include<bits/stdc++.h>
using namespace std;

int main()
{
	int row1[100],row2[100],col1[100],col2[100],val1[100],val2[100],n1,n2,A[100][100],i,j,r1,r2,c1,c2;

	cin>>r1>>c1>>n1;
	for(i=0;i<n1;i++)
		cin>>row1[i];
	for(i=0;i<n1;i++)
		cin>>col1[i];
	for(i=0;i<n1;i++)
		cin>>val1[i];

	cin>>r2>>c2>>n2;
	for(i=0;i<n2;i++)
		cin>>row2[i];
	for(i=0;i<n2;i++)
		cin>>col2[i];
	for(i=0;i<n2;i++)
		cin>>val2[i];

	if(c1!=r2)
	{
		cout<<"Cannot multiply those matrices\n";
		return 0;
	}

	for(i=0;i<r1;i++)
		for(j=0;j<c2;j++)
			A[i][j]=0;

	//Multiplication
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(col1[i]==row2[j])
			{
				A[row1[i]][col2[j]]+=val1[i]*val2[j];
			}
		}
	}
	cout<<endl;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
