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
} libro;

libro* ultimo = NULL;				//Inicializacion de la variable

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
	//Forma dinamica
	printf("Bienvenido al programa de registro de libros\n");
	//Esto podria ser metido en un metodo, dejando los malloc en el main, but whatever
	while(agregarOtro == 1){
		char* nombreTemp = malloc(sizeof(char));;
		char* autorTemp = malloc(sizeof(char));

		libro* uno = malloc(sizeof(libro));

		printf("Introduzca un libro:\n");
		//Este regular expression me permite tomar todos los caracteres, exceptuando el salto de linea
		//El espacio del inicio ignora el salto de linea anterior al mismo
		scanf(" %99[0-9a-zA-Z ]s", nombreTemp);
		uno->nombre=nombreTemp;

		printf("Introduzca su autor:\n");
		scanf(" %99[0-9a-zA-Z ]s", autorTemp);
		uno->autor = autorTemp;
		
		agregar(uno);

		printf("Desea agregar otro? 0/1:");
		scanf("%i", &agregarOtro);
	}
	
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
	printf("Vamos a mostrar\n");
	
	libro* i = extraer();
	
	while(i != NULL){
		printf("%s, de %s\n", i->nombre, i->autor);
		i = extraer();
		
	}
	
	return 0;
}