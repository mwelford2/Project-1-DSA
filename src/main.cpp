#include <iostream>
#include <cstring>
#include <sstream>

#include "AVLTree.h"

using namespace std;

/*
 *insert NAME ID
 *     Add a Student object into the tree with the specified name, NAME, and GatorID number, ID.
 *     Balance the tree automatically if necessary.
 *     The ID must be unique.
 *     The ID and NAME must satisfy the constraints stated below.
 *     Also, prints “successful” if insertion is successful and prints “unsuccessful” otherwise.
 *     NAME identifier will be separated by double inverted commas for parsing, e.g., "Josh Smith."
 *remove ID
 *     Find and remove the account with the specified ID from the tree.
 *     [Optional: Balance the tree automatically if necessary. We will test your code only on cases where the tree will be balanced before and after the deletion. So you can implement a BST deletion and still get full credit]
 *     If deletion is successful, print ““successful.”
 *     If the ID does not exist within the tree, print “unsuccessful.”
 *     You must prioritize replacing a removed node with its inorder successor for the case where the deleted node has two children.
 *search ID
 *     Search for the student with the specified ID from the tree.
 *     If the ID was found, print out their NAME.
 *     If the ID does not exist within the tree, print “unsuccessful.”
 *search NAME
 *     Search for the student in the tree with the specified name, NAME.
 *     If the student's name was found, print the associated ID.
 *     If the tree has more than one object with the same NAME, print each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
 *     If the name does not exist within the tree, print “unsuccessful.”
 *     NAME identifier will be surrounded by double quotes for parsing, e.g., "Josh Smith."
 *printInorder
 *      Print out a comma separated inorder traversal of the names in the tree.
 *printPreorder
 *      Print out a comma-separated preorder traversal of the names in the tree.
 *printPostorder
 *      Print out a comma-separated postorder traversal of the names in the tree.
 *printLevelCount
 *     Prints the number of levels that exist in the tree.
 *     Prints 0 if the head of the tree is null. For example, the tree in Fig. 1 has four levels.
 *removeInorder N
 *     Remove the Nth GatorID from the inorder traversal of the tree (N = 0 for the first item, etc).
 *     If removal is successful, print “successful.”
 *     Optional: Balance the tree automatically if necessary. We will test your code only on cases where the tree will be balanced before and after the deletion. So you can implement a BST deletion and still get full credit.
 *     If the Nth GatorID does not exist within the tree, print “unsuccessful.”
 */

bool isNum(string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (!isdigit(str[i])) return false;
    return true;
}

int main()
{
    string numCommands;
    AVLTree t;

    getline(cin, numCommands);

    for (int i = 0; i < std::stoi(numCommands); i++)
    {
        string input;
        getline(cin, input);

        stringstream s(input);
        string com, arg;

        s >> com; //put command into com

        if (com == "insert")
        {
            s.ignore(); //ignore ' '
            s.ignore(); // ignore ""

            getline(s, arg, '"'); //put name into arg

            string idstr;
            s >> idstr;
            if (!isNum) cout << "unsuccessful" << endl;
            else t.insert(arg, stoi(idstr));
        }
        else if (com == "remove")
        {
            s >> arg; //put id into arg
            if (!isNum) cout << "unsuccessful" << endl;
            else t.remove(stoi(arg));
        }
        else if (com == "search")
        {
            s.ignore(); //ignore ' '
            if (s.peek() == '"')
            {
                s.ignore(); //ignore "
                getline(s, arg, '"');
                t.search(arg);
            }
            else
            {
                s >> arg;
                if (!isNum) cout << "unsuccessful" << endl;
                else t.search(stoi(arg));
            }
        }
        else if (com == "printInorder") t.printInOrder();
        else if (com == "printPreorder") t.printPreOrder();
        else if (com == "printPostorder") t.printPostOrder();
        else if (com == "printLevelCount") t.printLevelCount();
        else if (com == "removeInorder")
        {
            s >> arg; //put N into arg
            if (!isNum) cout << "unsuccessful" << endl;
            else t.removeInOrder(stoi(arg));
        }
        else cout << "unsuccessful" << endl;
    }
    return 0;
}