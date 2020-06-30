#include<iostream>
#include<climits>

using namespace std;
int main(){
	int N, T;
/*
	cin>>N>>T;

	int arr[N][T+1];
	for(int i=0; i<N; i++){
		for(int j=0; j<=T; j++){
			cin>>arr[i][j]; 
		}
	}
*/

	N = 3;
	T = 7;
	int arr[N][T+1] = {
		{2, 2, 4, 3, 5, 2, 6, 2, 3},
		{3, 5, 7, 4, 3, 9, 3, 2, 2},
		{1, 2, 4, 2, 7, 5, 3, 2, 4}
	};

	int temp_T = T;
	if( T % 2 != 0 )
		T--;

	int scores[N][T/2], k=0;
	for(int i=0; i<N; i++){
		k=0;
		for(int j=0; j<T && k<T/2; j+=2){
			scores[i][k] = (arr[i][j] + arr[i][j+1]) * arr[i][temp_T];
			if(k==0){
				scores[i][k] = (arr[i][j] + arr[i][j+1]) * arr[i][temp_T];
			}else{
				scores[i][k] = scores[i][k-1] + (arr[i][j] + arr[i][j+1]) * arr[i][temp_T];
			}
			k++;
		}
	}

	int leaderboard[N] = {0}, max_score_cnt=INT_MIN;
	for(int i=0; i<T/2; i++){
		
		int max_elem=INT_MIN;

		for(int j=0; j<N; j++){
			//cout<<scores[j][i]<<"  ";
			if(scores[j][i] >= max_elem && max_elem!=0){
				max_elem = scores[j][i];
			}
		}

		for(int j=0; j<N; j++){
			if(scores[j][i] == max_elem)
				leaderboard[j]++;
		}

		/*cout<<"Score Count: ";
		for(int j=0; j<N; j++){
			cout<<leaderboard[j]<<"  ";
		}
		cout<<"\n";*/
	}

	for(int i=0; i<N; i++){
		if( leaderboard[i] >= max_score_cnt)
			max_score_cnt = leaderboard[i];
	}
	//cout<<max_score_cnt<<"\n";

	int winnerIndex= 0;
    for (int i=1; i<N; i++){
      
      if( leaderboard[i] > leaderboard[winnerIndex] )
        winnerIndex = i;
    }
    cout<<winnerIndex+1;

	return 0;
}