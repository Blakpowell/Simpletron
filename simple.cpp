#include "Simple.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Simple::Simple()
{
	acumulador = 0;
}

Simple::~Simple()
{
	cout << "Simpletron a terminado..." << endl;
	cout << "(Se va mimir)." << endl;
}

void Simple::establecerEnMemoria(int vector[], int tamanio)
{
	for (int i = 0; i < 100; ++i)
	{
		memoria[i] = vector[i];
	}
	ultimaInstruc = tamanio;
}

void Simple::bucleBase()
{
	int fin = 100;
	fin = ultimaInstruc;
	while (contador < fin)
	{
		decodear(contador);
		pantallaMain(contador, codigoDeOperacion, operando);
		ejecutar(codigoDeOperacion, operando);
		contadorMasUno(codigoDeOperacion);
		cout << endl;
		if (terminar == true)
			contador = fin;
		system("cls");
	}
}

int Simple::primeraInstruc()
{
	int i = 0;
	while (i < 100)
	{
		if (memoria[i] != 0)
			break;
		i++;
	}
	return i;
}

void Simple::pantallaMain(int conta, int codigoDeOperacion, int oper)
{
	cout << "REGISTROS" << endl << "acumulador\t\t";
	cout << showpos << setw(5) << setfill('0') << internal << acumulador << endl;
	cout << "contador\t\t";
	cout << noshowpos << setw(2) << setfill('0') << internal << conta << endl;
	cout << "registroDeInstruccion\t";
	cout << showpos << setw(5) << setfill('0') << internal << registroDeInstruccion << endl;
	cout << "codigoDeOperacion\t";
	cout << noshowpos << setw(2) << setfill('0') << codigoDeOperacion << endl;
	cout << "operador\t\t";
	cout << setw(2) << setfill('0') << oper << endl;

	cout << "MEMORIA:\n  ";
	for (int j = 0; j < 10; j++)
		cout << noshowpos << right << setw(6) << setfill(' ') << j;
	cout << endl;
	for (int i = 0; i < 100; i++)
	{
		if (i == 0) cout << noshowpos << right << setw(2) << i;
		if (i % 10 == 0 && i > 9)
			cout << endl << noshowpos << setw(2) << i;
		cout << " " << showpos << setfill('0') << internal << setw(5) << memoria[i];
	}
}

void Simple::decodear(int cont)
{
	registroDeInstruccion = memoria[cont];
	codigoDeOperacion = registroDeInstruccion / 100;
	operando = registroDeInstruccion % 100;
}

void Simple::ejecutar(int codigoDeOperacion, int oper)
{
	switch (codigoDeOperacion)
	{
	case LEE:
		lee(oper);
		break;
	case ESCRIBE:
		cout << endl;
		escribe(oper);
		break;
	case CARGA:
		carga(oper);
		break;
	case ALMACENA:
		almacena(oper);
		break;
	case SUMA:
		suma(oper);
		break;
	case RESTA:
		resta(oper);
		break;
	case DIVIDE:
		divide(oper);
		break;
	case MULTIPLICA:
		multiplica(oper);
		break;
	case BIFURCA:
		bifurca(oper);
		break;
	case BIFURCANEG:
		bifurcaneg(oper);
		break;
	case BIFURCACERO:
		bifurcacero(oper);
		break;
	case ALTO:
		alto();
		break;
	default: break;
	}
}

void Simple::lee(int indice)
{
	cout << endl << ">> ";
	cin >> memoria[indice];
}

void Simple::escribe(int instruc)
{
	cout << "Salida: " << noshowpos << memoria[instruc] << endl;
	system("pause");
}

void Simple::carga(int instruc)
{
	acumulador = memoria[instruc];
	cout << endl;
	system("pause");
}

void Simple::almacena(int instruc)
{
	memoria[instruc] = acumulador;
	cout << endl;
	system("pause");
}

void Simple::suma(int instruc)
{
	acumulador += memoria[instruc];
	cout << endl;
	system("pause");
}

void Simple::resta(int instruc)
{
	acumulador -= memoria[instruc];
	cout << endl;
	system("pause");
}
void Simple::divide(int instruc)
{
	acumulador /= memoria[instruc];
	cout << endl;
	system("pause");
}
void Simple::multiplica(int instruc)
{
	acumulador *= memoria[instruc];
	cout << endl;
	system("pause");
}
void Simple::bifurca(int instruc)
{
	contador = instruc;
	cout << endl;
	system("pause");
}
void Simple::bifurcaneg(int instruc)
{
	if (acumulador < 0) contador = instruc;
	else contador++;
	cout << endl;
	system("pause");
}
void Simple::bifurcacero(int instruc)
{
	if (acumulador == 0) contador = instruc;
	else contador++;
	cout << endl;
	system("pause");
}

void Simple::alto()
{
	cout << "\n\n*** Termino la ejecucion de Simpletron ***\n\n";
	terminar = true;
	system("pause");
}

void Simple::contadorMasUno(int codigoDeOperacion)
{
	switch (codigoDeOperacion)
	{
	case BIFURCA:
	case BIFURCANEG:
	case BIFURCACERO:
		break;
	case LEE:
	case ESCRIBE:
	case CARGA:
	case ALMACENA:
	case SUMA:
	case RESTA:
	case DIVIDE:
	case MULTIPLICA:
	case ALTO:
	default:
		contador++;
		break;
	}
}
