/*
EJERCICIO #2
El director de un colegio desea realizar un programa que procese un archivo 
de registros correspondiente a los diferentes 
alumnos del centro a fin de obtener los siguientes datos:

    Nota más alta y número de identificación del alumno correspondiente.
    Nota media del colegio.
Datos de Estudiantes:
    Identificación
    Nombre
    Nota
    
Crear un funcion que borre un registro, ingresando el id
*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

using namespace std;
void insert_data_db();
void mp();
void leer_data_db();
void eliminar();
void modificar();
/*struct estudiante {
	int id;
	string nombre;
	float nota;	
};*/

int main(){	
	mp();
	//return 0;	
}
//===============================================================================================================
void mp(){
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Estudiantes "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Eliminar Registro"<<"\n";
		cout<<" 4 - Modificar Registro"<<"\n";
		cout<<" 5 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insert_data_db();			
		}
		else if (resp==2){		
			system("CLS");
			leer_data_db();
		}
		else if (resp==3){		
			system("CLS");
			eliminar();	
		}			
		else if (resp==4){
			system("CLS");
			modificar();
		}
		else if (resp==5)
			break;
		else 
			break;
		
	} while(resp!=5);	
}
//===================================================================================================
void insert_data_db(){
	//declaracion de variables
	int iid;
	string inombre;
	float inota;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"*** Ingreso de Datos de Estudiantes ***\n\n";
	cout<<"Indique identificacion del estudiante: "<<endl;
	cin>>iid;
	//cin.ignore();
	fflush(stdin);
	cout<<"Indique Nombre del Estudiante:         "<<endl;
	getline(cin,inombre);
	fflush(stdin);	
	cout<<"Indique Nota del Estudiante:         "<<endl;
	cin>>inota;
	//reemplaca espacios en blanco " " con "_"	
	const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = inombre;
 	//
	//Insercion de datos a un archivo
	try {
		db.open("Estudiante.txt",ios::app);
		db<<regex_replace(valor, obj, repl) <<"\t"<<iid<<"\t"<<inota<<endl;   //"|"
		db.close();
	}
	catch(exception X){
//=====================================================================================================
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
	
	//=======================================================================================================
}
void leer_data_db(){
	//declaracion de variables
	int oid,i,mayorid;
	string onombre;
	float onota;	
	string linea;
	float suma= 0;
	int mayornota = -1;
	
	ifstream db;	
	try{
		db.open("Estudiante.txt",ios::in);	

		cout<<"Datos del archivo:"<<endl;
		cout<<" Id|"<<"      Nombre      |"<<"Nota|"<<endl;		
		while (db>>onombre>>oid>>onota){
			//reemplaca "_" con " "	<-espacios en blanco
			const auto obj = regex{ "_" };
    		const auto repl = string{ " " };
    		const auto valor = onombre;
			//
			cout<<setw(3)<<oid<<"|"<<setw(18)<<regex_replace(valor, obj, repl)<<"|"<<setw(4)<<onota<<"|"<<endl;
			i++;					
			suma+=onota;
//			system("Pause");
			if (onota>mayornota){
				mayornota=onota;
				mayorid =oid;
			}
		}	
		db.close();	
		
		cout<<"\nPromedio Global: "<<suma/i<<endl;
		cout<<"ID de Nota Mas Alta: "<<setw(3)<<mayorid<<" - Nota Mas alta: "<<setw(3)<<mayornota<<endl;
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}
void eliminar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,oid,onota,flag;
	string onombre;
	remove("Temporal.txt");
	
	db_a.open("Estudiante.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>onombre>>oid>>onota){
		if(aux==oid){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=oid)
			db_n<<onombre<<"\t"<<oid<<"\t"<<onota<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("Estudiante.txt");
		rename("Temporal.txt","Estudiante.txt");
	}	
	system("Pause");
}

//==============================================================================================
void modificar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,oid,onota,flag,inota;
	string onombre;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("Estudiante.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID al que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese Nota a modificar: "<<endl;
		cin>>inota;
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (db_a>>onombre>>oid>>onota){
		if(aux==oid){
			db_n<<onombre<<"\t"<<oid<<"\t"<<inota<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=oid)
			db_n<<onombre<<"\t"<<oid<<"\t"<<onota<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("Estudiante.txt");
		rename("Temporal.txt","Estudiante.txt");
	}	
	system("Pause");
}
