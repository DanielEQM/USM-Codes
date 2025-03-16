<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="http://localhost/lab2/CSS/views.css">
    <title>Document</title>
</head>
<body style="background: #6BB6FF">
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST"){
        if($_POST["num_habitacion"] == ""){
            $mess = urldecode("Falta un dato");
            header("Location: registro.php". "?message=" . $mess);
        }
        $num_habitacion = $_POST["num_habitacion"];

        try {
            require_once "../dbh.inc.php";

            $connect = mysqli_connect("localhost","root","","lab2");

            $sql = "SELECT * FROM view_reserva WHERE N_HABITACION = '$num_habitacion'";

            $result = mysqli_query($connect,$sql);

            $pdo = null;
            $stmt = null;

        } catch (PDOException $e) {
            die("Query failed: " . $e->getMessage());
        }
    }
    else {
        header("Location: ../registro.php");
    }
    ?>
    <br />  
        <div class="container2" style="width:500px;">  
            <h3 align="">Reservas: </h3><br />                 
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
    <form method="post" action="registro.php">
        <button> Volver </button>
    </form>  
</body>
</html>