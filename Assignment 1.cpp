#include<string>
#include<iostream>
using namespace std;



//function for uppercase

string case(string x){

	int i=0;
	while(i<x.size()){
		i++;
	
		if(x[i]>=96){
			x[i]-=32;
		}
	}
	return x;
}






//function for remove special charecter

string charecter(string x){
	
	string fun="";
	int i = 0;
	while(i<x.size()){
		i++;
		
		if(x[i]>=96 && x[i]<=122 || x[i]>=65 && x[i]<=91){
			fun+=x[i];
		}
	}
	return fun;
}







//function for remove duplicates

string duplicate(string y){
	int i,j;
	bool x=false;
	string a = "";
	a += y[0];
	
	
	for(i=1;i<y.size();i++){
		for(j=0;j<a.size();i++){
			x=false;
			
			if(y[i]==a[j]){
				x=true;
			}

		}
		if(x==false){
			a += y[i];
		}
	}
		return a;	
}



