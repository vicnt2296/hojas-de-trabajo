/*
Ejercicio # 2
Una empresa tiene diez almacenes y necesita crear un programa 
que lea las ventas mensuales 
de los diez almacenes, calcular la media de ventas 
y obtener un listado de los almacenes 
cuyas ventas mensuales son superiores a la media.
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct vtas{
  int almacenid;
  int mes;
  float montovendido;
};
int main() {
  int i,n=0;  
  float sumatotal=0,media,mayor;
  string almacenes =" ";
  ostringstream ssal;  //ostringstream
  ostringstream ssmsv;
  ostringstream ssmt;
  cout<<"Cuantos datos almacenara? ";
  cin>>n;
  
  vtas ventas[n];
  /*Ingreso de Datos*/
  	for(i=0;i<n;i++){
    	cout<<"Ingrese Codigo de Almacen: "<<endl;
    	cin>>ventas[i].almacenid;
    	cout<<"Ingrese Mes de la venta: "<<endl;
    	cin>>ventas[i].mes;
    	cout<<"Monto venido: "<<endl;
    	cin>>ventas[i].montovendido;
    	sumatotal=sumatotal+ventas[i].montovendido;
    	system("CLS");
  	}
  	
  	/*Calculo de Media General*/
  	media= sumatotal/n; //float(n);
  	mayor=media;

	/*Deshabilitado*/
  	/*Determinar el id de almacen mas alto*/
  	/*for(i=0;i<n;i++){
    	if(ventas[i].almacenid>mayor)
    	  mayor=ventas[i].almacenid;
  	} */ 
	/*Determinar Ventas Mayores*/
  	for(i=0;i<n;i++){
  		//Doble validación para que no se duplique en la cadena final
  		if(ventas[i].montovendido>media){
		  if(ventas[i].montovendido>mayor){
		  	/*Convertir Int to String*/
	  		ssal << ventas[i].almacenid;
	  		ssmsv << ventas[i].mes;
	  		ssmt << ventas[i].montovendido;
	  		/*Concatenar valores*/
	  		almacenes=almacenes+"Almacen:"+ssal.str()+"-Mes:"+ ssmsv.str()+"-Monto:"+ssmt.str()+" / ";
	  		/*Limpiar stream ostringstream*/
	  		ssmsv.str("");
	  		ssmt.str("");
	  		ssal.str("");
	  		ssmsv.clear();
  			ssmt.clear();
  			ssal.clear();
			mayor=ventas[i].montovendido;
		  }			  			
  		}
	}
	//Imprisión en pantalla final
	cout<<"Promedio General: "<<media<<endl;
	cout<<"Mayores ventas:   "<<almacenes.substr(0,almacenes.length()-2)<<endl;
	
}
