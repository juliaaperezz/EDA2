# EDA2
enlace report pdf y video : https://drive.google.com/drive/folders/1Fk58uxIkzjp1jDN_Np_wIeDF1VPYzeDx?usp=sharing 





ESTRUCTURAS DE DATOS Y ALGORITMOS II, 2022-2023
BookTune








Isaac Monje, Dipti Nirola, Carla Núñez, Julia Pérez
U215084, U213918, U214970, U214026
08/06/2023




LISTA DE CONTENIDOS 
Introducción
Objetivos del proyecto
Objetivos obligatorios alcanzados
Objetivos deseable alcanzados
Objetivos exploratorios alcanzados
Solución
Arquitectura del sistema
Gestión de errores
Diseño del modelo de datos
Descripción y procesamiento del conjunto de datos
Referencias



INTRODUCCIÓN
En este proyecto se nos pedía construir e implementar en código C desde cero nuestra propia red social, para ello se ha tenido que crear una arquitectura del sistema para poder manejar y procesar todos los datos que necesitábamos, también se han tenido en cuenta los posibles errores.
Para decidir la temática de nuestra red social, simplemente pusimos en común las aficiones de los integrantes de este proyecto y acabamos decidiendo que sería relacionado con libros y música, ahí mismo se decidió que el nombre de la aplicación sería BookTune. 

Nuestra propuesta era crear un red social que sirviera para conocer gente con tus mismos gustos en cuanto a lectura y música.
En este proyecto se han alcanzado todos los objetivos obligatorios propuestos, además, se ha cumplido el objetivo deseable de que la app sea temática y finalmente también se ha desempeñado el objetivo exploratorio relacionado con cargar un archivo CSV y guardar los datos del los usuarios. 
OBJETIVOS DEL PROYECTO 
Nuestros objetivos: 
Crear una red social para la gente interesada en libros y música. 
Brindar un espacio seguro para compartir y recibir gustos sin sentirse juzgados

Para cumplir estos objetivos se utilizan las siguientes : 

Se ubican en el apartado main+menu: 

displayMenu : se encarga de imprimir un menú en la consola con diferentes opciones para interactuar con el programa.

operateAsUser : Se encarga de proporcionar un menú de opciones para que un usuario ya inscrito interactúe con la red social. Así permitiendo a los usuarios operar como un usuario de la red social y elegir lo que quieren hacer (enviar solicitud a alguien, hacer una publicación, ver las publicaciones, etc…). 

Para esta función las variables utilizadas son : 
username : variable tipo array de caracteres para almacenar el nombre de usuario.
user : un puntero a la estructura User
choice : variable entera utilizada para almacenar la opción seleccionada por el usuario


     

Estructura de datos : 
UserList
User
FriendList
FriendRequestList
 					
El algoritmo elegido para el objetivo de la función operateAsUser es un bucle  do-while con una estructura de control switch. El comportamiento esperado es permitir al usuario seleccionar opciones del menú y realizar acciones correspondientes, como enviar solicitudes de amistad, crear publicaciones, gestionar solicitudes de amistad, entre otras. El bucle se repite hasta que el usuario elija la opción para regresar al menú principal. Para esta función tardamos 1h y media. 

Mejoras : Utilizar funciones más seguras para leer la entrada del usuario después de utilizar scanf, como fgets, para evitar errores de entrada y permitir una mejor manipulación de los datos ingresados por el usuario.

Se ubican en el apartado de usuarios: 

insertUser : Esta función permite al usuario crear una cuenta en la red social proporcionando información como nombre de usuario, edad, correo electrónico, etc. 

Para esta función creamos una estructura de datos llamado User con las variables       
Este algoritmo permite al usuario ingresar los datos del nuevo usuario, verificando previamente si la lista de usuarios ha alcanzado su capacidad máxima (MAX_USERS). Además, realiza validaciones de la edad y el correo electrónico ingresados por el usuario. Luego, asigna memoria dinámica para las estructuras de datos de amigos y solicitudes de amistad del nuevo usuario. Los datos ingresados se almacenan en una estructura User y finalmente se agrega esa estructura a la lista de usuarios (UserList). Y tardamos aproximadamente 2h en hacer esta función. 

Limitaciones : no se verifica si el nombre de usuario ya existe en la lista, no se valida la longitud máxima de los campos y no se realizan otras validaciones más avanzadas.

