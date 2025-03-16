public class Amarillo extends Pikinim{

    Amarillo(){
        /*
         * Parametros: Ninguno
         * 
         * Inicializa a los pikinims Amarillos con sus
         * respectivos valores iniciales
         * 
         * return: Nada
         */
        setAtaque(1);
        setCapacidad(3);
        setCantidad(10);
    }

    public void disminuir(int cantidad){
        /*
         * Parametros: int cantidad
         * 
         * recibe una cantidad y se la resta a la cantidad
         * de pikinims que hay (No baja de 0)
         * 
         * return: Nada
         */
        setCantidad(getCantidad() - cantidad);
        if(getCantidad() < 0){
            setCantidad(0);
        }
    }

    public void multiplicarse(int cantidad){
        /*
         * Parametros: int cantidad
         * 
         * recibe una cierta cantidad y este se multiplica segun
         * su formula, en este caso cantidad * 1.5 aproximado.
         * 
         * return: Nada
         */
        setCantidad(getCantidad() + (int) Math.ceil(cantidad * 1.5));
    }
}
