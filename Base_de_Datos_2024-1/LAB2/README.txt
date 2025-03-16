Daniel Quispe 202273529-5 ; Matias Fernandez 202273506-6

Instrucciones:
Se actualizado la aplicación XAMPP para enlazar el Mysql con php. Para arrancar la pagina se debe abrir el Panel de Control de XAMPP presionando "start" en las secciones
Apache y Mysql. Dentro del archivo se encuentra una carpeta llamada "BD" en la cual se encuentra la base de datos llamada lab2.sql, esta se tiene que importar
en el phpmyadmin que se accede mediante "http://localhost/phpmyadmin/", se tiene que ir al apartado de import sin tocar ninguna configuación.
Para los archivos php se a accedido a traves del usuario "root" sin clave predefinido al crear la base de datos de mysql.

En caso de salir el siguiente error:
    Connection failed: SQLSTATE[HY000] [1045] Access denied for user 'root'@'localhost' (using password: NO)
Tendrá que cambiar todas lineas que contengan el siguiente comando "mysqli_connect("localhost","root","","lab2")" en donde si quiere cambiar de usuario
debe cambiar "root" por el nombre de ususario de mysql que desee y su respectiva contraseña que en este caso es "" a la que posea su usuario. En el archivo
"dbh.inc.php" debe cambiar $dbusername y $dbpassword por el nombre de usuario y contraseña respectivamente.

El archivo debe ser incluido en la carpeta "htdocs" dentro de la carpeta donde se encuentra XAMPP siendo de esta manera "../xampp/htdocs".
Luego se puede iniciar el programa entrando a su navegador favorito y escribiendo "localhost" en la barra de busqueda de este mismo.
Una vez dentro podrá clickear la carpeta "lab2" y entrará a la pagina para su respectivo funcionamiento.

El archivo index.php sirve para redirigir más rapidamente a la pagina, por lo que se considero necesario tenerlo fuera de la carpeta PHP.

Supuestos:
* Solo habran 20 habitaciones que se podran escoger, el numero de habitación tiene registrado un tipo de habitación en particular.
* Una persona puede reservar varias habitaciones al mismo tiempo.
* Se puede reservar una misma habitación en distintas fechas.
* Una persona que ha actualizado los datos de la reserva de su habitacion perderá los datos de los tours que ha reservado.
* Cuando se realiza el check out, luego de mostrar el monto total a pagar se borra a la persona de la base de datos y se queda registrado en reportería.
* Las reservas de los huespedes se harán a partir del 2024-06-01.
* Las fechas serán ingresadas con el siguiente formato: AAAA-MM-DD (YYYY-MM-DD)
* Las calificaciones seran numeros del 0 al 5 (Tambien pudiendo ser decimales)
* Asumimos los input son correctos. (Por ejemplo, un input tipo int siempre recibira un int).
* En reportería aún no hay datos ya que nadie a hecho Check Out. (Durante la fase experimental se comprobará la inserción)