#include<bits/stdc++.h>
#include <fstream>
#include "include\jagpdf\api.h"

using namespace std;
using namespace jag;
int main(){
    FILE *arq = fopen("cabecalho.txt", "a+");
    FILE *arq1 = fopen("dataset.txt", "a+");

    int operacao=0;

		printf("|-----------------------------------------------------|\n");
		printf("|                    MENU DE OPCOES                   |\n");
		printf("|-----------------------------------------------------|\n");
		printf("|--- 1 - IMPRIMIR RELATORIO DE ERROS NO TERMINAL. ----|\n");
		printf("|--- 2 - GERAR PDF DE RELATORIO DE ERROS. ------------|\n");
		printf("|--- QUALQUER NUMERO DIFERENTE PARA SAIR. ------------|\n");
		printf("|-----------------------------------------------------|\n");
                cout << endl;
				cout << "- Insira a sua OPCAO: ";
				cin >> operacao;
				if (operacao <=0 || operacao >2){
                    printf("---------------- PROGRAMA ENCERRADO! ----------------\n");
				}
                //************************* COPIA ARQUIVO ******************************
				ifstream ifs("dataset.dat");
                ofstream ofs("dataset.txt", ios::trunc);
                string data;
                while(!ifs.fail()){
                    getline(ifs, data);
                    ofs << data <<endl;
                }
                    ifs.close();
                //**********************************************************************
				if(operacao ==1 ){
                    char h;
                    cout << endl;
                    while((h=getc(arq1)) != EOF){
						  printf("%c", h);
                    }
                    cout << "----------- PROGRAMA ENCERRADO! -----------"<< endl;
				}
				else if(operacao==2){
					  char c,d[100],a[3000];
					  string e;
					  //LIMPA VETOR
					  int i=0, t=1000, j=0, tf=0;
                        for (int k=0; k<=100; ++k){
                            d[k] = '\0';
                        }
                        pdf::Document doc(pdf::create_file("LogErro.pdf"));
                        doc.page_start(597.6, 1000);//TAMANHO DA PÁGINA
                      cout << endl;
					  while((c=getc(arq)) != EOF){
						    d[i]=c;

							//printf("%c", c);


                            if(d[i]=='\n'){
                                d[i]=' ';

                                if(t!=0){
                                    t-=12;
                                    doc.page().canvas().text_start(50,t);
                                    doc.page().canvas().text(d);
                                    doc.page().canvas().text_translate_line(0,-15);
                                    doc.page().canvas().text_end();
                                    while(j<=i){
                                        d[j]=' ';
                                        j++;
                                    }
                                    i=0;j=0;
                                }

                            }
                            i++;
						}
						i=0;
						j=0;

						//t=tf;
						while((c=getc(arq1)) != EOF){
						    d[i]=c;

							//printf("%c", c);

                            if(d[i]=='\n'){
                                d[i]=' ';

                                if(t!=0){
                                    t-=12;
                                    doc.page().canvas().text_start(50,t);

                                    doc.page().canvas().text(d);
                                    doc.page().canvas().text_translate_line(0,-15);
                                    doc.page().canvas().text_end();
                                    while(j<=i){
                                        d[j]=' ';
                                        j++;
                                    }
                                    i=0;j=0;
                                }

                            }
                            i++;
						}

                        doc.page_end();
                        doc.finalize();

                        fclose(arq);
                cout << "***************************************************"<<endl;
                cout << "*--> PDF DE RELATORIO DE ERROS GERADO COM SUCESSO!*"<< endl;
                cout << "***************************************************"<<endl<< endl;

                cout << "ARQUIVO: LogErro.pdf"<<endl<<endl;
                cout << "----------- PROGRAMA ENCERRADO! -----------"<< endl;
				}

	return 0;
}
