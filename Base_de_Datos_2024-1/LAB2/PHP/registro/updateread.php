<!DOCTYPE html>
<html lang="en">
<head>
    <link rel="stylesheet" href="http://localhost/lab2/CSS/views.css">
</head>
<body style="background: #6BB6FF"> 
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST"){
    if($_POST["rut"] == ""){
        $mess = urldecode("Falta un dato");
        header("Location: registro.php". "?message=" . $mess);
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
else if(isset($_GET['rut'])){
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
    header("Location: registro.php");
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
<h2> Actualizar Reserva: </h2>
<h4> Reserva a modificar: </h2>
    <form method="post" action="update.inc.php">
        <input type="hidden" name="rut" value="<?php echo $rut ?>" />
        N° Habitación: <input type="text" name="num_habitacion">
        <br>
        Fecha check in: <input type="text" name="fecha_check_in">
        <br>
        Fecha check out: <input type="text" name="fecha_check_out">
        <br>
        <h4> Nuevos datos: </h4>
        N° Habitación: <input type="text" name="new_num_habitacion">
        <br>
        Fecha check in: <input type="text" name="new_fecha_check_in">
        <br>
        Fecha check out: <input type="text" name="new_fecha_check_out">
        <br>
        <button> Modificar </button>
    </form>
    <h2> Borrar huesped: </h2>
    <form method="post" action="delete.inc.php">
        <input type="hidden" name="rut" value="<?php echo $rut ?>" />
        N° Habitación: <input type="text" name="num_habitacion">
        <br>
        Fecha check in: <input type="text" name="fecha_check_in">
        <br>
        Fecha check out: <input type="text" name="fecha_check_out">
        <br>
        <button> Eliminar </button>
    </form>
    <br>
    <?php
    if(isset($_GET['message'])){
        echo $_GET['message'];
    }
    ?>
    <br>
    <br>
    <form method="post" action="registro.php">
        <button> Volver </button>
    </form>
</body>
</html>