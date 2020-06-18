#include<iostream>
#include<vector>

using namespace std;

int cw_count = 0, acw_count = 0;
vector<vector<char>> cw, acw;

int rotate_clock(vector<vector<char>> &v, int i, int j){
	if(v[i][i]=='X')
		return cw_count;
	else{
		char a,b,c,d;
		a = v[i][i];
		b = v[i][j];
		c = v[j][j];
		d = v[j][i];
		
		int k = j;	//Top Horizontal
		while( k > i ){
			char temp = v[i][k-1];
			v[i][k--] = temp;
		}
		
		int l = j;  //Right Vertical
		while( l > i){
			char temp = v[l-1][j];
			v[l--][j] = temp;
		}
		
		int m = i;  //Bottom Horizontal
		while( m < j){
			char temp = v[j][m+1];
			v[j][m++] = temp;
		}
		int n = i;  //Left Vertical
		while(n < j){
			char temp = v[n+1][i];
			v[n++][i] = temp;
		}
		
		v[i+1][j] = b;
		v[j-1][i] = d;
		v[j][j-1] = c;

		cw_count++;
		rotate_clock(v,i,j);
	}
	return cw_count;
}


int rotate_anti_clock(vector<vector<char>> &v, int i, int j){
	if(v[i][i] == 'X'){
		return acw_count;
	}else{
		char a,b,c,d;
		a = v[i][i];
		b = v[i][j];
		c = v[j][j];
		d = v[j][i];
		
		int m = i;  //Top Horizontal
		while( m < j ){
			char temp = v[i][m+1];
			v[i][m++] = temp;
		}

		int k = j;	//Bottom Horizontal
		while( k > i ){
			char temp = v[j][k-1];
			v[j][k--] = temp;
		}
		
		int l = j;  //Left Vertical
		while( l > i ){
			char temp = v[l-1][i];
			v[l--][i] = temp;
		}
		
		int n = i;  //Right Vertical
		while(n < j ){
			char temp = v[n+1][j];
			v[n++][j] = temp;
		}
		
		v[i+1][i] = a;
		v[j-1][j] = c;

		acw_count++;
		rotate_anti_clock(v,i,j);
	}
	return acw_count;
}

int main(){
	/* Given Case 1
	int N=5;
	vector<vector<char>> v = {
		{'O','I','M','U','R'},
		{'J','V','U','X','A'},
		{'X','W','T','S','R'},
		{'K','Z','F','H','D'},
		{'Q','W','K','V','M'}};
	*/	
	//Given Case 2
	int N=7;	
	vector<vector<char>> v = {
		{'L','E','A','R','K','X','G'},
		{'N','Z','N','Z','Q','B','S'},
		{'O','P','E','B','M','S','I'},
		{'A','Z','R','T','X','M','U'},
		{'A','W','S','S','O','K','U'},
		{'A','X','B','A','G','M','O'},
		{'D','F','Q','A','C','U','U'}
	};
	
	for(int i=0; i<v.size(); i++){
		for(char c : v[i]){
			cout<<c<<"  ";
		}
		cout<<"\n";
	}

	cout<<"\n";
	
	int i=0, j=N-1, total_steps=0;
	cw = acw = v;
	
	for(int i=0; i<N/2; i++){
		cw_count = acw_count = 0;

		cw_count = rotate_clock(cw, i, j);
		acw_count = rotate_anti_clock(acw, i ,j);

		if(cw_count < acw_count){
			v = cw;
			total_steps = cw_count*(-1);
		}
		else{
			v = acw;
			total_steps = acw_count;
		}

		j--;
		cout<<total_steps<<" ";
	}
	cout<<"\n";
	for(int i=0; i<v.size(); i++){
		for(char c : v[i]){
			cout<<c<<"  ";
		}
		cout<<"\n";
	}

	return 0;
}