#ifndef BSTREE_H
#define BSTREE_H
#include "Animal.h"

struct BSNode {
	int data;
	struct BSNode* left;
	struct BSNode* right;
};

class BSTree
{
    public:

        BSTree();
        virtual ~BSTree();

        void Insert(const int&);
        bool Search(const int&);
        void DeleteElement(const int&);

        void DeleteTree();

        void printPre();
        void printIn();
        void printPost();

    protected:

    private:

        BSNode* root;

        BSNode* insertTree(BSNode*, const int&);
        BSNode* searchTree(BSNode*, const int&);
        void deleteElementTree(BSNode*, const int&);

        void preorderTraversal(BSNode*);
        void inorderTraversal(BSNode*);
        void postorderTraversal(BSNode*);

        void treeDestructor(BSNode*);
};

#endif // BSTREE_H
