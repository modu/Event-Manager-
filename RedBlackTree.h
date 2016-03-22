#include <vector>
using namespace std;
#define RED		1
#define BLACK	2

struct Node {
    Node(){}
    Node(int _key , int _count): key(_key), count(_count), left(NULL) , right(NULL), color(BLACK) {
    }
    int key;
    int count;
    struct Node *left, *right, *p;
    int color;
};
struct inputPair {
    int ID;
    int count;
};
typedef struct inputPair * inputPairPTR;
typedef struct Node *NODEPTR;


// Class to represent Red-Black Tree
class RBTree
{
private:
    Node *root;
protected:
    void leftrotate(NODEPTR treeroot, NODEPTR x);
    void rightrotate(NODEPTR treeroot, NODEPTR y);
    void rbinsertfixup(NODEPTR treeroot, NODEPTR z);
    void rbtransplant(NODEPTR treeroot, NODEPTR u, NODEPTR v);
    void rbdeletefixup(NODEPTR treeroot, NODEPTR x);
//    NODEPTR cbst(vector<inputPairPTR> &num, int st, int ed, NODEPTR p );
//    NODEPTR getClosestNode(NODEPTR pRoot, int value);

public:
    // Constructor
    RBTree() { root = NULL; }
    RBTree(NODEPTR _root) { root = _root; }
    void inorder(NODEPTR x);
    NODEPTR search(NODEPTR root, int k);
    NODEPTR minimum(NODEPTR root);
    NODEPTR maximum(NODEPTR root);
    NODEPTR successor(NODEPTR root, int x) ;
    NODEPTR predecessor(NODEPTR root, int x);
    NODEPTR getClosestNode(NODEPTR pRoot, int value);
    NODEPTR sortedArrayToBST(vector<inputPairPTR> &num);
    void makeLeafRed(NODEPTR root);
    
    void rbinsert(NODEPTR treeroot, int z, int _count);
    
    void rbdelete(NODEPTR treeroot, int z);

    
    void Increase(int theID , int m , NODEPTR root );

    void Reduce( NODEPTR root,int theID , int m  );
    
    
    void Count(NODEPTR root , int theID );
    int InRange(NODEPTR root , int low , int high );
    
};