#include "Tree.h"

Tree::Tree()
{
    //ctor
}
bool Tree::play_again()
{
    string input;
    cout << "That was fun! Do you want to play again?" << endl;
    cin >> input;
    cin.ignore();
    if (input == "yes")
        return true;
    else
    {
        if (input == "no")
            return false;
        else
        {
            cout << "Invalid answer. " << endl;
            play_again();
        }
    }
}
/*Gets the filename with the tree.
INPUT: Ifstream
OUTPUT: The file in the ifstream.
*/
void Tree::get_tree(ifstream& in_file)
{
    string filename;

    cout << "Input file name.Follow by (.txt)."<<endl;
    cin >> filename;
    in_file.open(filename);

    if (in_file.fail())
    {
        cout << "Invalid. ";
        get_tree(in_file);
    }
    else
    {
        return;
    }
}


/* Builds the new question if the guessed animal wasn't right. It first asks for the animal and question, and then reorganizes tree.
Original animal is moved to the yes_ans treenode, the new animal to the no_ans and the new question to the head of the two branches.
INPUT: TreenodePtr at which it was last accessed
OUTPUT: Reassigned last accessed node with new link pointers.
*/
void Tree::build_question(TreeNodePtr& start)
{
    string new_a;
    string new_q;
    cout << "WHAT'S YOUR ANIMAL?" << endl;

    getline(cin, new_a);
    cin.clear();
    cout << "OK. Help my by adding a question! Type a question for which yes is a " << new_a << " and no for a " << start->text << "." << endl;
    getline(cin,new_q);
    cin.clear();
    //cout << new_q;

    TreeNodePtr yes = new TreeNode;
    yes->text = new_a;
    yes->yes=NULL;
    yes->no=NULL;

    TreeNodePtr no = new TreeNode;
    no->text = start->text;
    no->yes = NULL;
    no -> no = NULL;

    start->text = new_q;
    start->yes = yes;
    start->no = no;
    return;
}

/*Asks if animal is right.
INPUT: TreeNodePtr at where it was last accessed
OUTPUT: TRUE if guessed correctly and FALSE if not.
*/
bool Tree::ask_if_animal(TreeNodePtr start)
{
    int user_decision;
    cout << "Is your animal a " << start->text << "?" << endl;
    user_decision = get_answer();
    if (user_decision == 0)
        return false;
    else
    {
        if (user_decision == 1)
            return true;
        else
        {
            cout << "Invalid answer.";
            ask_if_animal(start);
        }
    }
}
/*Allows user to navigate tree by saying yes or no to identify animal.
INPUT: TreeNodePtr start and last accessed
OUTPUT: Referenced TreeNodePtr's
*/
void Tree::choice(TreeNodePtr& start, TreeNodePtr& last_accessed)
{
    int user_choice;
    last_accessed = start;
    if (start->yes == NULL && start->no == NULL)
        return;
    else
    {
        cout << "Question " << start->text << endl;
        user_choice = get_answer();
        //cout << "ANSWER = " << user_choice << endl;
        if (user_choice == 0) // NO -> no_ans
        {
            choice(start->no, last_accessed);
        }
        else
        {
            if (user_choice == 1) // YES -> yes
            {
                choice(start->yes, last_accessed);
            }
            else
            {
                cout << "Not a valid answer. ";
                choice(start, last_accessed);
            }
        }

    }
}

/* Writes the entire tree into a text file for future use
INPUT: TreeNodePtr at where it was lasted accessed and ofstream
OUTPUT: The text file.
*/
void Tree::write_to_file(TreeNodePtr start, ofstream& out_file)
{
    if (start == NULL)
        out_file << "*" << endl;
    else
    {

        out_file << start->text << endl;
        write_to_file(start->yes, out_file);
        write_to_file(start->no, out_file);
    }
    return;
}

/* Reads the file in the ifstream and builds the tree.
INPUT: TreeNodePtr start for the linked list tree and ifstream infile for the tree data
OUTPUT: The completed TreeNodePtr start tree
*/
void Tree::read_from_file(TreeNodePtr& start,ifstream& in_file)
{
    string input;

    getline(in_file, input);


    if (input != "*" )
    {
        start = new TreeNode;
        start->text = input;
        read_from_file(start->yes, in_file);
        read_from_file(start->no, in_file);
    }
    else
    {
        //cout << "NULL";
        start = NULL;
    }
}

/* Creates the default tree linked list
INPUT: NONE
OUTPUT: A usable tree TreeNodePtr defined as head in main.
*/


/* Gets the answer to a question by getting the input if it is yes or no
INPUT: None
OUTPUT: An int that represents yes, no or an invalid answer.
*/
int Tree::get_answer()
{
    string answer;
    cin.clear();
    getline(cin,answer);
    //cout << "GET_ANS = " << answer;
    if(answer == "yes" || answer == "YES" || answer == "Yes")
    {
        return 1;
    }

    else
    {
        if(answer == "No" || answer == "NO" || answer == "no")
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}
Tree::~Tree()
{
    //dtor
}
