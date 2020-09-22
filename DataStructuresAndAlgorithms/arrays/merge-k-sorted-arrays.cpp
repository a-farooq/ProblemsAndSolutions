/****
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].
Example 2:

Input:
K = 4
arr[][]={{1,2,3,4}{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6]  [7, 8, 9, 9 ]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
6, 6, 7, 8, 9, 9 ].
Your Task:
You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList<Integer> in java, and list in python)

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Note: This space is required for returning the resulted sorted array, other work should be done in O(K) Auxiliary Space.

Constraints:
1 <= K <= 100

Algorithm:

An efficient solution is to use heap data structure. The time complexity of heap based solution is O(N Log k).

1. Create an output array.
2. Create a min heap of size k and insert 1st element in all the arrays into the heap
3. Repeat following steps while priority queue is not empty.
…..a) Remove minimum element from heap (minimum is always at root) and store it in output array.
…..b) Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.


  ****/

struct element
{
    int val, row, col;
    element(int a, int b, int c) : val(a), row(b), col(c)
    {}
};
struct cmp
{
    int operator()(element& s1, element& s2)
    {
        return s1.val > s2.val;
    }
};
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
int *mergeKArrays(int arr[][N], int k)
{
//code here
    int *a = new int[k*k];
    int ptr=0;
    priority_queue<element, vector<element>, cmp> pqmin;

    //push first element of each array into minhep
    for(int i=0; i<k; i++) {
        element elem(arr[i][0], i, 0);
        pqmin.push(elem);
    }

    //add the top of heap to out array and insert next (of same array as top)
    //into heap
    while(!pqmin.empty()) {
        element e_min = pqmin.top();
        pqmin.pop();

        a[ptr++] = e_min.val;

        int row = e_min.row;
        int col = e_min.col;
        if(col < k-1) {
            element elem(arr[row][col+1], row, col+1);
            pqmin.push(elem);
        }
    }

    return a;
}
