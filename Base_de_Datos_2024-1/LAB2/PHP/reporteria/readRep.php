<!DOCTYPE html>
<html lang="en"> 
<form method="post" action="reporteria.php">
    <button> Volver </button>
</form>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="http://localhost/lab2/CSS/views.css">
    <title>Document</title>
</head>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST"){

    try {
        $num_habitacion = $_POST["num_habitacion"];
        require_once "../dbh.inc.php";

        $connect = mysqli_connect("localhost","root","","lab2");

        $sql = "SELECT * FROM reporteria WHERE num_habitacion = $num_habitacion";

        $result = mysqli_query($connect,$sql);

        $pdo = null;
        $stmt = null;

    } catch (PDOException $e) {
        die("Query failed: " . $e->getMessage());
    }
}
else {
    header("Location: reporteria.php");
}
?>
<body style="background: #6BB6FF">
    <br />  
        <div class="container2" style="width:700px;">
            <h3 align="">Reporteria: </h3><br />    
            <h4> <?php echo "Los dato de la habitación N° " . $num_habitacion . " estan indicados:"?> </h4>
            <div class="table-responsive">  
                    <table class="table table-striped">  
                        <tr>  
                            <th>Check Out<div style="width:100px;"></th>  
                            <th>Recaudado</th> 
                            <th>Calificación</th> 
                        </tr>  
                        <?php  
                        while($row = mysqli_fetch_array($result))  
                        {  
                        ?>  
                        <tr>  
                            <td><?php echo $row["checkout"];?></td>
                            <td><?php echo $row["recaudado"]; ?></td>
                            <td><?php echo $row["calificacion"]; ?></td>
                        </tr>  
                        <?php  
                        }  
                        ?>  
                    </table>  
            </div>  
        </div>  
    <br />  
</body>
</html>