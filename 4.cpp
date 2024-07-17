#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null ";
            }
        }
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;
        stringstream ss(data);
        string item;
        getline(ss, item, ' ');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!getline(ss, item, ' ')) break;
            if (item != "null") {
                node->left = new TreeNode(stoi(item));
                q.push(node->left);
            }
            if (!getline(ss, item, ' ')) break;
            if (item != "null") {
                node->right = new TreeNode(stoi(item));
                q.push(node->right);
            }
        }
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    Codec codec;
    string serializedTree = codec.serialize(root);
    cout << "Serialized tree: " << serializedTree << endl;
    
    TreeNode* deserializedRoot = codec.deserialize(serializedTree);
    cout << "Deserialized tree: ";
    printTree(deserializedRoot);
    
    return 0;
}
