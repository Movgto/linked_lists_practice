#include <iostream>
#include <string>
#include <conio.h>

using namespace std;



struct Usuario {
	string name;
	bool admin;
	string sucursal;
	string contrasena;

	Usuario* sig;
};

struct Cliente {
	string name;
	string sucursal;
	string email;
	int points = 0;

	Cliente* sig;
};

struct Promocion {
	string name;
	int reqPoints;
	int perc;
	bool status;

	Promocion* sig;
};

struct Sucursal {

};


Usuario* agregar(Usuario* inicio, string name, string sucursal, bool admin, string contrasena);
void mostrarLista(Usuario* inicio);

int main() {
	Usuario* inicioUsu = nullptr;
	Cliente* inicioCli = nullptr;
	Sucursal* inicioSuc = nullptr;
	Promocion* inicioPro = nullptr;

	int num = 1;

	while (num != 0) {
		int op;
		cout << "-----Menu-----\n\t1. Usuarios\n\t2.Clientes\n\t3.Sucursales\n\4.Promociones";
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

Usuario* agregar(Usuario* inicio, string name, string sucursal, bool admin) {
	Usuario* numero = new Usuario();
	if (inicio == nullptr) {
		numero->id = 1;
	}
	else {
		numero->id = inicio->id + 1;
	}
	numero->name = name;
	numero->sig = inicio;
	return numero;
}

void mostrarLista(Usuario* inicio) {
	if (inicio != nullptr) {
		cout << "Estos son los elementos en la lista: \n";
		for (Usuario* p = inicio; p != nullptr; p = p->sig) {
			cout <<"Elemento: " << p->id << endl;
			cout << "Nombre de usuario: " << p->name << endl;
		}
	}
}


