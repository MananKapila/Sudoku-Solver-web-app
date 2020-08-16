#include<bits/stdc++.h>
using namespace std;

bool possible(int mat[][9],int sr,int sc,int n,int i)
{
	for(int row=0;row<n;row++)
	{
		if(mat[row][sc]==i)
		 return false;
	}
	
	for(int col=0;col<n;col++)
	{
		if(mat[sr][col]==i)
		{
			return false;
		}
	}
	
	//check the subgrid 
	int rn=sqrt(n);
	int r=(sr/rn)*rn;
	int c=(sc/rn)*rn;
	
	for(int row=r;row<r+rn;row++)
	{
		for(int col=c;col<c+rn;col++)
		{
			if(mat[row][col]==i)
			{
				return false;
			}
		}
	}
	return true;
}
bool solveSudoku(int mat[][9],int sr,int sc,int n)
{
	//base case
	if(sr==n)  //it means we have analysed all the rows 
	{
		//Print the Matrix
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<"\n";
		}
	
	}
	//Case row end
	if(sc==n)
	{
		return solveSudoku(mat,sr+1,0,n);
	}
	//Skip the prefilled cell
	if(mat[sr][sc]!=0)
	{
		return solveSudoku(mat,sr,sc+1,n);
	}
	
	//Rec
	//Fill the current cell with possible options
	for(int i=1;i<=n;i++)
	{
		if(possible(mat,sr,sc,n,i))
		{
			mat[sr][sc]=i;
			bool success=solveSudoku(mat,sr,sc+1,n);
			if(success)
			   return true;
			mat[sr][sc]=0; //BackTrack <-- all the values that were changed so far will revert back to 0   
		}		
	}
	return false;
}
int main()
{
	int mat[9][9]=
	{
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
	solveSudoku(mat,0,0,9);
	return 0;
}
