#include<iostream>
using namespace std;

class Nodo{
	private:
		int num;
		Nodo *sig;
	public:
		Nodo();
		Nodo *get_sig();
		int get_num();
		friend class Lista;
};

Nodo::Nodo(){
    sig=NULL;
}

Nodo *Nodo::get_sig(){
	return sig;
}

int Nodo::get_num(){
	return num;
}

class Lista{
	public:
		Nodo *i;
	public:
		Lista();
		void crear();
		void insertar(int);
		int contar();
		void ordenar();
		void recorrer();
};

Lista::Lista(){
	i=NULL;
}

void Lista::crear(){
	Nodo *p,*r;
	int num;
	char op;
	i=new Nodo();
	cout<<"\nIngrese un dato: ";
	cin>>num;
	i->num=num;
	cout<<"Desea continuar (s/n): ";
    cin>>op;
	while(op=='s'){
		cout<<"Ingrese un dato: ";
		cin>>num;
		p=new Nodo();
		p->num=num;
		if (i==NULL){
			i=p;
		}else{
			r=i;
			while((r->sig)!=NULL){
				r=r->sig;
			}
			r->sig=p;
		}
		cout<<"Desea continuar (s/n): ";
    	cin>>op;
	}
}

void Lista::insertar(int num){
	Nodo *p=new Nodo();
	Nodo *r;
	p->num=num;
	if (i==NULL){
		i=p;
	}else{
		r=i;
		while((r->sig)!=NULL){
			r=r->sig;
		}
		r->sig=p;
	}
}

int Lista::contar(){
	Nodo *p=i;
	int cen=0;
	while(p!=NULL){
		cen=cen+1;
		p=p->sig;
		if(p==NULL){
			break;
		}
	}
	return cen;
}

void Lista::recorrer(){
	Nodo *p=i;
	while(p!=NULL){
		cout<<p->num;
		p=p->sig;
		if(p==NULL){
			break;
		}else{
			cout<<" -> ";
		}
	}
	cout<<endl;
}

//Metodos para ordenamiento mergesort
Lista *merge(Lista *l1,Lista *l2){
	Lista *ord=new Lista();
    Nodo *np=l1->i;
	Nodo *nu=l2->i;
	
    while((np!=NULL)&&(nu!=NULL)){
        if(np->get_num()<nu->get_num()){
            ord->insertar(np->get_num());
            np=np->get_sig();
        }
        else{
            ord->insertar(nu->get_num());
            nu=nu->get_sig();
        }
    }

    while(np!=NULL){
    	ord->insertar(np->get_num());
        np=np->get_sig();
    }

    while(nu!=NULL){
    	ord->insertar(nu->get_num());
        nu=nu->get_sig();
    }
	
	return ord;
}

Lista *get_lista1(Lista *l){
	Lista *newlista=new Lista();
	Nodo *q=l->i;
	
	int len=l->contar();
	int medio;
	
	if(len%2==0){
		medio=len/2;
	}else{
		medio=(len/2)+1;
	}
	
	while(medio>0){
		newlista->insertar(q->get_num());
		q=q->get_sig();
		medio=medio-1;
	}
	
	return newlista;
}

Lista *get_lista2(Lista *l){
	Lista *newlista=new Lista();
	Nodo *q=l->i;
	
	int len=l->contar();
	int medio;
	
	if(len%2==0){
		medio=len/2;
	}else{
		medio=(len/2)+1;
	}
	
	while(medio>0){
		q=q->get_sig();
		medio=medio-1;
	}
	
	while(q!=NULL){
		newlista->insertar(q->get_num());
		q=q->get_sig();
	}
	
	return newlista;
}

Lista *mergeSort(Lista *l){
	Lista *l1, *l2, *lord, *lord1, *lord2;
    if(l->contar()<=1){
    	return l;
	}else{
		l1=get_lista1(l);
		l2=get_lista2(l);
		lord1=mergeSort(l1);
		lord2=mergeSort(l2);
	    lord=merge(lord1,lord2);
	    return lord;
	}
}

void Lista::ordenar(){
	Lista *nl=new Lista();
	nl=mergeSort(this);
	nl->recorrer();
}

int main(){
	Lista lista=Lista();
	
	cout<<"---- Crear lista enlazada ---- \n";
	lista.crear();
	
	cout<<"\nLista: \n";
    lista.recorrer();
	
	cout<<"\nLista ordenada: \n";
	lista.ordenar();
	
	return 0;
}

