<!DOCTYPE html>
<html lang="en">
<head>
    <link rel="stylesheet" href="http://localhost/lab2/CSS/views.css">
</head>
<body style="background: #6BB6FF">
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST"){
    if($_POST["rut"] == ""){
        $mess = urldecode("No hay Rut");
        header("Location: tour.php ?message=".$mess);
    }
    $rut = $_POST["rut"];

    try {
        require_once "../dbh.inc.php";

        $connect = mysqli_connect("localhost","root","","lab2");

        $sql = "SELECT * FROM view_reserva WHERE RUT = $rut;";

        $result = mysqli_query($connect, $sql);

        $pdo = null;
        $stmt = null;
        
    } catch (PDOException $e) {
        die("Query failed: " . $e->getMessage());
    }
}
else if (isset($_GET['rut'])) {
    $rut = $_GET['rut'];
    try {
        require_once "../dbh.inc.php";

        $connect = mysqli_connect("localhost","root","","lab2");

        $sql = "SELECT * FROM view_reserva WHERE RUT = $rut;";

        $result = mysqli_query($connect, $sql);

        $pdo = null;
        $stmt = null;
        
    } catch (PDOException $e) {
        die("Query failed: " . $e->getMessage());
    }
}
else {
    header("Location: tour.php");
}
?>
<br />  
    <div class="container2" style="width:500px;">  
    <h3 align="">Habitaciones del Huesped: </h3><br />                 
        <div class="table-responsive">  
            <table class="table table-striped">  
                <tr>  
                    <th>Rut</th>  
                    <th>N° de Habitación</th>  
                    <th>Fecha CHECK IN</th>  
                    <th>Fecha CHECK OUT</th>  
                    <th>Tipo de Habitación</th>  
                    <th>Valor Dolares</th>  
                </tr>  
                <?php  
                while($row = mysqli_fetch_array($result))  
                {  
                ?>  
                <tr>  
                    <td><?php echo $row["RUT"]; ?></td>
                    <td><?php echo $row["N_HABITACION"]; ?></td>    
                    <td><?php echo $row["CHECK_IN"];?></td>  
                    <td><?php echo $row["CHECK_OUT"];?></td>  
                    <td><?php echo $row["Type"];?></td>  
                    <td><?php echo $row["Price"]; ?></td>  
                </tr>  
                <?php  
                }  
                ?>  
            </table>  
        </div>  
    </div>  
<br />
<form method="post" action="reservartour.inc.php">
    <input type="hidden" name="rut" value="<?php echo $rut ?>" />
    N° Habitación: <br><input type="text" name="num_habitacion">
    <br>
    Fecha check in: <br><input type="text" name="fecha_check_in">
    <br>
    Fecha check out: <br><input type="text" name="fecha_check_out">
    <br>
    Id del tour: <br><input type="text" name="tours_id">
    <br><br>
    <button> Reservar </button>
    <?php
    if (isset($_GET['message'])){
        echo $_GET['message'];
    }
    ?>
</form>

<br>
<h1> Cancelar Reserva </h1>
<form method="post" action="deletetour.php">
    <input type="hidden" name="rut" value="<?php echo $rut ?>" />
    N° Habitación: <br><input type="text" name="num_habitacion">
    <br>
    Fecha check in: <br><input type="text" name="fecha_check_in">
    <br>
    Fecha check out: <br><input type="text" name="fecha_check_out">
    <br><br>
    <button> Revisar </button>
    <?php
    if (isset($_GET['message2'])){
        echo $_GET['message2'];
    }
    ?>
</form>
<br><br>
<form method="post" action="tour.php">
    <button> Volver </button>
</form>
</body>
</html>