Mejoras : No se manejan adecuadamente los errores de lectura de entrada. Por ejemplo, si el usuario ingresa más caracteres de los permitidos en un campo, el exceso de caracteres no se descarta y puede afectar la próxima lectura.

validateEmail : Esta función se utiliza para validar la dirección de correo electrónico ingresada por el usuario antes de agregarla a un objeto de usuario o realizar cualquier otra operación relacionada con el correo electrónico. Es un algoritmo básico donde solo mira si se ha utilizado ‘@’ y un ‘.’ después. Lo hicimos en 45 min. 

listAllUsers : Imprime todos los usuarios que están registrados en nuestra red social. Y eso lo hace a través de la estructura de datos UserList. 

Las variables utilizadas en son : 
list : Puntero a la estructura UserList, que contiene la lista de usuarios y su recuento.
i : Variable de iteración para recorrer la lista de usuarios.
		
El algoritmo utilizado es el MergeSort. Y se utiliza para ordenar la lista de usuarios por edad en orden ascendente. MergeSort es un algoritmo de ordenamiento eficiente que divide la lista en sub-listas más pequeñas, las ordena recursivamente y luego las combina para obtener una lista ordenada. Tardamos 2h en hacerlo. 

Limitaciones : El algoritmo MergeSort tiene una complejidad de tiempo de O(n log n), lo cual puede ser lento si la lista de usuarios es muy grande. Y no maneja casos especiales como usuarios con edades iguales. 

Mejoras : Utilizar una función de ordenamiento más eficiente, como QuickSort o HeapSort, si la lista es muy grande.

searchUser : Nos permite buscar usuarios por su nombre para poder seguirles y poder compartir los gustos literarios y musicales. 

Las variables utilizadas son : 
list: Es un puntero a la estructura UserList que contiene una lista de usuarios.
username: Es un puntero a una cadena de caracteres que representa el nombre de usuario a buscar.

	La estructura de datos utilizada en este caso es un array de usuarios (UserList) que 
almacena la información de los usuarios.
	
	El algoritmo utilizado es una búsqueda lineal en el array de usuarios. Se recorre 
cada elemento del array y se compara el nombre de usuario con el nombre pasado 
como argumento. Si se encuentra una coincidencia, se devuelve un puntero al 
usuario encontrado. Hemos tardado 1h en hacer esta función.

Limitaciones : Realiza una búsqueda secuencial en la lista de usuarios, lo que 
implica recorrer todos los elementos hasta encontrar una coincidencia. Esto puede 
ser ineficiente en casos donde la lista de usuarios es grande.

Mejoras : No considera la sensibilidad a mayúsculas y minúsculas al realizar la
 comparación de nombres de usuario. Esto significa que "John" y "john" se 
considerarían diferentes.

Cola para la sección de solicitudes

addFriend : Permite a los usuarios agregar amigos a otros usuarios cuyos gustos les interesen, creando conexiones y recomendaciones personalizadas.

Para esta función las variables utilizadas son : 
list : puntero a la lista de usuarios
user : usuario actual que envía la solicitud de amistad.
friendUsername : arreglo de caracteres que almacena el nombre de usuario del amigo a agregar.

	Y la siguiente estructura de datos (indirectamente de User) : 
	

El algoritmo de esta función solicita al usuario el nombre de usuario del amigo a agregar, busca al amigo en la lista de usuarios, verifica si el amigo existe y es diferente al usuario actual, verifica si ya existe una solicitud de amistad pendiente del usuario actual hacia el amigo, mira si el amigo ya está en la lista de amigos del usuario actual, agrega la solicitud de amistad del usuario actual al amigo y muestra un mensaje de éxito. En esta función tardamos 7h.

Limitaciones : Realiza una búsqueda secuencial en la lista de usuarios para encontrar al amigo solicitado. Esto puede ser ineficiente en casos donde la lista de usuarios es grande.

Mejoras : Utilizar una estructura de datos más eficiente para almacenar los usuarios, como un diccionario (hash table) o un árbol de búsqueda (binary search tree), lo que permitiría una búsqueda más rápida y eficiente del amigo solicitado.

