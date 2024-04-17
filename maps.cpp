#include<map>
#include<string>
#include<iostream>
using namespace std;
// Adding elements in Map
map<int,int> mapInsert(int arr[],int n)
{
  map<int,int>mp;
  for(int i=0;i<n;i++){
  // mp[key]=value
     mp[arr[i]]=i;
  }
  return mp;
}
void mapDisplay(map<int,int>mp)
{
  // print every keey value pair in new line
  map<int,int>:: iterator it;
  for(it=mp.begin();it!=mp.end();it++){
    cout<<it->first<<" "<<it->second<<endl;  }
}

void mapErase(map<int,int>&mp,int x)
    {auto it = mp.find(x);
    if(it!=mp.end()){
      mp.erase(it);
      cout<<"erased"<<x;
    }
    else{
      cout<<endl;
    }
    }