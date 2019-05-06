#include <bits/stdc++.h>
using namespace std;

//compute lower band
int lowband(int r, int c, vector<vector<int> > matrix){
	int lower_bandwidth = r-1, row, col;

	while(lower_bandwidth){
		row = lower_bandwidth;
		col = 0;
		while(row < r && col < c){
			if(matrix[row][col] != 0)
				return lower_bandwidth;
			row++;
			col++;
		}
		lower_bandwidth--;
	}
	return 0;
}

//compute upper band
int upband(int r, int c, vector<vector<int> > matrix){
	int upper_bandwidth = c-1, row, col;

	while(upper_bandwidth){
		row = 0;
		col = upper_bandwidth;
		while(row < r && col < c){
			if(matrix[row][col] != 0)
				return upper_bandwidth;
			row++;
			col++;
		}
		upper_bandwidth--;
	}
	return 0;
}

//get banded storage matrix
vector<vector<int> > band(int r, int c, vector<vector<int> > matrix){
	int lband = lowband(r, c, matrix);
	int uband = upband(r, c, matrix);

	vector<vector<int> > band(lband + uband + 1, vector<int>(c, 0));

	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			if(i-j+uband >= 0 && i-j < lband+1)
				band[i-j+uband][j] = matrix[i][j];

	return band;
}

int main(){
	int r1, c1, r2, c2,i,j;


	vector<vector<int> > matrix1, matrix2, band1, band2;
	cin>>r1>>c1;

	matrix1.resize(r1);
	for(i=0;i<r1;i++)
		for(j=0;j<c1;j++)
		{
			int b;
			cin>>b;
			matrix1[i].push_back(b);
		}
	cin>>r2>>c2;
	matrix2.resize(r2);
	for(i=0;i<r2;i++)
		for(j=0;j<c2;j++)
		{
			int b;
			cin>>b;
			matrix2[i].push_back(b);
		}

	if(c1!=r2){
		cout << "Cannot multiply those matrices" << endl;
		return 0;
	}
	band1 = band(r1, c1, matrix1);
	band2 = band(r2, c2, matrix2);



	vector<vector<int> > matrix3(r1, vector<int>(c2, 0));
	int a1, a2, b1, b2, p2, q2, p1, q1,x,y;

	p1 = lowband(r1, c1, matrix1);
	q1 = upband(r1, c1, matrix1);

	p2 = lowband(r2, c2, matrix2);
	q2 = upband(r2, c2, matrix2);

	//Multiplication
	for(j = 0 ; j < c2 ; j++)
	{
		for(i = 0 ; i < r1 ; i++)
		{
			a1 = max(0, i-q1);
			a2 = min(r1-1, i+p1);
			b1 = max(0, q1-i);
			b2 = b1 + a2 - a1;

			if(i-j+q2 >= 0 && i-j < p2+1)
			{
				for(x = a1, y = b1 ; x <= a2 ; x++, y++)
					matrix3[x][j] += band1[y][i] * band2[i-j+q2][j];
			}
		}
	}
	cout << endl;
	for(i = 0 ; i < r1 ; i++){
		for(j = 0 ; j < c2 ; j++)
			cout << matrix3[i][j] << " ";
		cout << endl;
	}

	return 0;
}