handleFriendRequests : esta función maneja las solicitudes de amistad del usuario, donde verifica si el usuario actual tiene solicitudes de amistad pendientes mostrandolos, y permite al usuario aceptar o rechazar cada solicitud. 
	
	Las variables utilizadas son : 
requestQueue: Cola que almacena las solicitudes de amistad pendientes.
requestingUser: Usuario que envió la solicitud de amistad.
friend: Usuario solicitante de amistad en la lista de usuarios.
counter: Contador utilizado para eliminar correctamente la solicitud de amistad de la lista de solicitudes pendientes.
La estructura de dato utilizado es :  
     

Estructura de datos de cola implementada para almacenar las solicitudes de  amistad.


	El algoritmo recorre las solicitudes de amistad en orden y permite al usuario principal 
aceptar o rechazar cada solicitud. La cola asegura que las solicitudes se procesen 
en el orden en que fueron recibidas. Tardamos un día entero en hacerlo. 

Limitación : solo procesa una solicitud a la vez y no permite la aceptación o rechazo 
de múltiples solicitudes simultáneamente. 

Mejoras :  permitir que el usuario principal maneje múltiples solicitudes a la vez.

Usuarios via CSV

readUsersFromFile : Lee los datos de usuarios almacenados en un archivo CSV (usuarios.csv) y los carga en la estructura UserList.

Las variables utilizadas son : 
filename : Almacena el nombre del archivo CSV a leer.
file : Puntero al archivo CSV abierto.
line : Almacena cada línea del archivo CSV leída.
user : Almacena los datos de un usuario antes de agregarlo a la lista.

El algoritmo utilizado en la función readUsersFromFile : abre un archivo CSV, lee los 
datos de los usuarios almacenados en él y los carga en una estructura de lista de 
usuarios. Utiliza un bucle para leer cada línea del archivo, divide la línea en tokens 
utilizando la coma como delimitador y extrae los datos relevantes de cada token. 
Luego, reserva memoria y agrega el usuario a la lista. Al finalizar, cierra el archivo y 
muestra un mensaje de confirmación.

	Limitaciones : Si los datos no cumplen con el formato esperado, puede haber 
comportamientos inesperados.
Mejoras : Manejar adecuadamente los errores. Para esta función tardamos 8h.
Sección de solicitud sin usar Queue

addUnknownFriend : Esta función permite a un usuario enviar solicitud de amistad a 3 personas con sus gustos iguales para ampliar su lista de amistades.

Las variables que se utilizan son : 
availableUsers : es una matriz de punteros a usuarios que almacena los usuarios disponibles para añadir como amigos
common : cuenta la cantidad de preferencias en común entre el usuario actual y uno aleatorio. 
availableCount : cuenta los usuarios que son disponibles 
randomIndex : un índice donde se almacena 3 usuarios al azar que no estén en la lista de amigos del usuario actual
randomUser : un puntero a usuario que apunta al usuario aleatorio seleccionado.

	Las estructuras utilizadas son : 
UserList
User
FriendRequestList

	El algoritmo selecciona tres usuarios aleatorios que cumplan con los requisitos, 
(tener las máximas preferencias en común con el usuario, que no esté en la lista de 
solicitud de amistad y que no sean amigos) y los muestra. Si el usuario decide
agregarlos como amigos, se envía una solicitud de amistad. El proceso se repite 
hasta revisar los 3 usuarios aleatorios y finaliza. 
 
Limitaciones : Una limitación de este algoritmo es que solo se seleccionan sólo
tres usuarios aleatorios para mostrar como opciones de amistad. Y se dejan otras 
posibles amistades

Mejoras : ajustar el algoritmo para manejar esta situación y ofrecer alternativas
cuando no se cumplan todas las condiciones para los tres usuarios seleccionados. 
Para esta función tardamos 3h.


Se ubican en el apartado posts : 

createPost : Permite al usuario crear una publicación con sus gustos en libros y música, compartiendo información sobre los títulos de libros o canciones que le guste.

Para esta función las variables utilizadas son : 
post : esta variable almacena el contenido de la publicación hecho por el usuario. 
user : y se usa este puntero para acceder al usuario actual. 

	Esta función no utiliza una estructura de datos adicional. La publicación se almacena
           en el arreglo posts del usuario. 

