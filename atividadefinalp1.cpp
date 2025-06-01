#include <iostream>
#include <locale.h>

using namespace std;

struct Data
{
   int dia;
   int mes;
   int ano;	
};

class Contato
{
	private:
		string email;
		string nome;
		string telefone;
		Data dtnasc;
	public:
		Contato() {
            this->email = "";
            this->nome = "";
            this->telefone = "";
            this->dtnasc = {1, 1, 2000};
        }
		Contato(string email, string nome, string telefone, Data dtnasc){
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			this->dtnasc = dtnasc;
		}	
		void setEmail(string email){
			this->email = email;
		}
		void setNome(string nome){
			this->nome = nome;
		}
		void setTelefone(string tel){
			this->telefone = tel;
		}
		void setDtNasc(Data dtnasc){
			this->dtnasc = dtnasc;
		}
		string getNome(){
			return this->nome;
		}
		string getEmail(){
			return this->email;
		}
		string getTelefone(){
			return this->telefone;
		}
		Data getDtNasc(){
			return this->dtnasc;
		}
		int idade(){
		    Data hoje;
		    hoje.ano = 2025;
		    int idadeAtual = hoje.ano - dtnasc.ano; 
		    return idadeAtual;
		}
		
};

double mediaIdades(Contato contatos[], int tamanho){
	double media = 0;
	for(int i = 0; i < tamanho; i++){
		  media += contatos[i].idade();	
	}
	return media / tamanho;
}

int CalcularMaioresDeIdade(Contato contatos[]){
	int qtd = 0;
	for(int i = 0; i < 10; i++){
		if(contatos[i].idade() >= 18){
			qtd++;	
		}	
	}
	return qtd;
}

double CalcularaMaiorIdade(Contato contatos[]){
	int maiorIdade = contatos[0].idade();
	for (int i = 1; i < 10; i++) {
	    if (contatos[i].idade() > maiorIdade) {
	        maiorIdade = contatos[i].idade();
	    }
	}
	return maiorIdade;
}

string citacaoBibliografica(string nome) {
    string sobrenome = "";
    string primeirosNomes = "";

    int i = nome.length() - 1;
    while (i >= 0 && nome[i] != ' ') {
        sobrenome = nome[i] + sobrenome;
        i--;
    }

    if (i >= 0 && nome[i] == ' ') {
        i--;
    }

    primeirosNomes = nome.substr(0, i + 1);

    for (int j = 0; j < sobrenome.length(); j++) {
        sobrenome[j] = toupper(sobrenome[j]);
    }

    return sobrenome + ", " + primeirosNomes;
}

int main(int argc, char** argv)
{
	Contato contatos[10];

    // Entrada de dados
    for (int i = 0; i < 10; i++) {
        cout << "\nDigite os dados do contato " << (i + 1) << endl;

        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Email: ";
        getline(cin, email);

        cout << "Telefone: ";
        getline(cin, telefone);

        cout << "Data de nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;

        Data dataNasc;
        dataNasc.dia = dia;
        dataNasc.mes = mes;
        dataNasc.ano = ano;
        
        Contato c(email, nome, telefone, dataNasc);
        contatos[i] = c;
    }
    
    // Exibir dados
    double media = mediaIdades(contatos, 10);
    int quantidade = CalcularMaioresDeIdade(contatos);
    int maiorIdade = CalcularaMaiorIdade(contatos);
    
    cout << "\n--- Dados ---\n";
        cout << "Média das idades: " <<  media << endl;
        cout << "\nContatos com idade acima da média:\n";
		for (int i = 0; i < 10; i++) {
  			if (contatos[i].idade() > media) {
        	cout << contatos[i].getNome() << endl;
    		}
		}
        cout << "Quantidade de maiores de idade: " << quantidade << endl;
        cout << "\nContato(s) mais velho(s):\n";
		for (int i = 0; i < 10; i++) {
	    	if (contatos[i].idade() == maiorIdade) {
		        cout << "Nome: " << citacaoBibliografica(contatos[i].getNome()) << endl;
		        cout << "Email: " << contatos[i].getEmail() << endl;
		        cout << "Telefone: " << contatos[i].getTelefone() << endl;
		        cout << "Idade: " << contatos[i].idade() << " anos\n";
		        cout << "--------------------------\n";
	    	}
		}
        cout << "--------------------------\n";

    return 0;
}