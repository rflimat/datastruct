#include<iostream>
using namespace std;

class Termino{
	public:
		int coef;
		int exp;
		Termino *sig;
	public:
		Termino();
		friend class Polinomio;
};

Termino::Termino(){
	sig=NULL;
}

class Polinomio{
	public:
		Termino *pol;
		int cant;
	public:
		Polinomio();
		void crear();
		void insertar(int,int);
		void eliminar();
		void mostrar();
};

Polinomio::Polinomio(){
	pol=NULL;
}

void Polinomio::crear(){
	cout<<"Ingrese cantidad de exponentes: ";
	cin>>cant;
	int coef,exp;
	for(int i=1;i<=cant;i++){
		Termino *t=new Termino();
		cout<<"Ingrese el coeficiente: ";
		cin>>coef;
		cout<<"Ingrese el exponente: ";
		cin>>exp;
		t->coef=coef;
		t->exp=exp;
		t->sig=pol;
		pol=t;
	}
}

void Polinomio::insertar(int coef,int exp){
	Termino *t=new Termino();
	t->coef=coef;
	t->exp=exp;
	t->sig=pol;
	pol=t;
}

void Polinomio::eliminar(){
	while(pol!=NULL){
		Termino *q=pol;
		pol=q->sig;
		delete(q);
	}
}

void Polinomio::mostrar(){
	Termino *m=pol;
	
	if(m==NULL){
		cout<<0;
	}else{
		while(m!=NULL){
			if(m->exp==0){
				cout<<m->coef;
			}else if(m->exp==1){
				if(m->coef==1){
					cout<<"x";
				}else{
					cout<<m->coef<<"x";
				}
			}else{
				cout<<m->coef<<"x^"<<m->exp;
			}
			m=m->sig;
			if(m==NULL){
				break;
			}else{
				cout<<" + ";
			}
		}
	}
	cout<<endl;
}

//Funcion donde se divide los polinomios
void dividir(Polinomio p1,Polinomio p2){
	Polinomio coc,res;
	Termino *pol1=p1.pol;
	Termino *pol2=p2.pol;
	int coef,exp,difcoef;
	int cen=p2.cant;
	
	int i=0;
	while(i<cen){
		//Avanzar a otro termino del polinomio si i>0
		if(i>0){
			int k=0;
			while(k<cen){
				pol1=pol1->sig;
				k=k+1;
			}
		}
		
		//Se divide dos terminos y se inserta en la lista polinomio coc(cociente)
		coef=(pol1->coef)/(pol2->coef);
		exp=(pol1->exp)-(pol2->exp);
		coc.insertar(coef,exp);
		
		Termino *n=p1.pol;
		Termino *m=p2.pol;
		
		int j=0;
		while(j<cen){
			//Se multiplica dos terminos para restar con los terminos
			//de divididendo 
			coef=(coc.pol->coef)*(m->coef);
			exp=(coc.pol->exp)+(m->exp);
			
			if(i==0){
				difcoef=n->coef-coef;
			}else if((i==cen-1)&&(j==cen-1)){
				difcoef=pol1->coef-coef;
			}else{
				difcoef=res.pol->coef-coef;
				res.pol=res.pol->sig;
			}
			
			//Si la diferencia entre dos terminos no es igual a 0
			//se inserta en la lista polinomio llamado res (residuo)
			if(difcoef!=0){
				res.insertar(difcoef,exp);	
			}
			
			m=m->sig;
			n=n->sig;
			j=j+1;
		}
		
		pol2=pol2->sig;
		i=i+1;	
	}
	
	cout<<"\nCociente: ";
	coc.mostrar();
	cout<<"\nResiduo: ";
	res.mostrar();
}

int main(){
	Polinomio p1=Polinomio();
	Polinomio p2=Polinomio();
	
	//Dividir como sugerencia este polinomio 8x^2+16x+6/2x+3
	
	//Ingresar los polinomios en este orden 6+16x+8x^2
	cout<<"-----Division de polinomios-----"<<endl;
	cout<<"\nIngresar polinomio 1 (Dividendo)\n";
	p1.crear();
	cout<<"Resultado polinomio 1: ";
	p1.mostrar();
	
	cout<<"\nIngresar polinomio 2 (Divisor)\n";
	p2.crear();
	cout<<"Resultado polinomio 2: ";
	p2.mostrar();

	dividir(p1,p2);

	return 0;
}



