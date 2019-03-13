class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node(int x);
};
class Tree{
public:
  Node *root;
  Tree(int x);
  Node* insert(Node* subRoot, int x);
  void insert(int x);
  Node* deleteNode(Node *subRoot, int x);
  void deleteNode(int x);
  void inOrderTraverse(Node* subRoot);
  void preOrderTraverse(Node* subRoot);
  void postOrderTraverse(Node* subRoot);
  void inOrderTraverse();
  void preOrderTraverse();
  void postOrderTraverse();
};
