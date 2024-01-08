#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-9;
double fun(double x){
	return 15*x-5000-x*(10-5/(1-exp(-x)));
//  return x*x-4;
}
int main(){
	cout<<setprecision(10)<<fixed;
	double l=eps,r=1e9;
	int it=0;
	while(r-l>eps){
		it++;
		double m=(l+r)/2;
		if(fabs(fun(m))<=eps){
			cout<<"result:"<<m<<" iterations:"<<it<<endl;
			return 0;
		}
		if(fun(l)*fun(m)<0){
			r=m;
		}
		else{
			l=m;
		}
	}
	cout<<"result:"<<(l+r)/2<<" iterations:"<<it<<endl;
	return 0;
}