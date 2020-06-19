#include<iostream>
#include<unordered_map>
#include<cmath>

using namespace std;

float findDistance(int x, int y){
	return sqrt(x*x + y*y);
}

float findTime(float distance, int speed){
	return (distance / speed);
}

int combinate(int cnt){
	return ((cnt)*(cnt-1))/2;
}

int main(){
	int N;
	//cin>>N;
	N = 10;
	//int arr[N][3];
	/*
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cin>>arr[i][j];
		}
	}*/

	int arr[N][3] = {
		{5, 12, 1}, 	//13		-- A
		{16, 63, 5},	//13		-- B				A,B,C -- 13---- A,B; A,C; B,C
		{-10, 24, 2},
		{10, 24, 2},
		{24, 10, 2},	//13		-- C  				A,B,C,D,E -- 13 --- A,B; A,C; A,D; A,E; B,C; B,D; B,E; C,D; C,E; D,E
		{7, 24, 2},		//12.5		-- D
		{-24, 7, 2},		//12.5		-- E
		{3, 4, 1},
		{4, 3, 1},
		{12, 5, 1},

	};

	
	unordered_map<int, int> timeCnt;
	for(int i=0; i<N; i++){
		float distance = findDistance(arr[i][0], arr[i][1]);
		float time_f = findTime(distance, arr[i][2]);

		if(timeCnt.find(time_f) != timeCnt.end()){
			timeCnt[time_f]++;
		}else{
			timeCnt[time_f] = 1;
		}
	}

	int Cnt = 0;
	for(auto it=timeCnt.begin(); it!=timeCnt.end(); it++){
		if(it->second > 1){
			Cnt += combinate(it->second);
		}
	}

	cout<<Cnt<<"\n";

	int collisionCnt = 0;
	for(int i=0; i<N; i++){
		float distance = findDistance(arr[i][0], arr[i][1]);
		float time_f = findTime(distance, arr[i][2]);

		for(int j=i+1; j<N; j++){
          	if(time_f == findTime(findDistance(arr[j][0], arr[j][1]), arr[j][2])){
	            collisionCnt++;
        	}
        }
	}
	cout<<collisionCnt;

	return 0;
}