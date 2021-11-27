// Este programa fue apoyado por la colabracion indirecta de singhvikram11 (GitHub).
#include <iostream>
#include <iomanip>
#include <vector>
#include "Simple.h"

using namespace std;

void bienvenida();

int main()
{
	int i;
	bienvenida();
	int registro[100] = { 0 };
	for (int j = 0; j < 100; j++)
		registro[j] = 0;

	for (i = 0; i < 100; i++)
	{
		do
		{
			cout << setw(2) << setfill('0') << i << " ? ";
			cin >> registro[i];
		} while (!(registro[i] == -99999 || (registro[i] >= -9999 && registro[i] <= 9999)));
		
		if (registro[i] == -99999)
		{
			registro[i] = 0;
			cout << "\n\n*** Se completo la carga del programa ***\n"
				<< "*** Empieza la ejecucion del programa ***\n\n";
			system("pause");
			break;
		}
	}

	system("cls");
	Simple simpletron;
	simpletron.establecerEnMemoria(registro, i);
	simpletron.bucleBase();
	return 0;
}

void bienvenida()
{
	cout << "*** Bienvenido a Simpletron! ***\n\n"
		<< "*** Por favor, introduzca en su programa una instruccion    ***\n"
		<< "*** (o palabra de datos) a la vez. Yo le mostrare el        ***\n"
		<< "*** numero de ubicacion y un signo de interrogacion (?).    ***\n"
		<< "*** Entonces usted escribira la palabra para esa ubicacion. ***\n"
		<< "*** Escriba el valor centinela -99999 para dejar de         ***\n"
		<< "*** introducir su programa. ***\n\n";
}

// Simpletron solo entiende LMS
