/*
Realice un programa que, dado el peso, la altura, la edad y el género (M/F) de un grupo de N personas 
que pertenecen a un departamento de la república, obtenga un promedio de peso, altura y edad de esta población.  
Los datos deben guardarse de forma ordenada por edad en un archivo de datos.  Así mismo el programa 
debe ser capaz leer los datos del archivo y generar un reporte con la media del peso, altura y la edad. 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<conio.h>
using namespace std;

int main(){
	
	float peso[3];
	float altu[3];
	float edad[3];
	char gen[3];
	int i,j;
	float aux[3];
	float mayor;
	float edad1=0,peso1=0,altu1=0;
	float edad2=0,peso2=0,altu2=0;
	
	for(i=0;i<3;i++){
		cout<<"Ingrese peso:"<<endl;
		cin>>peso[i];
		cout<<"Ingrese altura:"<<endl;
		cin>>altu[i];
		cout<<"Ingrese edad:"<<endl;
		cin>>edad[i];
		cout<<"Ingrese sexo, M=masculino o F=femenino"<<endl;
		cin>>gen[i];
		aux[i]= edad[i];
		system("cls");
	}
	
	//metodo de la burbuja
	
	for(i=1;i<3;i++){
		for(j=0;j<3-i;j++){
			if(aux[j]>aux[j+1]){
			  mayor=aux[j];
			  aux[j]=aux[j+1];
			  aux[j+1]=mayor;
				
			}
			
		}
		
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(edad[j]==aux[i]){
				cout<<"DATOS SEGUN EDAD:"<<endl;
				cout<<"EDAD: "<<edad[j]<<" ||PESO: "<<peso[j]<<" ||ALTURA: "<<altu[j]<<" ||GENERO: "<<gen[j]<<endl;
				edad1+=edad[j];
				edad2=edad1/3;
				peso1+=peso[j];
				peso2=peso1/3;
				altu1+=altu[j];
				altu2=altu1/3;
			}
		}
	}
	
	cout<<"Promedio de edad:"<<edad2<<endl;
	cout<<"Promedio del peso:"<<peso2<<endl;
	cout<<"Promedio de altura:"<<altu2<<endl;
	
	system("pause");
	return 0;
}
	

