import java.util.List;

public class Hebras extends Thread{
    
    char[][] matrix;
    int row1;
    int row2;
    int col1;
    int col2;
    List<Character> resultados;

    public Hebras(char[][] matrix, int row1, int row2, int col1, int col2, List<Character> resultados){
        this.matrix = matrix;
        this.row1 = row1;
        this.row2 = row2;
        this.col1 = col1;
        this.col2 = col2;
        this.resultados = resultados;
    }

    /*****************
     * método: Hebras
     * ***************
     * parámetros: char[][] matrix (matriz de inicio), int size (tamaño de matriz), int row (fila),
     * int col (columna), List<Character> resultados (Lista con los carácteres encontrados).
     * ***************
     * descripción: Constructor de la clase Hebras para inicializar los valores dichos en los parámetros.
    */

    public void run(){
        if(col1 == col2 && row1 == row2){
            if(matrix[row1][col1] != '0') resultados.add(matrix[row1][col1]);
        } else if(col1 == col2) {
            int mitad = (row1 + row2) / 2;
            Hebras C1 = new Hebras(matrix, row1, mitad, col1, col2, resultados);
            Hebras C2 = new Hebras(matrix, mitad + 1, row2, col1, col2, resultados);

            C1.start(); C2.start();

            try{
                C1.join(); C2.join();
                
            } catch(InterruptedException ie) {
                Thread.currentThread().interrupt();
            }

        } else if(row1 == row2){
            int mitad = (col1 + col2) / 2;
            Hebras C1 = new Hebras(matrix, row1, row2, col1, mitad, resultados);
            Hebras C2 = new Hebras(matrix, row1, row2, mitad + 1, col2, resultados);

            C1.start(); C2.start();

            try{
                C1.join(); C2.join();
                
            } catch(InterruptedException ie) {
                Thread.currentThread().interrupt();
            }

        } else {
            int mitadR = (row1 + row2) / 2;
            int mitadC = (col1 + col2) / 2;

            Hebras C1 = new Hebras(matrix, row1, mitadR, col1, mitadC, resultados);
            Hebras C2 = new Hebras(matrix, mitadR + 1, row2, mitadC + 1, col2, resultados);
            Hebras C3 = new Hebras(matrix, row1, mitadR, mitadC + 1, col2, resultados);
            Hebras C4 = new Hebras(matrix, mitadR + 1, row2, col1, mitadC, resultados);

            C1.start(); C2.start(); C3.start(); C4.start();

            try{
                C1.join(); C2.join(); C3.join(); C4.join();

            } catch(InterruptedException ie) {
                Thread.currentThread().interrupt();
            }
        }
    }
    /*****************
     * método: run
     * ***************
     * parámetros: no tiene
     * ***************
     * descripción: Recorre la matriz diviendola recursivamente en 4 subsegmentos, donde cada uno
     * es asignado a una hebra y al final se hace un join, para que en caso de encontrarla se agregue
     * a resultados.
    */
}
