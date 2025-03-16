<!DOCTYPE html>
<html lang="en"> 
<form method="post" action="tour.php">
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
        require_once "../dbh.inc.php";

        $connect = mysqli_connect("localhost","root","","lab2");

        $sql = "SELECT * FROM view_tours ORDER BY id";

        $result = mysqli_query($connect,$sql);

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
<body style="background: #6BB6FF">
    <br />  
        <div class="container" style="width:700px;">  
            <h3 align="">Tours: </h3><br />                 
            <div class="table-responsive">  
                    <table class="table table-striped">  
                        <tr>  
                            <th>ID</th>
                            <th>Lugar<div style="width:100px;"></th>  
                            <th>Fecha<div style="width:100px;"></th>  
                            <th>Medio de Transporte</th> 
                            <th>Precio</th>
                            <th>Imagen del Lugar</th> 
                        </tr>  
                        <?php  
                        while($row = mysqli_fetch_array($result))  
                        {  
                        ?>  
                        <tr>  
                            <td><?php echo $row["id"]; ?></td>  
                            <td><?php echo $row["Place"]; ?></td>  
                            <td><?php echo $row["fecha"];?></td>
                            <td><?php echo $row["Transport"]; ?></td>
                            <td><?php echo $row["Price"]; ?></td>
                            <td><?php echo '<img src="' . $row["Image"] . '" alt="Imagen de cliente" width="400" height="220" />'; ?></td>
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