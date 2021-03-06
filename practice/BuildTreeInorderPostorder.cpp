#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int postindex = 0;
    
int getindex(vector<int> &in, int rootdata) {
	for( int i = 0 ; i < in.size() ; i++ ) {
            if( in[i] == rootdata ) {
                return i;
            }
        }
        return -1;
}

void build(TreeNode ** root, vector<int> &in, int start, int end, vector<int> &post) {
        
        if( start > end || postindex < 0) {
			*root = NULL;
            return;
        }

        int rootdata = post[postindex--];
        
        (*root) = new TreeNode(rootdata);
        int mid = getindex(in,rootdata);

		cout << "root = " << rootdata << endl;
		cout << "start = " << start << " and end = " << end << " and mid = " << mid << endl;
        
        build(&((*root)->left), in, start, mid-1, post);
        build(&((*root)->right), in, mid+1, end, post);
        
}

void _build( TreeNode ** root, vector<int> &in, vector<int> &post ) {
        postindex = post.size()-1;
        build(root,in,0,in.size()-1,post);
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
       
       if( inorder.size() == 0 || postorder.size() == 0 ) {
           return NULL;
       }
       
       TreeNode * root;
       _build(&root, inorder,postorder);
       return root;
}

void preorder(TreeNode * root) {
	if( root == NULL ) {
		return;
	}

	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

int main() {

	//int array1[] = {-4,-10,3,-1,7,11,-8,2};
	//int array2[] = {-4,-1,3,-10,11,-8,2,7};
	
	int array1[] = {2,1,3};
	int array2[] = {2,3,1};
	
	int n = sizeof(array1) / sizeof(array1[0]);

	vector<int> inorder;
	vector<int> postorder;

	for( int i = 0 ; i < n ; i++ ) {
		inorder.push_back(array1[i]);
		postorder.push_back(array2[i]);
	}

	TreeNode * root = buildTree(inorder,postorder);
	preorder(root);
	cout << endl;

	return 0;

}
