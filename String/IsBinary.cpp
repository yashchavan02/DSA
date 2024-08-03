#include <iostream>
#include<string>

using namespace std;

class binary {
   string s;
   public:
     void read(void);
     bool check(void);
};

void binary :: read(void){
  cout<<"Enter the number : ";
  cin>>s;
}

bool binary :: check(void){
 for(int i=0;i<s.length();i++){
   if(s.at(i)!='0' && s.at(i)!='1'){
       return false;
     }
   }
}

int main(){

  binary b;

  b.read();

  if(!(b.check())){
   cout<<"Binary Number"<<endl;
  }
  else{
   cout<<"Not a Binary Number"<<endl;
  }
  
  return 0;
}