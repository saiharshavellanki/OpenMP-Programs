#include<bits/stdc++.h>
using namespace std;

//finding norm
float getnorm(vector<vector<float> > R,int j)
{
	float norm=0;
	for(int i=j;i<R.size();i++)
	{
		norm+=(R[i][j]*R[i][j]);
	}
	norm=sqrt(norm);
	return norm;
}

//Transpose of matrix
vector<vector<float> > gettranspose(vector<vector<float> > mat)
{
	vector<vector<float> > trans(mat[0].size(),vector<float>(mat.size(),0));
	int i,j;
	for(i=0;i<mat.size();i++)
		for(j=0;j<mat[i].size();j++)
			trans[j][i]=mat[i][j];
	return trans;
}

//multiply matrix with a value
vector<vector<float> > multiply1(float val,vector<vector<float> > a)
{
	int i,j;
	for(i=0;i<a.size();i++)
		for(j=0;j<a[i].size();j++)
			a[i][j]=a[i][j]*val;
	return a;
}

//Multiply matrix with matrix
vector<vector<float> > multiply(vector<vector<float> > a,vector<vector<float> > b)
{
	int i,j,k,n,m,p;
	n=a.size();
	m=a[0].size();
	p=b[0].size();
	vector<vector<float> > c(n,vector<float>(p,0));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(k=0;k<p;k++)
				c[i][k]+=a[i][j]*b[j][k];
	return c;
}

//Subtract matrix from matrix
vector<vector<float> > subtract(vector<vector<float> > a,vector<vector<float> > b)
{
	int n,m,i,j;
	n=a.size();
	m=a[0].size();
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=a[i][j]-b[i][j];
	return a;
}

//Print a matrix
void print(vector<vector<float> > Q)
{
	int i,j;
	for(i=0;i<Q.size();i++)
	{
		for(j=0;j<Q[i].size();j++)
		{
			if(Q[i][j]>=-0.0001 && Q[i][j]<=0.001)
				Q[i][j]=0;
			cout<<Q[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//Backward sweep algorithm
vector<vector<float> > backwardsweep(vector<vector<float> > u,vector<vector<float> > b)
{
	vector<vector<float> > y(b.size(),vector<float>(1,0));
	for(int i=b.size()-1;i>=0;i--)
	{
		float val=0;
		for(int j=b.size()-1;j>i;j--)
		{
			val+=u[i][j]*y[j][0];
		}
		y[i][0]=(b[i][0]-val)/u[i][i];
	}
	return y;
}

int main()
{
	int m,n,j,k,l,i;
	cin>>m>>n;
	vector<vector<float> > A(m,vector<float>(n));
	vector<vector<float> > B(m,vector<float>(1));
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cin>>A[i][j];
	for(i=0;i<m;i++)
		cin>>B[i][0];
	vector<vector<float> > Q(m,vector<float>(m,0));
	vector<vector<float> > R;
	float s,u1,tau,normx;
	for(i=0;i<m;i++)
		Q[i][i]=1;
	R = A;
	//Main algorithm - QR factorization
	for(j=0;j<n;j++)
	{
		normx = getnorm(R,j);
		if(R[j][j]>0)
			s=-(float)1;
		else if(R[j][j]==0)
			s=(float)0;
		else
			s=(float)1;
		u1=R[j][j]-s*normx;
		vector<vector<float> > w(m-j,vector<float>(1,0));
		vector<vector<float> > wt(1,vector<float>(m-j,0));
		for(i=j;i<m;i++)
			w[i-j][0]=R[i][j]/u1;
		w[0][0]=1;
		tau = -s*u1/normx;

		vector<vector<float> > r_crop(m-j,vector<float>(n,0));
		for(i=j;i<m;i++)
			for(k=0;k<n;k++)
				r_crop[i-j][k]=R[i][k];

		wt=gettranspose(w);
		r_crop = subtract(r_crop,multiply(multiply1(tau,w),(multiply(wt,r_crop))));
		for(i=j;i<m;i++)
			for(k=0;k<n;k++)
				R[i][k]=r_crop[i-j][k];

		vector<vector<float> > q_crop(m,vector<float>(n-j,0));
		for(i=0;i<m;i++)
			for(k=j;k<n;k++)
				q_crop[i][k-j]=Q[i][k];
		q_crop = subtract(q_crop,multiply(multiply(q_crop,w),gettranspose(multiply1(tau,w))));
		for(i=0;i<m;i++)
			for(k=j;k<n;k++)
				Q[i][k]=q_crop[i][k-j];
	}

	//Resizing Q and R matrices - thin QR
	Q.resize(m);
	for(i=0;i<m;i++)
		Q[i].resize(n);

	R.resize(n);
	for(i=0;i<n;i++)
		R[i].resize(n);

	cout<<"Q is \n";
	print(Q);
	cout<<"R is \n";
	print(R);

	B = backwardsweep(R,multiply(gettranspose(Q),B));
	print(B);
	return 0;
}


