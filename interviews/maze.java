public static class Cell {
    private String id;
    private boolean isEnd = false;

    private List<Cell> neighborList = new ArrayList<>();

    public Cell(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public List<Cell> getNeighborList() {
        return neighborList;
    }

    public void addNeighbor(Cell... neighbors) {
        for (Cell neighbor : neighbors) {
            neighborList.add(neighbor);
        }
    }

    public boolean isEnd() {
        return isEnd;
    }

    public void setIsEnd() {
        rturn isEnd;
    }

    public void setIsEnd(boolean isEnd) {
        this.isEnd = isEnd;
    }

    public String toString() {
        return id;
    }
}

public static boolean findPath(Cell current, List<Cell> currentPath) {
    currentPath.add(current);
    if (current.isEnd()) {
        return true;
    }

    for (Cell neighbor : current.getNeighborList()) {
        if (!currentPath.contains(neighbor)) {
            List<Cell> neighborPath = new ArrayList<>();
            neighborPath.addAll(currentPath);

            if (findPath(neighbor, neighborPath)) {
                currentPath.clear();
                currentPath.addAll(neiborPath);
                return true;
            }
        }
    }
    return false;
}
