#include <iostream>
#include <string>
#include <map>

char nonRepeating(std::string &str){
  std::map<char,int> charCount;
  for(char c : str){
    auto indx = charCount.find(c);
    if (indx != charCount.end()){
      indx->second++;
    }else{
      charCount.insert(std::pair<char,int>(c,1));
    }
  }
  for(char c : str){
    auto indx = charCount.find(c);
    if (indx->second == 1){
      return c;
    }
  }
  return (char)NULL;
}

int main(){
  std::string str = "aabbbc";
  char a  = nonRepeating(str);
  std::cout<<a<<std::endl;
  return 0;
}
