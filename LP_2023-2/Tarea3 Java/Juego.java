import java.util.Random;
import java.util.Scanner;

public class Juego{
    static int piezasE = 3;
    static Scanner scanner = new Scanner(System.in);
    static Random random = new Random();

    public static void main(String[] args){
        int turnos = 0, pos = 5, antPos = 0, bloqueo = 0, cantPikinim = 1;
        Amarillo amarillo = new Amarillo();
        Magenta magenta = new Magenta();
        Cyan cyan = new Cyan();
        Pieza pieza0 = new Pieza(50);
        Enemigo enemigo1 = new Enemigo(130, 20, 25);
        Enemigo enemigo2 = new Enemigo(50, 20, 15);
        Pildora pildora3 = new Pildora(25);
        Muralla muralla4 = new Muralla(50);
        Pieza pieza5 = new Pieza(100);
        Enemigo enemigo6 = new Enemigo(45,8, 10);
        Pieza pieza7 = new Pieza(35);
        Pildora pildora8 = new Pildora(15);
        Enemigo enemigo9 = new Enemigo(75, 15, 20);
        Muralla muralla10 = new Muralla(150);
        Zona[] zonas = {pieza0, enemigo1, enemigo2, pildora3, muralla4, pieza5, enemigo6, pieza7, pildora8,enemigo9, muralla10};
        Pikinim[] pikinims = {amarillo, magenta, cyan};
        System.out.println("\nDespues de un gran inconveniente, Lomiar a aterrizado en un planeta desconocido\nUnas extrañas criaturas de este planeta parece que le van a ayudar...");
        while((piezasE != 0) && (turnos != 30) && (cantPikinim != 0)){
            System.out.println("\n >>> ¡Turno "+(turnos + 1)+"! <<<\n");
            System.out.println("Tienes los siguientes Pikinims:\n__________\nAmarillos >> "+pikinims[0].getCantidad()+"\n Magenta  >> "+pikinims[1].getCantidad()+"\n   Cyan   >> "+pikinims[2].getCantidad()+"\n___________________");        
            System.out.println(" >> Piezas encontradas: "+(3-piezasE)+"\n >> Posicion en el mapa: "+pos+"\n___________________\n");
            zonas[pos%11].tipeZone();
            System.out.println("Lomiar: Me pregunto que es lo mejor que puedo hacer...");
            if(pos - 1 == -1){
                pos = 11;
                antPos = 0;
            }
            if(zonas[pos%11].getClass().equals(Muralla.class) && !zonas[pos%11].getCompletada()){
                if((pos < antPos) || (pos == 10 && antPos == 0)){
                    System.out.println("[1] Ir a la izquierda     (Zona Bloqueada)");
                    System.out.println("[2] Ir a la derecha       (Zona "+zonas[(pos+1)%11].datos()+")");
                    System.out.println("[3] Quedarse en esta zona (Zona "+zonas[pos%11].datos()+")");
                    bloqueo = 1;
                } else if (pos > antPos){   
                    System.out.println("[1] Ir a la izquierda     (Zona "+zonas[(pos-1)%11].datos()+")");
                    System.out.println("[2] Ir a la derecha       (Zona Bloqueada)");
                    System.out.println("[3] Quedarse en esta zona (Zona "+zonas[pos%11].datos()+")");
                    bloqueo = 2;
                }
            } else {
                System.out.println("[1] Ir a la izquierda     (Zona "+zonas[(pos-1)%11].datos()+")");
                System.out.println("[2] Ir a la derecha       (Zona "+zonas[(pos+1)%11].datos()+")");
                System.out.println("[3] Quedarse en esta zona (Zona "+zonas[pos%11].datos()+")");
                bloqueo = 0;
            }
            System.out.print("Cual es tu elección: "); 
            int opt = scanner.nextInt();
            System.out.println();
            if(opt == 1){
                if (bloqueo == 1){
                    System.out.println("(Lomiar intenta pasar pero se choca con la Muralla Brutalmente)");
                    System.out.println("Lomiar: No debería intentar pasar a la fuerza...");
                } else {
                    zonas[(pos-1)%11].interactuar(pikinims);
                    antPos = pos % 11;
                    pos--;
                    pos = pos % 11;
                    turnos++;
                }
            } else if(opt == 2){
                if (bloqueo == 2){
                    System.out.println("(Lomiar intenta pasar pero se choca con la Muralla Brutalmente)");
                    System.out.println("Lomiar: No debería intentar pasar a la fuerza...");
                } else {
                    zonas[(pos+1)%11].interactuar(pikinims);
                    antPos = pos % 11;
                    pos++;
                    pos = pos % 11;
                    turnos++;
                }
            } else if(opt == 3){
                zonas[pos%11].interactuar(pikinims);
                turnos++;
            }
            cantPikinim = pikinims[0].getCantidad() + pikinims[1].getCantidad() + pikinims[2].getCantidad();
            System.out.println("________________________________\n");
        }
        if (piezasE == 0){
            System.out.println("Lomiar: He logrado recuperar todas las piezas antes");
            System.out.println("        que se me acabe el oxigeno, ahora puedo volver");
            System.out.println("        a casa sin problemas");
        } else if (turnos == 30){
            System.out.println("(Lomiar se cae en medio de la zona "+zonas[pos].getClass().getName()+")");
            System.out.println("Lomiar: Me cuesta respirar de hace un rato, creo que el");
            System.out.println("        tanque de oxigeno se agoto. Me pregunto porque me");
            System.out.println("        miran asi estas criaturas... Parece que me llevan");
            System.out.println("        algun lado... Pero ya no tengo fuerzas\n");
            System.out.println(" >>> HAS PERDIDO D: (MEJOR SUERTE PARA LA PROXIMA!) <<<");
        } else if (cantPikinim == 0){
            System.out.println("Lomiar: Ese enemigo a eliminado a todos mis compañeros");
            System.out.println("        ya no tengo quien me ayude...");
            System.out.println("        Supongo que es mi final en este mundo");
            System.out.println("(Lomiar cae en la desesperacion y antes de darse cuenta se\n agoto el tanque de oxigeno que llevaba)\n");
            System.out.println(" >>> HAS PERDIDO D: (MEJOR SUERTE PARA LA PROXIMA!) <<<");            
        }
        scanner.close();
    }
}