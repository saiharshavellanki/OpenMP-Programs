#include<bits/stdc++.h>
using namespace std;


vector<float> house(vector<float> x)
{
	int m,i;
	m=x.size();
	float sum;
	vector<float> v(m,0);
	for(i=0;i<m;i++)
		sum+=x[i]*x[i];
	sum=sqrt(sum);
	if(x[0]>0)
		v[0]=x[0]-sum;
	else if(x[0]==0)
		v[0]=x[0];
	else
		v[0]=x[0]+sum;
	for(i=1;i<m;i++)
		v[i]=x[i];
	return v;
}
int main()
{
	int m,i;
	vector<float> x,v;
	cin>>m;
	x.resize(m);
	for(i=0;i<m;i++)
		cin>>x[i];
	v = house(x);
	float sum=0,beta,val;
	val=v[0];
	for(i=0;i<m;i++)
	{
		v[i]=v[i]/val;
		sum+=v[i]*v[i];
	}
	beta=2/sum;
	cout<<"Beta: "<<beta<<endl;
	cout<<"V is\n";
	for(i=0;i<m;i++)
		cout<<v[i]<<" ";
	cout<<endl;

}
