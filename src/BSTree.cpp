#include "BSTree.h"

BSTree::BSTree()
{
    root = nullptr;
}

void BSTree::Insert(const int& value)
{
	if (root == nullptr)
    {
		root = new BSNode;
		root->data = value;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
		insertTree(root, value);
}

bool BSTree::Search(const int& value)
{
	BSNode* tmp;
	if ((tmp = searchTree(root, value)) != nullptr)
		return true;
	return false;
}
void BSTree::DeleteElement(const int& value) {
	deleteElementTree(root, value);
}


void BSTree::printPre() {
	preorderTraversal(root);
}

void BSTree::printIn() {
	inorderTraversal(root);
}

void BSTree::printPost() {
	postorderTraversal(root);
}

////////////////////////////////////////////////////////////
// Funciones auxiliares para la implementación de la clase //
/////////////////////////////////////////////////////////////
BSNode* BSTree::insertTree(BSNode* actual, const int& value)
{
	// Si llegamos al final de una rama del árbol sin encontrar el valor, entonces creamos un nodo
	// y lo insertamos en el árbol
	if (actual == nullptr) {
		actual = new BSNode;
		actual->data = value;
		actual->left = nullptr;
		actual->right = nullptr;
	}
	else {  // Si el nodo actual no es NULL, preguntamos si debemos buscar a la izquierda (valor es menor)
		if (actual->data > value)
			actual->left = insertTree(actual->left, value);
		else if (actual->data < value)  // Si el valor no es menor, buscamos por la derecha
			actual->right = insertTree(actual->right, value);
	}
	return actual;
}

BSNode* BSTree::searchTree(BSNode* actual, const int& value) {
	// Si el nodo actual es nullptr, o apunta al valor que buscamos, retornamos la referencia del puntero
	if (actual == nullptr || actual->data == value)
		return actual;
	else if (actual->data > value)  // Si el valor que estamos buscando es menor, buscamos en la rama izquierda
		return searchTree(actual->left, value);
	else
		return searchTree(actual->right, value);   // Buscamos en la rama derecha si el valor es mayor que el nodo actual
}

// Función auxiliar para realizar el recorrido en Pre Orden
void BSTree::preorderTraversal(BSNode* actual) {
	if (actual != nullptr) {
		std::cout << actual->data;
		std::cout << " ";
		preorderTraversal(actual->left);
		preorderTraversal(actual->right);
	}
}

// Función auxiliar para realizar el recorrido En Orden
void BSTree::inorderTraversal(BSNode* actual) {
	if (actual != nullptr) {
		inorderTraversal(actual->left);
		std::cout << actual->data;
		std::cout << " ";
		inorderTraversal(actual->right);
	}
}

// Función auxiliar para realizar el recorrido Pos Orden
void BSTree::postorderTraversal(BSNode* actual) {
	if (actual != nullptr) {
		postorderTraversal(actual->left);
		postorderTraversal(actual->right);
		std::cout << actual->data;
		std::cout << " ";
	}
}




void BSTree::deleteElementTree(BSNode*, const int&) {

}


BSTree::~BSTree()
{
    //dtor
}
