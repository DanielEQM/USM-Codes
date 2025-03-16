<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="http://localhost/lab2/css/barra_busqueda.css">
    <title>Document</title>
</head>
<body>
    <h1> Bienvenido: </h1>
    <br>
    <h2> Barra de búsqueda habitación: </h2>
    <form method="post" action="readRep.php">
        N° Habitación: <input type="text" name="num_habitacion">
        <button> Buscar </button>
    </form>
    <br>
    <form method="post" action="../main.php">
        <button> Volver </button>
    </form>  
</body>
</html>