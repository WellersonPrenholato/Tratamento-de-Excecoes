// BIBLIOTECAS UTILIZADAS NO PROGRAMA
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <math.h>
#include <locale.h>
#include <fstream>
#include <ctime>
#include <time.h>
#include <Windows.h>

#define pulaLinha cout <<endl;
#define ZERO 000000000000000000000
using namespace std;

//****************** ESTRUTURA REFERENTE AS CORES USADAS NO PROGRAMA *******************************
enum DOS_COLORS {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
	LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
	LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };

//-------------------------------------------------------------

void textcolor (DOS_COLORS iColor)
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

//************************************************************************************************

//PROTOTIPOS UTILIZADDOS PARA LEITURA E ESCRITA DE ARQUIVO
    bool escreveArquivo(ofstream&, char*);
	bool leArquivo (ifstream&, char*);

	bool status;
	//ofstream outFile;
	fstream outFile("dataset.dat",ios::in | ios::out | ios::app);

    //bool flagLe = leArquivo(inputFile, "dataset.dat");

	//bool flagEscreve = escreveArquivo(outFile, "dataset.dat");

  	//int codigoErro=1;

    //******************** METODO PARA ESCREVER DATA E HORA NO ARQUIVO .dat ********************
  	void escreveData (){
  		// DATA E TEMPO SAO BASEADOS NO SISTEMA
		   time_t now = time(0);
		   tm *ltm = localtime(&now);

		   outFile <<"Data: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon <<"/"<<1900 + ltm->tm_year<<endl;
		   outFile.precision(2);
		   outFile << "Horario: "<< ltm->tm_hour << ":";
		   outFile << ltm->tm_min << ":";
		   outFile << ltm->tm_sec << endl << endl;
	}
    //********************************************************************************************

	//METODO PARA VERIFICAR FORMATO DA DATA
	bool verificaData (string data){

	}

template <class T> class excecoes {

 public:
    class erro{ }; /*classe para referência na ocorrencia de erro. Utiliza-se construtor por ocultação*/
    void Mensagem(string msg); /*Permite passar por parâmetro qualquer mensagem e exibi-la para o usuário*/
    bool isDivByZero(T numero); /*retorna true se ocorreu uma tentativa de divisao por zero*/
    bool isNegativeSQR(T numero); /*retorna true se houver tentativa de raiz negativa */
    bool isNumber (T numero); /*retorna true se o valor valor passado possui apenas números */
    bool isWord (T palavra); /*retorna true se o valor valor passado possui apenas char */
    bool isDate (T dia, T mes, T ano); /*returna true se for uma data válida */
    T *alocation(T *ptr); /*Caso não ocorra um erro de alocação de memmória devolve um ponteriro alocado */
    //....demais métodos para tratamento de erros

 private:
    T item; /*Atributo privado que futuramente pode ser utilizado*/
};



template <class T> void excecoes<T>:: Mensagem(string msg) /*implementação do método mensagem */
{
      cout << msg << endl;
}
///////////////////////////////////////////////////////////////////
template <class T> bool excecoes<T>::isDivByZero(T numero){ /*implementação da verificação de tentativa de divisao por zero */
 try {
        if (numero==ZERO){
          throw (erro());
        }
        else{
            return true;
        }
     } // final do bloco TRY
     catch (excecoes::erro){
        textcolor(RED);
        Mensagem("\nERRO de Divisao por Zero! - (Erro Gravado no arquivo!)");
        textcolor(WHITE);
        //pulaLinha;
        outFile << "Opcao escolhida no MENU: 1" <<endl;
        outFile << "MENSAGEM: Erro de Divisao por ZERO!"<< endl; //Escreve no arquivo
        outFile << "DENOMINADOR INSERIDO: " << numero << endl;
        //outFile << "CODIGO DO ERRO: "<<codigoErro++<< endl;
		escreveData(); //Escreve Dia/Mes/Ano e Hora:Minuto:Segundo no arquivo.dat
		return false;
     }
}

//*********************************************************************************************
//****************************** CONTINUACAO DO CODIGO ****************************************
//*********************************************************************************************
template <class T> bool excecoes<T>::isNegativeSQR(T numero){ /*implementação da verificação de tentativa de divisao por zero */
 try {
        if (numero < (double)ZERO){
          throw (erro());
          //return true;
        }else{
            return true;
        }

     } // final do bloco TRY
     catch (excecoes::erro){
        textcolor(RED);
        Mensagem("\nERRO RAIZ NEGATIVA! - (Erro Gravado no arquivo!)");
        textcolor(WHITE);
        pulaLinha;
        outFile << "Opcao escolhida no MENU: 2" <<endl;
        outFile << "MENSAGEM: Erro RAIZ NEGATIVA!"<< endl; //Escreve no arquivo
        outFile << "RAIZ INSERIDA: " << numero << endl;
		escreveData(); //Escreve Dia/Mes/Ano e Hora:Minuto:Segundo no arquivo.dat
		return false;
     }
}

