public class Muralla extends Zona {
    private int vida;

    public Muralla(int vida){
        /*
         * Parametros: int vida
         * 
         * Inicializa a las Murallas, con sus respectivos
         * parametros y dandole su valor de completada por super
         * a la clase padre.
         * 
         * return: Nada
         */
        super(false);
        this.vida = vida;
    }

    //setter de vida
    public void setVida(int vida){
        this.vida = vida;
    }

    //getter de vida
    public int getVida(){
        return vida;
    }

    public boolean TryRomper(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * Intenta romper la muralla, en caso de que el
         * ataque de los pikinims logran destruir la muralla
         * retorna true, caso contrario, retorna false.
         * 
         * return: - true
         *         - false
         */
        int poder = 0;
        for(Pikinim p: pikinims){
            poder += p.getAtaque() * p.getCantidad();
        }
        setVida(getVida() - poder);
        if(getVida() <= 0){
            System.out.println("Lomiar: Con la ayuda de todos logramos derribar el");
            System.out.println("        muro, ahora podremos seguir delante\n");
            setVida(0);
            return true;
        }
        else{
            System.out.println("Lomiar: Parece que no tenemos la suficiente fuerza");
            System.out.println("        derribarlo, es mejor intentar de nuevo\n");
            return false;
        }
    }

    public void interactuar(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * Envia a combatir a los pikinims e intentan destruir
         * la muralla en caso de que la zona no este completada,
         * y setea completada con el retorno de TryRomper.
         * Caso contrario, llama a super.
         * 
         * return: Nada
         */
        if(!getCompletada()){
            System.out.println("Lomiar: Hay una Muralla que bloquea el paso, espero");
            System.out.println("        que con el poder de estas criaturas podamos");
            System.out.println("        derribarlo\n");
            setCompletada(TryRomper(pikinims));
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
        System.out.println("---->>> Zona Muralla <<<----\n");
        if(!getCompletada()){
            System.out.println("Lomiar: Este muro me esta dando muchos problemas...");
            System.out.println("        Espero que podamos derrotarlo luego");
            System.out.println("        Parece que estas criaturas estan listos para el combate...\n");
            System.out.println("(Este muro tiene mucha resistencia, necesitas la fuerza de todos tus pikinims para");
            System.out.println(" bajarle "+getVida()+" de vida)\n");
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
         * return:  - "Muralla "+super.datos()
         *          - "Muralla, su vida es de: "+getVida()
         */
        if(getCompletada()){
            return "Muralla "+super.datos();
        }
        return "Muralla, su vida es de: "+getVida();
    }
}
