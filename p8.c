#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *lchild, *rchild;
} node;

void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int);

node *get_node()
{
    node *temp = (node *)malloc(sizeof(node));
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void insert(node *root, node *new_node)
{
    if (new_node->data < root->data)
    {
        if (root->lchild == NULL)
            root->lchild = new_node;
        else
            insert(root->lchild, new_node);
    }
    else if (new_node->data > root->data)
    {
        if (root->rchild == NULL)
            root->rchild = new_node;
        else
            insert(root->rchild, new_node);
    }
}

node *search(node *root, int key)
{
    node *temp = root;
    if (root == NULL)
        return NULL;
    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;
        temp = key < temp->data ? temp->lchild : temp->rchild;
    }
    return NULL;
}

void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->lchild);
        printf("%d, ", temp->data);
        inorder(temp->rchild);
    }
}

void preorder(node *temp)
{
    if (temp != NULL)
    {
        printf("%d, ", temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}

void postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d, ", temp->data);
    }
}

int main()
{
    int choice, n, i, key;
    node *new_node, *root = NULL, *tmp;

    do
    {
        printf("\n1.Create\n2.Recursive Traversals\n3.Search\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nHow many nodes you want to enter: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                new_node = get_node();
                scanf("%d", &new_node->data);
                if (root == NULL)
                    root = new_node;
                else
                    insert(root, new_node);
            }
            break;
        case 2:
            if (root == NULL)
                printf("Tree Is Not Created\n");
            else
            {
                printf("Inorder: ");
                inorder(root);
                printf("\nPreorder: ");
                preorder(root);
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
            }
            break;
        case 3:
            printf("Enter Element to be searched: ");
            scanf("%d", &key);
            tmp = search(root, key);
            if (tmp)
                printf("The %d Element is Present\n", tmp->data);
            else
                printf("The Key %d is not present in the BST\n", key);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
