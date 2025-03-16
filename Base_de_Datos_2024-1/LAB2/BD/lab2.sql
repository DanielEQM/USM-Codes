-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 14, 2024 at 04:39 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `lab2`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `GET_Precio` (IN `num` INT, OUT `tipo` INT)   SELECT Type INTO tipo FROM habitacion WHERE N_HABITACION = num$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `sumaGeneral` (IN `id` INT, IN `numero` INT, IN `checkout` DATE, OUT `sumaT` INT, OUT `sumaD` INT, OUT `Precio` INT)   BEGIN
SELECT IFNULL(SUM(Price),0) INTO sumaT FROM all_tour WHERE all_tour.ID = id;
SELECT TimestampDiff (day, CHECK_IN, checkout) INTO sumaD FROM reservas WHERE reservas.ID = id;
CALL GET_Precio(numero, @tipo);
SELECT Price INTO Precio FROM type WHERE type.ID = @tipo;
END$$

--
-- Functions
--
CREATE DEFINER=`root`@`localhost` FUNCTION `get_ID` (`R` INT, `N` INT, `C_I` DATE, `C_O` DATE) RETURNS INT(11)  BEGIN
    DECLARE I INT;
    SELECT ID INTO I FROM reservas WHERE RUT = R AND N_HABITACION = N AND CHECK_IN = C_I AND CHECK_OUT = C_O ;
    RETURN I;
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Suma` (`id` INT, `num` INT, `checkout` DATE) RETURNS INT(11)  BEGIN
	DECLARE total INT;
	CALL sumaGeneral(id, num, checkout, @sumaT, @sumaD, @Precio);
    SELECT @sumaT + @sumaD * @Precio INTO total;
	RETURN total;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `all_tour`
--

CREATE TABLE `all_tour` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `CHECK_IN` date NOT NULL,
  `CHECK_OUT` date NOT NULL,
  `N_HABITACION` int(11) NOT NULL,
  `tipo` int(11) DEFAULT NULL,
  `RUT` int(11) NOT NULL,
  `Price` int(11) NOT NULL,
  `fecha_tour` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `habitacion`
--

CREATE TABLE `habitacion` (
  `N_HABITACION` int(11) NOT NULL,
  `Type` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `habitacion`
--

INSERT INTO `habitacion` (`N_HABITACION`, `Type`) VALUES
(1, 1),
(2, 1),
(4, 1),
(5, 1),
(6, 1),
(7, 1),
(8, 1),
(9, 1),
(17, 1),
(3, 2),
(10, 2),
(11, 2),
(12, 2),
(13, 2),
(15, 2),
(16, 2),
(14, 3),
(18, 3),
(19, 3),
(20, 3);

-- --------------------------------------------------------

--
-- Table structure for table `list_tour`
--

CREATE TABLE `list_tour` (
  `ID` int(11) NOT NULL,
  `Place` varchar(50) NOT NULL,
  `Transport` varchar(20) NOT NULL,
  `Image` varchar(9000) NOT NULL,
  `Price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `list_tour`
--

INSERT INTO `list_tour` (`ID`, `Place`, `Transport`, `Image`, `Price`) VALUES
(1, 'Volcan Osorno', 'Bus', 'https://conociendochile.cl/wp-content/uploads/2020/10/Volcan-Osorno.jpg', 45),
(2, 'Cerro Tronador', 'Caballo', 'https://barilocheturismo.gob.ar/images/actividades/cerros/tronador/cerrotronador_01.jpg', 68),
(3, 'Museo Colonial Alemán de Frutillar', 'Bus', 'https://live.staticflickr.com/1538/24857011199_6af6acfd29_b.jpg', 60),
(4, 'Parque Nacional Chiloé', 'Bus', 'https://www.porquemegustaviajar.com/wp-content/uploads/2021/07/Senderos-del-Parque-Nacional-de-Chiloé.jpeg', 70),
(5, 'Teatro del Lago', 'Mini van', 'https://a.travel-assets.com/findyours-php/viewfinder/images/res70/121000/121035-Frutillar.jpg', 80);

-- --------------------------------------------------------

--
-- Table structure for table `reg_tour`
--

