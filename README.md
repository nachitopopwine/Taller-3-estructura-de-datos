# Taller-3-estructura-de-datos
TallerEstructura -----------------INTEGRANTES------------------ 
Nombre: Ignacio Andres Rodriguez Bruna Rut: 20.543.006-7 Correo: ignacio.rodriguez02@alumnos.ucn.cl 
Nombre: Claudio Gabriel Palta Contreras Rut: 20.788.795-1 Correo: claudio.palta@alumnos.ucn.cl

-----------------LINEAS DE COMPILACIÓN Y EJECUCIÓN------------------------ Linea para compilar:
g++ -o main main.cpp InterfazUsuario.cpp GestorTransacciones.cpp Transaccion.cpp NodoABB.cpp NodoAVL.cpp ArbolABB.cpp ArbolAVL.cpp

Linea para Ejecutar:
./main

----MAIN----

1.- Se crea un objeto de InterfazUsuario llamado interfaz, luego se inicia la interfaz.
2.- al iniciar la interfaz se despliega un menu de opciones para el usuario la cual contiene 6 opciones:

-La primera es registrar transacciones la cual le permite al usuario agregar una nueva transaccion, preguntandole por los datos necesarios que deben tener cada una de estas (id, origen, destino, ubicacion, fechaHora). Luego se guardan los datos en un nuevo objeto de transacciones.
    
-La segunda es buscar una transaccion en especifico, la cual se le pide al usuario ingresar la id de la transaccion que desea buscar, primero se ingresa la id de la transaccion que se desea buscar y se almacena ese valor, luego se crea un puntero de la clase transaccion que va a ser igual al nodo de la id de la transaccion que se busca, luego se verifica que esta transaccion exista y si esta se encuentra registrada en el sistema se le mostrara por pantalla y en el caso de que no exista se le mostrara "transaccion no encontrada".

-La tercera es dectectar transacciones sospechosas al seleccionar esta opcion se le despliega otro submenu de opciones para establecer los parametros para poder dectar una transaccion sospechosa. Estos parametros pueden ser Transacciones que excedan un monto específico, Frecuencia inusualmente alta de transacciones en un corto periodo o Transacciones desde ubicaciones geográficas diferentes en un corto tiempo.

-La cuarta opcion es modificar la forma de detectar las transacciones sospechosas esat ocpion despliega un submenu el cual contiene las opciones de Modificar cantidad maxima de transacciones para frecuencia alta en un corto periodo(1 dia) y Modificar cantidad maxima de transacciones desde ubicaciones diferentes en un corto tiempo (1 dia). Si selecciona la primera opcion le pide al ususario que ingrese una nueva cantidad de transacciones en un corto periodo de tiempo para luego modificar el valor anterior, luego la segunda opcion hace lo mismo pero con la cantidad de transacciones desde ubicaciones diferentes.

-La quinta opcion genera un reporte donde se detallan las opciones sospechosas identificadas hasta el momento.

-La sexta opcion es salir del sistema.
