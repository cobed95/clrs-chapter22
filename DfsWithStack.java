import java.util.*;

class DfsWithStack {
  private static ArrayList<Integer> color = new ArrayList<Integer>();
  private static ArrayList<Integer> discovered = new ArrayList<Integer>();
  private static ArrayList<Integer> finished = new ArrayList<Integer>();
  private static Integer t;

  private static ArrayList<ArrayList<Integer>> buildAdjList(int n, ArrayList<ArrayList<Integer>> edges) {
    ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();
    for (int i = 0; i < n; i++) adjList.add(new ArrayList<Integer>());
    for (ArrayList<Integer> edge : edges) {
      adjList.get(edge.get(0)).add(edge.get(1));
      adjList.get(edge.get(1)).add(edge.get(0));
    }

    return adjList;
  }

  private static void push(ArrayList<Integer> stack, int u) {
    stack.add(u);
    for (int i = stack.size()-2; i >= 0; i--) stack.set(i+1, stack.get(i));
    stack.set(0, u);
  }

  private static Integer pop(ArrayList<Integer> stack) {
    Integer popped = stack.get(0);
    stack.remove(0);
    return popped;
  }

  private static void dfsWithStack(ArrayList<ArrayList<Integer>> adjList) {
    ArrayList<Integer> stack = new ArrayList<Integer>();
    
    for (int i = 0; i < adjList.size(); i++) {
      color.add(0);
      discovered.add(null);
      finished.add(null);
    } 
    t = 0;

    for (int s = 0; s < adjList.size(); s++) {
      if (color.get(s) != 2) { 
        push(stack, s);
        push(stack, s);

        while (!stack.isEmpty()) {
          int u = pop(stack); 
          t++;

          if (color.get(u) != 2) {
            color.set(u, 2);
            discovered.set(u, t);
            
            for (Integer v : adjList.get(u)) {
              if (color.get(v) == 0) {
                color.set(v, 1);
                push(stack, v);
                push(stack, v);
              }
            }
          }

          else {
            finished.set(u, t);
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
    dfsWithStack(adjList);

    System.out.println(color);
    System.out.println(discovered);
    System.out.println(finished);
  }
}
