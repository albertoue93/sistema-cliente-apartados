#include"Funciones.h"
/*
UNIVERSIDAD NACIONAL DE COSTA RICA.
Proyecto Final- Estructura de Datos.
Integrantes:
Alberto Urbina Espinoza.
Josselyne Bonilla Espinoza.
*/

int main(){
	Funciones func;
	
	int opc = 0;
	int opcion = 0;
	system("color 70");
	
	if(func.buscarArchivo()){
		
		cout << "*********************************" <<endl;
		cout << "*   Archivo Cargado con Exito   *" << endl;
		cout << "*********************************" << endl;
		system("pause>nul");
		system("cls");
		
		goto MENU;
		
	}else{
		
		do
		{
			cout << " No Hay Ningun Registro!" << endl;
			system("pause>nul");
			system("cls");
			cout << "**********Menu**********" << endl
				<< "************************" << endl
				<< "* 1. Crear Archivo     *" << endl
				<< "* 2. salir             *" << endl
				<< "************************" << endl
				<< " Elija una opcion: [ ]\b\b";
			cin>>opc;
			
			switch (opc)
			{
			case 1:
				system("cls");
				func.crearArchivo();
				goto MENU;
				break;
			case 2:
				exit(0);
				break;
			default:
				cout << "\n Debe seleccionar opcion!" << endl;
				system("pause>NULL");
				break;
			}
		} while (opc <= 3);
	}
	
	MENU:
						  do
	{
		int valor = 0;
		system("color 70");
		opcion = 0;
		system("cls");
		
		cout << "\tARCHIVO DE CLIENTE"<<endl
			<< "***************Menu***************" << endl
			<< "* 1. CREAR REGISTRO CLIENTE      *" << endl
			<< "* 2. MOSTRAR                     *" << endl
			<< "* 3. CONSULTAR                   *" << endl
			<< "* 4. CREAR APARTADO              *" << endl
			<< "* 5. MODIFICAR APARTADO          *" << endl
			<< "* 6. MOSTRAR APARTADOS           *" << endl
			<< "* 7. SALIR                       *" << endl
			<< "**********************************" << endl
			<< " Elija una opcion [ ]\b\b";
		cin >> opcion;
		
		switch (opcion)
		{
		case 1:
			system("cls");
			func.ingresarCliente();
			system("pause>NULL");
			break;
		case 2:
			system("cls");
			func.mostrarCliente();
			system("pause>NULL");
			break;
		case 3:
			system("cls");
			func.consultarCliente();
			system("pause>NULL");
			break;
		case 4:
			system("cls");
			func.ingresarApartado();
			system("pause>NULL");
			break;
		case 5:
			system("cls");
			func.modificarApartado();
			system("pause>NULL");
			break;
		case 6:
			system("cls");
			
			cout << "\n*************************************Apartados Pendientes********************************** \n" << endl;
			
			valor = func.mostrarApartado(0,"PENDIENTE");
			
			if (valor!=0)
			{
				cout << " Total = " << func.getSumatoria() << "\n"<<endl;
				
			}else
			{
				cout << "\n No Hay Apartados\n"<<endl;
			}
			cout << " Total apartados = "<<valor<<"\n\n\n\n";
			
			cout << "\n*************************************Apartados Cancelados********************************** \n" << endl;
			
			valor = func.mostrarApartado(0,"CANCELADO");
			
			cout << "\n Total apartados = " << valor << "\n\n\n\n";
			
			system("pause>NULL");
			break;
		case 7:
			exit(0);
			break;
		default:
			break;
		}
	} while (opcion<=7);
}
