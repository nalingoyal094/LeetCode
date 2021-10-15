/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/




//                        root= 1
//   right subtree       =             (3)
//                                     5,7
//                                     4,6
//                                 (6)       (7)
//                                 5,5       7,7
//                                 4,4       5,5
//                             (null) (null) (null)   (null)
//                               5,4   6,5   7,6      8,7                                             


// left subtree =  (2)
//                 0,3
//                 0,3
//            (4)             (5)
//            0,1             3,3
//            0,1             2,2
//        (NULL)  (8)   (null)  (null)
//         0,-1   1,1    3,2     4,3
//         0,-1   0,0
//            (null)   (null)
//             1,0    2,1         
            













TreeNode*solve(vector<int> &A, int is, int ie, vector<int>&B, int ps, int pe,unordered_map<int , int>& mp )
{

    if (ie<is || pe<ps)
    {
        return NULL;

    }
   // cout<<is<<" "<<ie<<" "<<ps<<" "<<pe<< endl;
    TreeNode*temp=new TreeNode(B[pe]);
    int pivot=mp[B[pe]];
    
    temp->left=solve(A,is, pivot-1, B, ps,ps+pivot-1-is,mp);
    temp->right=solve(A,pivot+1,ie,B, ps+pivot-is, pe-1, mp);
    return temp;

}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    if (A.size()!=B.size()) return NULL;
        
      int  n=A.size();

    int ind=n-1;


    unordered_map<int , int>mp;
    int indd=0;
    for (auto i:A)
    {
        mp[i]=indd;
        indd++;
    }

        int is=0;
        int ie=n-1;
        int ps=0;
        int pe=n-1;
        
    return solve(A,is,ie,B,ps,pe,mp);
  
    }


