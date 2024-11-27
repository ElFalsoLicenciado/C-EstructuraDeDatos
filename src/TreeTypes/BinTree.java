package TreeTypes;

import Utils.DialogHelper;

public class BinTree {
    Node1 root;

    public BinTree() {
        root = null;
    }

    public void insertNode(int val) {
        if (root == null) {
            root = new Node1(val);
        } else
            insert(root, val);
    }

    private void insert(Node1 node, int val) {
        if (val > node.checkValue()) {
            if (node.checkLeft() == null) node.left = new Node1(val);
            else insert(node.checkLeft(), val);
        } else if (val < node.checkValue()) {
            if (node.checkRight() == null) node.right = new Node1(val);
            else insert(node.checkRight(), val);
        } else DialogHelper.warning("No se pueden valores repetidos.");
    }


    public String print(Node1 node) {
        StringBuilder treeString = new StringBuilder();
        if (node != null) {
            treeString.append(node.checkValue()).append(" ");
            treeString.append(print(node.checkLeft()));
            treeString.append(print(node.checkRight()));
        }
        return treeString.toString();
    }

    public Node1 getRoot() {
        return root;
    }
}


class Node1 {

    int val;
    public Node1 left;
    public Node1 right;

    public Node1(int val) {
        this.val = val;
        left = null;
        right = null;
    }

    public int checkValue() {
        return val;
    }

    public Node1 checkLeft() {
        return left;
    }

    public Node1 checkRight() {
        return right;
    }

}

