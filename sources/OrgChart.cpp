#include "OrgChart.hpp"
using namespace std;
#include <queue>
#include <bits/stdc++.h>
namespace ariel{
OrgChart &OrgChart::add_root(string name){
temp.push_back(" ");
return *this;
}

OrgChart &OrgChart::add_sub(string root, string child){

return *this;    
}

string *OrgChart::begin_level_order(){
return &temp[0];   
}

string *OrgChart::end_level_order(){
return &temp[temp.size()]; 
}

string *OrgChart::begin_reverse_order(){
return &temp[0];     
}

string *OrgChart::reverse_order(){
return &temp[temp.size()];      
}

string *OrgChart::begin_preorder(){
return &temp[0];      
}
string *OrgChart::end_preorder(){
return &temp[temp.size()];   
}

string *OrgChart::begin(){
return begin_level_order();
}
string *OrgChart::end(){
return end_level_order();
}

ostream &operator<<(ostream &os, OrgChart &org){
os<< "";
return os;
}




}