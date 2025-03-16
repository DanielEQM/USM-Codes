<?php

if ($_SERVER["REQUEST_METHOD"] == "POST"){
    if($_POST["num_habitacion"] == "" or $_POST["fecha_check_in"] == "" or $_POST["fecha_check_out"] == ""){
        $rut = $_POST["rut"];
        $mess = urldecode("Falta un dato");
        header("Location: updateread.php ?message=" . $mess . "&rut=" . $rut);
    }
    $rut = $_POST["rut"];
    $num_habitacion = $_POST["num_habitacion"];
    $fecha_check_in = $_POST["fecha_check_in"];
    $fecha_check_out = $_POST["fecha_check_out"];

    try {
        require_once "../dbh.inc.php";
        $connect = mysqli_connect("localhost","root","","lab2");

        $query = "DELETE FROM reservas 
        WHERE RUT = $rut AND N_HABITACION = $num_habitacion AND CHECK_IN = '$fecha_check_in' AND CHECK_OUT = '$fecha_check_out';";

        $funct = "SELECT get_ID($rut, $num_habitacion, '$fecha_check_in', '$fecha_check_out') AS ID";
        $result = mysqli_query($connect, $funct);
        $row = mysqli_fetch_array($result);
        $ID = $row["ID"];
        $query2 = "DELETE FROM all_tour WHERE ID = $ID";

        $stmt = $pdo->prepare($query);
        $stmt2 = $pdo->prepare($query2);
        $stmt->execute();
        $stmt2->execute();

        $pdo = null;
        $stmt = null;

        header("Location:updateread.php ?rut=".$rut);

        die();
    } catch (PDOException $e) {
        die("Query failed: " . $e->getMessage());
    }
}
else {
    header("Location:updateread.php");
}

?>