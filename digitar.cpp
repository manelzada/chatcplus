#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main(){
 setlocale(LC_ALL, "portuguese");
  char nick[16];  //guarda o nome de usuário
  char texto[256]; //guarda o texto 

  cout<<"Manel Chat 0.1 \n\n";
  cout<<"Digite um nome de usuário!\n"; //solicita um nome de usuário
    cin.getline(nick,16);  //salva o nick com no maximo 16 caracteres
    
  system("cls"); //limpa a tela
  
  ofstream log("chat.dll",ios::app); //abre o arquivo no final e sem apagar conteudo
  log<<endl<<nick<<" Entrou na sala..";//escreve no log que o usuario entrou na sala
  log.close(); //fecha o log
  
  do{
   // _flushall(); //limpeza
    system("cls");//limpa a tela
    gets(texto);//salva o texto que sera enviado
    log.open("chat.dll", ios::app); //abre o arquivo no final e sem apagar o conteudo
    log<<endl<<nick<<">> "<<texto;//escreve o nick, os ''>>'' e o texto salvo 
    log.close();//fecha o arquivo
  }while(strcmp(texto,"exit"));//executa o laço ate que o usuario digite ''exit''
  //log.open("chat.dll",ios::app);//abre o arquivo
  //log<<nick<<"\nsaiu da sala..";//escreve o nick e informa que saiu da sala
  log.close();//fecha o arquivo
    return 0; //retorno
}
