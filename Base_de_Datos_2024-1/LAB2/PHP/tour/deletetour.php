<!DOCTYPE html>
<html lang="en">
<head>
    <link rel="stylesheet" href="http://localhost/lab2/CSS/views.css">
</head>
<body style="background: #6BB6FF">
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST"){
    if($_POST["num_habitacion"] == "" or $_POST["fecha_check_in"] == "" or $_POST["fecha_check_out"] == ""){
        $mess = urldecode("Falta un dato");
        header("Location: createTour.php ?rut=" . $_POST["rut"] . "&message2=" . $mess);
    }
    $connect = mysqli_connect("localhost","root","","lab2");
    $rut = $_POST["rut"];
    $num_habitacion = $_POST["num_habitacion"];
    $fecha_check_in = $_POST["fecha_check_in"];
    $fecha_check_out = $_POST["fecha_check_out"];


    $funct = "SELECT get_ID($rut, $num_habitacion, '$fecha_check_in', '$fecha_check_out') AS ID";
    $result = mysqli_query($connect, $funct);
    $row = mysqli_fetch_array($result);
    $ID = $row["ID"];
    if($ID == ""){
        $mess = urldecode("Persona no encontrada");
        header("Location: createTour.php ?rut=" . $_POST["rut"] . "&message2=" . $mess);
        die();
    }

    $sql = "SELECT * FROM view_all_tour WHERE ID = $ID";
    $result1 = mysqli_query($connect, $sql);

    $pdo = null;
    $stmt = null;
} 
else if (isset($_GET['rut'])){
    $connect = mysqli_connect("localhost","root","","lab2");
    $rut = $_GET["rut"];
    $num_habitacion = $_GET["num_habitacion"];
    $fecha_check_in = $_GET["fecha_check_in"];
    $fecha_check_out = $_GET["fecha_check_out"];

    $funct = "SELECT get_ID($rut, $num_habitacion, '$fecha_check_in', '$fecha_check_out') AS ID";
    $result = mysqli_query($connect, $funct);
    $row = mysqli_fetch_array($result);
    $ID = $row["ID"];

    $sql = "SELECT * FROM view_all_tour WHERE ID = $ID";
    $result1 = mysqli_query($connect, $sql);

    $pdo = null;
    $stmt = null;
}
else {
    header("Location: tour.php");
}
?>
<br />  
    <div class="container2" style="width:500px;">  
    <h3 align="">Tours del Huesped: </h3><br />                 
        <div class="table-responsive">  
            <table class="table table-striped">  
                <tr>  
                    <th>Rut</th>  
                    <th>N° de Habitación</th>  
                    <th>Fecha CHECK IN</th>  
                    <th>Fecha CHECK OUT</th>  
                    <th>Lugar de Tour</th>
                    <th> ID tour </th>
                </tr>  
                <?php  
                while($row = mysqli_fetch_array($result1))  
                {  
                ?>  
                <tr>  
                    <td><?php echo $row["RUT"]; ?></td>
                    <td><?php echo $row["N_HABITACION"]; ?></td>    
                    <td><?php echo $row["CHECK_IN"];?></td>  
                    <td><?php echo $row["CHECK_OUT"];?></td>  
                    <td><?php echo $row["Place"];?></td> 
                    <td><?php echo $row["tipo"];?></td> 
                </tr>  
                <?php  
                }  
                ?>  
            </table>  
        </div>  
    </div>  
<br />
<form method="post" action="deletetour.inc.php">
    <input type="hidden" name="rut" value="<?php echo $rut ?>" />
    <input type="hidden" name="num_habitacion" value="<?php echo $num_habitacion ?>" />
    <input type="hidden" name="fecha_check_in" value="<?php echo $fecha_check_in ?>" />
    <input type="hidden" name="fecha_check_out" value="<?php echo $fecha_check_out ?>" />
    Id del tour: <input type="text" name="tours_id">
    <br>
    <button> Borrar </button>
    <?php
    if (isset($_GET['message'])){
        echo $_GET['message'];
    }
    ?>
</form>
<br>
<form method="post" action="createTour.php">
    <input type="hidden" name="rut" value="<?php echo $rut ?>" />
    <button> Volver </button>
</form>
</body>
</html>