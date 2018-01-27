import java.util.*;

class DfsWithStack2 {
  private static ArrayList<Boolean> isVisited = new ArrayList<Boolean>();
  private static ArrayList<Integer> discoveredAt = new ArrayList<Integer>();
  private static ArrayList<Integer> finishedAt = new ArrayList<Integer>();
  private static ArrayList<Integer> isPopped = new ArrayList<Integer>();
  private static Integer time;
  
  private static ArrayList<ArrayList<Integer>> buildAdjList(int n, ArrayList<ArrayList<Integer>> edges) {
    ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();
    for (int i = 0; i < n; i++) adjList.add(new ArrayList<Integer>());

    for (ArrayList<Integer> edge : edges) {
      adjList.get(edge.get(0)).add(edge.get(1));
      adjList.get(edge.get(1)).add(edge.get(0));
    }

    return adjList;
  }

  private static void dfsWithStack(ArrayList<ArrayList<Integer>> adjList, int m) {
    ArrayList<Integer> stack = new ArrayList<Integer>();
    
    for (int i = 0; i < adjList.size(); i++) {
      isVisited.add(false);
      discoveredAt.add(null);
      finishedAt.add(null);
      isPopped.add(0);
    } time = 0;

    for (int root = 0; root < adjList.size(); root++) {
      if (!isVisited.get(root)) {
        stack.add(0, root);
        stack.add(0, root);

        while (!stack.isEmpty()) {
          if (isPopped.get(stack.get(0)) == 2) {
            stack.remove(0);
            stack.remove(0);
          }
          
          else if (isPopped.get(stack.get(0)) < 2) {
            int u = stack.get(0);
            stack.remove(0);
            isPopped.set(u, isPopped.get(u)+1);
            time++;

            if (!isVisited.get(u)) {
              isVisited.set(u, true);
              discoveredAt.set(u, time);

              for (Integer v : adjList.get(u)) {
                if (!isVisited.get(v)) {
                  stack.add(0, v);
                  stack.add(0, v);
                }
              }
            }
          
            else {
              finishedAt.set(u, time);
            }
          }
        }
      }
    }  
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
    dfsWithStack(adjList, m);

    System.out.println(isVisited);
    System.out.println(discoveredAt);
    System.out.println(finishedAt);
  }
}
