#pragma once
#include <iostream>
using namespace std;
class Apartado
{
private :
	int numApartado;
	long cedulaCliente;
	char fecha [20];
	char nombProducto[25];
	double precio;
	short int cantidad;
	double total;
	char estado[10];
public:

	Apartado()
	{
		this->numApartado = 0;
		this->cedulaCliente = 0;
		strcpy(this->fecha,"");
		strcpy(this->nombProducto,"");
		this->precio=0;
		this->cantidad=0;
		this->total=0;
		strcpy(this->estado,"") ;
	}
	Apartado(int _numApartado,long _cedulaCliente,string _fecha,string _nombProducto,double _precio,short int _cantidad,double _total,string _estado)
	{
		this->numApartado = _numApartado;
		this->cedulaCliente = _cedulaCliente;
		strncpy(this->fecha,_fecha.data(),20);
		this->fecha[10] = '\0';

		strncpy(this->nombProducto,_nombProducto.data(),25);
		this->nombProducto[25] = '\0';

		this->cantidad = _cantidad;
		this->total = _total;

		strncpy(this->estado,_estado.data(),10);
		this->estado[10]='\0';
	}
	~Apartado(void)
	{
	}
	
	void setNumApartado(int code){
		numApartado = code;
	}
	void setCedulaCliente(long ced){
		cedulaCliente = ced;
	}
	void setFecha(string _fecha){
		strncpy(this->fecha,_fecha.data(),20);

	}
	void setNom_Producto(string Pnom_Producto){

		strncpy(this->nombProducto,Pnom_Producto.data(),25);
	}
	void setPrecio(double p){
		precio = p;
	}
	void setCant(short int c){
		cantidad = c;
	}
	void setTotal(double t){
		total = t;
	}
	void setEstado(string _estado ){
		strncpy(this->estado,_estado.data(),10);
	}

	int getNumApartado(){
		return numApartado;
	}
	long getCedulaCliente(){
		return cedulaCliente;
	}
	char * getFecha(){
		return fecha;
	}
	char * getNombProducto(){
		return nombProducto;
	}
	double getPrecio(){
		return precio;
	}
	short int  getCantidad(){
		return cantidad;
	}
	double getTotal(){
		return total;
	}
	char *getEstado(){
		return estado;
	}
	
};

