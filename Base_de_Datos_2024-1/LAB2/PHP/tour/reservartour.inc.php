<?php
if($_POST["num_habitacion"] == "" or $_POST["fecha_check_in"] == "" or $_POST["fecha_check_out"] == "" or $_POST['tours_id']== ""){
    $mess = urldecode("Falta un dato");
    header("Location: createTour.php ?rut=" . $_POST["rut"] . "&message=" . $mess);
    die();
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
if($ID == ""){
    $mess = urldecode("Persona no encontrada");
    header("Location: createTour.php ?rut=" . $_POST["rut"] . "&message=" . $mess);
    die();
}
$funct3 = "SELECT tipo, fecha FROM tour WHERE id = $tours_id";
$resultado1 = mysqli_query($connect, $funct3);
$row3 = mysqli_fetch_array($resultado1);
$fecha = $row3["fecha"];
$tipo = $row3["tipo"];

if($fecha > $fecha_check_out){
    $mess = urldecode("El tour se realiza después de la fecha de check out");
    header("Location: createTour.php ?rut=" . $_POST["rut"] . "&message=" . $mess);
    die();
} else if ($fecha_check_in > $fecha){
    $mess = urldecode("El tour se realiza antes de la fecha de check in");
    header("Location: createTour.php ?rut=" . $_POST["rut"] . "&message=" . $mess);
    die();
}

$funct2 = "SELECT Price FROM list_tour WHERE ID = $tipo";
$resultado = mysqli_query($connect, $funct2);
$row2 = mysqli_fetch_array($resultado);
$price = $row2["Price"];

$sql = "SELECT tipo FROM view_all_tour WHERE ID = $ID";
$findout = mysqli_query($connect, $sql);
while($row = mysqli_fetch_array($findout)){
    if($row["tipo"] == $tours_id){
        $mess = urldecode("Tour ya registrado");
        header("Location: createTour.php ?rut=" . $_POST["rut"] . "&message=" . $mess);
        die();
    }
}

$sql1 = "UPDATE reg_tour SET tipo = $tours_id WHERE id = $ID";
$result1 = mysqli_query($connect,$sql1);
$sql2 = "UPDATE all_tour SET RUT = $rut, N_HABITACION = $num_habitacion, CHECK_IN = '$fecha_check_in', CHECK_OUT = '$fecha_check_out', Price = $price, fecha_tour = '$fecha' WHERE ID = $ID AND tipo = $tours_id";
$result2 = mysqli_query($connect,$sql2);
$pdo = null;
$stmt = null;

header("Location: createTour.php ?rut=". $rut);
?>

