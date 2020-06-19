#include<iostream>
#include<cmath>

using namespace std;
int main(){
	int T;
	cin>>T;
	int arr[T];
	for(int t=0; t<T; t++){
		int N;
		cin>>N;

		arr[t] = (1 + floor(log2(N)));
	}

	for(int t=0; t<T; t++){
		cout<<arr[t]<<"\n";
	}

	return 0;
}