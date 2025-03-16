<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="http://localhost/lab2/css/barra_busqueda.css">
    <title>Document</title>
</head>
<body>
<h1> Ingrese rut para reservar tour: </h1>
<form method="post" action="createTour.php">
    Rut: <input type="text" name="rut">
    <button> Revisar </button>
</form>
<?php
if(isset($_GET['message'])){
 echo $_GET['message'];
}
?>
<h1> Tours disponibles: </h1>
<form method="post" action="readtours.php">
    <button> Ver Tours </button>
</form>
<br>
<form method="post" action="../main.php">
    <button> Volver </button>
</form>
</body>
</html>