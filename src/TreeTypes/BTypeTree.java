package TreeTypes;

public class BTypeTree
{
    NodeB root;
    int order;
    boolean initialized;

    public BTypeTree()
    {
        root = null;
        order = 0;
        initialized = false;
    }

    public void insertNode(int val)
    {

    }

    public String print(NodeB node)
    {
        return "";
    }

    public void setInitialized(int order) {
        this.order = order * 2;
        initialized = true;
    }

    public boolean isInitialized() {
        return initialized;
    }

    public NodeB getRoot()
    {
        return root;
    }
}

class NodeB {
    int val;

    public NodeB(int val) {
        this.val = val;
    }

    public int checkValue() {
        return val;
    }
}
