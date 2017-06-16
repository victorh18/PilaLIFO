/*
 * Este programa muestra la estructura de una pila LIFO, Last In First Out, los objetos que se 
 * introducen deben ser sacados en orden inverso
 * */
 
 //Para poder leer y escribir en consola
 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 
 //Nuestra estructura, o tipo de datos que queremos usar en la pila, puede tener cualquier atributo
 typedef struct {
	struct libro* anterior;			//Este puntero va a hacer referencia al espacio en memoria del objeto que fue introducido anterior al mismo
	char* nombre;					//Atributo
	char* autor;					//Atributo
	char* editora;
	char* fecha;
	char* categoria;
	
	
} libro;

libro* ultimo = NULL;				//Inicializacion de la variable
libro* ultimoUltimo = NULL;

//Este metodo nos permite agregar elementos a la pila
void agregar(libro* _libro){		//Pasamos un parametro puntero del libro
	_libro -> anterior = NULL;		//-> es como representamos las propiedades de un struc, inicializamos el anterior para evitar errores
	//Si la pila esta vacia, el elemento que agreguemos sera el primero y ultimo
	if(ultimo == NULL){
		ultimo = _libro;			//Asignamos nuestro primer elemento como ultimo
	} else {
		//Si existen ya varios libros, determinamos que el ultimo pasara a ser el anterior del nuevo, y ahora el nuevo sera el ultimo
		_libro -> anterior = ultimo;
		ultimo = _libro;
	}
	
}

//Este metodo nos permitira obtener el libro a sacar en un determinado momento
libro* extraer(){
	if(ultimo == NULL){
		return NULL;
	}
	//Seteamos la variable que vamos a devolver. Esto no setea el puntero de ultimo a libro_retorno, porque no he especificado & para que me devuelva el puntero de ultimo
	//Como ambos son punteros, y lo que devuelve la consulta del puntero es la posicion en memoria de otra variable, cuando igualo dos punteros, lo que sucede es que la direccion en memoria de la variable 
	//que se le asigno al de la derecha pasa al de la izquierda. La posicion en memoria que estaba EN ultimo se guarda en libro_retorno, no la posicion en memoria DE ultimo. 
	libro* libro_retorno = ultimo;	
	ultimo = libro_retorno -> anterior;	//Aqui determinamos que el ultimo de la pila es ahora el anterior al que acabamos de sacar.
	return libro_retorno;				//Devolvemos el libro.
}