El algoritmo comienza verificando si el usuario ha alcanzado el límite máximo de publicaciones. Si es así, muestra un mensaje de error y se detiene. Luego, solicita al 
usuario que ingrese el contenido de la publicación, lo guarda en la variable post,  elimina el carácter de nueva línea y lo copia en el arreglo de publicaciones del usuario. El contador de publicaciones se actualiza y se muestra un mensaje de éxito. Hicimos esta función en 2h. 

Limitaciones : No maneja casos en los que el usuario intente crear un post vacío o 
con contenido no válido.

Mejoras : Utilizar una estructura de datos más eficiente para almacenar los posts del usuario, como una lista enlazada o un árbol de búsqueda. Esto permitiría una  gestión más eficiente de los posts y facilitaría operaciones como la inserción, eliminación y búsqueda.

listUserPosts : Permite a los usuarios ver todos los posts que él mismo ha hecho en la consola.

La variable utilizada para esta función és user : puntero al usuario cuyas publicaciones se van a listar. Y no utiliza ninguna estructura de datos adicionales. 

El algoritmo verifica si el usuario tiene publicaciones, y si no tiene, muestra un mensaje indicando que el usuario no tiene publicaciones. En cambio, sí hay publicaciones, entonces itera a través del arreglo de posts del usuario e imprime cada post en la consola. Y para codificar esto tardamos 2h también. 

Mejoras : Poder ver la fecha en el que se realizó el posteo. 

listAllUsersPosts : se encarga de listar las publicaciones de todos los usuarios registrados en la red social.

La variable utilizada es : 
list: Puntero a la estructura UserList que contiene la lista de usuarios registrados.

	La estructura de datos utilizado es : UserList

El algoritmo de esta función verifica si la lista de usuarios está vacía. Si no hay usuarios registrados, se muestra un mensaje de "No users found" y se retorna. Si hay usuarios registrados, se muestra el encabezado "=== ALL USERS' POSTS ===". Luego, se itera sobre cada usuario en la lista y se muestra su nombre de usuario. Para cada usuario, se llama a la función listUserPosts para listar sus publicaciones. Después de listar las publicaciones de un usuario, se pasa al siguiente usuario en la lista. Al final, se muestra un separador. Tardamos 1h para hacerlo. 

Limitaciones : El algoritmo puede volverse ineficiente y difícil de leer si hay muchos usuarios con muchas publicaciones, por lo que es más seguro implementar la limitación en la cantidad de publicaciones mostradas por usuario para mejorar la legibilidad.

Mejoras : Permitir a los usuarios una búsqueda para encontrar publicaciones específicas de usuarios específicos. 

Se ubican en el apartado stack_strangers : 

Esta sección del código implementa un stack (pila) utilizando una lista enlazada.

createStack : Función para crear un nuevo stack vacío

isEmpty : Función para verificar si el stack está vacío

push : Función para agregar un elemento al stack

pop : Función para sacar un elemento del stack

connectWithStrangers : Permite a un usuario enviar solicitud de amistad a 3 personas aleatorios para ampliar su lista de contactos.

Las variables utilizadas son : 
numStrangers: Almacena el número de usuarios aleatorios encontrados que cumplen con los criterios.
strangers: Arreglo de punteros a usuarios que representan las personas aleatorias encontradas.
stack: Pila que se utiliza para almacenar las personas aleatorias.
	

Las estructuras de datos son : 
		
Una estructura de datos tipo pila implementada como una lista enlazada. Se utiliza para almacenar las personas aleatorias encontradas.

El algoritmo recorre la lista de usuarios y selecciona aquellos que no son amigos del usuario principal. Luego, aleatoriamente elige tres de estos usuarios y los coloca en una pila. A continuación, se le pregunta al usuario principal si desea enviar una solicitud de amistad a cada usuario de la pila. Si la respuesta es afirmativa y el usuario seleccionado no tiene una solicitud de amistad pendiente, se envía la solicitud y se agrega el usuario a la lista de solicitudes pendientes del usuario principal. Finalmente, se libera la memoria utilizada por la pila. Para esta función tardamos un día entero. 

Limitaciones : El algoritmo utiliza una selección aleatoria simple mezclando el arreglo strangers. Esto puede resultar en una selección no completamente uniforme y algunas personas pueden tener menos posibilidades de ser seleccionadas.

