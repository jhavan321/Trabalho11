#include <stdio.h>
#include "bibliotecas/telas.h"

void main(){
int opcao;
struct filme f;

do {

opcao = home();
switch (opcao){
case 1: 
cadastrar(f);
break;
case 2:
editar(f);
break;
case 3: 
locar(f);
break;
case 4:
devolver(f);
break;
case 5:
break;
case 6:
break;
case 7:
break;
} 

}

while (opcao !=8);



}
