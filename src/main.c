#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void InorderTraversal(struct TreeNode *root)
{
    if (root) {
        InorderTraversal(root->left);
        printf("%d ", root->val);
        InorderTraversal(root->right);
    }
}

void PreorderTraversal(struct TreeNode *root)
{
    if (root) {
        printf("%d ", root->val);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

void PostorderTraversal(struct TreeNode *root)
{
    if (root) {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%d ", root->val);
    }
}

void InOrderTraversal(struct TreeNode *root)
{
    struct TreeNode *stack[101];
    int index = -1;
    while (root || index > -1) {
        while (root) {
            index++;
            stack[index] = root;
            root = root->left;
        }
        if (index > -1) {
            root = stack[index];
            index--;
            printf("%d ", root->val);
            root = root->right;
        }
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int *nums = (int *)malloc(101 * sizeof(int));
    struct TreeNode *stack[101];
    int index = -1;
    struct TreeNode *p = root;
    while (p || index > -1) {
        if (p != NULL) {
            index++;
            stack[index] = p;
            p = p->left;
        } else {
            p = stack[index];
            index--;
            nums[*returnSize] = p->val;
            (*returnSize)++;
            p = p->right;
        }
    }
    return nums;
}

void PostorderTraversal_2(struct TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    struct TreeNode *stack[101];
    int index = -1;
    struct TreeNode *pCur = root;
    struct TreeNode *pLastVisit = NULL;
    while (pCur != NULL) {
        index++;
        stack[index] = pCur;
        pCur = pCur->left;
    }
    while (index > -1) {
        pCur = stack[index];
        index--;
        if (pCur->right == NULL || pCur->right == pLastVisit) {
            printf("%d ", pCur->val);
            pLastVisit = pCur;
        } else {
            index++;
            stack[index] = pCur;
            pCur = pCur->right;
            while (pCur != NULL)
            {
                index++;
                stack[index] = pCur;
                pCur = pCur->left;
            }
        }
    }
}

struct TreeNode *Find(int x, struct TreeNode *root)
{
    if (root == NULL) {
        return NULL;
    }
    if (x > root->val) {
        return Find(x, root->right);
    } else if (x < root->val) {
        return Find(x, root->left);
    } else {
        return root;
    }
}

struct TreeNode *FindNo(int x, struct TreeNode *root)
{
    while (root != NULL) {
        if (x > root->val) {
            root = root->right;
        } else if (x < root->val) {
            root = root->left;
        } else {
            return root;
        }
    }
    return NULL;
}

struct TreeNode *FindMin(struct TreeNode *root)
{
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    }
    return FindMin(root->left);
    
}

struct TreeNode *FindMax(struct TreeNode *root)
{
    if (root == NULL) {
        return NULL;0
    } 
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct TreeNode *Delete(int x, struct TreeNode *root)
{
    struct TreeNode *tmp = root;
    if (root == NULL) {
        /* error */
    }
    else if (x < root->val) {
        root->left = Delete(x, root->left);
    } else if (x > root->val) { 
        root->right = Delete(root->right);
    } else if (root->left != NULL && root->right != NULL) {

        tmp = FindMin(root->right);
        root->val = tmp->val;
        root->right = Delete(root->val, root->right);
    } else {
        tmp = root;
        if (root->left == NULL) {
            root = root->right;
        } else if (root->right == NULL) {
            root = root->left;
        }
        free(tmp);
    }
    return root;
}

struct TreeNode *Insert(int x, struct TreeNode *root)
{
    if (root == NULL) {
        root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = x;
        root->left = NULL;
        root->right = NULL;
    } else if (x < root->val) {
        root->left = Insert(x, root->left);
    } else if (x > root->val) {
        root->right = Insert(x, root->right);
    }
    return root;
}