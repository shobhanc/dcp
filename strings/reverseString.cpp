#include <iostream>
#include <string>

using namespace std;

void recurReverseStr(string &str, int l, int r){
	if(l>=r) return;
	swap(str[l],str[r]);
	recurReverseStr(str,l+1,r-1);
}

void reverseStr(string &str){
	int l=0, r=str.length()-1;
	while(l<r){
		swap(str[l],str[r]);
		l++;
		r--;
	}
}

int main(int argc, char*argv[]){
	if(argc!=2){
		return 1;
	}
	string str(argv[1]);
	cout<<"Original Str="<<str<<endl;
	recurReverseStr(str, 0, str.length()-1);
	cout<<"Transformed Str="<<str<<endl;

	return 0;
}
