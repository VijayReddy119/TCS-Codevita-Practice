#include<iostream>
#include<stack>
#include<climits>
using namespace std;

int find_distance(int x1,int y1){
	int x=1, y=1;
	return (x1-x) + (y1-y);
}

int main(){
	/*
	int m=2, n=9;
	int arr[10][10] = {{1,0,1,1,0,1,1,1,1},{0,0,0,1,0,1,0,0,1}};

	int m=6, n=6;
	int arr[10][10] = {
		{1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 0},
		{0, 0, 1, 1, 1, 0},
		{0, 0, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0},
	};*/

	int m=2, n=3;
	int arr[10][10] = {{1,0,1},{0,0,0}};
	
	int max_count=0, count=0;
	arr[0][0] = 0;

	stack<pair<int,int>> st;

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			count = 0;
			if(arr[i][j] == 1)
			{
				//Top Row
				if( i>0 && arr[i-1][j] == 1 )
					count++;
				if( i>0 && j>0 && arr[i-1][j-1] == 1 )
					count++;
				if( i>0 && j+1<n && arr[i-1][j+1] == 1 )
					count++;
				//Same Row
				if( j>0 && arr[i][j-1] == 1 )
					count++;
				if( j+1<n && arr[i][j+1] == 1 )
					count++;
				//Bottom Row
				if( i+1<m && arr[i+1][j] == 1 )
					count++;
				if( i+1<m && j>0 && arr[i+1][j-1] == 1 )
					count++;
				if( i+1<m && j+1<n && arr[i+1][j+1] == 1 )
					count++;

				//cout<<i<<" : "<<j<<" : "<<count<<"\n";

				if( count!=0 && count > max_count){
					max_count = count;
					while(!st.empty()){
						st.pop();
					}
					st.push(make_pair(i,j));
				}
				else if(count!=0 && count == max_count){
					st.push(make_pair(i,j));
				}
			}
		}
	}

	if(max_count == 0){
		cout<<"No Suitable Girl Found"<<"\n";
		return 0;
	}

	int min_distance=INT_MAX, x_f, y_f;
	if(st.size() == 1){
		x_f = st.top().first;
		y_f = st.top().second;
		cout<<x_f+1<<" : "<<y_f+1<<" : "<<max_count;
	}
	else{
		while(!st.empty()){
			if( find_distance(st.top().first, st.top().second) < min_distance){
				x_f = st.top().first;
				y_f = st.top().second;
				min_distance = find_distance(st.top().first, st.top().second);
			}
			else if(find_distance(st.top().first, st.top().second) == min_distance){
				cout<<"Polygamy not allowed";
				return 0;
			}
			st.pop();
		}
		cout<<x_f+1<<" : "<<y_f+1<<" : "<<max_count;
	}

	return 0;
}