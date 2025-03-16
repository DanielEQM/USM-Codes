import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Collections;
import java.util.Comparator;

public class FuerzaIntergalactica {

    public static List<String> listFilesForFolder(final File folder) throws Exception {
        List<String> listM = new ArrayList<>();

        for (final File fileEntry : folder.listFiles()) {
            listM.add(fileEntry.getName());
        }

        Collections.sort(listM, new Comparator<String>() {
            public int compare(String s1, String s2) {
                int s1Num = Integer.valueOf(s1.split("code")[1]);
                int s2Num = Integer.valueOf(s2.split("code")[1]);
                return Integer.compare(s1Num, s2Num);
            }
        });
        /*****************
        * método: compare
        * ***************
        * parámetros: String s1 (nombre archivo de texto 1), String s2 (nombre archivo de texto 2)
        * ***************
        * descripción: Compara el número asociado al archivo, ordenandolos desde 1 hasta N,
        * donde N es la cantidad de archivos en total.
        */
        return listM;
    }
    /*****************
     * método: listFilesForFolder
     * ***************
     * parámetros: final File folder (carpeta con los casos)
     * ***************
     * descripción: Retorna una lista con los nombres de la carpeta 
     * seguido de los archivos de texto ordenados del 1 al n.
    */

    public static void main(String arg[]) throws Exception {
        final File folder = new File("Caso1");

        List<String> listM = listFilesForFolder(folder);
        double totalExecutionTime = 0;

        List<Character> resultados = new ArrayList<>();

        for (String fileEntry : listM) {
            File file = new File(folder + "/" + fileEntry);
            Scanner readF = new Scanner(file);
            String data = readF.nextLine();
            int n = Integer.parseInt(data.split("x")[0]);

            char[][] matrix = new char[n][n];
            int row = 0;

            while (readF.hasNextLine()) {
                data = readF.nextLine();
                String[] elements = data.split(" ");
                for (int col = 0; col < elements.length; col++) {
                    matrix[row][col] = elements[col].charAt(0);
                }
                row++;
            }
            readF.close();

            Hebras recorrerMatrix = new Hebras(matrix, 0, matrix.length - 1, 0, matrix[0].length - 1, resultados);

            long startTime = System.nanoTime();
            recorrerMatrix.start();
            recorrerMatrix.join();
            long endTime = System.nanoTime();

            // Verificación de que `resultados` no esté vacío antes de acceder
            if (!resultados.isEmpty()) {
                System.out.println("La letra encontrada es: " + resultados.get(resultados.size() - 1));
            } else {
                System.out.println("No se encontró ningún carácter distinto de cero en la matriz.");
            }

            double searchTime = (endTime - startTime) / 1_000_000_000.0;
            totalExecutionTime += searchTime;

            System.out.println("El tiempo utilizado para completar la búsqueda fue: "
                    + String.format("%.4f", searchTime) + " segundos");
        }

        System.out.print("La palabra formada es: ");
        for (char c : resultados) {
            System.out.print(c);
        }
        System.out.println();

        System.out.println(
                "Tiempo de ejecución empleado: " + String.format("%.4f", totalExecutionTime) + " segundos");
    }
}
