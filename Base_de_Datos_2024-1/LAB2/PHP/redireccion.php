<?php
if (isset($_POST['boton1'])) {
    header("Location: registro/registro.php");
    exit();
} elseif (isset($_POST['boton2'])) {
    header("Location: tour/tour.php");
    exit();
} elseif (isset($_POST['boton3'])) {
    header("Location: checkout/checkout.php");
    exit();
} elseif (isset($_POST['boton4'])) {
    header("Location: reporteria/reporteria.php");
    exit();
}
?>
