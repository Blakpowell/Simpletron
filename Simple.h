#ifndef SIMPLE_H
#define SIMPLE_H

// Operaciones de entrada/salida
const int LEE = 10;
const int ESCRIBE = 11;

// Operaciones de carga/almacena
const int CARGA = 20;
const int ALMACENA = 21;

// Operaciones aritmeticas
const int SUMA = 30;
const int RESTA = 31;
const int DIVIDE = 32;
const int MULTIPLICA = 33;

// Operaciones de transferencia de control
const int BIFURCA = 40;
const int BIFURCANEG = 41;
const int BIFURCACERO = 42;
const int ALTO = 43;

class Simple
{
public:
	Simple();
	~Simple();
	void establecerEnMemoria(int vector[], int tamanio);
	void decodear(int cont);
	void bucleBase();
	void pantallaMain(int conta, int codigoDeOperacion, int oper);
	void ejecutar(int codigoDeOperacion, int oper);
private:
	int memoria[100] = { 0 };
	int contador = 0;
	int acumulador;
	int registroDeInstruccion;
	int operando;
	int codigoDeOperacion;
	bool terminar = false;
	int primeraInstruc();
	int ultimaInstruc;
	void suma(int instruc);
	void resta(int instruc);
	void divide(int instruc);
	void multiplica(int instruc);
	void lee(int indice);
	void escribe(int instruc);
	void carga(int instruc);
	void almacena(int instruc);
	void bifurca(int instruc);
	void bifurcaneg(int instruc);
	void bifurcacero(int instruc);
	void alto();
	void contadorMasUno(int codigoDeOperacion);
};

#endif
