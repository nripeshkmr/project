#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node*left;
	node*right;
};

node* new_node(int data)
{
	node* Node = new node;
	
	Node->data = data;
	Node->right=NULL;
	Node->left=NULL;
	
	return Node;
}

void Preorder(node*root)
{
	if(root==NULL)
	return;
	
	cout<<" "<<root->data;
	Preorder(root->left);
	Preorder(root->right);
}

node*convert(int arr[],int start,int end)
{
	if(start>end)
	return NULL;
	
	int mid = (start+end)/2;
	
	node*NNode = new_node(arr[mid]);
	
	NNode->left = convert(arr,start,mid-1);
	NNode->right = convert(arr,mid+1,end);
	
	return NNode;
}

int main()
{
	int arr[]={1,2,3,4,5,7};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	node*root = convert(arr,0,n-1);
	
	cout<<"\nPreorder traversal:";
	Preorder(root);
	
}
	

