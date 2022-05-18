
#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>
#include<string>

#include <vector>
using namespace std;
namespace ariel{
TEST_CASE("good tests")
{
OrgChart org;
org.add_root("universe")
  .add_sub("universe", "earth")
  .add_sub("universe", "sun")
  .add_sub("universe", "moon")
  .add_sub("earth", "countries")
  .add_sub("countries", "cities")
  .add_sub("moon", "rocks");

 string level_o1;
  //level order
for (auto it = org.begin_level_order(); it != org.end_level_order(); ++it)
  {
    level_o1 += (*it)+ " " ;
  }
CHECK_EQ(level_o1,"universe earth sun moon countries cities rocks");
  //reverse order
  string reverse_o1;
for (auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it)
  {
    reverse_o1+= (*it) + " " ;
  } 
CHECK_EQ(reverse_o1,"cities countries rocks earth sun moon universe");
//preorder
string preorder1;
 for (auto it=org.begin_preorder(); it!=org.end_preorder(); ++it) {
    preorder1+=  (*it) + " " ;
  } 
CHECK_EQ(preorder1,"universe earth countries cities sun moon rocks");
//size
string size1;
for (auto it = org.begin_level_order(); it != org.end_level_order(); ++it)
  {
    size1+=to_string(it->size())  + " ";
  }
  
CHECK_EQ(size1,"8 5 3 4 9 6 5 8 5 3 4 9 6 5");

string level_o21;
for (auto element : org){
    level_o21+= element + " " ;
  }
CHECK_EQ(level_o21,"universe earth sun moon countries cities rocks");






OrgChart organization;
organization.add_root("root")
  .add_sub("root", "branch1")
  .add_sub("root", "branch2")
  .add_sub("root", "branch3")
  .add_sub("branch1", "leaf1")
  .add_sub("branch1", "leaf2")
  .add_sub("branch1", "leaf3")
  .add_sub("branch2", "leaf4")
  .add_sub("branch2", "leaf5")
  .add_sub("branch2", "leaf6")
  .add_sub("branch3", "leaf7")
  .add_sub("branch3", "leaf8")
  .add_sub("branch3", "leaf9");

  string level_o;
  //level order
for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    level_o += (*it)+ " " ;
  }
CHECK_EQ(level_o,"root branch1 branch2 branch3 leaf1 leaf2 leaf3 leaf4 leaf5 leaf6 leaf7 leaf8 leaf9");
  //reverse order
  string reverse_o;
for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
    reverse_o+= (*it) + " " ;
  } 
CHECK_EQ(reverse_o,"leaf3 leaf2 leaf1 leaf6 leaf5 leaf4 leaf9 leaf8 leaf7 branch1 branch2 branch3 root");
//preorder
string preorder;
 for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
    preorder+=  (*it) + " " ;
  } 
CHECK_EQ(preorder,"root branch1 leaf1 leaf2 leaf3 branch2 leaf4 leaf5 leaf6 branch3 leaf7 leaf8 leaf9");
//size
string size;
for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    size+=to_string(it->size())  + " ";
  }
  
CHECK_EQ(size,"4 7 7 7 5 5 5 5 5 5 5 5 5");

string level_o2;
for (auto element : organization){
    level_o2+= element + " " ;
  }
CHECK_EQ(level_o2,"root branch1 branch2 branch3 leaf1 leaf2 leaf3 leaf4 leaf5 leaf6 leaf7 leaf8 leaf9");

//if the keft input exist twice or more check not throw:
organization.add_sub("branch3", "leaf1");

organization.add_sub("branch3", "branch1");

CHECK_NOTHROW(organization.add_sub("leaf1", "leaf10"));
CHECK_NOTHROW(organization.add_sub("leaf1", "leaf11"));
CHECK_NOTHROW(organization.add_sub("leaf1", "leaf12"));
CHECK_NOTHROW(organization.add_sub("leaf1", "leaf13"));
CHECK_NOTHROW(organization.add_sub("leaf1", "leaf14"));
CHECK_NOTHROW(organization.add_sub("leaf1", "leaf15"));
CHECK_NOTHROW(organization.add_sub("leaf1", "leaf16"));

CHECK_NOTHROW(organization.add_sub("branch1", "leaf10"));
CHECK_NOTHROW(organization.add_sub("branch1", "leaf11"));
CHECK_NOTHROW(organization.add_sub("branch1", "leaf12"));
CHECK_NOTHROW(organization.add_sub("branch1", "leaf13"));
CHECK_NOTHROW(organization.add_sub("branch1", "leaf14"));
CHECK_NOTHROW(organization.add_sub("branch1", "leaf15"));
CHECK_NOTHROW(organization.add_sub("branch1", "leaf16"));


organization.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO

string begin;
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    begin +=  (*it) + " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI

  CHECK_EQ(begin,"CEO CTO CFO COO VP_SW VP_BI");
string reverse;  
  for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
    reverse += (*it) + " " ;
  } // prints: VP_SW VP_BI CTO CFO COO CEO
  CHECK_EQ(reverse,"VP_SW VP_BI CTO CFO COO CEO");
string pre;  
  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: CEO CTO VP_SW CFO COO VP_BI
CHECK_EQ(pre,"CEO CTO VP_SW CFO COO VP_BI");
string level;
  for (auto element : organization)
  { // this should work like level order
    level+= element + " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI
CHECK_EQ(level,"CEO CTO CFO COO VP_SW VP_BI");
string s;
for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    s+=to_string(it->size()) + " " ;
  } 

  CHECK_EQ(s,"3 3 3 3 5 5");
}

TEST_CASE("bad tests"){
  OrgChart organization;
  organization.add_root("root")
  .add_sub("root", "branch1")
  .add_sub("root", "branch2")
  .add_sub("root", "branch3")
  .add_sub("branch1", "leaf1")
  .add_sub("branch1", "leaf2")
  .add_sub("branch1", "leaf3")
  .add_sub("branch2", "leaf4")
  .add_sub("branch2", "leaf5")
  .add_sub("branch2", "leaf6")
  .add_sub("branch3", "leaf7")
  .add_sub("branch3", "leaf8");
  
//the left input dosent exist  
CHECK_THROWS( organization.add_sub("branch4", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch5", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch6", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch7", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch8", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch9", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch10", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch11", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch12", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch13", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch14", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch15", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch16", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch17", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch18", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch19", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch20", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch21", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch22", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch23", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch24", "leaf9")); 
CHECK_THROWS( organization.add_sub("branch25", "leaf9")); 

}
}
