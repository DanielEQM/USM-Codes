<?php
if($_POST['tours_id']== ""){
    $mess = urldecode("Falta un dato");
    header("Location: deletetour.php ?rut=" . $_POST["rut"] . "&num_habitacion=" . $_POST["num_habitacion"] . "&fecha_check_in=" . $_POST["fecha_check_in"] . "&fecha_check_out=" . $_POST["fecha_check_out"] . "&message=" . $mess);
}

$connect = mysqli_connect("localhost","root","","lab2");
$rut = $_POST["rut"];
$num_habitacion = $_POST["num_habitacion"];
$fecha_check_in = $_POST["fecha_check_in"];
$fecha_check_out = $_POST["fecha_check_out"];
$tours_id = $_POST['tours_id'];

$funct = "SELECT get_ID($rut, $num_habitacion, '$fecha_check_in', '$fecha_check_out') AS ID";
$result = mysqli_query($connect, $funct);
$row = mysqli_fetch_array($result);
$ID = $row["ID"];

$sql1 = "DELETE FROM all_tour WHERE ID = $ID AND tipo = $tours_id";
$result1 = mysqli_query($connect,$sql1);
$pdo = null;
$stmt = null;

header("Location: deletetour.php ?rut=" . $_POST["rut"] . "&num_habitacion=" . $_POST["num_habitacion"] . "&fecha_check_in=" . $_POST["fecha_check_in"] . "&fecha_check_out=" . $_POST["fecha_check_out"]);

?>