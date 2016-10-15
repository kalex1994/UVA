import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ICPC_7303 {

    private static class Segment {

        private static int nextId = 0;

        static void resetIDs() {
            nextId = 0;
        }

        static int nextID() {
            int currentID = nextId;
            ++nextId;
            return currentID;
        }

        final int id;
        
        public Segment() {
            this.id = Segment.nextID();
        }

    }

    private static class Cell {

        final int row;
        final int col;
        final char wall;
        private final Segment top;
        private final Segment bottom;

        Cell(int row, int col, char wall) {
            this.row = row;
            this.col = col;
            this.wall = wall;
            this.top = new Segment();
            this.bottom = new Segment();
        }

        Segment getTop() {
            return top;
        }

        Segment getBottom() {
            return bottom;
        }

        Segment getRight() {
            return wall == '/' ? bottom : top;
        }

        Segment getLeft() {
            return wall == '/' ? top : bottom;
        }
    }

    private static class Grid {

        final int rows;
        final int cols;
        final Cell[][] cells;
        final int[][] cost;

        Grid(int rows, int cols) {
            this.rows = rows;
            this.cols = cols;
            this.cells = new Cell[rows][cols];
            this.cost = new int[rows][cols];
        }

        void addCell(int row, int col, char wall) {
            cells[row][col] = new Cell(row, col, wall);
        }
    }

    private static class SegmentGraph {

        final List<List<Integer>> adjList;
        private int[] colors;

        public SegmentGraph(int n) {
            adjList = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                adjList.add(new ArrayList<>());
            }
        }

        void addEdge(int v1, int v2) {
            adjList.get(v1).add(v2);
        }

        private int colorConnectedComponents() {
            colors = new int[adjList.size()];
            for (int i = 0; i < colors.length; ++i) {
                colors[i] = -1;
            }

            int currentColor = 0;
            for (int i = 0; i < colors.length; ++i) {
                if (colors[i] == -1) {
                    coloring(i, currentColor);
                    ++currentColor;
                }
            }

            return currentColor;
        }

        private void coloring(int node, int color) {
            colors[node] = color;
            for (int neighbour : adjList.get(node)) {
                if (colors[neighbour] == -1) {
                    coloring(neighbour, color);
                }
            }
        }

        public List<List<Integer>> getConnectedSegments() {
            int components = colorConnectedComponents();
            List<List<Integer>> connectedSegments = new ArrayList<>();
            for (int component = 0; component < components; ++component) {
                connectedSegments.add(new ArrayList<>());
            }
            for (int node = 0; node < adjList.size(); ++node) {
                connectedSegments.get(colors[node]).add(node);
            }

            return connectedSegments;
        }

    }

    private static class UnionFind {

        private final int[] parent, rank;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int findSet(int i) {
            return parent[i] == i ? i : (parent[i] = findSet(parent[i]));
        }

        boolean isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);
                if (rank[x] > rank[y]) {
                    parent[y] = x;
                } else {
                    parent[x] = y;
                    if (rank[x] == rank[y]) {
                        ++rank[y];
                    }
                }
            }
        }
    }

    private static class MSTGraph {

        public static class Edge implements Comparable<Edge> {

            final int v1;
            final int v2;
            final int weight;

            public Edge(int v1, int v2, int weight) {
                this.v1 = v1;
                this.v2 = v2;
                this.weight = weight;
            }

            @Override
            public int compareTo(Edge o) {
                return Integer.compare(weight, o.weight);
            }
        }

        private final List<Edge> edgeList;
        private final int numberOfVertices;

        public MSTGraph(int numberOfVertices) {
            this.numberOfVertices = numberOfVertices;
            this.edgeList = new ArrayList<>();
        }

        public void addEdge(int v1, int v2, int weight) {
            edgeList.add(new Edge(v1, v2, weight));
        }

        int kruskalMST() {
            Collections.sort(edgeList);
            int cost = 0;
            UnionFind unionFind = new UnionFind(numberOfVertices);
            for (Edge edge : edgeList) {
                if (!unionFind.isSameSet(edge.v1, edge.v2)) {
                    cost += edge.weight;
                    unionFind.unionSet(edge.v1, edge.v2);
                }
            }
            return cost;
        }
    }

    private static Grid readCase(BufferedReader input) throws IOException {
        String line = input.readLine();
        String[] splitted = line.split("\\s+");
        int rows = Integer.parseInt(splitted[0]);
        int cols = Integer.parseInt(splitted[1]);
        Grid grid = new Grid(rows, cols);
        for (int i = 0; i < rows; ++i) {
            line = input.readLine();
            for (int j = 0; j < cols; ++j) {
                grid.addCell(i, j, line.charAt(j));
            }
        }
        for (int i = 0; i < rows; ++i) {
            line = input.readLine();
            splitted = line.split("\\s+");
            for (int j = 0; j < cols; ++j) {
                grid.cost[i][j] = Integer.parseInt(splitted[j]);
            }
        }
        return grid;
    }

    private static SegmentGraph buildSegmentGraph(Grid grid) {
        SegmentGraph segmentGraph = new SegmentGraph(grid.rows * grid.cols * 2);

        for (int row = 0; row < grid.rows; ++row) {
            for (int col = 0; col < grid.cols; ++col) {
                if (grid.cells[row][col].wall == '/') {
                    Segment top = grid.cells[row][col].getTop();
                    if (row - 1 >= 0) {
                        segmentGraph.addEdge(top.id, grid.cells[row - 1][col].getBottom().id);
                    }
                    if (col - 1 >= 0) {
                        segmentGraph.addEdge(top.id, grid.cells[row][col - 1].getRight().id);
                    }

                    Segment bottom = grid.cells[row][col].getBottom();
                    if (row + 1 < grid.rows) {
                        segmentGraph.addEdge(bottom.id, grid.cells[row + 1][col].getTop().id);
                    }
                    if (col + 1 < grid.cols) {
                        segmentGraph.addEdge(bottom.id, grid.cells[row][col + 1].getLeft().id);
                    }
                } else {
                    // \
                    Segment top = grid.cells[row][col].getTop();
                    if (row - 1 >= 0) {
                        segmentGraph.addEdge(top.id, grid.cells[row - 1][col].getBottom().id);
                    }
                    if (col + 1 < grid.cols) {
                        segmentGraph.addEdge(top.id, grid.cells[row][col + 1].getLeft().id);
                    }

                    Segment bottom = grid.cells[row][col].getBottom();
                    if (row + 1 < grid.rows) {
                        segmentGraph.addEdge(bottom.id, grid.cells[row + 1][col].getTop().id);
                    }
                    if (col - 1 >= 0) {
                        segmentGraph.addEdge(bottom.id, grid.cells[row][col - 1].getRight().id);
                    }
                }
            }
        }

        return segmentGraph;
    }

    private static MSTGraph buildMSTGraph(Grid grid, List<List<Integer>> connectedComponents) {
        Map<Integer, Integer> segmentToComponent = new HashMap<>();
        for (int component = 0; component < connectedComponents.size(); ++component) {
            for (int segment : connectedComponents.get(component)) {
                segmentToComponent.put(segment, component);
            }
        }

        MSTGraph mstGraph = new MSTGraph(connectedComponents.size());
        for (int component = 0; component < connectedComponents.size(); ++component) {
            for (int segmentID : connectedComponents.get(component)) {
                int cell = segmentID / 2;
                int row = cell / grid.cols;
                int col = cell % grid.cols;

                if (segmentID % 2 == 0) {
                    int neighbour = segmentID + 1;
                    mstGraph.addEdge(component, segmentToComponent.get(neighbour), grid.cost[row][col]);
                } else {
                    int neighbour = segmentID - 1;
                    mstGraph.addEdge(component, segmentToComponent.get(neighbour), grid.cost[row][col]);
                }
            }
        }

        return mstGraph;
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader input = new BufferedReader(new InputStreamReader(System.in))) {
            int testcases = Integer.parseInt(input.readLine());
            for (int testcase = 0; testcase < testcases; ++testcase) {
                Segment.resetIDs();
                Grid grid = readCase(input);
                SegmentGraph segmentGraph = buildSegmentGraph(grid);
                List<List<Integer>> connectedComponents = segmentGraph.getConnectedSegments();
                MSTGraph mstGraph = buildMSTGraph(grid, connectedComponents);
                System.out.println(String.format("Case %d: %d", testcase + 1, mstGraph.kruskalMST()));
            }
        }
    }
}
