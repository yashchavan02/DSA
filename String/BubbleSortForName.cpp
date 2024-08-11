#include<iostream>
#include<vector>

using namespace std;

vector<string> SortByName(vector<string> &v) {
	int LengthOfVec = v.size();
	for(int i=0; i<(LengthOfVec-1); i++) {
		for(int j=0; j<(LengthOfVec-i-1); j++) {
			if(v.at(j+1) < v.at(j)) {
				string Temp = v.at(j);
				v.at(j) = v.at(j+1);
				v.at(j+1) = Temp;
			}
		}
	}
	return v;
}

int main() {

	vector<string> v;

	v.push_back("vivek");
	v.push_back("abhay");
	v.push_back("kunal");
	v.push_back("tanmay");
	v.push_back("aditya");

	vector<string> res = SortByName(v);
	int LengthOfVec = res.size();
	for(int i=0; i<LengthOfVec; i++) {
		cout<<v.at(i)<<", ";
	}
	return 0;
}