public class Zona {
    private boolean completada;

    public Zona(boolean completada){
        /*
         * Parametros: boolean completada
         * 
         * Inicializa las zonas.
         * 
         * return: Nada
         */
        this.completada = completada;
    }

    //getter de Completada
    public boolean getCompletada(){
        return completada;
    }

    //setter de Completada
    public void setCompletada(boolean completada){
        this.completada = completada;
    }

    public void interactuar(Pikinim[] pikinims){
        /*
         * Parametros: Pikinim[] pikinims
         * 
         * Imprime en la consola un mensaje de que la zona
         * esta completada.
         * 
         * return: Nada
         */
        System.out.println("Lomiar: Estare dando vueltas en circulos...? siento que esta zona ya la");
        System.out.println("        he visto, supongo que ya pase por acá...\n");
    }

    public void tipeZone(){
        /*
         * Parametros: Ninguno
         * 
         * Imprime un texto para la ambientación del
         * juego.
         * 
         * return: Nada
         */
        System.out.println("Lomiar: Parece que ya he explorado esta zona...");
        System.out.println("        A este paso me quedaré sin oxigeno... Tengo que apurarme...\n");
    }
    
    public String datos(){
        /*
         * Parametros: Ninguno
         * 
         * Imprime un texto al lado de las opciones
         * de dirección, para darle info al jugador.
         * 
         * return: "Completado"
         */
        return "Completado";
    }
}