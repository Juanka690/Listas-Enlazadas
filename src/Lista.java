import java.util.Scanner;

public class Lista {
    private Nodo head = null;

    public Lista() {
    }

    public void crearLista() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingrese enteros o -1 para terminar");

        for(int dato = sc.nextInt(); dato != -1; dato = sc.nextInt()) {
            this.head = new Nodo(dato, this.head);
        }

        sc.close();
    }

    public void visualizarLista() {
        Nodo temp = this.head;
        if (temp == null) {
            System.out.println("La lista está vacía");
        } else {
            while(true) {
                if (temp == null) {
                    System.out.println();
                    break;
                }

                System.out.print(temp.getData() + " | ");
                temp = temp.getLink();
            }
        }

    }

    public void insertarAlaCabeza(int dato) {
        Nodo nuevo = new Nodo(dato);
        nuevo.setLink(this.head);
        this.head = nuevo;
    }

    public void insertarALaCola(int dato) {
        Nodo ultimo = new Nodo(dato);
        Nodo temp = this.head;
        if (temp == null) {
            this.head = ultimo;
        } else {
            while(true) {
                if (temp.getLink() == null) {
                    temp.setLink(ultimo);
                    break;
                }

                temp = temp.getLink();
            }
        }

    }

    public void insertarEnIndice(int dato, int indice) {
        if (indice < 0) {
            System.out.println("Índice inválido");
        } else {
            Nodo nuevo = new Nodo(dato);
            if (indice == 0) {
                nuevo.setLink(this.head);
                this.head = nuevo;
            } else {
                Nodo temp = this.head;

                for(int contador = 0; temp != null && contador < indice - 1; ++contador) {
                    temp = temp.getLink();
                }

                if (temp == null) {
                    System.out.println("Índice inválido");
                } else {
                    nuevo.setLink(temp.getLink());
                    temp.setLink(nuevo);
                }
            }

        }
    }
}