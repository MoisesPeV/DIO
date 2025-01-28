#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Função para obter a altura de um nó
int height(Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

// Função para obter o fator de balanceamento de um nó
int get_balance(Node *n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

// Função para criar um novo nó
Node *create_node(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Inicialmente, altura é 1
    return node;
}

// Função para rotacionar à direita
Node *rotate_right(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x; // Nova raiz
}

// Função para rotacionar à esquerda
Node *rotate_left(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y; // Nova raiz
}

// Função para inserir um nó na árvore AVL
Node *insert(Node *node, int key) {
    // Passo 1: Inserção normal na árvore de busca binária
    if (node == NULL) return create_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Valores duplicados não são permitidos
        return node;

    // Passo 2: Atualiza a altura do nó pai
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Passo 3: Verifica o fator de balanceamento
    int balance = get_balance(node);

    // Caso 1: Desbalanceado à esquerda (Rotação à direita)
    if (balance > 1 && key < node->left->key)
        return rotate_right(node);

    // Caso 2: Desbalanceado à direita (Rotação à esquerda)
    if (balance < -1 && key > node->right->key)
        return rotate_left(node);

    // Caso 3: Esquerda-Direita (Rotação dupla: esquerda + direita)
    if (balance > 1 && key > node->left->key) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Caso 4: Direita-Esquerda (Rotação dupla: direita + esquerda)
    if (balance < -1 && key < node->right->key) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node; // Retorna o nó (sem alteração caso já balanceado)
}

// Função para encontrar o menor valor (sucessor)
Node *min_value_node(Node *node) {
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Função para remover um nó da árvore AVL
Node *delete_node(Node *root, int key) {
    // Passo 1: Remoção normal na árvore de busca binária
    if (root == NULL) return root;

    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else {
        // Nó com apenas um filho ou nenhum filho
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            // Sem filhos
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // Um filho
                *root = *temp;

            free(temp);
        } else {
            // Nó com dois filhos: Obtém o sucessor
            Node *temp = min_value_node(root->right);

            // Copia o valor do sucessor
            root->key = temp->key;

            // Remove o sucessor
            root->right = delete_node(root->right, temp->key);
        }
    }

    if (root == NULL) return root;

    // Passo 2: Atualiza a altura do nó atual
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // Passo 3: Verifica o fator de balanceamento
    int balance = get_balance(root);

    // Caso 1: Desbalanceado à esquerda
    if (balance > 1 && get_balance(root->left) >= 0)
        return rotate_right(root);

    // Caso 2: Esquerda-Direita
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // Caso 3: Desbalanceado à direita
    if (balance < -1 && get_balance(root->right) <= 0)
        return rotate_left(root);

    // Caso 4: Direita-Esquerda
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

// Função para exibir a árvore (em ordem)
void in_order(Node *root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->key);
        in_order(root->right);
    }
}

// Função principal
int main() {
    Node *root = NULL;

    // Inserindo valores na árvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Árvore AVL em ordem: ");
    in_order(root);
    printf("\n");

    // Removendo um nó
    root = delete_node(root, 20);
    printf("Árvore AVL após remoção: ");
    in_order(root);
    printf("\n");

    return 0;
}
