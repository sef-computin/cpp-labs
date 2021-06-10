#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


struct node 
{

	node* lkid;
	node* rkid;

	unsigned int val;
};






class btree
{
public:
	btree() { root = NULL; };              
	~btree() { destroy_tree(); };  

	void destroy_tree() {
		destroy_tree(root);
	}

	node* search(int key) 
	{
		return search(key, root);
	}

	void insert(int key) {			
		if (root != NULL)			
			insert(key, root);		
							

		else				
		{
			root = new node;
			root->val = key;
							
			root->lkid = NULL;
			root->rkid = NULL;
		}
	}

private:
	void destroy_tree(node* leaf) 
	{
		if (leaf != NULL)		
		{						
			destroy_tree(leaf->lkid);	
			destroy_tree(leaf->rkid);  	
			leaf = NULL;			
		}
	};


	node* search(int key, node* leaf)	
	{
		if (leaf != NULL)	
		{
			if (key == leaf->val)	
				return leaf;	
			if (key < leaf->val)
			
				return search(key, leaf->lkid);	
			else							
				return search(key, leaf->rkid);	
		}
		else return NULL;					
	}
	
	void insert(int key, node* leaf)		
	{
		if (key < leaf->val)  			
		{
			if (leaf->lkid != NULL)		
				insert(key, leaf->lkid);
			else						
			{
				leaf->lkid = new node;	
				leaf->lkid->val = key;	
				leaf->lkid->lkid = NULL;
				leaf->lkid->rkid = NULL;
			}
		}
		else if (key >= leaf->val)		
		{
			if (leaf->rkid != NULL)		
				insert(key, leaf->rkid);		
			else		
			{
				leaf->rkid = new node;		
				leaf->rkid->val = key;		
				leaf->rkid->lkid = NULL;  	
				leaf->rkid->rkid = NULL;    
			}
		}
	}

	node* root;				
};

node* root = nullptr;

int main(int argc, char* argv[]) 
{
	clock_t start;
	char* filename_input;
	char* filename_output;
	bool operate = false;
	if (argc < 3) {
		printf("not enough arguments - default filenames would be given\n");
		filename_input = (char*)"input.txt";
		filename_output = (char*)"output.txt";
		operate = true;
	}
	else {
		filename_input = argv[1];
		filename_output = argv[2];
		if ((argc > 3) && (argv[3] == "-t")) { operate = true; }
	}

	btree MainTree;

	printf("Starting timer\n");
	
	
	fstream file;
	file.open(filename_input, ios::in);

	if (!file.fail()) {
		unsigned int key;
		while (file >> key) { MainTree.insert(key); };
	}
	


	
	

	printf("Finding element key ---> ");
	node* element;
	unsigned int key;
	std::cin >> key;
	start = clock();
	element = MainTree.search(key);
	if (element == nullptr) { printf("not found\n"); }
	else printf("%d found\n", element->val);




	MainTree.destroy_tree();
	printf("Tree Destroyed\n");
	printf("Elapsed time : %f seconds", (float)(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}


