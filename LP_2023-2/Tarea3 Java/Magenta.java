public class Magenta extends Pikinim{
    Magenta(){
        /*
         * Parametros: Ninguno
         * 
         * Inicializa a los pikinims Magenta con sus
         * respectivos valores iniciales
         * 
         * return: Nada
         */
        setAtaque(2);
        setCapacidad(1);
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
         * su formula, en este caso cantidad * su ataque.
         * 
         * return: Nada
         */
        setCantidad(getCantidad() + cantidad * getAtaque());
    }
}
