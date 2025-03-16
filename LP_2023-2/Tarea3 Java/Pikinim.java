public abstract class Pikinim {
    private int ataque;
    private int capacidad;
    private int cantidad;

    //setter de Ataque
    public void setAtaque(int ataque){
        this.ataque = ataque;
    }

    //setter de Capacidad
    public void setCapacidad(int capacidad){
        this.capacidad = capacidad;
    }

    //setter de Cantidad
    public void setCantidad(int cantidad){
        this.cantidad = cantidad;
    }

    //getter de Ataque
    public int getAtaque(){
        return ataque;
    }

    //getter de Capacidad
    public int getCapacidad(){
        return capacidad;
    }
    
    //getter de Cantidad
    public int getCantidad(){
        return cantidad;
    }

    public abstract void multiplicarse(int cantidad);
    public abstract void disminuir(int cantidad);
}