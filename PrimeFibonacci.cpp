#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>

using namespace std;

bool isPrime(int n)
{
	if (n == 1)
		return false;
	int i=2;
	while(i*i <= n){
		if(n%i == 0)
			return false;
		i++;
	}
	return true;
}

void combination(vector<string> &lst, unordered_set<int> &combineList)
{
	for(int i=0; i<lst.size(); i++){
		for(int j=0; j<lst.size(); j++){
			if (i == j)
				continue;
			combineList.insert(stoi(lst[i]+lst[j]));
		}
	}
}

int main(){
	int n1, n2;
	cin>>n1>>n2;

	vector<string> prime_lst;
	for(int i=n1; i<n2; i++){
		if(isPrime(i)){
			prime_lst.push_back(to_string(i));
		}
	}
	unordered_set<int> combinedList;
	combination(prime_lst, combinedList);

	int max_no=0, min_no=INT_MAX, countPrime=0;
	for(auto it=combinedList.begin(); it!=combinedList.end(); it++){
		if(isPrime(*it)){
			if(*it > max_no)
				max_no = *it;
			
			if(*it < min_no)
				min_no = *it;

			countPrime++;
		}
	}

	long long a = min_no, b=max_no;
	long long fibonacci;

	for(long long o=1; o<countPrime-1; o++){
		fibonacci = a+b;
		a = b;
		b = fibonacci;
	}

	cout<<fibonacci;

	return 0;
}