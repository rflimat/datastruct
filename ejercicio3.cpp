#include<iostream>
#include<conio.h>
using namespace std;

class Nodo{
	private:
		int info;
		Nodo *sig;
	public:
		Nodo();
		friend class Lista;
};

Nodo::Nodo(){
    sig=NULL;
}

class Lista{
	private:
		Nodo *i;
	public:
		Lista();
		void crear();
		void invertir();
		void recorrer();
};

Lista::Lista(){
	i=NULL;
}

void Lista::crear(){
	int dato;
    char op;
    do{
        Nodo *p=new Nodo();
        cout<<"Ingrese un dato: ";
        cin>>dato;
        p->info=dato;
        p->sig=i;
        i=p;
        cout<<"Desea continuar (s/n): ";
        cin>>op;
    }while(op=='s');
}

void Lista::invertir(){
	Nodo *inv;
	Nodo *p=i;
	int acum=0;
	while(p!=NULL){
		inv=new Nodo();
		inv->info=p->info;
		inv->sig=i;
		i=inv;
		p=p->sig;
		acum=acum+1;
	}
	int k=0;
	while(k<acum){
		Nodo *q=i;
		Nodo *r;
		while((q->sig)!=NULL){
			r=q;
			q=q->sig;
		}
		if(i==q){
			i=NULL;
		}else{
			r->sig=NULL;
		}
		delete(q);
		k=k+1;
	}
}

void Lista::recorrer(){
	Nodo *p=i;
	while(p!=NULL){
		cout<<p->info;
		p=p->sig;
		if(p==NULL){
			break;
		}else{
			cout<<" -> ";
		}
	}
	cout<<endl;
}

int main(){
	Lista l=Lista();
	
	cout<<"---- Crear lista enlazada ---- \n\n";
	l.crear();
	
	cout<<"\nLista: \n";
    l.recorrer();
	
	l.invertir();
	
	cout<<"\nLista invertida: \n";
	l.recorrer();
	
	getch();
	return 0;
}

