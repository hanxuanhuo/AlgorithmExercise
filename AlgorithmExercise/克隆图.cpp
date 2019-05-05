#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）。
*/

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

map<Node*, Node*> visited;

Node* dfs(Node* node)
{
	
	map<Node*, Node*>::iterator iter;
	iter = visited.find(node);
	if (iter == visited.end())
	{
		Node* copynode = new Node(node->val, node->neighbors);
		visited[node] = copynode;
		cout << node << " has been visited" << endl;
		for (int i = 0; i < copynode->neighbors.size(); i++)
		{
			cout << "now copy id " << node->val << "  neighbor id " << node->neighbors[i]->val << endl;
			copynode->neighbors[i] = dfs(node->neighbors[i]);
			
		}
		cout << "id: " << copynode->val << " neighbor : [" << copynode->neighbors[0]->val << " , " << copynode->neighbors[1]->val << "]" << endl;
		return copynode;
	}
	cout << "id " << node->val << "  visited" << endl;
	return visited[node];

}

Node * cloneGraph(Node* node)
{
	
	//visited[node] = 1;
	Node* ans = dfs(node);

	return ans;
}

void cloneGraph_main()
{
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();
	Node* node4 = new Node();

	node1->val = 1;
	node2->val = 2;
	node3->val = 3;
	node4->val = 4;
	node1->neighbors = { node2, node4 };
	node2->neighbors = { node1, node3 };
	node3->neighbors = { node2, node4 };
	node4->neighbors = { node1, node3 };

	Node* ans = cloneGraph(node1);
	cout << ans->val << endl;
}