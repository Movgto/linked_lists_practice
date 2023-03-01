#include <iostream>
#include <string>
#include <conio.h>

using namespace std;



struct Usuario {
	string username;
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
	int phoneNum;
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
	string name;
	string dir;

	Sucursal* sig;
};

void mostrarListaCli(Cliente* inicio);
Usuario* crearCuenta(Usuario* inicio, string username, string name, string psw, string sucursal, bool admin);
Usuario* iniciarSesion(Usuario* inicio, string username, string psw);
Cliente* agregarCliente(Cliente* inicio, string name, string email, int phoneNum, string sucursal);
Sucursal* agregarSucursal(Sucursal* inicio, string name, string dir);
void mostrarListaSuc(Sucursal* inicio);
Promocion* agregarProm(Promocion* inicio, string name, int points, int perc, bool status);
void mostrarListaProm(Promocion* inicio);

int main() {
	Usuario* inicioUsu = nullptr;
	Cliente* inicioCli = nullptr;
	Sucursal* inicioSuc = nullptr;
	Promocion* inicioPro = nullptr;

	int num = 1;

	while (num != 0) {
		int op;
		cout << "--------Menu--------\n\t1. Usuarios\n\t2.Clientes\n\t3.Sucursales\n\t4.Promociones\n\t5.Salir\n";
		cin >> op;
		switch (op) {
			case 1: {
				int a;
				cout << "\t1.Iniciar Sesion\n\t2.Crear cuenta\n";
				cin >> a;
				switch (a) {
					case 1: {
						cout << "Nombre de usuario: ";
						string username;
						cin.ignore();
						getline(cin, username);
						cout << "\nContrasena: ";
						string psw;
						getline(cin, psw);
						Usuario* logAttempt = iniciarSesion(inicioUsu, username, psw);
						if (logAttempt == nullptr) { 
							cout << "Usuario no registrado o datos incorrectos...\n";
							break;
						}
						cout << "Bienvenido: " << username << endl;
						bool sessionActive = true;
						while (sessionActive) {
							int b;
							cout << "\n\n\t1.Ver informacion de cuenta\n\t2. Regresar\n";
							cin >> b;
							switch (b) {
								case 1: {
									cout << "Nombre: " << logAttempt->name << "\nNombre de usuario: " << logAttempt->username << endl;
									cout << "Sucursal: " << logAttempt->sucursal << "\nContrasena: " << logAttempt->contrasena << endl;
									cout << "Administrador/Cajero: ";
									if (logAttempt->admin) {
										cout << "Administrador";
									}
									else {
										cout << "Cajero";
									}
									cout << "\nPresione cualquier tecla para continuar...";
									_getch();
									break;
								}
								case 2: {
									cout << "Regresando...\n";
									sessionActive = false;
									break;
								}
							}
						}
						break;
					}
					case 2: {
						cout << "Nombre completo: ";
						string name;
						cin.ignore();
						getline(cin, name);
						cout << "\nNombre de usuario: ";
						string usr;
						getline(cin, usr);
						cout << "\nContrasena: ";
						string psw;
						getline(cin, psw);
						cout << "Sucursal: ";
						string suc;
						getline(cin, suc);
						int a;
						bool admin;
						bool adval = true;
						while (adval) {
							cout << "\n1.Administrador\n2.Cajero\n";
							cin >> a;
							switch (a) {
							case 1: {
								admin = true;
								adval = false;
								break;
							}
							case 2: {
								admin = false;
								adval = false;
								break;
							}
							default: {
								cout << "Opcion invalida, vuelve a intentar...";
							}
							}
						}

						inicioUsu = crearCuenta(inicioUsu, usr, name, psw, suc, admin);
						cout << "Cuenta creada exitosamente, presione cualquier tecla para continuar...\n";
						break;
					}
				}
				break;
			}
			case 2: {
				
				bool cliStatus = true;
				
				while (cliStatus) {
					cout << "\t1.Agregar\n\t2.Ver lista\n\t3.Atras\n";
					int a;
					cin >> a;
					switch (a) {
						case 1: {
							cout << "Nombre completo: ";
							cin.ignore();
							string name;
							getline(cin, name);

							cout << "\nEmail: ";
							string email;
							getline(cin, email);

							cout << "\nNumero de telefono: ";
							int phoneNum;
							cin >> phoneNum;
							cout << "\nSucursal: ";
							string suc;
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							getline(cin, suc);

							inicioCli = agregarCliente(inicioCli, name, email, phoneNum, suc);
							cout << "Cliente agregado exitosamente...\n";
							break;
						}
						case 2: {
							mostrarListaCli(inicioCli);
							break;
						}
						case 3: {
							cliStatus = false;
							break;
						}
						default: {
							cout << "Opción invalida, vuelve a intentar...\n";
							break;
						}
					}
					_getch();
					system("cls");
				}
				break;
			}
			case 3: {
				bool sucStatus = true;
				while (sucStatus) { 
					int a;
					cout << "1.Agregar sucursal\n2.Ver lista\n3.Volver\n";
					cin >> a;
					switch (a) {
						case 1: {
							cout << "Nombre: ";
							string name;
							cin.ignore();
							getline(cin, name);
							cout << "\nDireccion: ";
							string dir;
							getline(cin, dir);

							inicioSuc = agregarSucursal(inicioSuc, name, dir);

							cout << "Sucursal agregada exitosamente...\n";
							break;
						}
						case 2: {
							mostrarListaSuc(inicioSuc);
							break;
						}
						case 3: {
							cout << "Volviendo...";
							sucStatus = false;
							break;
						}
					}
					_getch();
					system("cls");
				}

			}
			case 4: {
				bool promStatus = true;
				while (promStatus) {
					int a;
					cout << "1.Agregar\n2.Ver lista\n3.Regresar\n";
					cin >> a;
					switch (a) {
						case 1: {
							cout << "Nombre: ";
							string name;
							cin.ignore();
							getline(cin, name);
							cout << "\nPuntos requeridos: ";
							int points;
							cin >> points;
							cin.ignore();
							cout << "\nEstado: ";
							bool status;
							cout << "\n1.Activa\n2.Inactiva\n";
							bool statval = true;
							while (statval) {
								int b;
								cin >> b;
								switch (b) {
									case 1: {
										status = true;
										statval = false;
										break;
									}
									case 2: {
										status = false;
										statval = false;
										break;
									}
									default: {
										cout << "Opcion no valida, vuelve a intentar...\n";
										_getch();
									}
								}
							}

							int perc;
							cout << "Porcentaje de descuento: ";
							cin >> perc;

							inicioPro = agregarProm(inicioPro, name, points, perc, status);

							cout << "Promocion agregada exitosamente...\n";
							break;
						}
						case 2: {
							mostrarListaProm(inicioPro);
							break;
						}
						case 3: {
							promStatus = false;
							cout << "Regresando...\n";
							break;
						}
					}
					_getch();
					system("cls");
				}
				break;
			}
			case 5: {
				cout << "Seguro que deseas salir? S/N...\n";
				bool exitStatus = true;
				while (exitStatus) {
					char exit;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					exit = _getch();
					switch (exit) {
						case 's':

						case 'S': {
							num = 0;
							exitStatus = false;
							break;
						}
						case 'n':

						case 'N': {
							cout << "Regresando...";
							exitStatus = false;
							break;
						}
					}
				}
				break;
			}
		}
		cout << "Presione una tecla para continuar...\n";
		_getch();
		system("cls");
	}

	return 0;
}

