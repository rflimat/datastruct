#include<iostream>
#include<conio.h>
using namespace std;

class Matriz{
	private:
		int matriz[20][20];
		int n;
	public:
		Matriz(int);
		void generar();
		void mostrar();
};

Matriz::Matriz(int _n){
	n=_n;
}

void Matriz::generar(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matriz[i][j]=0;
		}
	}
	
	int i=0;
	int j=n/2;

	int x=1;
	matriz[0][j]=x++;
	
	while(x<=n*n){	
		if(x%n-1!=0){
			if(i-1<0) i=n;
			if(j+1>=n) j=-1;
			i--;
			j++;
			matriz[i][j]=x++;
		}else{
			i++;
			matriz[i][j]=x++;
		}
	}
}

void Matriz::mostrar(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	
	cout<<"Ingrese la dimension de la matriz: ";
	cin>>n;
	
	//Ingresando un numero impar se cumplen las 3 condiciones
	//y la sumatoria de todos los renglones es igual
	cout<<"\nCuadrado Magico\n";
	if(n%2==0){
		cout<<"Las sumas de los renglones no son iguales";
	}else{
		Matriz m=Matriz(n);
		m.generar();
		m.mostrar();
	}
	
	getch();
	return 0;
}
