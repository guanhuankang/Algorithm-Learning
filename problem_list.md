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