#include "binary_tree.h"

#include <stdio.h>

#define min(a, b) (a <= b ? a : b)
#define max(a, b) (a > b ? a : b)

#define MON_INT_MIN -2147483647
#define MON_MAX_INT 2147483647

///////////////////////////////////////////////////////////////////////////////////////////SIZE/////////////////////////////////////////////////////////////////////////////////////////////////

int size(const struct binary_tree *tree)
{
    if (tree != NULL)
        return 1 + size(tree->left) + size(tree->right);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////HEIGHT///////////////////////////////////////////////////////////////////////////////////////////////

int height(const struct binary_tree *tree)
{
    if (tree == NULL)
        return -1;
    return 1 + max(height(tree->left), height(tree->right));
}

///////////////////////////////////////////////////////////////////////////////////////////PRINT////////////////////////////////////////////////////////////////////////////////////////////////

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        dfs_print_prefix(tree->left);
        dfs_print_prefix(tree->right);
    }
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        dfs_print_infix(tree->left);
        printf("%d ", tree->data);
        dfs_print_infix(tree->right);
    }
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        dfs_print_postfix(tree->left);
        dfs_print_postfix(tree->right);
        printf("%d ", tree->data);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////PERFECT////////////////////////////////////////////////////////////////////////////////////////////////

int is_perfect(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        if (tree->left != NULL && tree->right != NULL)
            return min(min(1, is_perfect(tree->left)),
                       min(1, is_perfect(tree->right)));
        if (tree->left == NULL && tree->right == NULL)
            return 1;
        return 0;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////COMPLETE///////////////////////////////////////////////////////////////////////////////////////////////

static int is_complete_rec(const struct binary_tree *tree, int i, int size)
{
    if (tree == NULL)
        return 1;
    if (i >= size)
        return 0;

    return min(min(1, is_complete_rec(tree->left, 2 * i + 1, size)),
               min(1, is_complete_rec(tree->right, 2 * i + 2, size)));
}

int is_complete(const struct binary_tree *tree)
{
    return is_complete_rec(tree, 0, size(tree));
}

/////////////////////////////////////////////////////////////////////////////////////////DEGENERATE/////////////////////////////////////////////////////////////////////////////////////////////

int is_degenerate(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;

    if (tree->left == NULL && tree->right == NULL)
        return 1;
    if ((tree->left == NULL && tree->right != NULL)
        || (tree->left != NULL && tree->right == NULL))
        return is_degenerate(tree->left) && is_degenerate(tree->right);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////FULL////////////////////////////////////////////////////////////////////////////////////////////////

int is_full(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    if (tree->right != NULL && tree->left != NULL)
        return is_full(tree->left) && is_full(tree->right);
    if (tree->right == NULL && tree->left == NULL)
        return 1;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////BST/////////////////////////////////////////////////////////////////////////////////////////////////

static int is_bst_rec(const struct binary_tree *tree, int mon_min, int mon_max)
{
    if (tree == NULL)
        return 1;

    if (tree->data <= mon_min || tree->data > mon_max)
        return 0;

    return is_bst_rec(tree->left, mon_min, tree->data - 1)
        && is_bst_rec(tree->right, tree->data, mon_max);
}

int is_bst(const struct binary_tree *tree)
{
    return is_bst_rec(tree, MON_INT_MIN, MON_MAX_INT);
}

////////////////////////////////////////////////////////////////////////////////////////////END/////////////////////////////////////////////////////////////////////////////////////////////////
