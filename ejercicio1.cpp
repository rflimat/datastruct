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
	int x=1;
	int cen=n/2;
	
	if(n%2==0){
		cen=cen-1;
	}
		
	matriz[cen][cen]=x++;
	
	int ki=cen,kj=cen;
	int t=1;
	while(t<=n){
		if(t%2!=0){
			if(t>=n){
				for(int k=0;k<t;k++){
					kj=kj+1;
					matriz[ki][kj]=x++;
				}
				break;
			}
			for(int k=0;k<t;k++){
				kj=kj+1;
				matriz[ki][kj]=x++;
			}
			for(int k=0;k<t;k++){
				ki=ki+1;
				matriz[ki][kj]=x++;
			}	
		}else{
			for(int k=0;k<t;k++){
				kj=kj-1;
				matriz[ki][kj]=x++;
			}
			for(int k=0;k<t;k++){
				ki=ki-1;
				matriz[ki][kj]=x++;
			}
		}
		t++;
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
	
	Matriz m=Matriz(n);
	m.generar();
	
	cout<<"\nMatriz Espiral\n";
	m.mostrar();
	
	getch();
	return 0;
}

