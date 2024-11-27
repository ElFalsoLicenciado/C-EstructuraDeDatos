package TreeTypes;

public class BTypeTree {
    NodeB root;
    int order;
    boolean initialized;

    public BTypeTree() {
        root = null;
        order = 0;
        initialized = false;
    }

    public void setInitialized(int order) {
        this.order = order * 2;
        initialized = true;
    }

    public boolean isInitialized() {
        return initialized;
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