Mejoras : Se puede implementar un mecanismo más sofisticado para la selección de personas aleatorias, como utilizar algoritmos de muestreo aleatorio más eficientes y justos, o selección por preferencias similares.

sendFriendRequest : se encarga de enviar una solicitud de amistad desde un remitente hacia un receptor. Y está hecho especialmente para  la función connectWithStrangers. La función permite evitar el envío de solicitudes duplicadas y la posibilidad de solicitar amistad con usuarios que ya son amigos.

Se ubican en el apartado dictionary_words : 

Para inicializar el diccionario : 

initializeDictionary : Inicializa el diccionario con la capacidad especificada

addWord : se encarga de agregar una palabra al diccionario. Toma como argumentos un puntero al diccionario (Dictionary* dict) y una cadena de caracteres que representa la palabra a agregar (const char* word).

compareWordCounts : compara para ordenar los elementos del diccionario por contador descendente

destroyDictionary : Libera la memoria utilizada por el diccionario

displayTopWords : Se encarga de contar las palabras más usadas en los posts de los usuarios y mostrar las 10 palabras que más se están utilizando. 

Las variables implementadas son : 
dict : Es una variable de tipo Dictionary que se utiliza para almacenar las palabras y su frecuencia en los posts de los usuarios.
printCount : Es una variable de tipo int que determina cuántas palabras se imprimirán en la lista de las más usadas.
i, j : Variables de tipo int utilizadas en los bucles for para recorrer los usuarios y sus posts.

	Las estructuras utilizadas son : 
Dictionary: Es una estructura que contiene un arreglo de estructuras WordCount para almacenar las palabras y su frecuencia. También mantiene un contador de size y capacity del diccionario. 

WordCount: Es una estructura que almacena una palabra y su frecuencia en los posts. Tiene dos campos: word para almacenar la palabra y count para la frecuencia.


Este algoritmo utiliza un diccionario para contar las palabras en los posts de los usuarios y luego muestra las palabras más usadas. Se implementan funciones para manipular el diccionario, realizar comparaciones y liberar la memoria asignada. El algoritmo recorre los usuarios y sus posts, agrega las palabras al diccionario y
ordena los elementos según su frecuencia. Hemos tardado 3 días en  hacerlo completo. 

Mejoras : Que la lista vaya cambiando periódicamente para obtener la tendencia actual de las palabras más usadas.   

Se ubican en el apartado merge : 

merge : combina y ordena dos subarreglos en un arreglo principal según el criterio de comparación de la edad de los elementos. Es utilizada como parte del algoritmo de ordenamiento "Merge Sort" para ordenar un arreglo de usuarios por su edad.

mergeSort : implementa el algoritmo "Merge Sort" de manera recursiva para ordenar un arreglo de usuarios por su edad. Divide el arreglo en subarreglos más pequeños, los ordena individualmente y luego los mezcla en orden ascendente.
Objetivos obligatorios alcanzados 

Hemos logrado implementar todos los objetivos obligatorios para crear nuestra red social. A continuación, se resumen las características clave de nuestra implementación:

Punto 1. 
Para la función insertUser, hemos utilizado una lista enlazada para almacenar y administrar los usuarios.

La función connectWithStrangers hace uso de una pila (stack) para conectar a los usuarios con personas desconocidas.

La función handleFriendRequests se apoya en una cola (queue) para manejar las solicitudes de amistad pendientes.

Punto 2.
La función searchUser implementa una búsqueda lineal (linear search) para encontrar un usuario específico en la lista.

Punto 3. 
En listAllUsers, hemos implementado las funciones merge y mergeSort para ordenar los usuarios existentes por edad, en orden ascendente.

Punto 4. 
La función displayTopWords hace uso de un diccionario para contar y mostrar las 10 palabras más utilizadas en los mensajes de los usuarios.

Punto 5. 
Además, nos hemos asegurado de que nuestro código esté adecuadamente comentado, de manera que sea comprensible para cualquier persona que lo revise, incluso sin haber formado parte del equipo de desarrollo del proyecto.

Punto 6.
Durante el desarrollo, hemos utilizado GitHub como plataforma de control de versiones para facilitar el trabajo colaborativo, y la mayoría de los miembros del equipo han participado activamente en el proyecto.

En resumen, hemos logrado implementar las funcionalidades requeridas de manera organizada y colaborativa, aprovechando diferentes estructuras de datos para satisfacer las necesidades de nuestra red social.
Objetivos deseables alcanzados

