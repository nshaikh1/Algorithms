#include<iostream>
#include<map>
#include<cmath>
#include<vector>

using namespace std;

void init(map<char,unsigned> &db)
{
  for(unsigned x=97;x<=122;x++)
  {
    db.insert(pair<char,unsigned>((char)x,x%97));
  }
}
void display(map<char,unsigned> db)
{
  for(auto x=db.begin();x!=db.end();x++)
  {
    cout<<x->first<<"="<<x->second<<endl;
  }
}
//Convert an input patter to a hashed value based on the mapping in DB
int getPatternHash(string p,map<char,unsigned> db)
{
  unsigned len = p.length();
  int hashed = -1;
  for(int x=0;x<len;x++)
  {
    auto it = db.find(p[x]);
    if(it!=db.end())
    {
      if(hashed==-1)
        hashed=0;
      hashed = hashed + (it->second * (pow(26,x)));
      //cout<<it->second<<endl;
    }
  }
  return hashed;
}
bool charWise(string a,string b)
{
  if(a==b)
    return true;
  else
    return false;
}
vector<unsigned> findOccur(int patternHash,map<char,unsigned> db,string input,string pattern)
{
  unsigned patLen = pattern.length();
  
  int from=0;
  int to=patLen-1;
  vector<unsigned> occur;
  while(to<=input.length())
  {
    string sel;
    for(int x=from;x<=to;x++)
    {
      sel = sel + input[x];
    }
    int hashS = getPatternHash(sel,db);
    if(hashS==patternHash)
    {
      //NEED TO PERFORM FURTHER CHECK CHAR WISE
      //Test case string = hahaahaah
      //pattern = aha
      //Error if no further check as aha == aah
      bool flag = charWise(sel,pattern);
      if(flag==true)
        occur.push_back(from);
    }
    from++;
    to++;
  }
  return occur;
}

int main()
{
  //Rabin Karp Finger Print algorithm  
  //map contains alphabet and code mapping.
  map<char,unsigned> db;
  init(db);
  //cout<<"Current Mapping is:"<<endl;
  //display(db);
  string input;
  cout<<"Enter a string(No Spaces, No Specials, No Capital):"<<endl;
  cin>>input;
  cout<<"Enter the pattern(No Spaces, No Specials, No Capital):"<<endl;
  string pattern;
  cin>>pattern;
  cout<<"Entered String:"<<endl;
  cout<<input<<endl;
  cout<<"Searching Patter:"<<endl;
  cout<<pattern<<endl;
  
  int patternHash = getPatternHash(pattern,db);
  
  vector<unsigned> occurs = findOccur(patternHash,db,input,pattern);
  cout<<"Pattern occurs:"<<occurs.size()<<" times."<<endl;
  cout<<"Location of occurance:"<<endl;
  for(int x=0;x<occurs.size();x++)
  {
    cout<<occurs.at(x)<<" "<<endl;
  }
    
  
}