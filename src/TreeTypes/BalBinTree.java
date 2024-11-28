package TreeTypes;

import Utils.DialogHelper;

public class BalBinTree {

    Node2 root;

    public BalBinTree() {
        root = null;
    }

    public void insertNode(int val) {
        if (root == null)
            root = new Node2(val);
        else
            root = insert(root, val);
    }

    private Node2 insert(Node2 node, int val) {
        if (val > node.val)
            if(node.checkLeft() ==  null) node.left = new Node2(val);
            else insert(node.checkLeft(), val);
        else if (val < node.val)
            if(node.checkRight() == null) node.right = new Node2(val);
            else insert(node.checkRight(), val);
        else
            DialogHelper.warning("No se pueden valores repetidos.");

        node.setHeight(1 + Math.max(seeHeight(node.left), seeHeight(node.right)));

        int balance = getBalance(node);

        if (balance > 1 && val < node.left.val)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && val > node.right.val)
            return leftRotate(node);

        if (balance > 1 && val > node.left.val) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        if (balance < -1 && val < node.right.val) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }

    public Node2 rightRotate(Node2 r) {
        Node2 l = r.left;
        Node2 aux = l.right;

        l.right = r;
        r.left = aux;

        r.height = 1 + Math.max(seeHeight(r.left), seeHeight(r.right));
        l.height = 1 + Math.max(seeHeight(l.left), seeHeight(l.right));

        return l;
    }

    public Node2 leftRotate(Node2 l) {
        Node2 r = l.right;
        Node2 aux = r.left;

        r.left = l;
        l.right = aux;

        l.height = 1 + Math.max(seeHeight(l.left), seeHeight(l.right));
        r.height = 1 + Math.max(seeHeight(r.left), seeHeight(r.right));

        return r;
    }


    public int getBalance(Node2 node) {
        if (node == null) {
            return 0;
        }
        return seeHeight(node.checkLeft()) - seeHeight(node.checkRight());
    }

    public int seeHeight(Node2 node)
    {
        if (node == null)
            return 0;
        return node.getHeight();
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
        right = null;//
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

    public void setHeight(int height) {
        this.height = height;
    }

    public int getHeight() { return height;}

}