Hemos logrado cumplir al menos uno de los otros objetivos que nos habían proporcionado. Nuestro sitio web está diseñado para personas que disfrutan escuchando música mientras leen o que simplemente disfrutan de la combinación de literatura y música.

Esta característica especial de nuestra red social permite a los usuarios recibir recomendaciones de amistades basadas en intereses comunes en música y lectura. Los usuarios también pueden ver y compartir recomendaciones que podrían interesar a otros usuarios. Y creemos que estas características de nuestra red social harán que los usuarios tengan conexiones significativas. 

¡Esperamos que nuestros usuarios disfruten de esta combinación única de música y lectura en nuestra red social como lo hacemos nosotros!

Objetivos exploratorios adquiridos

Para cumplir el segundo objetivo exploratorio hemos implementado la función readUsersFromFile. Esta función se encarga de leer los datos registrados de los usuarios en un archivo (usuarios.csv) y los carga en la aplicación. Y esto nos permite agregar usuarios de manera más rápida y precisa. 

SOLUCIÓN
Arquitectura del sistema

El modelo de datos utilizado en todo el programa han sido las listas enlazadas, estas se han usado por ejemplo para usuarios; gracias a una lista enlazada podemos guardar los usuarios que registrados en la red social, también se ha seguido esta dinámica para las listas de los amigos de cada usuario y sus solicitudes pendientes.

La aplicación de listas enlazadas se ha implementado por varios motivos, las listas enlazadas nos dan flexibilidad y eficaces a la hora de mover datos y gestionarlos, también, son muy eficientes con la memoria, ya que se asigna memoria cuando va a coger un nuevo elemento y se libera cuando lo deja ir. 

El uso de las listas enlazadas, nos ha hecho tener una muy buena gestión de usuarios, dándonos diversas opciones con las que trabajar. 
En la red social se puede crear un usuario insertando todos los datos desde la consola, pero también podrá leer documento txt con la información pertinente de los usuarios, e ir agregando cada usuario a nuestra base de datos (la lista de usuarios). Otra opción posible, es visualizar todos los usuarios registrados en nuestra aplicación, aquí utilizamos un algoritmo de ordenamiento, MergeSort, para ordenar todos los usuarios existentes hasta el momento de más joven a más mayor, después se imprimirán todos los usuarios ordenados por edad.
El uso de este algoritmo es debido a que MergeSort utiliza el enfoque de "divide y conquista", esto ha facilitado la implementación y el mantenimiento. Además, se puede implementar eficientemente en listas enlazadas, lo cual aplica a nuestro enfoque respecto al programa.

Cada usuario tiene asociada una estructura que contiene información sobre este, nombre de usuario, edad, correo electrónico, ubicación, gustos e intereses. El usuario una vez registrado, puede acceder a múltiples opciones con las que puede interactuar con otros usuarios, estas són:  enviar solicitudes de amistad, encontrar a personas desconocidas, administrar sus solicitudes de amistad, crear una publicación, listar sus publicaciones,o de todos, y enseñar las 10 palabras más usadas entre todos los usuarios en sus publicaciones.

En las opciones relacionadas con otros usuarios, se verifica si estos son amigos o si ya hay una solicitud de amistad pendiente. En el caso de que te conecte con extraños lo hace de una manera aleatoria, siempre se pregunta al usuario si quiere agregar a esa persona como amigo, en el caso que si se envía una solicitud de amistad.
La opción de ver las palabras más utilizadas, hace que el usuario esté enterado de las tendencias o los temas de moda en la aplicación.

El método utilizado para buscar al usuario que queremos agregar o enviar solicitud de amistad, es la búsqueda lineal, también conocida como búsqueda secuencial. Esta, ofrece varias ventajas en comparación con otros métodos de búsqueda más complejos. Una de las principales ventajas es su sencillez en la implementación. Este algoritmo se basa en un bucle que recorre cada elemento de la lista y compara el nombre de usuario asociado con el nombre del usuario buscado. No se requiere ninguna estructura de datos adicional ni cálculos complicados.
Otra ventaja es su flexibilidad, este método se puede aplicar a cualquier tipo de lista o arreglo, independientemente de si los elementos están ordenados o no. No es necesario que los elementos estén en un orden específico para que el método funcione correctamente.
Además, el método de búsqueda lineal puede ser eficiente para listas pequeñas. Cuando se trabaja con un número reducido de elementos, la sobrecarga adicional de implementar un algoritmo de búsqueda más complejo puede no ser justificada.


