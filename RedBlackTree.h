

enum Color {RED, BLACK};

struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;
    
    // Constructor
    Node(int data)
    {
        this->data = data;
        left = right = parent = NULL;
    }
};
//typedef struct tree{
//    struct tree* left;
//    struct tree* right;
//    struct tree* parent;
//    int info;
//    char color;
//}node;


// Class to represent Red-Black Tree
class RBTree
{
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    void levelOrder();
    void inorderHelper(Node *root);
    Node* BSTInsert(Node* root, Node *pt);
    void levelOrderHelper(Node *root);

    void del_fixup(Node* &root , Node* x , Node* &neel);
    void del(Node* &root , Node* &z , Node* &neel);
    void transplant(Node* &root , Node* &u , Node* &v , Node* neel);
    Node* find_min(Node* &root , Node* neel);

    
};