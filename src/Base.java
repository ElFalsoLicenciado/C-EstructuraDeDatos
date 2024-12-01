import Utils.DialogHelper;
import java.util.ArrayList;
import java.util.Random;


public class Base
{
    static Random rand = new Random();

    public static void main(String[] args)
    {
        ArrayList<Integer> arreglo = new ArrayList<>();
        for (int i = 0; i < rand.nextInt(11) + 6; i++)
            arreglo.add(i+1);
        imprimir(arreglo);

        boolean flag = false;

        while (!flag)
        {
            switch (DialogHelper.optionD("Búsqueda binaria.",new String[]{"Buscar","Agregar","Imprimir","Salir"})+1)
            {
                case 1 -> resultado(arreglo,arreglo.size()-1);
                case 2 ->
                {
                    if (DialogHelper.optionD("Elige:",new String[]{"Desde 0","Lista predefinida"})==1)
                        insertar(arreglo);
                    else
                    {
                        ArrayList<Integer> cero = inicializar();
                        imprimir(cero);
                        reordenar(cero,0,cero.size()-1);
                        imprimir(cero);
                    }
                }
                case 3 -> imprimir(arreglo);
                case 4 -> flag = true;
            }
        }
    }

    private static int bus_binaria(ArrayList<Integer> a, int n, int l, int r)
    {
        int m = l + (r - l)/2;

        if (l >= r && a.get(m) != n)
            return -1;
        if (a.get(m) == n)
            return m;
        else if (a.get(m) > n)
            return bus_binaria(a, n, l, m - 1);
        else
            return bus_binaria(a, n, m + 1, r);
    }

    public static ArrayList<Integer> inicializar()
    {
        ArrayList<Integer> arreglo = new ArrayList<>();
        while (true)
        {
            int input = DialogHelper.intIn("Dame un número\n0. Terminar",-1);

            if (input==0)
                break;
            else
                arreglo.add(input);
        }
        return arreglo;
    }

    public static void insertar(ArrayList<Integer> a)
    {
        int n = DialogHelper.intIn("Dame un número para insertar.",0);
        if (bus_binaria(a,n,0,a.size()-1) == -1) {
            a.add(n); reordenar(a,0,a.size()-1);
            imprimir(a);
        }
        else
            DialogHelper.error("No se puede números repetidos.");
    }


    private static void reordenar(ArrayList<Integer> a,  int low, int high)
    {
        if (low <= high)
        {
            int pivotIndex = pastel(a, low, high);
            reordenar(a, low, pivotIndex - 1);
            reordenar(a, pivotIndex + 1, high);
        }
    }

    public static int pastel(ArrayList<Integer> a, int low, int high)
    {
        int pivot = a.get(high);
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (a.get(j) <= pivot) {
                i++;
                intercambio(a, i, j);
            }
        }
        intercambio(a, i + 1, high);
        return i + 1;
    }

    public static void intercambio(ArrayList<Integer> a, int x, int y) {
        int temp = a.get(x);
        a.set(x,a.get(y));
        a.set(y,temp);
    }

    public static void resultado(ArrayList<Integer> arreglo, int length)
    {
        int lugar = bus_binaria(arreglo,DialogHelper.intIn("Busca un número.",0),0,length);
        if (lugar != -1)
            DialogHelper.info(String.format("El número %d se encuentra en el índice %d.",arreglo.get(lugar),lugar));
        else
            DialogHelper.error("No se encontró el número.");
    }

    public static void imprimir(ArrayList<Integer> a)
    {
        DialogHelper.info(String.format("Numero de elementos: %s\nArreglo: %s ",a.size(), a));
    }
}