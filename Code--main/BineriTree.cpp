#include<iostream>
#include<vector>
struct Node
{
	int data ;
	Node* left;
	Node* right;
	Node(int num)
	{
		this->data = num ;
		this->left = nullptr ;
		this->right = nullptr ;
	}
	~Node()
	{
	delete this->left;
	delete this->right;
	}

};
	void insert(int num,Node* root)
	{
		if(num < root->data && root->left==nullptr)
		{
			root->left = new Node(num);
		}
		else if(num > root->data && root->right==nullptr)
		{
			root->right = new Node(num);
		}
		else if(num > root->data && root->right!=nullptr)
		{
			insert(num,root->right);
		}
		else if(num < root->data && root->left!=nullptr)
		{
			insert(num,root->left);
		}
	}
	void inorder(Node* root)
	{
		if(!root){return;}
		inorder(root->left);
		std::cout<< root->data <<std::endl;
		inorder(root->right);
	}
	void postorder(Node* root)
	{
		if(!root){return;}
		postorder(root->left);
		postorder(root->right);
		std::cout<< root->data <<std::endl;
	}
	void preorder(Node* root)
	{
		if(!root){return;}
		std::cout<< root->data <<std::endl;
		preorder(root->left);
		preorder(root->right);
	}	
	void Leval_print(Node* root,std::vector<int>& vec)
	{
		if(!root){return;}
		if(root->left!=nullptr){vec.push_back(root->left->data);}
		if(root->right!=nullptr){vec.push_back(root->right->data);}
		Leval_print(root->left,vec);
		Leval_print(root->right,vec);
	
	}
	void LevalPrint(Node* root)
	{
	
		std::vector<int>vec;
		vec.push_back(root->data);
		Leval_print(root,vec);
		for(int i=0;i<vec.size();++i)
		{
			std::cout<<vec[i]<<std::endl;
		}
	}
int main()
{
	Node tmp(50);
	insert(40,&tmp);
	insert(30,&tmp);
	insert(45,&tmp);
	insert(60,&tmp);
	inorder(&tmp);
	std::cout<<"****"<<std::endl;
	postorder(&tmp);
	std::cout<<"****"<<std::endl;
	preorder(&tmp);
	std::cout<<"****"<<std::endl;
	LevalPrint(&tmp);
//	std::cout<<tmp.data << tmp.left->data <<tmp.left->left->data<<tmp.left->right->data <<tmp.right->data << std::endl;
	return 0;
}
