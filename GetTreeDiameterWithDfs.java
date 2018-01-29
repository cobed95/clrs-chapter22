import java.util.*;

class GetTreeDiameterWithDfs {
  private static ArrayList<Boolean> isVisited = new ArrayList<Boolean>();
  private static ArrayList<Integer> candidates = new ArrayList<Integer>();
  private static Integer candidate;
  private static boolean fell;

  private static ArrayList<ArrayList<Integer>> buildAdjList(int n, ArrayList<ArrayList<Integer>> edges) {
    ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();
    for (int i = 0; i < n; i++) adjList.add(new ArrayList<Integer>());

    for (ArrayList<Integer> edge : edges) {
      adjList.get(edge.get(0)).add(edge.get(1));
      adjList.get(edge.get(1)).add(edge.get(0));
    }

    return adjList;
  }
  
  private static boolean goesDown(ArrayList<ArrayList<Integer>> adjList, int u) {
    for (Integer v : adjList.get(u)) {
      if (!isVisited.get(v)) return true;
    }
    return false;
  }

  private static void dfsVisit(ArrayList<ArrayList<Integer>> adjList, int u) {
    isVisited.set(u, true);
   
    if (!fell && goesDown(adjList, u)) {
      candidate++;
      fell = true;
    }

    else if (fell && goesDown(adjList, u)) {
      candidate++; 
    }

    System.out.println("At " + u);
    System.out.println(candidate);

    for (Integer v : adjList.get(u)) {
      if (!isVisited.get(v)) {
        dfsVisit(adjList, v);
      }
    }

    if (fell && !goesDown(adjList, u)) {
      candidate++;
      candidates.add(candidate);
      candidate = 1;
      fell = false;
    } 

    else if (!fell && !goesDown(adjList, u)) {
      candidate++;
    }
    System.out.println("At " + u);
    System.out.println(candidate);

  } 

  private static void dfs(ArrayList<ArrayList<Integer>> adjList) {
    for (int i = 0; i < adjList.size(); i++) {
      isVisited.add(false);
    } candidate = 0;
      fell = true;
       
    for (int u = 0; u < adjList.size(); u++) {
      if (!isVisited.get(u)) dfsVisit(adjList, u);
    }
  }

  private static int getLargest(ArrayList<Integer> candidates) {
    int largest = candidates.get(0);
    for (int i = 1; i < candidates.size(); i++) {
      if (largest < candidates.get(i)) {
        largest = candidates.get(i);
      }
    }

    return largest;
  }
  
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    ArrayList<ArrayList<Integer>> edges = new ArrayList<ArrayList<Integer>>();
    for (int i = 0; i < m; i++) {
      int u = scanner.nextInt();
      int v = scanner.nextInt();
      ArrayList<Integer> edge = new ArrayList<Integer>();
      edge.add(u);
      edge.add(v);
      edges.add(edge);
    }

    ArrayList<ArrayList<Integer>> adjList = buildAdjList(n, edges);
    dfs(adjList);
    System.out.println(candidates);
    int diameter = getLargest(candidates);
    System.out.println(diameter);    
  }
}
