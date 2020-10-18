#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;
class Locadora{
	public:
		string tipo_veiculo;
		bool seguro;   
		fstream arq_veiculo;                //declarando os métodos da classe mãe.

		ficha(){
		tipo_veiculo="carro";          //construtor inicializando os valores 
		seguro= true;
		}
		
		void set_tipo_veiculo(string tipo){
			tipo_veiculo=tipo;
		}                                            
		string get_tipo_veiculo(){
			return tipo_veiculo;
		}
		
	    void set_seguro(bool seg){
			seguro=seg;
		}                                              //metodos getters e setters
		bool get_seguro(){
			return seguro;
		}
		

	
};
class Esportivo : public Locadora{
	public:
		string tipo_esportivo; //conversível ou nao, 2 lugares ou mais...	
		int tempo;	
		string temp;
		int temp2;
		
		void set_tipo_esportivo(string esp){
			tipo_esportivo=esp;
		}                                                            //métodos da subclasse Esportivo
		string get_tipo_esportivo(){
			return tipo_esportivo;
		}
		
		void set_tempo(int time){
			tempo=time;
		}                                            
		int get_tempo(){
			return tempo;
		}
	
		void preco_esportivo(int tempo){
			cout<<"Quanto tempo voce deseja alugar o carro?\n";
			cin>>tempo;	
			cout<<"O aluguel custará: "<<750+tempo*100<<endl;		
		}
		
		
		void escrever(){
	    	arq_veiculo.open("arq_veiculo.txt", ios::out | ios::app);
			cout<<"Digite qual tipo de carro( conversivel ou nao ), e quanto tempo vai alugar"<<endl;
			cin >> temp >> temp2 ;
			
			set_tipo_esportivo(temp);  
			set_tempo(temp2);
			arq_veiculo<<"Esportivo "<<temp<<" "<<temp2;
			arq_veiculo.close();
		}
};

class Casual : public Locadora { 
	
	public:

		string tipo_casual; //conversível ou nao, 2 lugares ou mais...	
		int tempo;	
		string temp;
		int temp2;
		
		void set_tipo_casual(string cas){
			tipo_casual=cas;
		}                                                            //métodos da subclasse Casual
		string get_tipo_casual(){
			return tipo_casual;
		}
		
		void set_tempo(int time){
			tempo=time;
		}                                            
		int get_tempo(){
			return tempo;
		}
	
		void preco_casual(int tempo){
			cout<<"Quanto tempo voce deseja alugar o carro?\n";
			cin>>tempo;
			cout<<"O aluguel custará: "<<500+tempo*80<<endl;
		}
		
		
		void escrever(){
	    	arq_veiculo.open("arq_veiculo.txt", ios::out | ios::app);
			cout<<"Digite qual tipo de carro (conversivel ou normal), e quanto tempo vai alugar"<<endl;
			cin >> temp >> temp2 ;
			
			set_tipo_casual(temp);  
			set_tempo(temp2);
			arq_veiculo<<"Casual "<<temp<<" "<<temp2;
			arq_veiculo.close();
		}
};

int main(){
	
	string tipo_veiculo;
	bool seguro;   
	fstream arq_veiculo;
	string tipo_casual; 	
	int tempo;	
	string temp;
	int temp2;
	int taxa_casual=500;
	int taxa_esportivo=750;
	
	Esportivo esp;  //Objeto para a classe Esportivo
	
	Casual cas;  //Objeto para a classe Casual
	
	int menu;
	
	cout<<"\t\t ********************************\n";
	cout<<endl;
	cout<<"\t\t       LOCADORA DE CARROS\n";
	cout<<endl;
	cout<<"\t\t ********************************\n\n\n";
	
	while(4){
		
		// Menu para controle do programa.
		
		cout << "\t\t 1- Calcular o preco do aluguel de um veiculo." << endl;
		cout << "\t\t 2- Alugar um carro." << endl;
		cout << "\t\t 3- Devolver um carro." << endl;
		cout << "\t\t 4- Sair." << endl;
		
		cin >> menu;
		
		switch(menu){
			
			case 1:{
				
				system("cls");
				
				cout << "Digite o tipo de veiculo que voce deseja alugar (casual ou esportivo):" << endl;
				cin >> tipo_veiculo;
				
				if(tipo_veiculo == "casual"){
					cas.preco_casual(tempo);
				}
				
				else if(tipo_veiculo == "esportivo"){
					esp.preco_esportivo(tempo);
				}
				
				break;
			}
			
			case 2:{
				
				system("cls");
				
				cout << "Digite o tipo de veiculo que voce deseja alugar (casual ou esportivo):" << endl;
				cin >> tipo_veiculo;
				
				if(tipo_veiculo == "casual"){
					
					cas.escrever();
					cout<<"Casual "<< temp <<" esta alugado!!"<<endl;	
				}
				
				else if(tipo_veiculo == "esportivo"){
					
					esp.escrever();
					cout<<"Esportivo "<<temp<<" esta alugado!!"<<endl;	
					
				}
				
				break;
				
				break;
			}
			case 3:{
				
				system("cls");
				
				cout << "Digite o tipo de veiculo que voce deseja devolver (casual ou esportivo):" << endl;
				cin >> tipo_veiculo;
				
				break;
			}			
			
			case 4:{
				exit(4);
				break;
			}
			
		
		
		}
			
			
			
	}
	
	
}

















