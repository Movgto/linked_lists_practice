#include <iostream>
#include <string>
#include <conio.h>

using namespace std;



struct Nodo {
	int id;
	string username;

	Nodo* sig;
};

Nodo* agregar(Nodo* inicio, string username);
void mostrarLista(Nodo* inicio);

int main() {
	Nodo* inicio = nullptr;
	Nodo* aux = nullptr;
	int num = 1;

	while (num != 0) {
		int op;
		cout << "-----Menu-----\n\t1. Agregar\n\t2.Mostrar lista\n";
		cin >> op;
		switch (op) {
		case 1: {
			cout << "Ingrese nombre de usuario : \n";
			string usr;
			cin.ignore();
			getline(cin, usr);
			inicio = agregar(inicio, usr);
			break; 
		}
			case 2:
				mostrarLista(inicio);
				break;
			default:
				cout << "Opcion invalida, presione una tecla para continuar...\n";
				_getch();
				break;
		}
	}

	mostrarLista(inicio);

	return 0;
}

Nodo* agregar(Nodo* inicio, string username) {
	Nodo* numero = new Nodo();
	if (inicio == nullptr) {
		numero->id = 1;
	}
	else {
		numero->id = inicio->id + 1;
	}
	numero->username = username;
	numero->sig = inicio;
	return numero;
}

void mostrarLista(Nodo* inicio) {
	if (inicio != nullptr) {
		cout << "Estos son los elementos en la lista: \n";
		for (Nodo* p = inicio; p != nullptr; p = p->sig) {
			cout <<"Elemento: " << p->id << endl;
			cout << "Nombre de usuario: " << p->username << endl;
		}
	}
}