//Ejecucion del programa
int main(){
	
	
	int agregarOtro = 1;
	int contador = 0;
	int opcion = 0;
	char* b = 0;
	//char* categoriaTempB = malloc(sizeof(char));
	
	//Iterador de las opciones
	while (opcion != 5){
		switch (opcion){
			//Lsitar los libros
			case 1:
				printf("Los libros en la coleccion son:\n");
				break;
			//Introduce libros
			case 2:
				while(agregarOtro == 1){
				char* nombreTemp = malloc(sizeof(char));
				char* autorTemp = malloc(sizeof(char));
				char* editoraTemp = malloc(sizeof(char));
				char* fechaTemp = malloc(sizeof(char));
				char* categoriaTemp = malloc(sizeof(char));


				libro* uno = malloc(sizeof(libro));

				printf("Introduzca el nombre del libro:\n");
				//Este regular expression me permite tomar todos los caracteres, exceptuando el salto de linea
				//El espacio del inicio ignora el salto de linea anterior al mismo
				scanf(" %99[0-9a-zA-Z ]s", nombreTemp);
				uno->nombre=nombreTemp;

				//Nombre del autor
				printf("Introduzca su autor:\n");
				scanf(" %99[0-9a-zA-Z ]s", autorTemp);
				uno->autor = autorTemp;
				
				printf("Introduzca la editora del libro:\n");
				scanf(" %99[0-9a-zA-Z ]s", editoraTemp);
				uno->editora = editoraTemp;
				
				printf("Introduzca la fecha de publicacion:\n");
				scanf(" %99[0-9a-zA-Z ]s", fechaTemp);
				uno->fecha = fechaTemp;
				
				printf("Introduzca su categoria:\n");
				scanf(" %99[0-9a-zA-Z ]s", categoriaTemp);
				uno->categoria = categoriaTemp;
				
				
				agregar(uno);

				printf("Desea agregar otro? 0/1:");
				scanf("%i", &agregarOtro);
				}
				break;
				
			//Mostrar el ultimo libro
			case 3:
				printf("El ultimo libro de la pila es:\n");
				libro* i = extraer();
				printf("Titulo: %s\n", i->nombre);
				printf("Autor: %s\n", i->autor);
				printf("Editora: %s\n", i->editora);
				printf("Fecha: %s\n", i->fecha);
				printf("Categoria: %s\n", i->categoria);
				break;
			//Buscar libro
			case 4:
				
				printf("Introduzca la categoria a buscar:\n");
				scanf("%s", b);
				
				libro* k = extraer();
	
				while (k != NULL){
					if(k -> categoria != *b){
						printf("Se ha removido el libro: %s, no cumple con el criterio de busqueda", k->categoria);
						k = extraer();
					} else {
					printf("Se ha removido el libro: %s, cumple con el criterio de busqueda");
					k = NULL;
					}
					system("pause");
				}
				break;
				
			//Salir
			case 5:
				printf("Decidiste salir del programa\n");
				system("pause");
				break;
			default:
				break;
		}
		
		//Para seleccionar la opcion
		printf("Seleccione una opcion del menu:\n");
		printf("1 - Listar productos\n");
		printf("2 - Aniadir productos\n");
		printf("3 - Solicitar ultimo libro\n");
		printf("4 - Buscar libro por categoria\n");
		printf("5 - Salir del programa\n");
		scanf("%i", &opcion);
		
	}
	
	
	
	/*//Forma dinamica
	printf("Bienvenido al programa de registro de libros\n");
	//Esto podria ser metido en un metodo, dejando los malloc en el main, but whatever
	while(agregarOtro == 1){
		char* nombreTemp = malloc(sizeof(char));;
		char* autorTemp = malloc(sizeof(char));
		char* editoraTemp = malloc(sizeof(char));;
		char* fechaTemp = malloc(sizeof(char));
		char* categoriaTemp = malloc(sizeof(char));;


		libro* uno = malloc(sizeof(libro));

		printf("Introduzca el nombre del libro:\n");
		//Este regular expression me permite tomar todos los caracteres, exceptuando el salto de linea
		//El espacio del inicio ignora el salto de linea anterior al mismo
		scanf(" %99[0-9a-zA-Z ]s", nombreTemp);
		uno->nombre=nombreTemp;

		//Nombre del autor
		printf("Introduzca su autor:\n");
		scanf(" %99[0-9a-zA-Z ]s", autorTemp);
		uno->autor = autorTemp;
		
		printf("Introduzca la editora del libro:\n");
		scanf(" %99[0-9a-zA-Z ]s", editoraTemp);
		uno->editora = editoraTemp;
		
		printf("Introduzca la fecha de publicacion:\n");
		scanf(" %99[0-9a-zA-Z ]s", fechaTemp);
		uno->fecha = fechaTemp;
		
		printf("Introduzca su categoria:\n");
		scanf(" %99[0-9a-zA-Z ]s", fechaTemp);
		uno->categoria = categoriaTemp;
		
		
		agregar(uno);

		printf("Desea agregar otro? 0/1:");
		scanf("%i", &agregarOtro);
	}*/
	
	//Forma estatica
	/*libro* uno = malloc(sizeof(libro));
	uno->autor="Fiodor Dostoyevski";
	uno->nombre="El jugador";
	
	libro* dos = malloc(sizeof(libro));
	dos->autor="Truman Capote";
	dos->nombre="A sangre fria";
	
	libro* tres = malloc(sizeof(libro));
	tres->autor="Aldous Huxley";
	tres->nombre="Un mundo feliz";
	
	libro* cuatro = malloc(sizeof(libro));
	cuatro->autor="Thomas Mann";
	cuatro->nombre="La montana magica";*/
	
	//"Agregamos" los libros, porque no los estamos agregando a un array como se suele pensar, sino que los creamos y controlamos los espacios en memoria
	/*agregar(uno);
	agregar(dos);
	agregar(tres);
	agregar(cuatro);*/
	
	//Mostramos los libros
	//printf("Vamos a mostrar\n");
	
	/*libro* i = extraer();
	
	while(i != NULL){
		printf("%s, de %s\n", i->nombre, i->autor);
		i = extraer();
		
	}*/
	
	return 0;
}