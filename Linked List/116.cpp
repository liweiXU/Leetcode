/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        //初始化队列的同时将第一层节点加入队列中，即根节点
        queue<Node*> Q;
        Q.push(root);
        //外层的while循环迭代的是层数
        while(!Q.empty)
        {
            //记录当前队列的大小
            int size = Q.size();
            //遍历这一层的所有节点
            for(int i = 0; i < size; i++)
            {
                //从队列首部取出元素
                Node* node = Q.front();
                Q.pop();

                //连接
                if(i < size - 1)
                {
                    node->next = Q.front();
                }
                
                //扩展下一层节点
                if(node->left != nullptr)
                {
                    Q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    Q.push(node->right);
                }
            }
        }
        //返回根节点
        return root;
    }
};