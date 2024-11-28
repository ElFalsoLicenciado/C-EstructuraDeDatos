import TreeTypes.*;
import Utils.DialogHelper;

import java.util.Random;


public class Base {
    static Random rand = new Random();

    public static void main(String[] args) {
        BinTree arbolBinario = new BinTree();
        BalBinTree arbolBinarioBalanceado = new BalBinTree();
        BTypeTree arbolB = new BTypeTree();
        NryTree arbolN = new NryTree();
        boolean exit = false;

        while (!exit) {
            switch (DialogHelper.optionD("Elige el tipo de árbol a usar", new String[]{"Sin balanceado", "Balanceado", "Arbol B", "Arbol N", "Salir"})) {
                case 0 -> menu1(arbolBinario);
                case 1 -> menu2(arbolBinarioBalanceado);
                case 2 -> {
                    if (!arbolB.isInitialized())
                        arbolB.setInitialized(DialogHelper.intIn("¿De qué orden el árbol tipo B?", 1));
                    menu3(arbolB);
                }
                case 3 -> menu4(arbolN);
                case 4 -> {
                    DialogHelper.warning("Saliendo.");
                    exit = true;
                }
            }
        }
    }

    public static BinTree menu1(BinTree arbolBinario) {
        boolean aux = false;
        while (!aux) {
            switch (DialogHelper.optionD("Árbol binario \n¿Qué quieres hacer?", new String[]{"Insertar", "Imprimir", "Salir"})) {
                case 0 -> //arbolBinario.insertNode(arbolBinario.getRoot(),DialogHelper.intIn("Dame un número.", 0));
                        arbolBinario.insertNode(rand.nextInt(1, 100));
                case 1 -> DialogHelper.info(arbolBinario.print(arbolBinario.getRoot()));
                case 2 -> aux = true;
            }
        }
        return arbolBinario;
    }

    public static BalBinTree menu2(BalBinTree arbolBinarioBalanceado) {
        boolean aux = false;
        while (!aux) {
            switch (DialogHelper.optionD("Árbol binario balanceado \n¿Qué quieres hacer?", new String[]{"Insertar", "Imprimir", "Salir"})) {
                case 0 -> arbolBinarioBalanceado.insertNode(rand.nextInt(1, 100));
                case 1 -> DialogHelper.info(arbolBinarioBalanceado.print(arbolBinarioBalanceado.getRoot()));
                case 2 -> aux = true;
            }
        }
        return arbolBinarioBalanceado;
    }

    public static BTypeTree menu3(BTypeTree arbolB) {
        boolean aux = false;
        while (!aux) {
            switch (DialogHelper.optionD("Árbol tipo B \n¿Qué quieres hacer?", new String[]{"Insertar", "Imprimir", "Salir"})) {
                case 0 -> arbolB.insertNode(rand.nextInt(1, 100));
                case 1 -> DialogHelper.info(arbolB.print(arbolB.getRoot()));
                case 2 -> aux = true;
            }
        }
        return arbolB;
    }

    public static NryTree menu4(NryTree arbolN) {
        boolean aux = false;
        while (!aux) {
            switch (DialogHelper.optionD("Árbol tipo N \n¿Qué quieres hacer?", new String[]{"Insertar", "Imprimir", "Salir"})) {
                case 0 -> {

                }
                case 1 -> {

                }
                case 2 -> aux = true;
            }
        }
        return arbolN;
    }


}