package TreeTypes;

import Utils.DialogHelper;

public class BalBinTree
{

    Node2 root;

    public BalBinTree()
    {
        root = null;
    }

    public void insertNode(int val)
    {
        root = insert(root, val);
    }

    private Node2 insert(Node2 node, int val)
    {
        if (node == null)
            return new Node2(val);

        if (val > node.val) node.right = insert(node.right, val);
        else if (val < node.val) node.left = insert(node.left, val);
        else
        {
            DialogHelper.warning("No se pueden valores repetidos.");
            return node;
        }
        node.setHeight(1 + Math.max(seeHeight(node.left), seeHeight(node.right)));
        return balance(node, val);
    }

    private Node2 balance(Node2 node, int val)
    {
        int balance = getBalance(node);

        if (balance > 1 && val < node.left.val)
            return rightRotate(node);

        if (balance < -1 && val > node.right.val)
            return leftRotate(node);

        if (balance > 1 && val > node.left.val)
        {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        if (balance < -1 && val < node.right.val)
        {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }
        return node;
    }


    public Node2 rightRotate(Node2 r)
    {
        if (r.left != null && r.right != null)
        {
            Node2 l = r.left;
            Node2 aux = l.right;

            l.right = r;
            r.left = aux;

            r.height = 1 + Math.max(seeHeight(r.left), seeHeight(r.right));
            l.height = 1 + Math.max(seeHeight(l.left), seeHeight(l.right));
            return l;
        }
        else
            return r;
    }

    public Node2 leftRotate(Node2 l)
    {
        if (l.left != null && l.right != null)
        {
            Node2 r = l.right;
            Node2 aux = r.left;

            r.left = l;
            l.right = aux;

            l.height = 1 + Math.max(seeHeight(l.left), seeHeight(l.right));
            r.height = 1 + Math.max(seeHeight(r.left), seeHeight(r.right));

            return r;
        }
        else
            return l;
    }


    public int getBalance(Node2 node)
    {
        if (node == null) return 0;
        return seeHeight(node.left) - seeHeight(node.right);
    }

    public int seeHeight(Node2 node)
    {
        if (node == null) return 0;
        return node.getHeight();
    }

    public String print(Node2 node) {
        return printTreeHelper(node, 0);
    }

    private String printTreeHelper(Node2 node, int space)
    {
        StringBuilder treeString = new StringBuilder();
        if (node != null)
        {
            space += 5;
            treeString.append(printTreeHelper(node.right, space));

            treeString.append("\n");
            treeString.append(" ".repeat(Math.max(0, space - 5)));
            treeString.append(node.val);

            treeString.append(printTreeHelper(node.left, space));
        }
        return treeString.toString();
    }


    public Node2 getRoot()
    {
        return root;
    }
}


class Node2
{
    int val;
    public Node2 left;
    public Node2 right;
    int height;

    public Node2(int val)
    {
        this.val = val;
        left = null;
        right = null;
        height = 1;
    }

    public void setHeight(int height)
    {
        this.height = height;
    }

    public int getHeight()
    {
        return height;
    }

}