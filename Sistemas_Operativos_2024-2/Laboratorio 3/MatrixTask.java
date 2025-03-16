import java.util.concurrent.RecursiveTask;

 class MatrixTask extends RecursiveTask<Character> {
    private final char[][] matrix;
    private final int rowStart, rowEnd, colStart, colEnd;

    public MatrixTask(char[][] matrix, int rowStart, int rowEnd, int colStart, int colEnd) {
        this.matrix = matrix;
        this.rowStart = rowStart;
        this.rowEnd = rowEnd;
        this.colStart = colStart;
        this.colEnd = colEnd;
    }

    /*****************
     * método: MatrixTask
     * ***************
     * parámetros: char[][] matrix (matriz de inicio), int rowStart (inicio de fila), int rowEnd (termino de fila),
     * int colStart (comienzo de columna), int colEnd (termino de columna).
     * ***************
     * descripción: Constructor de la clase MatrixTask para inicializar los valores dichos en los parámetros.
    */

    public Character compute() {
        // Si el área es un único elemento, busca sin dividir
        if ((rowEnd - rowStart) <= 1 && (colEnd - colStart) <= 1) {
            return matrix[rowStart][colStart];
        }

        // División de la matriz en submatrices
        int midRow = rowStart + (rowEnd - rowStart) / 2;
        int midCol = colStart + (colEnd - colStart) / 2;

        MatrixTask topLeft = new MatrixTask(matrix, rowStart, midRow, colStart, midCol);
        MatrixTask topRight = new MatrixTask(matrix, rowStart, midRow, midCol, colEnd);
        MatrixTask bottomLeft = new MatrixTask(matrix, midRow, rowEnd, colStart, midCol);
        MatrixTask bottomRight = new MatrixTask(matrix, midRow, rowEnd, midCol, colEnd);

        invokeAll(topLeft, topRight, bottomLeft, bottomRight);

        char[] results = {topLeft.join(), topRight.join(), bottomLeft.join(), bottomRight.join()};
        for (char result : results) {
            if (result != '0') return result;
        }
        return '0';
    }
}
     /*****************
     * método: compute
     * ***************
     * parámetros: no tiene
     * ***************
     * descripción: Realiza una llamada recursiva para dividir la matriz en 4 subsegmentos, en donde
     * por cada uno de ellos busca el carácter distinto de cero. Al encontrarlo, retorna.
    */
