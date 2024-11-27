package TreeTypes;

import Utils.DialogHelper;

public class BalancedBinaryTree {

    Node2 root;

    public BalancedBinaryTree() {
        root = null;
    }

    public void insertNode(Node2 node, int val) {
        if (root == null)
            root = new Node2(val);
        else
            insert(root, val);
    }

    private void insert(Node2 node, int val) {
        if (val > node.checkValue()) {
            if (node.checkLeft() == null) node.left = new Node2(val);
            else insert(node.checkLeft(), val);

        } else if (val < node.checkValue()) {
            if (node.checkRight() == null) node.right = new Node2(val);
            else insert(node.checkRight(), val);
        } else
            DialogHelper.warning("No se pueden valores repetidos.");


    }

    public int getBalance(Node2 node) {
        if (node == null) {
            return 0;
        }
        return root.checkLeft().checkHeight() - root.checkRight().checkHeight();
    }

    public String print(Node2 node) {
        StringBuilder treeString = new StringBuilder();
        if (node != null) {
            treeString.append(node.checkValue()).append(" ");
            treeString.append(print(node.checkLeft()));
            treeString.append(print(node.checkRight()));
        }
        return treeString.toString();
    }

    public Node2 getRoot() {
        return root;
    }
}


class Node2 {

    int val;
    public Node2 left;
    public Node2 right;
    int height;

    public Node2(int val) {
        this.val = val;
        left = null;
        right = null;
        height = 1;
    }

    public int checkValue() {
        return val;
    }

    public Node2 checkLeft() {
        return left;
    }

    public Node2 checkRight() {
        return right;
    }

    public int checkHeight() {
        return height;
    }

}