//Funciones para usuarios***********************************************************************************
Usuario* crearCuenta(Usuario* inicio, string username, string name, string psw, string sucursal, bool admin) {
	Usuario* usuario = new Usuario();
	usuario->username = username;
	usuario->name = name;
	usuario->contrasena = psw;
	usuario->sucursal = sucursal;
	usuario->admin = admin;
	
	usuario->sig = inicio;
	return usuario;
}

Usuario* iniciarSesion(Usuario* inicio, string username, string psw) {
	for (Usuario* p = inicio; p != nullptr; p = p->sig) {
		if (p->username == username && p->contrasena == psw) {
			return p;
		}
	}

	return nullptr;
}
//Funciones para clientes*************************************************************************************
Cliente* agregarCliente(Cliente* inicio, string name, string email, int phoneNum, string sucursal) {
	Cliente* cliente = new Cliente();
	//Asignación de datos
	cliente->name = name;
	cliente->email = email;
	cliente->sucursal = sucursal;
	cliente->phoneNum = phoneNum;
	//Se recorre la lista, conectando el puntero siguiente del elemento creado al elemento anterior 
	cliente->sig = inicio;
	//Se devuelve el elemento creado para ser asignado como el elemento inicial de la lista
	return cliente;
}

void mostrarListaCli(Cliente* inicio) {
	if (inicio != nullptr) {
		cout << "Estos son los usuarios en la lista: \n";
		for (Cliente* p = inicio; p != nullptr; p = p->sig) {
			cout << "Nombre de usuario: " << p->name << endl;
		}
	}
	else{
		cout << "No hay clientes registrados, presione una tecla para continuar...\n";
	}
}

//Funciones para sucursales********************************************************************************
Sucursal* agregarSucursal(Sucursal* inicio, string name, string dir) {
	Sucursal* sucursal = new Sucursal();
	sucursal->name = name;
	sucursal->dir = dir;

	sucursal->sig = inicio;

	return sucursal;
}

void mostrarListaSuc(Sucursal* inicio) {
	if (inicio != nullptr) {
		for (Sucursal* p = inicio; p != nullptr; p = p->sig) {
			cout << "Nombre de sucursal: " << p->name << endl;
			cout << "Direccion: " << p->dir << endl;
			cout << endl;
			cout << "Presiona una tecla para continuar...\n";
		}
	}
	else {
		cout << "No hay sucursales registradas volviendo...";
	}
}

//Funciones para promociones*******************************************************************************
Promocion* agregarProm(Promocion* inicio, string name, int points, int perc, bool status) {
	Promocion* promo = new Promocion();
	promo->name = name;
	promo->reqPoints = points;
	promo->perc = perc;
	promo->status = status;

	promo->sig = inicio;

	return promo;
}

void mostrarListaProm(Promocion* inicio) {
	if (inicio != nullptr) {
		for (Promocion* p = inicio; p != nullptr; p = p->sig) {
			cout << "Nombre: " << p->name << endl;
			cout << "Puntos requeridos: " << p->reqPoints << endl;
			cout << "Porcentaje: " << p->perc << endl; 
			cout << "Estado: ";
			if (p->status) {
				cout << "Activo\n";
			}
			else {
				cout << "Inactivo\n";
			}
		}
	}
	else {
		cout << "No hay promociones registradas...\n";
	}
}
