#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
namespace comp_assignment_3
{
struct TreeNode
{
    string text;
    TreeNode *yes, *no;
};
typedef TreeNode* TreeNodePtr;
}
using namespace comp_assignment_3;


class Tree
{
    public:
        Tree();

        void write_to_file(TreeNodePtr start,ofstream& out_file);
        void read_from_file(TreeNodePtr& start,ifstream& in_file);
        void choice(TreeNodePtr& start, TreeNodePtr& last_accessed);
        bool ask_if_animal(TreeNodePtr start);
        void add_new_question(TreeNodePtr& start);
        void build_question(TreeNodePtr& start);
        void get_tree(ifstream&);
        bool play_again();
        int get_answer();
        virtual ~Tree();

        TreeNodePtr head;
        TreeNodePtr last_accessed;
    protected:

    private:
};

#endif // TREE_H
