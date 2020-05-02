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


int main(){	
	mp();
	
}
//===============================================================================================================
void mp(){
	int resp;
		
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Datos Del Cuaderno Vendido. "<<"\n";
		cout<<" 2 - Reporte De Ventas"<<"\n";
		cout<<" 3 - Eliminar Registro De Ventas"<<"\n";
		cout<<" 4 - Modificar Registro De Ventas"<<"\n";
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
	
	int idia, imod;
	float icant;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"*** Ingreso de Datos del Cuaderno ***\n\n";
	cout<<"Indique dia de ingreso: "<<endl;
	cin>>idia;
	fflush(stdin);
	cout<<"Indique Modelo del cuaderno:         "<<endl;
	cin>>imod;
	fflush(stdin);	
	cout<<"Indique Cantidad vendida:         "<<endl;
	cin>>icant;
	
	try {
		db.open("cuaderno.txt",ios::app);
		db<<idia<<"\t"<<imod<<"\t"<<icant<<endl;   
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}
	
}
//=============================================================================
void leer_data_db(){
	//declaracion de variables
	int odia,i,omod,mayorodia;
	float ocant;	
	string linea;
	float suma= 0;
	float mayorcant = -1;
	
	ifstream db;	
	try{
		db.open("cuaderno.txt",ios::in);	

		cout<<"Datos del archivo:"<<endl;
		cout<<" DIA|"<<"      MODELO      |"<<"CANTIDAD|"<<endl;		
		while (db>>odia>>omod>>ocant){
			cout<<setw(3)<<odia<<"|"<<omod<<"|"<<setw(4)<<ocant<<"|"<<endl;
			i++;					
			suma+=ocant;
//			
			if (ocant>mayorcant){
				mayorcant=ocant;
				mayorodia =odia;
			}
		}	
		db.close();	
		
		
		cout<<"DIA DE LA VENTA MAS ALTA: "<<setw(3)<<mayorodia<<" - MAYOR CANTIDAD: "<<setw(3)<<mayorcant<<endl;
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}
//===============================================================
void eliminar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,idia,imod,icant,flag;
	//string onombre;
	remove("Temporal.txt");
	
	db_a.open("cuaderno.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>idia>>imod>>icant){
		if(aux==idia){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=idia)
			db_n<<idia<<"\t"<<imod<<"\t"<<icant<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("cuaderno.txt");
		rename("Temporal.txt","cuaderno.txt");
	}	
	system("Pause");
}


void modificar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,aux2,idia,omod,flag,imod,icant;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("cuaderno.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese el dia que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese el modelo a modificar a modificar: "<<endl;
		cin>>imod;
		cout<<"Ingrese cantidad nueva : "<<endl;
		cin>>icant;
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (db_a>>idia>>imod>>icant){
		if(aux==idia){
			db_n<<idia<<"\t"<<imod<<"\t"<<icant<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=idia)
			db_n<<idia<<"\t"<<imod<<"\t"<<icant<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("cuaderno.txt");
		rename("Temporal.txt","cuaderno.txt");
	}	
	system("Pause");
}
