#include "Tree.h"


int main()
{
    Tree t;
    ofstream out_file;
    ifstream in_file;


    cout << "Welcome to Animal Guessing Game." << endl;
    bool loop_play;

        t.get_tree(in_file);
        t.read_from_file(t.head, in_file);
        in_file.close();
        cin.ignore(1000, '\n');

    while (loop_play == true)
    {
        t.choice(t.head, t.last_accessed);

        if (t.ask_if_animal(t.last_accessed) == true)
        {
            cout << "YAY! I GOT IT RIGHT!!!!" << endl;
        }
        else
        {
            cout << "OH NO! I GOT IT WRONG!!!" << endl;
            t.build_question(t.last_accessed);
        }

        string filename;
        cout << "Saving your questions. Input a filename." << endl;
        cin >> filename;

        out_file.open(filename);
        t.write_to_file(t.head,out_file);
        out_file.close();

        loop_play = t.play_again();
    }

    cout << "Closing. Goodbye!" << endl;


    return 0;
}
/*Asks if player wants to play again. If invalid response, recursion occurs.
INPUT: nothing.
OUTPUT: TRUE or FALSE, depending on user choice.
*/

