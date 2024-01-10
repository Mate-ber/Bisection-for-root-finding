#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-9;
double fun(double x){
//	return 15*x-5000-x*(10-5/(1-exp(-x)));
//  return x*x-4;
	return 2*sin(x)-2;
}
int main(){
	cout<<setprecision(10)<<fixed;
	
//	ofstream cout;
//    cout.open ("data3.txt");
    
	double l=-2,r=2;
	int it=0;
	while(r-l>eps){
		it++;
		double m=(l+r)/2;
		
		cout<<r-l<<" "<<it<<endl;
		if(fun(l)*fun(m)<0){
			r=m;
		}
		else{
			l=m;
		}
	}
//	cout<<"result:"<<(l+r)/2<<" iterations:"<<it<<endl;
	return 0;
}
