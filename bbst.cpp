#include <iostream>
#include "RedBlackTree.h"
using namespace std;
int main()
{
    RBTree tree;
    /*Check if a file is given as a command-line parameter
     if not provided show error and exit*/
    if (argc == 0) {
        cout<<"Error print program usuage\n";
        return -1;
    }
    /*TODO: Check if file exists*/
    
    /*Read from the file-name and build a Red-Black Tree*/
    ifstream file(argv[1]); /*fstream*/
    vector<inputPairPTR> tempVector;
    int idTemp , countTemp;
    string temp;
    int ignoreFirstLine = 1;
    if(file.is_open()){
        while(file.good()){
            if (ignoreFirstLine == 1) { /*Ignore the first number in file which is anyway lenght of input*/
                getline(file,temp);
                ignoreFirstLine = 0;
                continue;
            }
            getline(file,temp);
            stringstream ss(temp);
            ss >> idTemp >> countTemp;
            //cout<< idTemp << " " << countTemp << "\n\n";
            struct inputPair * newNode = (struct inputPair *) malloc(sizeof(inputPair));
            newNode->ID =  idTemp;
            newNode->count = countTemp;
            tempVector.push_back(newNode);
        }
    } else{
        cout << "Error: Problem opening input file or some other problem with file\n\n";
        exit(0);
    }
    
    NODEPTR root = sortedArrayToBST(tempVector);
    /*Freeing the memory of vector , it is 1GB so need to free it! */
    vector<inputPairPTR>::iterator i;
    for (i = tempVector.begin(); i != tempVector.end(); i++) {
        free(*i);
    }
    tempVector.clear();
    //    inorder(root);
    //    cout<<"\n\n\n";
    RBTree rbTree(root);
    rbTree.makeLeafRed(root);
    /*Red Black Tree ready!*/
    
    while (1) {
        //Input a command
        string command;
        getline(cin,command);
        stringstream ss(command);
        cout<<command<<"\n";
        int theID , count = 0 ;
        string leaveIt;
        if (command.find("increase") != string::npos) {
            ss >> leaveIt >> theID >> count;
            //            cout<<"Increase Case\n";
            Increase(theID,count,root);
            cout<<"\n";
        }
        else if (command.find("reduce") != string::npos) {
            ss >> leaveIt >> theID >> count;
            //            cout<<"reduce Case\n";
            Reduce(root,theID,count);
            cout<<"\n";
        }
        else if (command.find("count") != string::npos) {
            ss >> leaveIt >> theID;
            //            cout<<"count Case\n";
            Count(root,theID);
            cout<<"\n";
        }
        else if (command.find("inrange") != string::npos) {
            int ID1 = 0 , ID2 = 0;
            ss >> leaveIt >> ID1 >> ID2;
            //Reduce(root,theID,count);
            cout << InRange(root, ID1 , ID2);
            cout<<"\n";
        }
        else if (command.find("next") != string::npos) {
            ss >> leaveIt >> theID;
            //            cout<<"next Case\n";
            NODEPTR temp = successor(root,theID);
            if (temp == NULL) {
                cout<<"0 0\n";
            }
            else {
                cout<<temp->key << " "<<temp->count;
            }
            cout<<"\n";
            
        }
        else if (command.find("previous") != string::npos) {
            ss >> leaveIt >> theID;
            //            cout<<"previous Case\n";
            NODEPTR temp = predecessor(root,theID);
            if (temp == NULL) {
                cout<<"0 0\n";
            }
            else {
                cout<<temp->key << " "<<temp->count;
            }
            cout<<"\n";
        }
        else if (command.find("quit") != string::npos) {
            exit(0);
        }
    }
    return 0;


}