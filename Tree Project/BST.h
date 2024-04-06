struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();

    void Add(int data);
    bool Remove(int data);
    int Maximum() const;
    void InorderTraverse() const;
    Node* Find(int data) const;

private:
    Node* root;

    Node* AddRecursive(Node* node, int data);
    Node* RemoveRecursive(Node* node, int data);
    Node* FindMax(Node* node) const;
    void InorderTraverseRecursive(Node* node) const;
    void DeleteTree(Node* node);
    Node* FindRecursive(Node* node, int data) const;
    Node* FindMin(Node* node) const;
    Node* RemoveNode(Node* node);
};


