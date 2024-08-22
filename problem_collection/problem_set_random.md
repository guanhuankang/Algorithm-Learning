`greedy`
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, n=0;
        map<char, int> m;
        while (j<s.length()) {
            char c = s[j];
            if (m.count(c)) {
                while (m[c]>0) {
                    m[s[i++]] -= 1;
                }
            }
            m[c] = 1;
            n = max(n, j-i+1);
            j++;
        }
        return n;
    }
};
```

https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1356443198/

```c++
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
class Solution {
public:
    bool probeNextSequeue(ListNode* head, int k) {
        int cnt = 0;
        while (cnt < k && head!=nullptr) {
            cnt += 1;
            head = head->next;
        }
        return cnt>=k;
    }

    pair<ListNode*, ListNode*> reverseSequeue(ListNode* head, int k) {
        ListNode *s=nullptr, *e=head, *nxt=nullptr;

        for(;k>0;k--){
            nxt = head->next;
            head->next = s;
            s = head;
            head=nxt;
        }
        e->next = nxt;
        return make_pair(s, e);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode H(0, head);
        ListNode* last = &H;

        while (probeNextSequeue(head, k)) {
            pair<ListNode*, ListNode*> p = reverseSequeue(head, k);
            last->next = p.first;
            last = p.second;
            head = p.second->next;
        }
        return H.next;
    }
};
```

https://leetcode.com/problems/reverse-linked-list/description/
```c++
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=nullptr, *cur=head;
        while (cur!=nullptr) {
            head = cur->next;
            cur->next = prev;
            prev = cur;
            cur = head;
        }
        head = prev;
        return head;
    }
};
```

https://leetcode.com/problems/kth-largest-element-in-an-array/description/
```c++
class Solution {
public:
    priority_queue<int> qu;
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(qu.size() < k) {
                qu.push(-nums[i]);
            }else{
                if (-qu.top() < nums[i]) {
                    qu.push(-nums[i]);
                    qu.pop();
                }
            }
        }
        return -qu.top();
    }
};
```

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
```c++
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> cache;
        int level = -1;
        int end = 1;

        queue<pair<int,TreeNode*>> qu;
        if(root!=nullptr) qu.push(make_pair(0, root));

        while(!qu.empty()) {
            pair<int, TreeNode*> p = qu.front();
            qu.pop();
            cout << level << " @ " << p.second->val << endl;
            if (p.first > level) {
                if (level & 1) reverse(cache.begin(), cache.end());
                if (cache.size()>0) ans.push_back(cache);
                cache.clear();
                level = p.first;
            }
            cache.push_back(p.second->val);
            if(p.second->left!=nullptr) qu.push(make_pair(level+1, p.second->left));
            if(p.second->right!=nullptr) qu.push(make_pair(level+1, p.second->right));

            if(qu.empty() && end) {
                // used to flush the last level
                qu.push(make_pair(level+1, p.second));
                end = 0;
            }
        }

        return ans;
    }
};
```

https://leetcode.com/problems/3sum/
```c++
class Solution {
public:
    vector<int> s;
    int bisearch(int l, int r, int val) {
        if (l>r || s[r]<val || s[l]>val) {
            return -1;
        }
        while(l<r){
            int t = (l+r)/2;
            if (s[t] < val)
                l = t + 1;
            else if (s[t] > val)
                r = t - 1;
            else{
                l = t;
                r = t;
            }

        }
        return s[l]==val?l:-1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        s.clear();
        for(int i=0;i<nums.size();i++) s.push_back(nums[i]);
        sort(s.begin(), s.end());

        for(int a=0;a<s.size();){
            for(int b=a+1;b<s.size();){
                int c = bisearch(b+1, s.size()-1, -s[a]-s[b]);
                if (c>=0) {
                    vector<int> tri = {s[a], s[b], s[c]};
                    ans.push_back(tri);
                }
                b++;
                while(b<s.size() && s[b]==s[b-1]) b++;
            }
            a++;
            while(a<s.size() && s[a]==s[a-1]) a++;
        }
        return ans;
    }
};
```

https://leetcode.com/problems/intersection-of-two-linked-lists/description/
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A=headA, *B=headB;
        
        int a=1,b=1;
        while(A->next!=NULL) {A=A->next;a++;}
        while(B->next!=NULL) {B=B->next;b++;}

        if(A!=B) {
            return NULL;
        }

        A = headA;
        B = headB;
        while(a>b){
            A = A->next;
            a--;
        }
        while(a<b){
            B = B->next;
            b--;
        }
        while(A!=B && A!=NULL){
            A = A->next;
            B = B->next;
        }
        return A;
    }
};
```

