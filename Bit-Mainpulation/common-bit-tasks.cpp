#include <iostream>

using namespace std;

bool getBit(int number, int i){
  return ((number&(1<<i))!=0);
}

int setBit(int number, int i){
  return (number|1<<i);
}

int clearBit(int number, int i){
  return (number&(~(1<<i)));
}

int updateBit(int number, int i, bool boolValue){
  int intValue = boolValue?1:0;
  int mask = ~(1<<i);
  return (number & mask) | (intValue<<i);
}
  
int main(){
  int number = 0x10;
  cout<<"Number: "<<number<<"; getBit i=4: "<<getBit(number,4)<<endl;
  cout<<"Number: "<<number<<"; setBit i=3: "<<setBit(number,3)<<endl;
  cout<<"Number: "<<number<<"; setBit i=3: "<<clearBit(number,3)<<endl;
  cout<<"Number: "<<number<<"; setBit i=3: "<<updateBit(number,3,1)<<endl;
  return 0;
}
