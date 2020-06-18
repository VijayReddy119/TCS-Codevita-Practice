#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	int rot;
	float longitude;

	rot = 24;
	longitude = 82.5;
	/*
	rot = 12;
	longitude = 360;*/

	float time = (rot/360.0)*longitude;
	int hr = (int)time;
	int min = ((float)(time - hr) * 60);

	float angle = abs(30 * (hr - (min/5)) + (min/2));

	if( (min == 0 && hr == 12) || (hr*5 == min) )
		angle = 0.00;
	
	cout<<fixed<<setprecision(2)<<angle;

	return 0;
}