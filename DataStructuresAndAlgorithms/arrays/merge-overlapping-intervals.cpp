/****
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Example 1:

Input:
N = 4
Intervals = {(1,3),(2,4),(6,8),(9,10)}
Output: 1 4 6 8 9 10
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].
Example 2:

Input:
N = 4
Intervals = {(6,8),(1,9),(2,4),(4,7)}
Output: 1 9
Your Task:
Complete the function overlappedInterval() that takes the list of pairs and N as input parameters and returns sorted list of pairs of intervals after merging.

Expected Time Complexity: O(N*Log(N) ).
Expected Auxiliary Space: O(1).
  ****/

//User function template for C++

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n)
{
    //code here
	sort(vec.begin(), vec.end(), [](pair<int,int>&p1, pair<int,int>&p2){
       return p1.first<p2.first;
    });
    /*
    //with extra space
    vector<pair<int,int>> res;
    res.push_back(vec[0]);

    for(auto i=1; i<vec.size(); i++) {
        pair<int,int>&p1 = res.back();
        pair<int,int> p2 = vec[i];
        if(p2.first <= p1.second) {
            p1.second = max(p1.second, p2.second);
        }
        else {
            res.push_back(p2);
        }
    }
    return res;
    */
    int i=0;
    int j=1;
    for(; j<vec.size(); j++) {
        pair<int,int>&p1 = vec[i];
        pair<int,int> p2 = vec[j];

		//merging with previous pair
        if(p2.first <= p1.second) {
            p1.second = max(p1.second, p2.second);
        }
		//updating next pair
        else {
            i++;
            vec[i].first = vec[j].first;
            vec[i].second = vec[j].second;
        }
    }
	//removing reduntant pairs from back
    /*
	j--;
    while(j>i) {
        vec.pop_back();
        j--;
    }
	*/
	vec.erase(vec.begin()+i+1, vec.end());
    return vec;
}
