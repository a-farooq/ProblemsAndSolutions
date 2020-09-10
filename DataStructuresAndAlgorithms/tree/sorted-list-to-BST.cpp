/****
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [0]
Output: [0]
Example 4:

Input: head = [1,3]
Output: [3,1]
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-10^5 <= Node.val <= 10^5

Approach 1: Recursion
Intuition

The important condition that we have to adhere to in this problem is that we have to create a height balanced binary search tree using the set of nodes given to us in the form of a linked list. The good thing is that the nodes in the linked list are sorted in ascending order.

As we know, a binary search tree is essentially a rooted binary tree with a very special property or relationship amongst its nodes. For a given node of the binary search tree, it's value must be \ge≥ the value of all the nodes in the left subtree and \le≤ the value of all the nodes in the right subtree. Since a binary tree has a recursive substructure, so does a BST i.e. all the subtrees are binary search trees in themselves.

The main idea in this approach and the next is that:

the middle element of the given list would form the root of the binary search tree. All the elements to the left of the middle element would form the left subtree recursively. Similarly, all the elements to the right of the middle element will form the right subtree of the binary search tree. This would ensure the height balance required in the resulting binary search tree.

Algorithm

Since we are given a linked list and not an array, we don't really have access to the elements of the list using indexes. We want to know the middle element of the linked list.
We can use the two pointer approach for finding out the middle element of a linked list. Essentially, we have two pointers called slow_ptr and fast_ptr. The slow_ptr moves one node at a time whereas the fast_ptr moves two nodes at a time. By the time the fast_ptr reaches the end of the linked list, the slow_ptr would have reached the middle element of the linked list. For an even sized list, any of the two middle elements can act as the root of the BST.
Once we have the middle element of the linked list, we disconnect the portion of the list to the left of the middle element. The way we do this is by keeping a prev_ptr as well which points to one node before the slow_ptr i.e. prev_ptr.next = slow_ptr. For disconnecting the left portion we simply do prev_ptr.next = None
We only need to pass the head of the linked list to the function that converts it to a height balances BST. So, we recurse on the left half of the linked list by passing the original head of the list and on the right half by passing slow_ptr.next as the head.
  ****/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> dataList;
public:
    /*
    ListNode* findmid(ListNode* head)
    {
        if(!head || !head->next)
            return head;

        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }*/
    void createDataList(ListNode* head)
    {
        while(head) {
            dataList.push_back(head->val);
            head = head->next;
        }
    }
    TreeNode* createBST(int l, int r)
    {
        TreeNode* root = nullptr;
        if(l<=r) {
            int m = l+(r-l)/2;
            root = new TreeNode(dataList[m]);
            //cout << l<<","<<r<<","<<m<<","<<dataList[m] << endl;

            root->left = createBST(l, m-1);
            root->right = createBST(m+1, r);
        }
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {

        if(!head)
            return nullptr;

        createDataList(head);

        return createBST(0, dataList.size()-1);
        /*
        TreeNode* root = nullptr;

        ListNode* mid = findmid(head);
        ListNode* midnext = nullptr;
        if(mid) {
            midnext = mid->next;
            mid->next = nullptr;
        }

        root = new TreeNode(mid->val);

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(midnext);

        return root;*/
    }
};
