#include <iostream>
#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
  int n=0;  //salva o numero de linhas no arquivo
  char linha[256]; //salva o conteudo de uma linha
  ifstream arquivo;//o arquivo para entrada dos dados
  int controle=0;//salva o numero de linha exibidas pelo programa

  arquivo.open("chat.dll"); //abre o log
  arquivo.clear();//limpa os sinalizadores do arquivo
  arquivo.seekg(0, ios::beg);//direciona o carro para o inicio do arquivo
//----
  while(!arquivo.eof()){
    arquivo.getline(linha,sizeof(linha)); //Conta o numero de linhas
    n++;
  }
//---
  controle=n; //iguala o controle com o numero de linhas do arquivo para nao exibir o
              //conteudo do arquivo antes da rotina principal ser executada

  for(;;){//um laço infinito, equivale ao while true
    arquivo.open("chat.dll");//abre o arquivo
    n=0;//leva o contador de linha para zero
    arquivo.clear();//limpa os sinalizadores
    arquivo.seekg(0, ios::beg);//leva o carro para o inicio do arquivo
//***
    while(!arquivo.eof()){
      arquivo.getline(linha,sizeof(linha)); //Conta o numero de linhas no arquivo
      n++;      
    }
//***
    arquivo.clear();//limpa os sinalizadores do arquivo
    arquivo.seekg(0, ios::beg); //abre o arquivo do seu inicio
    if(n>controle){//compara o numero de linhas contadas com o numero de linhas exibidas
      for(int i=0; i<n; i++)
        arquivo.getline(linha,sizeof(linha));
      cout<<linha<<endl;//exibe mais uma linha
      controle++;//incrementa o controle de linhas exibidas
      arquivo.close();
    }
  Sleep(500);//pausa a execução para nao sobrecarregar o sistema
  }//final do laço infinito
  
  arquivo.close();//fecha o arquivo,(mas a execução nunca cheque aqui)
    return 0;//retorna
}
