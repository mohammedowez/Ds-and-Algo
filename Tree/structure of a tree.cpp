// { Driver Code Starts
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;

struct Node 
{
    int data;
    Node* right,* left; 
    Node(int x)
	{
        data = x;
        right=left = NULL;
        // NULL;
    }
};

bool search(Node* root, int x);
void inorder( Node *root) 
{
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->data << " -> ";

    // Traverse right
    inorder(root->right);
  }
}
Node *insert(Node *tree, int val)
{
    Node *temp = NULL;
    if (tree == NULL)
        return new Node(val);

    if (val < tree->data)
    {
        tree->left = insert(tree->left, val);
    }
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }
    
    return tree;
}

int main()
{
	fast;
    int T;
    cin>>T;
    while(T--)
    {
        Node *root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            root = insert(root, k);

        }

        int s;
        cin>>s;
        
     cout<<search(root,s);
      cout << "Inorder traversal: ";
  inorder(root);
     cout<<endl;
    }
}

// } Driver Code Ends





//Function to search a node in BST.
bool search(Node* root, int x)
{
    //Your code here
    if(root==NULL)
        return 0;
    else if(root->data==x)
    {
        return 1;
    }
    else if(root->data < x)
    {
        return search(root->right,x);
    } 
    else if(root->data > x)
    {
        return search(root->left,x);
    }
}

/* Binary tree - Level Order Traversal */
#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	char data;
	Node *left;
	Node *right;
};

// Function to print Nodes in a binary tree in Level order
void LevelOrder(Node *root) 
{
	if(root == NULL) 
			return;
	queue<Node*> Q;
		Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) 
	{
		Node* current = Q.front();
				Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		
		if(current->left != NULL) 
			Q.push(current->left);
		if(current->right != NULL) 	
			Q.push(current->right);
	}
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) 
{
	if(root == NULL) 
	{
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) 
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return 
		root;
}

int main() 
{
	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
		   /
		  y
			
    */
	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	root = Insert(root,'D');
	//Print Nodes in Level Order. 
	LevelOrder(root);
	
	
}
