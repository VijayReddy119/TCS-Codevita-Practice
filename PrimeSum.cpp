#include<iostream>
#include<unordered_map>
#include<cmath>
#include<string>

using namespace std;

bool isPrime(int n){
	if (n == 1) 
        return false;
    
    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}

char getKey(unordered_map<char,int> &baseVal, int val){
	for(auto it=baseVal.begin(); it!=baseVal.end(); it++){
		if(it->second == val)
			return it->first;
	}
	return '-';
}

int getValue(unordered_map<char, int> &baseVal, string N, int base){
	int val = 0, cnt=0;
	if(N.size() == 1)
		return baseVal[N[0]];
	else{
		for(int i=N.size()-1; i>=0; i--){
			val += baseVal[N[i]] * pow(base, cnt);
			cnt++;
		}
	}
	return val;
}

int main(){
	string N;
	char S;
	//cin>>N>>S;

	N = "ZZ";
	S = 'Z';

	unordered_map<char, int> baseTaken;
	int i=0;
	for(i=0; i<10; i++)
		baseTaken['0' + i] = i;
	
	for(int j=0; j<26; j++)
		baseTaken['A' + j] = i++;
	
	int base = 2;
	if(baseTaken.find(N[N.size() - 1]) != baseTaken.end() && baseTaken[N[N.size() - 1]] >= 2 && baseTaken[N[N.size() - 1]] <= 35)
		base = baseTaken[N[N.size() - 1]] + 1;

	int prev_val = getValue(baseTaken, N, base), val=0;
	int req_base = baseTaken[S] + 1, prefix = 0;
	
	while(true){
		val = getValue(baseTaken, to_string(prefix)+""+S, base);
		if(isPrime(val) && val >= prev_val)
			break;
		prefix++;
	}

	string output_val_rev="";
	while(val > 0){
		output_val_rev += getKey(baseTaken, val%req_base);
		val /= req_base;
	}

	string output = "";
	for(int j = output_val_rev.size()-1; j>=0; j--){
		output += output_val_rev[j];
	}

	cout<<output;

	return 0;
}