<?php


if($_POST["num_habitacion"] == "" or $_POST["fecha_check_in"] == "" or $_POST["fecha_check_out"] == "" or $_POST['stars']== ""){
    $mess = urldecode("Falta un dato");
    header("Location: checkoutread.php ?rut=" . $_POST["rut"] . "&message=" . $mess);
    die();
}

$connect = mysqli_connect("localhost","root","","lab2");
$rut = $_POST["rut"];
$num_habitacion = $_POST["num_habitacion"];
$fecha_check_in = $_POST["fecha_check_in"];
$fecha_check_out = $_POST["fecha_check_out"];
$stars = $_POST['stars'];

$query = "SELECT CHECK_OUT FROM reservas WHERE N_HABITACION = $num_habitacion AND RUT = $rut AND CHECK_IN = '$fecha_check_in'";
$resulta = mysqli_query($connect, $query);
$row = mysqli_fetch_array($resulta);
$chekout = $row["CHECK_OUT"];

$get_ID = "SELECT get_ID($rut, $num_habitacion, '$fecha_check_in', '$chekout') AS ID";
$result = mysqli_query($connect, $get_ID);
$row1 = mysqli_fetch_array($result);
$ID = $row1["ID"];

if($row["CHECK_OUT"] < $fecha_check_out){
    $mess = urldecode("Error en la fecha ingresada");
    header("Location: checkoutread.php ?rut=" . $_POST["rut"] . "&message=" . $mess);
    die();
} 
else if ($fecha_check_out < $fecha_check_in) {
    $mess = urldecode("Fecha mal ingresada");
    header("Location: checkoutread.php ?rut=" . $_POST["rut"] . "&message=" . $mess);
    die();
}
if ($fecha_check_out < $row["CHECK_OUT"]){
    $sql = "DELETE FROM all_tour WHERE fecha_tour > '$fecha_check_out'";
    $complete = mysqli_query($connect, $sql);
}

$sumatour = "SELECT Suma($ID, $num_habitacion, '$fecha_check_out') AS total";
$sumaT = mysqli_query($connect, $sumatour);
$row2 = mysqli_fetch_array($sumaT);
$suma = $row2["total"];

$INSreport = "INSERT INTO reporteria (num_habitacion, checkout, recaudado, calificacion) VALUES ($num_habitacion, '$fecha_check_out', $suma, $stars)";
$INS = mysqli_query($connect, $INSreport);

$dl = "DELETE FROM reservas WHERE ID = $ID";
$dl2 = mysqli_query($connect, $dl);
$dl = "DELETE FROM all_tour WHERE ID = $ID";
$dl2 = mysqli_query($connect, $dl);

$mess = urldecode("El Total a pagar es: ");
header("Location: checkoutread.php ?rut=" . $_POST["rut"] . "&message2=" . $mess . "&total=" . $suma);
die();
?>