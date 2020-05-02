/*Una empresa necesita llevar el control de los datos personales de sus 10 empleados contratados, por la motivo la empresa lo ha contratado para la implementacion de este proyecto, los datos a almacenar son:

Codigo Empleado,
Nombre Empleado,
Puesto,
Departamento,
Salario.

Existen 3 departamentos, 1 Gerencia, 2 Administracion y 3 Produccion.  El programa debera de desplegar la lista de empleados almacenados y el total de la planilla
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

using namespace std;

struct empleado {
	int cod_emp;
	string nom_emp;
	string pues_emp;
	string dep_emp;
	float sal_emp;
};
int main(){
int n,i;
empleado *emp;
float total=0;
emp= new empleado[10];
for(i=0;i<10;i++){
	cout<<"Ingrese codigo de empleado:  "<<endl;
	cin>>emp[i].cod_emp;
	cin.ignore();
	
	cout<<"Ingrese nombre del empleado: "<<endl;
	getline(cin,emp[i].nom_emp);
	cin.ignore();
	
	cout<<"Ingrese puesto la persona:   "<<endl;
	getline(cin,emp[i].pues_emp);
	cin.ignore();
	
	cout<<"Ingrese departamento:        "<<endl;
    getline(cin,emp[i].dep_emp);
	cin.ignore();
	
	cout<<"Ingrese el salario de la persona:"<<endl;
	cin>>emp[i].sal_emp;
	cin.ignore();
	
	             }

cout<<"    La lista de empleados es la siguiente:"<<endl;
cout<<"================================================="<<endl;
for(i=0;i<10;i++){
cout<<"CODIGO: "<<emp[i].cod_emp<<" NOMBRE: "<<emp[i].nom_emp<<" PUESTO: "<<emp[i].pues_emp<<" DEPARTAMENTO: "<<emp[i].dep_emp<<" SALARIO: "<<emp[i].sal_emp<<endl;
total+=emp[i].sal_emp;

}
cout<<"Total a pagar a la planilla:"<<total<<endl;
delete []emp;


	}
