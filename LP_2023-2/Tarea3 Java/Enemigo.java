public class Enemigo extends Zona implements Ilevantable{
    private int vida;
    private int peso;
    private int ataque;

    public Enemigo(int vida, int peso, int ataque){
        /*
         * Parametros: int vida, int peso, int ataque
         * 
         * Inicializa a los Enemigos, con sus respectivos
         * parametros y dandole su valor de completada por super
         * a la clase padre.
         * 
         * return: Nada
         */
        super(false);
        this.vida = vida;
        this.peso = peso;
        this.ataque = ataque;
    }

    //setter de vida
    public void setVida(int vida){
        this.vida = vida;
    }

    //setter de Peso
    public void setPeso(int peso){
        this.peso = peso;
    }

    //setter de Ataque
    public void setAtaque(int ataque){
        this.ataque = ataque;
    }

    //getter de vida
    public int getVida(){
        return vida;
    }

    //getter de Peso
    public int getPeso(){
        return peso;
    }

    //getter de Ataque
    public int getAtaque(){
        return ataque;
    }

    public void Levantar(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * Intenta Levantar al Enemigo, en caso que los pikinims
         * logren levantar al enemigo, pueden reproducirse, en caso
         * contrario, termina.
         * 
         * return: Nada
         */
        int levantar = 0;
        for(Pikinim p: pikinims){
            levantar += p.getCapacidad() * p.getCantidad();
        }
        if(levantar >= getPeso()){
            System.out.println("Lomiar: Estas criaturas lograron levantar al enemigo");
            System.out.println("        (Escoge un tipo de Pikinim que quieras que se multiplique)");
            System.out.println("[1] >>> Amarillo\n[2] >>> Magenta\n[3] >>> Cyan");
            System.out.print("Lomiar: Creo que prefiero que se multipliquen: ");
            int opt = Juego.scanner.nextInt();
            System.out.print("(Tus pikinims "+pikinims[opt-1].getClass().getCanonicalName()+" han aumentado de "+pikinims[opt-1].getCantidad()+" a ");
            switch(opt){
                case 1: pikinims[0].multiplicarse(getPeso()); break;
                case 2: pikinims[1].multiplicarse(getPeso()); break;
                case 3: pikinims[2].multiplicarse(getPeso()); break;
            }
            System.out.println(pikinims[opt-1].getCantidad()+")");
        }
    }

    public boolean Pelear(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * Intenta Pelear con el enemigo, en caso de vencerlo, retorna True
         * en caso contrario, retorna false.
         * 
         * return: - true
         *         - false
         */
        int fuerza = 0;
        int ran = Juego.random.nextInt(3);
        for(Pikinim p: pikinims){
            fuerza += p.getAtaque() * p.getCantidad();
        }
        setVida(getVida() - fuerza);
        while (pikinims[ran].getCantidad() == 0){
            ran = Juego.random.nextInt(3);
        }
        int perdida = pikinims[ran].getCantidad();
        pikinims[ran].disminuir(getAtaque());
        perdida -= pikinims[ran].getCantidad();
        if(getVida() <= 0){
            System.out.println("Lomiar: Despues de un rato hemos podido vencerlo");
            System.out.println("        pero a usado su ultimo aliento para eliminar");
            System.out.println("        a "+perdida+" de color "+pikinims[ran].getClass().getCanonicalName()+"\n");
            setVida(0);
            return true;
        } else {
            System.out.println("Lomiar: No hemos podido vencerlo, y aparte");
            System.out.println("        hemos perdido a "+perdida+" de color "+pikinims[ran].getClass().getCanonicalName()+"\n");
        }
        return false;
    }

    public void interactuar(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * Envia a combatir a los pikinims y en caso de derrotar al
         * enemigo, lo intenta levantar, si lo derrota setea completada
         * con el return de Pelear.
         * Si esta completada, llama a Super.
         * 
         * return: Nada
         */
        if(!getCompletada()){
            System.out.println("Lomiar: Estas criaturas estan preparadas para");
            System.out.println("        para pelear, ¡Vayan amigos mios!");
            setCompletada(Pelear(pikinims));
            if(getCompletada()){
                Levantar(pikinims);
            }
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
        System.out.println("---->>> Zona Enemigo <<<----\n");
        if(!getCompletada()){
            System.out.println("Lomiar: Maldita sea, es un enemigo formidable");
            System.out.println("        Espero resistan estas criaturas...\n");
            System.out.println("(Este Enemigo es bastante resistente, tienes");
            System.out.println(" que usar toda tu fuerza para vencerlo)");
            System.out.println("----->>> Datos Enemigo <<<-----");
            System.out.println("Vida actual  >> "+getVida()+" HP\nAtaque Total >> "+getAtaque()+" DMG\nSu peso es   >> "+getPeso()+" W");
            System.out.println("-------------------------------\n");
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
         * return: - "Enemigo "+super.datos()
         *         - "Enemigo!! Su vida: "+getVida()+"| Su ataque: "+getAtaque()+"| Su peso: "+getPeso()
         */
        if(getCompletada()){
            return "Enemigo "+super.datos();
        }
        return "Enemigo!! Su vida: "+getVida()+"| Su ataque: "+getAtaque()+"| Su peso: "+getPeso();
    }
}