CREATE TABLE `reg_tour` (
  `uni` int(11) NOT NULL,
  `id` int(11) NOT NULL,
  `tipo` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `reg_tour`
--

INSERT INTO `reg_tour` (`uni`, `id`, `tipo`) VALUES
(18, 74, NULL),
(19, 75, NULL),
(21, 77, NULL),
(22, 78, NULL),
(23, 79, NULL),
(26, 82, NULL),
(27, 83, NULL),
(28, 84, NULL),
(29, 85, NULL),
(30, 86, NULL),
(31, 87, NULL),
(32, 88, NULL),
(33, 89, NULL),
(34, 90, NULL),
(35, 91, NULL),
(36, 92, NULL),
(37, 93, NULL),
(38, 94, NULL),
(39, 95, NULL),
(40, 96, NULL);

--
-- Triggers `reg_tour`
--
DELIMITER $$
CREATE TRIGGER `INS_all` AFTER UPDATE ON `reg_tour` FOR EACH ROW INSERT INTO all_tour (ID, tipo) VALUES (NEW.id, NEW.tipo)
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `reporteria`
--

CREATE TABLE `reporteria` (
  `ID_Reporteria` int(11) NOT NULL,
  `num_habitacion` int(11) NOT NULL,
  `checkout` date NOT NULL,
  `recaudado` int(11) NOT NULL,
  `calificacion` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `reservas`
--

CREATE TABLE `reservas` (
  `RUT` int(11) NOT NULL,
  `CHECK_IN` date NOT NULL,
  `CHECK_OUT` date NOT NULL,
  `N_HABITACION` int(11) NOT NULL,
  `ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `reservas`
--

INSERT INTO `reservas` (`RUT`, `CHECK_IN`, `CHECK_OUT`, `N_HABITACION`, `ID`) VALUES
(20000000, '2024-06-05', '2024-06-08', 17, 74),
(21438609, '2024-06-01', '2024-06-05', 5, 75),
(21000000, '2024-06-01', '2024-06-02', 13, 77),
(21000000, '2024-06-05', '2024-06-06', 4, 78),
(12345678, '2024-06-06', '2024-06-09', 5, 79),
(25836914, '2024-06-01', '2024-06-05', 16, 82),
(21438609, '2024-06-06', '2024-07-08', 8, 83),
(20242023, '2024-06-07', '2024-06-11', 9, 84),
(20212586, '2024-06-07', '2024-06-20', 11, 85),
(20000000, '2024-06-01', '2024-06-04', 17, 86),
(21458965, '2024-07-01', '2024-07-05', 1, 87),
(21458965, '2024-07-01', '2024-07-05', 19, 88),
(23568974, '2024-06-05', '2024-06-20', 20, 89),
(21546789, '2024-06-20', '2024-06-25', 16, 90),
(22165498, '2024-06-22', '2024-07-01', 14, 91),
(18976431, '2024-06-05', '2024-06-15', 12, 92),
(16789453, '2024-06-20', '2024-06-23', 10, 93),
(14734627, '2024-06-01', '2024-06-17', 3, 94),
(14734627, '2024-06-30', '2024-07-02', 3, 95),
(21438609, '2024-06-21', '2024-06-27', 4, 96);

--
-- Triggers `reservas`
--
DELIMITER $$
CREATE TRIGGER `INS_reg_tour` AFTER INSERT ON `reservas` FOR EACH ROW INSERT INTO reg_tour (id) VALUE (NEW.ID)
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `tour`
--

CREATE TABLE `tour` (
  `id` int(11) NOT NULL,
  `Tipo` int(11) NOT NULL,
  `fecha` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tour`
--

INSERT INTO `tour` (`id`, `Tipo`, `fecha`) VALUES
(1, 1, '2024-06-01'),
(2, 1, '2024-06-02'),
(3, 2, '2024-06-03'),
(4, 2, '2024-06-01'),
(5, 1, '2024-06-03'),
(6, 3, '2024-06-02'),
(7, 4, '2024-06-02'),
(8, 5, '2024-06-08'),
(9, 3, '2024-06-08'),
(10, 4, '2024-06-08'),
(11, 5, '2024-06-09'),
(12, 2, '2024-06-08'),
(13, 5, '2024-06-24'),
(14, 3, '2024-06-30'),
(15, 2, '2024-07-01'),
(16, 1, '2024-06-17'),
(17, 4, '2024-06-21'),
(18, 1, '2024-06-19');

-- --------------------------------------------------------

--
-- Table structure for table `type`
--

CREATE TABLE `type` (
  `ID` int(11) NOT NULL,
  `Type` varchar(6) NOT NULL,
  `Price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `type`
--

INSERT INTO `type` (`ID`, `Type`, `Price`) VALUES
(1, 'Single', 100),
(2, 'Double', 300),
(3, 'King', 700);

-- --------------------------------------------------------

--
-- Stand-in structure for view `view_all_tour`
-- (See below for the actual view)
--
CREATE TABLE `view_all_tour` (
`ID` int(11)
,`RUT` int(11)
,`N_HABITACION` int(11)
,`CHECK_IN` date
,`CHECK_OUT` date
,`Place` varchar(50)
,`Price` int(11)
,`fecha` date
,`tipo` int(11)
);

-- --------------------------------------------------------

--
-- Stand-in structure for view `view_reserva`
-- (See below for the actual view)
--
CREATE TABLE `view_reserva` (
`RUT` int(11)
,`N_HABITACION` int(11)
,`CHECK_IN` date
,`CHECK_OUT` date
,`Type` varchar(6)
,`Price` int(11)
);

-- --------------------------------------------------------

--
-- Stand-in structure for view `view_tours`
-- (See below for the actual view)
--
CREATE TABLE `view_tours` (
`id` int(11)
,`Place` varchar(50)
,`fecha` date
,`Transport` varchar(20)
,`Price` int(11)
,`Image` varchar(9000)
);

-- --------------------------------------------------------

--
-- Structure for view `view_all_tour`
--
DROP TABLE IF EXISTS `view_all_tour`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `view_all_tour`  AS SELECT `all_tour`.`ID` AS `ID`, `all_tour`.`RUT` AS `RUT`, `all_tour`.`N_HABITACION` AS `N_HABITACION`, `all_tour`.`CHECK_IN` AS `CHECK_IN`, `all_tour`.`CHECK_OUT` AS `CHECK_OUT`, `list_tour`.`Place` AS `Place`, `list_tour`.`Price` AS `Price`, `tour`.`fecha` AS `fecha`, `tour`.`id` AS `tipo` FROM ((`tour` join `all_tour` on(`all_tour`.`tipo` = `tour`.`id`)) join `list_tour` on(`list_tour`.`ID` = `tour`.`Tipo`)) ;

-- --------------------------------------------------------

--
-- Structure for view `view_reserva`
--
DROP TABLE IF EXISTS `view_reserva`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `view_reserva`  AS SELECT `reservas`.`RUT` AS `RUT`, `habitacion`.`N_HABITACION` AS `N_HABITACION`, `reservas`.`CHECK_IN` AS `CHECK_IN`, `reservas`.`CHECK_OUT` AS `CHECK_OUT`, `type`.`Type` AS `Type`, `type`.`Price` AS `Price` FROM ((`habitacion` join `reservas` on(`habitacion`.`N_HABITACION` = `reservas`.`N_HABITACION`)) join `type` on(`habitacion`.`Type` = `type`.`ID`)) ;

-- --------------------------------------------------------

--
-- Structure for view `view_tours`
--
DROP TABLE IF EXISTS `view_tours`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `view_tours`  AS SELECT `tour`.`id` AS `id`, `list_tour`.`Place` AS `Place`, `tour`.`fecha` AS `fecha`, `list_tour`.`Transport` AS `Transport`, `list_tour`.`Price` AS `Price`, `list_tour`.`Image` AS `Image` FROM (`tour` join `list_tour` on(`list_tour`.`ID` = `tour`.`Tipo`)) ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `habitacion`
--
ALTER TABLE `habitacion`
  ADD PRIMARY KEY (`N_HABITACION`),
  ADD KEY `Type` (`Type`);

--
-- Indexes for table `list_tour`
--
ALTER TABLE `list_tour`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `reg_tour`
--
ALTER TABLE `reg_tour`
  ADD PRIMARY KEY (`uni`),
  ADD KEY `id` (`id`),
  ADD KEY `tipo` (`tipo`);

--
-- Indexes for table `reporteria`
--
ALTER TABLE `reporteria`
  ADD PRIMARY KEY (`ID_Reporteria`);

--
-- Indexes for table `reservas`
--
ALTER TABLE `reservas`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `N_HABITACION` (`N_HABITACION`) USING BTREE;

--
-- Indexes for table `tour`
--
ALTER TABLE `tour`
  ADD PRIMARY KEY (`id`),
  ADD KEY `Tipo` (`Tipo`);

--
-- Indexes for table `type`
--
ALTER TABLE `type`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `list_tour`
--
ALTER TABLE `list_tour`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `reg_tour`
--
ALTER TABLE `reg_tour`
  MODIFY `uni` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;

--
-- AUTO_INCREMENT for table `reporteria`
--
ALTER TABLE `reporteria`
  MODIFY `ID_Reporteria` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `reservas`
--
ALTER TABLE `reservas`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=97;

--
-- AUTO_INCREMENT for table `tour`
--
ALTER TABLE `tour`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `type`
--
ALTER TABLE `type`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `habitacion`
--
ALTER TABLE `habitacion`
  ADD CONSTRAINT `habitacion_ibfk_1` FOREIGN KEY (`Type`) REFERENCES `type` (`ID`);

--
-- Constraints for table `reg_tour`
--
ALTER TABLE `reg_tour`
  ADD CONSTRAINT `reg_tour_ibfk_1` FOREIGN KEY (`id`) REFERENCES `reservas` (`ID`) ON DELETE CASCADE,
  ADD CONSTRAINT `reg_tour_ibfk_2` FOREIGN KEY (`tipo`) REFERENCES `tour` (`id`);

--
-- Constraints for table `reservas`
--
ALTER TABLE `reservas`
  ADD CONSTRAINT `N_HABITACION` FOREIGN KEY (`N_HABITACION`) REFERENCES `habitacion` (`N_HABITACION`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `tour`
--
ALTER TABLE `tour`
  ADD CONSTRAINT `tour_ibfk_1` FOREIGN KEY (`Tipo`) REFERENCES `list_tour` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
