<?php

if ($_SERVER["REQUEST_METHOD"] == "POST"){
    if($_POST["num_habitacion"] == "" or $_POST["fecha_check_in"] == "" or $_POST["fecha_check_out"] == ""){
        $mess = urldecode("Falta un dato");
        header("Location: registro.php ?message=" . $mess);
        die();
    }
    $rut = $_POST["rut"];
    $num_habitacion = $_POST["num_habitacion"];
    $fecha_check_in = $_POST["fecha_check_in"];
    $fecha_check_out = $_POST["fecha_check_out"];

    if($fecha_check_out < $fecha_check_in){
        $mess = urldecode("Fecha mal ingresada");
        header("Location: registro.php ?message=" . $mess);
        die();
    }

    try {
        require_once "../dbh.inc.php";

        // Primero, verificar si la habitación está disponible en las fechas solicitadas
        $queryCheck = "SELECT COUNT(*) as count FROM reservas WHERE N_HABITACION = :num_habitacion AND NOT (CHECK_OUT < :fecha_check_in OR CHECK_IN > :fecha_check_out)";

        $stmtCheck = $pdo->prepare($queryCheck);
        $stmtCheck->bindParam(":num_habitacion", $num_habitacion);
        $stmtCheck->bindParam(":fecha_check_in", $fecha_check_in);
        $stmtCheck->bindParam(":fecha_check_out", $fecha_check_out);
        $stmtCheck->execute();

        $result = $stmtCheck->fetch(PDO::FETCH_ASSOC);

        if ($result['count'] > 0) {
            $mess = urldecode("Habitación ya reservada");
            header("Location: registro.php ?message1=" . $mess);
        } else {
            // La habitación está disponible, procedemos a insertar la reserva
            $query = "INSERT INTO reservas (RUT, N_HABITACION, CHECK_IN, CHECK_OUT) VALUES 
            (:rut, :num_habitacion, :fecha_check_in, :fecha_check_out)";

            $stmt = $pdo->prepare($query);
            $stmt->bindParam(":rut", $rut);
            $stmt->bindParam(":num_habitacion", $num_habitacion);
            $stmt->bindParam(":fecha_check_in", $fecha_check_in);
            $stmt->bindParam(":fecha_check_out", $fecha_check_out);

            $stmt->execute();

            header("Location: registro.php"); // Redirige a la página de registro
            exit;
        }
        die();
    } catch (PDOException $e) {
        die("Query failed: " . $e->getMessage());
    }
}
else {
    header("Location: registro.php");
}

?>