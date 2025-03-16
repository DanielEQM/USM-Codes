public class Pieza extends Zona implements Ilevantable {
    private int peso;

    public Pieza(int peso){
        /*
         * Parametros: int peso
         * 
         * Inicializa a las Piezas, con sus respectivos
         * parametros y dandole su valor de completada por super
         * a la clase padre.
         * 
         * return: Nada
         */
        super(false);
        this.peso = peso;
    }
    
    //setter de Peso
    public void setPeso(int peso){
        this.peso = peso;
    }

    //getter de Peso
    public int getPeso(){
        return peso;
    }

    public void Levantar(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * Intenta Levantar la pieza, en caso de que la capacidad
         * de los pikinims sea mayor o igual al peso de la pieza,
         * se setea completada con true. Si
         * no pasa el caso anterior, no pasa nada.
         * 
         * return: Nada
         */
        int levantar = 0;
        for(Pikinim p: pikinims){
            levantar += p.getCantidad() * p.getCapacidad();
        }
        System.out.println("Lomiar: Todos estan intentando levantar la pieza, espero lo logremos");
        if(levantar >= getPeso()){
            System.out.println("Lomiar: ¡Con la ayuda de todos lo hemos podido levantar!");
            System.out.println("        Que alivio que no hubo problemas");
            Juego.piezasE--;
            setCompletada(true);
        } else {
            System.out.println("Lomiar: Me lo imaginaba, no somos suficientes para levantarla");
            System.out.println("        Lo mejor es buscar otro camino para llevarnosla luego");
        }
    }
    
    public void interactuar(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * Manda a los pikinims a intentar levantar la pieza en caso de
         * que la zona no este completada, caso contrario, llama al super.
         * 
         * return: Nada
         */
        if(!getCompletada()){
            System.out.println("Lomiar: He encontrado una pieza afortunadamente, me pregunto");
            System.out.println("        si seremos suficientes para llevarla...");
            Levantar(pikinims);
        }else{
            super.interactuar(pikinims);
        }
    }
    
    public void tipeZone(){
        /*
         * Parametros: Ninguno
         * 
         * Imprime un texto para la ambientación del
         * juego en caso de que la zona no esta completada,
         * caso contrario, llama a super.
         * 
         * return: Nada
         */
        System.out.println("---->>> Zona Pieza <<<----\n");
        if(!getCompletada()){
            System.out.println("Lomiar: Despues de caminar un rato, me encontre una pieza de mi nave!");
            System.out.println("        Me pregunto si ahora podemos llevarla...");
            System.out.println("(Esta Pieza pesa "+getPeso()+", se necesitaran muchos pikinims para levantarla");
            System.out.println("afortunadamente Lomiar cuenta con varios para ayudarlo)\n");
        } else {
            super.tipeZone();
        }
    }

    public String datos(){
        /*
         * Parametros: Ninguno
         * 
         * Imprime un texto al lado de las opciones
         * de dirección, para darle info al jugador.
         * 
         * return:  - "Pieza "+super.datos()
         *          - "Pieza, peso: "+getPeso()
         */
        if(getCompletada()){
            return "Pieza "+super.datos();
        }
        return "Pieza, peso: "+getPeso();
    }
}