template <class T> bool excecoes<T>::isNumber (T numero){
	int cont=0;
	for (int i=0; i<numero.length(); ++i){
        if(numero[i]>=48 && numero[i]<=57){
            cont++;
        }
	}
	try{
		if (cont != numero.length()){
            throw (erro());
        }
        else if (cont == numero.length()){
            return true;
        }

    }catch (excecoes::erro){
        textcolor(RED);
        Mensagem("O dado inserido NAO eh NUMERO! - (Erro Gravado no arquivo!)");
        textcolor(WHITE);
        //pulaLinha;
        outFile << "Opcao escolhida no MENU: 3" <<endl;
        outFile << "MENSAGEM: A dado inserido NAO eh um NUMERO!"<< endl; //Escreve no arquivo
        outFile << "DADO INSERIDO: " << numero << endl;
        //outFile << "Codigo do Erro: "<<codigoErro++<< endl;
		escreveData(); //Escreve Dia/Mes/Ano e Hora:Minuto:Segundo no arquivo.dat
		return false;
    	}
}

template <class T> bool excecoes<T>::isWord (T numero){
	int cont=0;
	for (int i=0; i<numero.length(); ++i){
        if((numero[i]>=65 && numero[i]<=90)||(numero[i]>=97 && numero[i]<=122)){
            cont++;
        }
	}
	try{
		if (cont != numero.length()){
			throw (erro());
        }else
            return true;
    } // final do bloco TRY
     catch (excecoes::erro){
        textcolor(RED);
        Mensagem("O dado inserido NAO eh LETRA! - (Erro Gravado no arquivo!)");
        textcolor(WHITE);
        pulaLinha;
        //ESCREVE NO ARQUIVO
        outFile << "Opcao escolhida no MENU: 4" <<endl;
        outFile << "MENSAGEM: A dado inserido NAO eh uma LETRA!"<< endl; //Escreve no arquivo
        outFile << "DADO INSERIDO: " << numero << endl;
        //outFile << "CODIGO DE ERRO: "<<codigoErro++<< endl;
        escreveData(); //Escreve Dia/Mes/Ano e Hora:Minuto:Segundo no arquivo.dat
        return false;
    	}
}

template <class T> bool excecoes<T>::isDate (T dia, T mes, T ano){
	//int verifica=0;

	try
	{
	    if (mes>12){
            throw(erro());
            return false;
	    }else if((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || 12) && dia>31){
                    throw(erro());
                    return false;
	    }else if ((mes==4 || mes==6 || mes==9 || mes==11) && dia>30){
            throw(erro());
            return false;
	    }else if (mes==2 && dia>28){
            throw(erro());
            return false;
	    }else
            return true;
	}
    catch(excecoes::erro){
        textcolor(RED);
        Mensagem("A informacao inserida NAO eh uma DATA! - (Erro Gravado no arquivo!)");
        textcolor(WHITE);
        pulaLinha;
        outFile << "Opcao escolhida no MENU: 5" <<endl;
        outFile << "MENSAGEM: A informacao inserida NAO eh uma DATA!"<< endl; //Escreve no arquivo
        outFile << "DADOS INSERIDOS: " << dia <<"/"<< mes << "/"<< ano<< endl;
        //outFile << "CODIGO DE ERRO: "<<codigoErro++<< endl;
        escreveData(); //Escreve Dia/Mes/Ano e Hora:Minuto:Segundo no arquivo.dat
        return false;
    }
}

template <class T> T* excecoes<T>::alocation (T *ptr){

//ptr = (T*) malloc(10 *sizeof(T));
    try{
        if (ptr == NULL || *ptr == 0) throw(erro());

        else{
            ptr = new (nothrow) T;
            return ptr;
        }
    }catch(excecoes::erro){
        textcolor(RED);
        Mensagem("\nERRO ao ALOCAR MEMORIA (NAO FOI POSSIVEL FAZER A ALOCACAO)! - (Erro Gravado no arquivo!)");
        textcolor(WHITE);
        pulaLinha;
        outFile << "Opcao escolhida no MENU: 6" <<endl;
        outFile << "MENSAGEM: ERRO ao ALOCAR MEMORIA (NAO FOI POSSIVEL FAZER A ALOCACAO)!"<< endl; //Escreve no arquivo
        //outFile << "CODIGO DO ERRO: "<<codigoErro++<< endl;
		escreveData(); //Escreve Dia/Mes/Ano e Hora:Minuto:Segundo no arquivo.dat
        return NULL;
    }
}

// ******************* MANIPULACAO DE ARQUIVO ****************************
 bool escreveArquivo (ofstream& file, char* strFile){ //ESCREVE NO ARQUIVO
    file.open(strFile);
    return !(file.fail()||!file.is_open()||!file.good());
 }

 bool leArquivo (ifstream& ifile, char* strFile){	//L� O ARQUIVO
    ifile.open(strFile);
    return !(ifile.fail()||!ifile.is_open()||!ifile.good());
 }

//***************************************************************************

