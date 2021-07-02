#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <sstream>
#include"Cliente.h"
#include"Apartado.h"
#include<Windows.h>

#define principal 101
#define total 127
class Funciones
{
private:
	Cliente cliente;
	Apartado apartado;
	double sumatoria;
public:
	
	Funciones(){
		
		this->cliente = Cliente();
		this->apartado = Apartado();
		this->sumatoria = 0;
		
	}
	~Funciones(void){
	}
	
	double getSumatoria(){
		
		return this->sumatoria;
		
	}
	//Funcion Hash
	int Hash(long clave){
		
		long posicion = clave % principal;
		return posicion;
		
	}
	//Metodo que controla las colisiones en el archivo
	int colisiones(Cliente client){
		
		fstream fout("clientes.txt",ios::in|ios::out);
		
		if(!fout){
			
			cout << "No se pudo abrir el archivo" << endl;
			fout.close();
			exit(1);
			
		}
		
		Cliente cli;
		ifstream fin("clientes.txt",ios::in);
		if(!fout){
			
			cout << "No se pudo abrir el archivo" << endl;
			fout.close();
			exit(1);
			
		}else{
			int j = principal;
			bool encontrado = false;
			
			while((j < total) && !encontrado){
				
				
				fout.seekp((j)*sizeof(Cliente),ios::beg);
				fout.read(reinterpret_cast<char *>(&cli),sizeof(Cliente));
				
				if(cli.getCedula()==0){
					
					encontrado = true;
					fout.seekp((cliente.getCedula())*sizeof(Cliente));
					fout.write((char *)&client,sizeof(Cliente));
					cout << "\n Cliente ingresado en el area de colisiones" << endl;
					
				}
				j++;
				fin.close();
			}
			fout.close();
			
			if(!encontrado){
				
				cout << "\n El area de colisiones esta completa!" << endl;
				
			}
		}
		
	}
	//Metodo que convierte un dato string en int
	long convertirString(string cadena){
		
		string sustituto;
		char s[9];
		bool ban=false;
		
		for(int x = 0; x<cadena.length();x++){
			
			if(cadena[x]=='-'){
				
				for(int j=x;j<=(cadena.length()-1);j++){
					
					cadena[j]=cadena[j+1];
					
					if(cadena[j]=='-'){
						
						cadena[j]=cadena[j+2];
						x=j;
						ban=true;
					}
				}
			}
			else{
				
				if(ban ==true){
					
					cadena [x]=cadena[x+1];
					
				}else{
					
					cadena [x]=cadena[x];
					
				}
			}
		}
		strncpy(s,cadena.data(),9);
		sustituto = s;
		long ced = stol(sustituto);
		
		return ced;
	}
	//Funcion que busca si los archivos estan creados o no
	bool buscarArchivo(){
		
		fstream regCliente("clientes.txt",ios::in );
		fstream regApartado("apartados.txt",ios::in);
		
		if(!regCliente && !regApartado){
			
			return false;
			
		}
		
		regCliente.close();
		regApartado.close();
		
		return true;
	}
	//Funcion que crea los archivos
	void crearArchivo(){
		
		ofstream regCliente("clientes.txt",ios::in | ios::app);
		ofstream regApartado("apartado.txt",ios::in | ios::app);
		
		cout << "\n\n\n\n\t\t Los Archivos Han Sido Creados!" << endl;
		system("pause>NULL");
		
		regCliente.close();
		regApartado.close();
	}
	//Funcion que ingresa los datos del cliente en el Archivo
	void ingresarCliente(){
		
		system("color 70");
		long cedula;
		string numC;
		string nombre ;
		long telefono;
		string direccion;
		
		cliente = Cliente();
		
			cout << "\n (Utilice el siguiente formato: #0###0### )" << endl
				<< "\n Ingrese su numero de cedula: ";
			cin >> numC;
			
			while(numC.length() < 9 || numC.length() > 9){
				
				cout << "\n La cedula debe seguir el formato #0###0###: " << endl
					<< "\n Intentelo de nuevo :";
				cin >> numC;
				
			}
			cedula = convertirString(numC);
			
			if(validarCliente(cedula).getCedula()!= cedula)
			{
				fstream fout("clientes.txt",ios::in | ios::out);
				
				if(!fout){
					
					cout<<"\n No se pudo abrir el archivo"<<endl;
					fout.close();
				}
				cin.ignore();
				cout<<"\n Ingrese su Nombre: ";
				getline(cin,nombre);
				cout<<"\n Ingrese su Numero de Telefono: ";
				cin>>telefono;
				cin.ignore();
				cout<<"\n Ingrese su Direccion: ";
				getline(cin,direccion);
				
				cliente.setCedula(cedula);
				cliente.setNombre(nombre);
				cliente.setTelefono(telefono);
				cliente.setDireccion(direccion);
				
				Cliente cli;
				ifstream fin("clientes.txt",ios::in);
				fin.seekg(Hash(cliente.getCedula())*sizeof(Cliente));
				fin.read(reinterpret_cast<char *>(&cli),sizeof(Cliente));
				
				if(cli.getCedula() == 0){
					fout.seekp(Hash(cliente.getCedula())*sizeof(Cliente));
					fout.write(reinterpret_cast<char *>(&cliente),sizeof(Cliente));
					
					fout.close();
					
					system("cls");
					system("color 70");
					cout << "\n Cliente Registrado Correctamente!" << endl;
				}else{
					colisiones(cliente);
				}
				fin.close();
				fout.close();
			
			
		}else{
			
			system("cls");
			system("color 70");
			cout << "\n Ya Existe Un Cliente Con Ese Numero de Cedula!"<<endl;
			
		}
	}
	//Funcion que valida si a cedula del cliente existe o no
	Cliente validarCliente(long cedula){
		
		ifstream fin("clientes.txt",ios::in);
		
		if(!fin){
			
			cout << "\n No se pudo abrir el archivo" << endl;
			fin.close();
		}else{
			
			cliente = Cliente();
			
			fin.seekg((Hash(cedula))*sizeof(Cliente)); 
			fin.read(reinterpret_cast<char *>(&cliente),sizeof(Cliente));
			
			if (cliente.getCedula() == cedula){
				
				fin.close();
				return cliente;
				
			}
		}
		
		cliente = Cliente();
		fin.close();
		
		return cliente;
		
	}
	//Funcion que muestra los datos registrados en el archivo clientes
	void mostrarCliente(){
		
		ifstream fin("clientes.txt",ios::in);
		
		if(!fin){
			
			cout<<"\n No se pudo abrir el archivo"<<endl;
			
		}else{
			
			system("cls");
			system("color 70");
			
			cout << "*************************************LISTA DE CLIENTES*************************************" << endl;
			
			cout << "\n" << left <<setw(20) << "N.Registro" 
				<< left << setw(20) << "Cedula" 
				<< left << setw(20) << "Nombre " 
				<< left << setw(20) << "Telefono" 
				<< left << setw(20) << "Direccion" << endl;
			
			cliente = Cliente();
			
			fin.read( reinterpret_cast < char* >( &cliente),sizeof(Cliente) );
			
			int contador = 0;
			int conta = 0;
			
			while (fin && !fin.eof())
			{
				if(cliente.getCedula()!= 0){
					cout << "*******************************************************************************************" << endl;
					cout << left << setw(20) << conta 
						<< left << setw(20) << cliente.getCedula()
						<< left << setw(20) << cliente.getNombre() 
						<< left << setw(20) << cliente.getTelefono()
						<< left << setw(20) << cliente.getDireccion() << endl;
					contador++;
					
				}
				conta++;
				
				fin.read( reinterpret_cast < char* >( &cliente),sizeof(Cliente) );
			}
			cout << "\n Total Clientes: " << contador <<"\n\n\n\n";
			
			fin.close();
		}
	}
	//Funcion para consultar los datos registrados en los registros
	bool consultarCliente(){
		
		string cedulaCliente;
		long ced;
		system("cls");
		system("color 70");
		
		cout << "*************************************CLIENTE*************************************\n" << endl;
		cout << "\n (formato = #0###0### ):" << endl
			<< "\n Ingrese su numero de cedula: " ;
		cin >> cedulaCliente;
		
		
		while(cedulaCliente.length() < 9 ||cedulaCliente.length() > 9){
			
			cout << "\n\n La cedula debe seguir el formato #0###0###: " << endl
				<< " Intentelo de nuevo :";
			cin >> cedulaCliente;
			
		}
		
		ced = convertirString(cedulaCliente);
		
		cliente = validarCliente(ced);
		
		system("cls");		
		
		this->sumatoria = 0;
		
		if(cliente.getCedula()!=0){
			
			cout << "\n" << left << setw(20) << "Cedula" 
				<< left << setw(20) << "Nombre" 
				<< left << setw(20) << "Telefono"
				<< left << setw(20) << "Direccion" << endl;
			
			cout << "*******************************************************************************************" << endl;
			
			cout << "\n" << left << setw(20) << cliente.getCedula()
				<< left << setw(20) << cliente.getNombre()
				<< left << setw(20) << cliente.getTelefono()
				<< left << setw(20) << cliente.getDireccion() << endl
				
				<< "*******************************************************************************************" << endl;
			
			this->sumatoria += apartado.getTotal();
			
			cout<<"\n*************************************Apartados Pendientes********************************** \n"<<endl;
			
			int temporal = mostrarApartado(cliente.getCedula(),"PENDIENTE");
			
			if(temporal == 0){
				
				cout << "\n No Hay Apartados Pendientes para mostrar\n\n\n\n" << endl;
				
			}else{
				
				cout << "\n Total De Apartados Pendientes: " << temporal << endl
					<< " Suma Total de la cuenta: " << this->sumatoria << "\n\n\n\n";
				
			}
			
			cout << "\n*************************************Apartados Cancelados********************************** \n" << endl;
			
			temporal = mostrarApartado(cliente.getCedula(),"CANCELADO");
			
			if(temporal == 0){
				
				cout << "\n No Hay Apartados Cancelados para mostrar\n\n\n\n" << endl;
				
			}else{
				
				cout << "\n Total De Apartados Cancelados: " << temporal << endl;
				
			}
			
			temporal = 0;
			
			return true;
			
		}else{
			
			system("cls");
			system("color 70");
			
			cout << "\n No Existe Un Cliente Con Ese Numero de Cedula!" << endl;
			
		}
		
		this->sumatoria = 0;
		
		return false;
		
	}
	//Funcion que obtiene los registros guardados
	int cuentaRegistro(){
		
		fstream fin("apartado.txt",ios::in);
		
		if (!fin){
			
			system("cls");
			system("color 70");
			cout<<"\n No se pudo abrir el archivo"<<endl;
			
		}else{
			
			apartado = Apartado();
			
			int code = 0;
			
			fin.read(reinterpret_cast<char *>(&apartado),sizeof(Apartado));
			
			while(!fin.eof()){
				
				code++;
				fin.read(reinterpret_cast<char *>(&apartado),sizeof(Apartado));
				
			}
			
			if(apartado.getNumApartado() > 0)
						   
						   return apartado.getNumApartado();
			
			fin.close();
		}
		
		return 0;
		
	}
	//Funcion para ingresar un apartado
	void ingresarApartado(){
		
		system("color 70");
		
		int code = (cuentaRegistro() + 1);
		string cedulaCliente;
		long ced;
		string fecha;
		string nom_Producto;
		double precio;
		short int cantidad;
		
		cout << "***************************************************************\n";
		
		cout << "\n (formato: #0###0### )"<< endl
			<< "\n Ingrese su numero de cedula: ";
		cin >> cedulaCliente;
		
		while(cedulaCliente.length() < 9 ||cedulaCliente.length() > 9){
			
			cout << "\n La cedula debe seguir el formato #0###0###" << endl
				<< " Intentelo de nuevo :";
			cin >> cedulaCliente;
			
		}
		ced = convertirString(cedulaCliente);
		
		if(validarCliente(ced).getCedula() == ced){
			
			fstream fout("apartado.txt",ios::in | ios::out );
			
			cin.ignore();
			cout << "*************************************\n";
			cout << "\n Numero de Apartado: " << code << endl;
			cout << "\n Ingrese el nombre del producto: ";
			getline(cin,nom_Producto);
			cout << "\n Ingrese la fecha DD/MM/AAAA: ";
			getline(cin,fecha);
			cout << "\n Ingrese el precio: ";
			cin >> precio;
			cout << "\n Ingrese la cantidad: ";
			cin >> cantidad;
			
			apartado.setNumApartado(code);
			apartado.setCedulaCliente(ced);
			apartado.setNom_Producto(nom_Producto);
			apartado.setFecha(fecha);
			apartado.setEstado("PENDIENTE");
			apartado.setPrecio(precio);
			apartado.setCant(cantidad);
			apartado.setTotal(cantidad*precio);
			
			fout.seekp((code-1)*sizeof(Apartado));
			fout.write(reinterpret_cast<char *>(&apartado),sizeof(Apartado));
			
			fout.close();
			
			system("cls");
			system("color 70");
			cout<<"\n Apartado Registrado Correctamente!"<<endl;
			
		}else{
			
			system("cls");
			system("color 0C");
			cout << "\n No Existe Un Cliente Con Ese Numero de Cedula!"<<endl;
			
		}
	}
	//Funcion para modificar un apartado
	void modificarApartado(){
		
		if(consultarCliente()){
			
			int code = 0;
			
			cout << "\n Ingrese el numero de registro a modificar: ";
			cin >> code;
			
			fstream fout("apartado.txt",ios::in| ios::out);
			
			if (!fout){
				
				cout<<"\n No se pudo abrir el archivo"<<endl;
				
			}else{
				
				apartado = Apartado();
				
				fout.seekg((code-1)*sizeof(Apartado));
				fout.read(reinterpret_cast<char* >(&apartado),sizeof(Apartado));
				
				if(apartado.getNumApartado() == code){
					
					int confir = 0;
					
					cout << "\n Desea modificar el apartado?" << endl
						<<"\n Si: 1\t No: 0 [ ]\b\b";
					cin >> confir;
					
					if(confir == 1){
						
						apartado.setEstado("CANCELADO");
						
						fout.seekp((code-1)*sizeof(Apartado));
						fout.write(reinterpret_cast<char* >(&apartado),sizeof(Apartado));
						
						cout << "\n Apartado Modificado Correctamente!"<<endl;
						
					}else{
						
						system("cls");
						system("color 70");
						
						cout << "\n Modificacion Cancelada" << endl;
						
					}
				}else{
					
					system("cls");
					system("color 70");
					cout << "\n El Numero de registro No Existe" << endl;
					
				}
			}
			fout.close();
		}
	}
	//Funcion que obtiene los apartados por cliente
	int mostrarApartado(long cedula,string filtrar){
		
		ifstream fin("apartado.txt",ios::in);
		
		int cont = 0;
		
		if(!fin){
			
			cout << "\n No se pudo abrir el archivo" << endl;
			
		}else{
			
			this->sumatoria = 0;
			
			cout << "\n" << left << setw(15) << "Codigo" 
				<< left << setw(15) << "Fecha" 
				<< left << setw(15) << "Producto"
				<< left << setw(15) << "Estado"
				<< left << setw(15) << "Precio"
				<< left << setw(15) << "Cantidad"
				<< endl;
			
			cout << "*******************************************************************************************" << endl;
			
			apartado = Apartado();
			
			fin.read(reinterpret_cast < char* >(&apartado),sizeof(Apartado));
			
			while (fin &&! fin.eof()){
				
				if(((apartado.getCedulaCliente() == cedula && filtrar == apartado.getEstado()) || 
				   ( apartado.getCedulaCliente() == cedula && filtrar == "TODO" ))|| filtrar == apartado.getEstado()){
					
					cont++;
					
					cout << left << setw(15) << apartado.getNumApartado()
						<< left <<setw(15) << apartado.getFecha()
						<< left <<setw(15) << apartado.getNombProducto()
						<< left <<setw(15) << apartado.getEstado()
						<< left <<setw(18) << apartado.getPrecio() 
						<< apartado.getCantidad()<< endl << endl;
					
					cout << "                                                                      TOTAl     :" << apartado.getTotal()<<endl;
					cout << "*******************************************************************************************" << endl;
					
					this->sumatoria += apartado.getTotal();
					
				}
				   fin.read( reinterpret_cast < char* >( &apartado),sizeof(Apartado) );
			}
			fin.close();
		}
		return cont;
		
	}
	
};
