<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="http://localhost/lab2/css/barra_busqueda.css">
    <title>Document</title>
</head>
<body>
    <h1> Crear reserva del huesped: </h1>
    <form method="post" action="create.inc.php">
        Rut: <br><input type="text" name="rut">
        <br>
        N° Habitación: <br><input type="text" name="num_habitacion">
        <br>
        Fecha check in: <br><input type="text" name="fecha_check_in">
        <br>
        Fecha check out: <br><input type="text" name="fecha_check_out">
        <br>
        <br>
        <button> Crear </button>
        <?php
        if(isset($_GET['message1'])){
            echo $_GET['message1'];
        }
        ?>
    </form>
    <br>
    <h2> Barra de búsqueda habitación: </h2>
    <form method="post" action="read.php">
        N° Habitación: <input type="text" name="num_habitacion">
        <button> Buscar </button>
    </form>
    <br>
    <h2> Modificar Reserva: </h2>
    <form method="post" action="updateread.php">
        Rut: <input type="text" name="rut">
        <button> Revisar </button>
    </form>
    <br>
    <?php
    if (isset($_GET['message'])){
        echo $_GET['message'];
    }
    ?>
    <form method="post" action="../main.php">
        <button> Volver </button>
    </form>
</body>
</html>