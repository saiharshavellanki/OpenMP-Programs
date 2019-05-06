#include<bits/stdc++.h>
using namespace std;
int main()
{
	int row_p1[100],row_p2[100],col_ind1[100],col_ind2[100],val1[100],val2[100],r1,r2,c1,c2,n1,n2,i,j,k,A[100][100],pos1,val;

	cin>>r1>>c1>>n1;
	for(i=0;i<n1;i++)
		cin>>val1[i];
	for(i=0;i<n1;i++)
		cin>>col_ind1[i];
	for(i=0;i<r1+1;i++)
		cin>>row_p1[i];

	cin>>r2>>c2>>n2;
	for(i=0;i<n2;i++)
		cin>>val2[i];
	for(i=0;i<n2;i++)
		cin>>col_ind2[i];
	for(i=0;i<r2+1;i++)
		cin>>row_p2[i];

	if(c1!=r2)
	{
		cout<<"cannot multiply those matrices\n";
		return 0;
	}


	for(i=0;i<r1;i++)
		for(j=0;j<c2;j++)
			A[i][j]=0;

	//Multiplication
	for(i=0;i<r1;i++)
	{
		for(j=row_p1[i];j<row_p1[i+1];j++)
		{
			pos1 = col_ind1[j];
			val = val1[j];
			for(k=row_p2[pos1];k<row_p2[pos1+1];k++)
			{
				A[i][col_ind2[k]]+=val*val2[k];
			}
		}
	}
	cout<<endl;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
