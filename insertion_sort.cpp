#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<int> val;
  int ip=0;
  while(cin>>ip)
  {
    val.push_back(ip);
  }
  cout<<"Input:"<<endl;
    for(int x=0;x<val.size();x++)
  {
    cout<<val[x]<<endl;
  }
  cout<<"**************************"<<endl;
  cout<<"Output"<<endl;
  int j = 1;
  int i = j - 1;
  
  while(j<=val.size()-1)
  {
    i = j-1;
    while(val[i]>val[j])
    {
      int t1 = val[i];
      val[i] = val[j];
      val[j] = t1;
      i--;
      j--;
    }
    j++;
  }
  
  
  for(int x=0;x<val.size();x++)
  {
    cout<<val[x]<<endl;
  }
}