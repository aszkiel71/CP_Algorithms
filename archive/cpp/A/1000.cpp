#include <iostream>
#include <vector>

using namespace std;

//fun fact, we don't even use it
/*
bool isValid(const string &s){

  //checking if in string are unexpected chars
  for(char c : s){
    if(c != 'X' and c != 'M' and c != 'L' and c != 'S')
      {
      return false;
      }
  }

  //checking if there is pattern like LX

  if (s.size() >= 2)
  {
    for(int i = 0; i < s.size()-1; i++)
    {
      if(s[i] != 'X' and s[i+1] == 'X')
      {
        return false;
      }
    }
  }

  //checking for pattern like X___X
  int first_x_index = 0;
  int last_x_index = 0;
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] == 'X')
    {
      first_x_index = i;
      break;
    }
  }
  for (int i = 0; i < s.size(); i++)
  {
    if(s[i] == 'X')
    {
      last_x_index = i;
    }
  }

  for (int i = first_x_index; i < last_x_index; i++)
  {
    if(s[i] != 'X')
    {
      return false;
    }
  }
  //checking amount of 'X' or if there is only 'X' in it.
  int counter_of_x = 0;
  int counter_of_m = 0;
  int counter_of_s = 0;
  int counter_of_l = 0;
  for(char c : s){
    if(c == 'X'){
      counter_of_x++;
    }
    else if(c == 'M'){
      counter_of_m++;
    }
    else if(c == 'S'){
      counter_of_s++;
    }
    else if(c == 'L'){
      counter_of_l++;
    }
  }

  if(counter_of_x == s.size() or counter_of_x > 3 or counter_of_m > 1 or counter_of_s > 1 or counter_of_l > 1){
    return false;
  }

  return true;
}
*/
vector<string> removeElementByIndex(const vector<string> &vec, int indexToRemove)
{
  if (indexToRemove < 0 || indexToRemove >= vec.size())
  {
    return vec;
  }

  vector<string> res = vec;
  res.erase(res.begin() + indexToRemove);
  return res;
}


int main() {
  int n;
  cin>>n;
  vector <string> sizes_a(n);
  for(int i = 0; i < n; i++)
  {
    cin>>sizes_a[i];
  }
  vector<string> sizes_b(n);
  for(int i = 0; i < n; i++)
  {
    cin>>sizes_b[i];
  }

  //missing in b
  for (int i = 0; i < sizes_a.size(); i++) {
    bool found = false;
    for (int j = 0; j < sizes_b.size(); j++) {
      if (sizes_a[i] == sizes_b[j]) {
        sizes_a = removeElementByIndex(sizes_a, i);
        sizes_b = removeElementByIndex(sizes_b, j);
        found = true;
        break;
      }
    }
    if (found) {
      i--;
    }
  }
  cout<<sizes_a.size()<<endl;



  return 0;
}
