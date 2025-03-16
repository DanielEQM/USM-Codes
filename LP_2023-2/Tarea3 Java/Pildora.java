public class Pildora extends Zona {
    private int cantidad;

    public Pildora(int cantidad){
        /*
         * Parametros: int cantidad
         * 
         * Inicializa a las Pildoras, con sus respectivos
         * parametros y dandole su valor de completada por super
         * a la clase padre.
         * 
         * return: Nada
         */
        super(false);
        this.cantidad = cantidad;
    }

    //setter de cantidad
    public void setCantidad(int cantidad){
        this.cantidad = cantidad;
    }

    //getter de cantidad
    public int getCantidad(){
        return cantidad;
    }

    public void interactuar(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * En caso de que no este completada, multiplica a los pikinims
         * que el usuario escogio y setea completada a true. Caso contrario, 
         * llama al super.
         * 
         * return: Nada
         */
        if(!getCompletada()){
            System.out.println("Lomiar: Parece que a las criaturas les interesa mucho esta rara");
            System.out.println("        pildora, tal vez se la deba dar a alguno de estos...");
            System.out.println("(Escoge el tipo de Pikinim al que se la quieres entregar)");
            System.out.println("[1] >> Amarillo\n[2] >> Magenta\n[3] >> Cyan");
            System.out.print("Lomiar: Ya me decidi, se la entregare a: "); 
            int opt = Juego.scanner.nextInt();
            System.out.print("(Tus pikinim de color "+pikinims[opt-1].getClass().getCanonicalName()+" han aumentado de "+pikinims[opt-1].getCantidad());
            switch(opt){
                case 1: pikinims[0].multiplicarse(getCantidad()); break;
                case 2: pikinims[1].multiplicarse(getCantidad()); break;
                case 3: pikinims[2].multiplicarse(getCantidad()); break;
            }
            System.out.println(" a "+pikinims[opt-1].getCantidad()+")");
            setCompletada(true);  
        } else {
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
        System.out.println("---->>> Zona Pildora <<<----\n");
        if(!getCompletada()){
            System.out.println("Lomiar: No se donde me encuento, pero me encontre una pildora muy rara...");
            System.out.println("        Parece que estas criaturas les gusta esa cosa, tal vez sea mejor darselas...\n");
            System.out.println("(Hay "+getCantidad()+" Pildoras, podrás multiplicar alguno de tus pikinims!)");
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
         * return:  - "Pildora "+super.datos()
         *          - "Pildora hay "+getCantidad()+" Pildoras"
         */
        if(getCompletada()){
            return "Pildora "+super.datos();
        }
        return "Pildora hay "+getCantidad()+" Pildoras";
    }
}
