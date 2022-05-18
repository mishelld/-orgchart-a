#include <iostream>
#include <vector>
#include <queue>
#include <map>



using namespace std;
namespace ariel
{

    class OrgChart
    {
        public:
        vector <string> temp; 
        OrgChart &add_root(string name);
        OrgChart &add_sub(string root, string child);

        string *begin_level_order();
        string *end_level_order();

        string *begin_reverse_order();
        string *reverse_order();

        string *begin_preorder();
        string *end_preorder();

        string *begin();
        string *end();
        
        friend ostream &operator<<(ostream &os, OrgChart &org);

    };
}