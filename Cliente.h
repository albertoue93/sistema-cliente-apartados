#pragma once
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
class Cliente
{
private :
	long cedula;
	char nombreCliente[25];
	long telefono;
	char direccion[50];
public:

	Cliente()
	{
		this->cedula = 0;

		strcpy(this->nombreCliente,"");
		this->telefono=0;
		strcpy(this->direccion,"");

	}
	Cliente(long _Cedula,string _Nombre,long _Telefono,string _Direccion){

		this->cedula =_Cedula;
		strncpy(this->nombreCliente,_Nombre.data(),15);
		this->nombreCliente[15] = '\0';
		this->telefono =_Telefono;
		strncpy(this->direccion,_Direccion.data(),50);
		this->direccion[50]='\0';
	}

	~Cliente(void)
	{
	}

	void setCedula(long _Cedula){
		this->cedula = _Cedula;
	}
	void setNombre(string _Nombre){
		strncpy(this->nombreCliente,_Nombre.data(),15);
		this->nombreCliente[15] = '\0';
	}
	void setTelefono(long _Telefono){
		this->telefono =_Telefono;
	}
	void setDireccion(string _Direccion){
		strncpy(this->direccion,_Direccion.data(),50);
		this->direccion[50] = '\0';
	}

	long getCedula(){
		return this->cedula;
	}
	char* getNombre(){
		return this->nombreCliente;
	}
	long getTelefono(){
		return this->telefono ;
	}
	char * getDireccion(){
		return this->direccion;
	}
};

