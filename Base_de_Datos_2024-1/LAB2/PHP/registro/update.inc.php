<?php

if ($_SERVER["REQUEST_METHOD"] == "POST"){
    if($_POST["num_habitacion"] == "" or $_POST["fecha_check_in"] == "" or $_POST["fecha_check_out"] == "" or $_POST["new_num_habitacion"] == "" or $_POST["new_fecha_check_in"] == "" or $_POST["new_fecha_check_out"] == ""){
        $rut = $_POST["rut"];
        $mess = urldecode("Falta un dato");
        header("Location: updateread.php ?message=" . $mess . "&rut=" . $rut);
    }

    $rut = $_POST["rut"];
    $num_habitacion = $_POST["num_habitacion"];
    $fecha_check_in = $_POST["fecha_check_in"];
    $fecha_check_out = $_POST["fecha_check_out"];
    $new_num_habitacion = $_POST["new_num_habitacion"];
    $new_fecha_check_in = $_POST["new_fecha_check_in"];
    $new_fecha_check_out = $_POST["new_fecha_check_out"];

    try {
        require_once "../dbh.inc.php";
        $connect = mysqli_connect("localhost","root","","lab2");

        $get_ID = "SELECT get_ID($rut, $num_habitacion, '$fecha_check_in', '$fecha_check_out') AS ID";
        $result = mysqli_query($connect, $get_ID);
        $row = mysqli_fetch_array($result);
        $ID = $row["ID"];

        $query1 = "DELETE FROM all_tour WHERE ID = $ID";
        $result1 = mysqli_query($connect, $query1);

        $query = "UPDATE reservas SET
        N_HABITACION = :new_num_habitacion , CHECK_IN = :new_fecha_check_in ,
        CHECK_OUT = :new_fecha_check_out
        WHERE RUT = $rut AND N_HABITACION = $num_habitacion AND CHECK_IN = '$fecha_check_in' AND CHECK_OUT = '$fecha_check_out'";

        $stmt = $pdo->prepare($query);
        $stmt->bindParam(":new_num_habitacion", $new_num_habitacion);
        $stmt->bindParam(":new_fecha_check_in", $new_fecha_check_in);
        $stmt->bindParam(":new_fecha_check_out", $new_fecha_check_out);
        $stmt->execute();

        $pdo = null;
        $stmt = null;

        header("Location:updateread.php ?rut=".$rut);
        die();
    } catch (PDOException $e) {
        die("Query failed: " . $e->getMessage());
    }
}
else {
    header("Location:updateread.php ?rut=".$rut);
}

?>