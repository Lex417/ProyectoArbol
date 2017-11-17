#include "BSTree.h"

using namespace std;

void busqueda(BSTree&, int);

int main()
{
	BSTree t;
	t.Insert(7);
	t.Insert(4);
	t.Insert(1);
	t.Insert(2);
	t.Insert(19);
	t.Insert(32);

	busqueda(t, 4);
	busqueda(t, 9);

	std::cout << "\nRecorrido Pre-Orden: ";
	t.printPre();
	std::cout << std::endl << std::endl;

	std::cout << "Recorrido En-Orden: ";
	t.printIn();
	std::cout << std::endl << std::endl;

	std::cout << "Recorrido Pos-Orden: ";
	t.printPost();
	std::cout << std::endl << std::endl;


	return 0;
}

void busqueda(BSTree& tree, int n) {
	bool flag;

	std::cout << "Buscando el numero " << n << "... ";

	flag = tree.Search(n);
	if (flag)
		std::cout << "ENCONTRADO";
	else
		std::cout << "NO ESTA EL NUMERO";
	std::cout << std::endl;
}
