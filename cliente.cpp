#include "excecoes.h"

using namespace std;

int main(){
    excecoes<double> EX; //A entrada eh do tipo double
    excecoes<char> EX2; //A entrada eh do tipo char
    excecoes<string> EX3; //A entrada eh do tipo string
    excecoes <int> EX5; //A entrada eh do tipo inteiro

	setlocale(LC_ALL, "Portuguese"); //Para aceitar acentuacao

	double result, numerador, denominador; //OPCAO 1
	double valorRaiz, raiz; //OPCAO 2
	string valorNum; //OPCAO 3
	string valorLetra; //OPCAO 4
	int dia, mes, ano; //OPCAO 5

	int opcao;

	do{
        textcolor(BLUE);
		printf("|-----------------------------------------------------|\n");
		printf("|                    MENU DE OPCOES                   |\n");
		printf("|-----------------------------------------------------|\n");
		printf("|--- 1 - Verificar o denominador de uma divisao. -----|\n"); //OK
		printf("|--- 2 - Verificar o numero de uma raiz quadrada. ----|\n");
		printf("|--- 3 - Verificar se eh um NUMERO. ------------------|\n"); //OK
		printf("|--- 4 - Verificar se eh uma LETRA. ------------------|\n");
		printf("|--- 5 - Verificar se eh uma DATA. -------------------|\n");
		printf("|--- 6 - Verificar Alocacao de Memoria----------------|\n");
		printf("|--- Qualquer numero diferente para sair. ------------|\n");
		printf("|-----------------------------------------------------|\n");
        textcolor(WHITE);

		printf("\n - Insira o NUMERO desejado: ");
		cin >> opcao;
		cout << endl; //Pula linha c++

		//***************************************************************************************
		if (opcao == 1){ //FUNCIONANDO
		    textcolor(MAGENTA);
            cout << "OPCAO ESCOLHIDA: Verificacao do denominador de uma divisao." <<endl;
            textcolor(WHITE);
            pulaLinha;
			cout<<"Insira o NUMERADOR: ";
		    cin>>numerador;
		    //cout << endl; //Pula linha c++
		    cout<<"Insira o DENOMINADOR: ";
		    cin>>denominador;

		    if(EX.isDivByZero(denominador)==true){
		        result = numerador/denominador;
		        pulaLinha;
				textcolor(GREEN);
		        cout<<"-> RESULTADO: "<< result << endl;
				textcolor(WHITE);
				//pulaLinha;
		    }
			pulaLinha;
			system("pause");
			system("cls");
		//***************************************************************************************
		}else if (opcao == 2){ //Ainda nao fiz
			textcolor(MAGENTA);
            cout << "OPCAO ESCOLHIDA: Verificacao do numero em uma RAIZ QUADRADA." <<endl;
            textcolor(WHITE);
            pulaLinha;
			cout<<"Insira o valor que deseja descobrir a RAIZ: ";
		    cin>>valorRaiz;
            pulaLinha;

		    if(EX.isNegativeSQR(valorRaiz)==true){
		        raiz = sqrt(valorRaiz);

				textcolor(GREEN);
		        cout<<"-> RESULTADO: "<< raiz << endl;
				textcolor(WHITE);
				pulaLinha;
		    }
		    system("pause");
			system("cls");
		//***************************************************************************************
		}else if (opcao == 3){	//FUNCIONANDO
			textcolor(MAGENTA);
            cout << "OPCAO ESCOLHIDA: Verificar se eh um NUMERO." <<endl;
            textcolor(WHITE);
            pulaLinha;
			cout << "Insira um NUMERO: ";
			fflush(stdin);
			getline(cin, valorNum);
            pulaLinha;

			if(EX3.isNumber(valorNum)==true){
				textcolor(GREEN);
		        cout<<"-> O dado inserido eh um NUMERO. "<< endl;
				textcolor(WHITE);
			}
			pulaLinha;
			system("pause");
			system("cls");
		//***************************************************************************************
		}else if (opcao == 4){	//FUNCIONANDO
			textcolor(MAGENTA);
			cout << "OPCAO ESCOLHIDA: Verificar se eh uma LETRA." <<endl;
			textcolor(WHITE);
            pulaLinha;

			cout << "Insira uma LETRA: ";
			fflush(stdin);
			getline(cin, valorLetra);
            pulaLinha;
			if(EX3.isWord(valorLetra)==true){
				textcolor(GREEN);
		        cout<<"-> O dado inserido eh uma LETRA. "<< endl;
				textcolor(WHITE);
				pulaLinha;
		    }
			system("pause");
			system("cls");
		//***************************************************************************************
		}else if (opcao == 5){
			textcolor(MAGENTA);
			cout << "OPCAO ESCOLHIDA: Verificar valores da DATA." <<endl;
			textcolor(WHITE);
            pulaLinha;
            textcolor(LIGHT_CYAN);
			cout << "-> Insira uma DATA: "<< endl;
			textcolor(WHITE);
			cout << "\t-Informe o DIA: ";
			cin >> dia;
			pulaLinha;
			cout << "\t-Informe o MES: ";
			cin >> mes;
			pulaLinha;
			cout << "\t-Informe o ANO: ";
			cin >> ano;
			pulaLinha;

			if (EX5.isDate(dia, mes, ano)==true){
				textcolor(GREEN);
		        cout<<"-> O dado inserido eh uma DATA. "<< endl;
				textcolor(WHITE);
				pulaLinha;
			}
        system("pause");
		system("cls");
		}
		else if (opcao == 6){
            int *ptr;
            ptr = (int*) malloc(100*sizeof(int));
            textcolor(MAGENTA);
			cout << "OPCAO ESCOLHIDA: Verificar ALOCACAO DE MEMORIA." <<endl;
			textcolor(WHITE);
			pulaLinha;
			textcolor(LIGHT_BLUE);
			cout << "Sabendo que o tamanho  de um numero inteiro eh 4 bytes."<< endl;
			textcolor(WHITE);
			pulaLinha;
			cout <<"- INSIRA O NUMERO DE BYTES QUE DESEJA RESERVAR: ";
			int bytes;
            cin >> bytes;
            ptr = &bytes;
            ptr = EX5.alocation(ptr);
            int totalbytes = bytes * 4;
			if (ptr == NULL);
			else{
                pulaLinha;
                textcolor(GREEN);
		        printf("-> MEMORIA ALOCADA COM SUCESSO. (%d bytes ALOCADOS)", totalbytes);
				textcolor(WHITE);
				pulaLinha;
                pulaLinha;
			}
        free(ptr);
        system("pause");
		system("cls");
		}


		//***************************************************************************************

	}while (opcao> 0 && opcao <=6);
	textcolor(LIGHT_RED);
    printf("---------------- PROGRAMA ENCERRADO! ----------------\n");
    textcolor(WHITE);

    return 0;
}
