#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}


int findMin(Node* root){
    if(root == nullptr){
        cout<<"Tree is empty\n";
    }
    while(root && root->left != NULL){
        root = root->left;
    }
    return root->data;
}


int findMax(Node* root){
    if(root == NULL) {
        cout<<"Tree is empty\n";
        return -1;
    }  

    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}


Node* deleteNode(Node* root, int value){
    if(root == nullptr){
        return root;
    }

    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }else{

        //case 1 && 2: only one node and zero child node
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //case 3: when Node have two child node
        Node* temp;
        int x=findMin(root->right);
        temp->data=x;
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);

    }
    return root;
}


void searchNode(Node* root,  int key){
    if(root == nullptr){
        cout<<key<<" node does not found in the tree\n";
        return;
        
    }

    if(root->data == key){
        cout<<key<<" node found in the tree\n";
        return;
        
    }else if(key < root->data){
        searchNode(root->left, key);
    }else{
        searchNode(root->right, key);
    }

}


int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    return 1 + max(left ,right);
}



// Traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preOrder(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main() {
    Node* root = NULL;
    int n, value,key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal of BST: ";
    inorder(root);

    cout << "Total Nodes: " << countNodes(root) << endl;
    cout << "Height of Tree: " << heightOfTree(root) << endl;
    cout << "Minimum Value: " << findMin(root) << endl;
    cout << "Maximum Value: " << findMax(root) << endl;

    // cout<<"\nenter node which you want to delete: ";
    // cin>>value;
    // root=deleteNode(root,value);
    // inorder(root);

    cout<<"\nEnter node for search: ";
    cin>>key;
    searchNode(root, key);

    return 0;
}