Gestión de errores 

En un programa de una red social es crucial una buena gestión de errores para garantizar una seguridad en la aplicación. La gestión de errores implica detectar, informar y manejar cualquier situación excepcional o incorrecta que pueda surgir durante la ejecución del programa. 

Para empezar, hay que controlar todas las entradas del programa, por ejemplo, los datos que pone el usuario. En el programa cuando se agrega un usuario, los datos proporcionados deben cumplir varias características. En nuestro caso, hemos considerado que el usuario debe tener más de 12 años y una edad no más grande de los 110 años ya que eso raramente pasará, también comprobamos que se escriba una dirección de correo electrónico válida, con carácteres delante y detrás del arroba (@), además de un punto ‘.’ .

También se ha implementado código para garantizar una inserción correcta, que lo que introduzca el usuario sean los caracteres correctos. Por ejemplo, al solicitar la edad del usuario, el programa analiza la respuesta para asegurar que no haya ingresado ningún carácter y que no sea un número más grande a tres dígitos.

Además, se ha prestado especial atención a la gestión de la memoria para garantizar el almacenamiento y manipulación adecuados de los datos. Para evitar desbordamientos de memoria, hemos utilizado prácticas adecuadas de asignación y liberación de memoria, así como el manejo de punteros nulos y la verificación de límites. Estas medidas nos permiten almacenar y recuperar datos precisos y sin corrupción.
Diseño del modelo de datos 
El flujo de datos es fundamental para el funcionamiento y la interacción de los usuarios. Comienza con el registro de nuevos usuarios, quienes proporcionan información personal como nombre, edad, correo electrónico, ubicación y preferencias. Esta información se almacena en una lista de usuarios para su posterior uso.

La interacción social es un aspecto clave de nuestra red social. Los usuarios pueden enviar solicitudes de amistad, aceptar o rechazar solicitudes. Todas estas interacciones generan datos que se procesan y almacenan para su posterior visualización y gestión.




Descripción y procesamiento del conjunto de datos 

El manejo de conjuntos de datos es esencial para almacenar y gestionar la información de los usuarios, sus relaciones y actividades. Para ello, se utilizan diferentes conjuntos de datos que son leídos y procesados dentro del programa.

Uno de los conjuntos de datos más importantes es el perfil de usuario, que contiene información personal como nombre, edad, correo electrónico, ubicación, intereses. Para obtener estos datos, el programa puede implementar funciones de entrada de datos, ya sea a través de formularios en la interfaz de usuario o mediante la carga de archivos externos en un formato específico, en nuestro caso CSV. Una vez leídos, los datos se procesan y se almacenan en la estructura de datos adecuada, en nuestro caso una lista enlazada, para facilitar su acceso y gestión.

Otro conjunto de datos importante son las relaciones sociales entre los usuarios, como la lista de amigos. Estos datos se pueden leer y procesar de manera similar a los perfiles de usuario. El programa permite a los usuarios enviar y aceptar solicitudes de amistad, lo que permite la actualización de la lista de amigos.

En el caso de querer mostrar las diez palabras más usadas por los usuarios en sus publicaciones, se implementa un diccionario, añadiendo cada palabra utilizada en cada publicación de cada usuario registrado. Después se utiliza otro algoritmo de ordenamiento(QuickSort) para ordenar las palabras de forma ascendente según su uso.

Una vez que los conjuntos de datos están en el programa, se procesan y utilizan para proporcionar funcionalidades a los usuarios. Esto implica realizar consultas y búsquedas en los datos, generar recomendaciones, mostrar información en la interfaz de usuario.
REFERENCIAS
Imagen portada : https://www.google.com/url?sa=i&url=https%3A%2F%2Fblog.sonicbids.com%2F5-inspirational-books-every-musician-should-read&psig=AOvVaw07Ztb0mHLFVZU3YRlKNZ21&ust=1685699400323000&source=images&cd=vfe&ved=0CBEQjRxqFwoTCJjRjuTlof8CFQAAAAAdAAAAABAD

