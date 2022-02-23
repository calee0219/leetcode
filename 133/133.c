#include <stdlib.h>
#include <string.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node * DFS(struct Node * curr, struct Node ** visited) {
    if (visited[curr->val] != NULL) {
        return visited[curr->val];
    }
    // clone itself
    struct Node * tmp = malloc(sizeof(struct Node));
    tmp->val = curr->val;
    tmp->numNeighbors = curr->numNeighbors;
    tmp->neighbors = malloc(tmp->numNeighbors * sizeof(struct Node *));
    visited[curr->val] = tmp;
    // traverse
    int idx;
    for (idx = 0; idx < curr->numNeighbors; ++idx) {
        tmp->neighbors[idx] = DFS(curr->neighbors[idx], visited);
    }
    return tmp;
}

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) {
        return NULL;
    }
	struct Node * curr = s;

    struct Node * visited[101] = {0};
    memset(visited, 0, sizeof(visited));
    // DFS
    return DFS(curr, visited);
}
