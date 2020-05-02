/*
EJERCICIO #1
El director de un colegio desea realizar un programa que procese un archivo de registros correspondiente a los diferentes 
alumnos del centro a fin de obtener los siguientes datos:

    Nota más alta y número de identificación del alumno correspondiente.
    Nota media del colegio.

Datos de Estudiantes:

    Identificación
    Nombre    
    Nota
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct estudiante {
	string nombre;
	int id;	
	float nota;	
};
void mp(); 
void ingresardatos(string na);
void leer_archivo(string na);
int main(){
	mp();	
}
void mp(){
	int resp;
	string nombrearchivo;
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Estudiantes "<<"\n";
		cout<<" 2 - Reporte "<<"\n";		
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			ingresardatos(nombrearchivo);			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo(nombrearchivo);
		}					
		else if (resp==4)
			break;
		else 
			break;
		
	} while(resp!=4);	
}

void ingresardatos(string na){
	int id_est;
	string nombre_est;
	float nota_est;
	
	cout<<"Ingrese codigo estudiante: "<<endl;
	cin>>id_est;
	fflush(stdin);
	cout<<"Ingrese Nombre de estudiante: "<<endl;
	getline(cin,nombre_est);
	cout<<"Ingrese Nota de estudiante: "<<endl;
	cin>>nota_est;
	
	ofstream archivo; //grabar en archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open(na.c_str(),ios::app); //append
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	archivo<<nombre_est<<"\t"<<id_est<<"\t"<<nota_est<<endl;
	archivo.close();
}

void leer_archivo(string na){
	ifstream archivo; //leer archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open("colegio.txt",ios::in); //append
	if(archivo.fail()){
		cout<<" 1 No se pudo abrir el archivo";
		exit(1);
	}
	int lineas;
	string s;
	while (getline(archivo, s))
        lineas++;
    archivo.close();
    
    estudiante recordset[lineas];
	archivo.open(na.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
            break;
        }
        //cout<<"i: "<<i;
        archivo>>recordset[i].nombre>>recordset[i].id>>recordset[i].nota;
    	//cout<<s;
	}
    archivo.close();
    for (int i = 0; i < lineas; i++){
    	cout<<recordset[i].id<<recordset[i].nombre<<recordset[i].nota<<endl;
	}
	system("Pause");
}