https://leetcode.com/problems/lru-cache/
```c++
class LRUCache {
public:
    map<int,int> data;
    queue<int> qu;
    map<int,int> inqueue;

    int capacity, count;

    LRUCache(int capacity) {
        data.clear();
        while(!qu.empty()) {
            qu.pop();
        }
        inqueue.clear();
        this->capacity = capacity;
        this->count = 0;
    }
    
    int get(int key) {
        if (data.count(key)) {
            qu.push(key);
            inqueue[key] += 1;
            return data[key];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        this->count += data.count(key)? 0:1;
        qu.push(key);
        inqueue[key] = inqueue.count(key)? inqueue[key]+1:1;
        data[key] = value;

        while (this->count > this->capacity) {
            int e = qu.front();
            qu.pop();
            if (inqueue[e]==1) {
                data.erase(e);
                inqueue.erase(e);
                this->count -= 1;
            } else {
                inqueue[e] -= 1;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, mincost=10001,n=prices.size();
        for(int i=0;i<n;i++){
            mincost = min(mincost, prices[i]);
            profit = max(profit, prices[i]-mincost);
        }
        return profit;
    }
};
```

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode *ans;  
    TreeNode* dfs (TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL) return NULL;
        if (root==p || root==q) {
            if (ans != NULL) {
                return ans;
            } else {
                ans = root;
            }
        }
        
        TreeNode* tmp = ans;
        TreeNode* L = dfs(root->left, p, q);
        if (L != NULL) return L;
        if (tmp==NULL && ans!=NULL) ans=root;

        TreeNode* R = dfs(root->right, p, q);
        if (R != NULL) return R;
        return NULL;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        return dfs(root, p, q);
    }
};
```

https://leetcode.com/problems/maximum-subarray/
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp=0, ans=-1e9-7;
        for(int i=0;i<nums.size();i++){
            dp = max(dp+nums[i], nums[i]);
            ans = max(ans, dp);
        }
        return ans;
    }
};
```

https://leetcode.com/problems/add-strings/
```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<char> ans;
        int n=num1.length(), m=num2.length(), c=0;
        for(int i=n-1,j=m-1;i>=0 || j>=0;i--,j--){
            int s = (i>=0? num1.at(i)-'0':0) + (j>=0? num2.at(j)-'0':0) + c;
            c = s>=10? 1: 0;
            s = c&1? s-10:s;
            ans.push_back(s+'0');
        }
        if (c>0) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return string(ans.begin(), ans.end());
    }
};
```

https://leetcode.com/problems/merge-two-sorted-lists/
```c++
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL) {
            return list2;
        }
        if (list2==NULL) {
            return list1;
        }
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
```

https://leetcode.com/problems/trapping-rain-water/description/
```c++
class Solution {
    int st;
public:
    int trap(vector<int>& height) {
        long long cap = 0, tmp = 0;
        
        st = 0;
        for(int i=0;i<height.size();i++){
            if(height[i]>=st){
                cap += tmp;
                tmp = 0;
                st = height[i];
            }else{
                tmp += st - height[i];
            }
        }
        tmp = 0;
        int lst = st;
        st = 0;
        for(int i=height.size()-1;i>=0;i--){
            if(height[i]>=st){
                cap += tmp;
                tmp = 0;
                st = height[i];
                if(st==lst)break;
            }else{
                tmp += st - height[i];
            }
        }
        return cap;
    }
};
```

https://leetcode.com/problems/binary-tree-right-side-view/description/
```c++
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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> qu;
        if (root) qu.push(root);

        while (qu.size() > 0) {
            ans.push_back(qu.front()->val);

            int n = qu.size();
            while (n--) {
                TreeNode *t = qu.front();
                qu.pop();
                if (t->right) qu.push(t->right);
                if (t->left)  qu.push(t->left);
            }
        }

        return ans;
    }
};
```

