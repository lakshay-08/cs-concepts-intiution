# Dijkstra's Algorithm

## Intuition

Dijkstra's algorithm finds the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights. The core intuition is simple:

**"Always expand the closest unvisited vertex first."**

Think of it like spreading ink on a paper - the ink reaches nearby points first, then gradually spreads to farther points. Similarly, Dijkstra's algorithm:

1. Starts at the source vertex with distance 0
2. Explores the nearest unvisited vertex
3. Updates distances to its neighbors if a shorter path is found
4. Marks the vertex as visited
5. Repeats until all vertices are processed

### Key Insight: Greedy Choice Property

Once we visit a vertex and finalize its shortest distance, we never need to revisit it. Why? Because we always pick the vertex with the minimum distance, and all edge weights are non-negative, so any future path going through other vertices will only increase the distance.

## Implementation Approaches

### 1. Priority Queue (Min-Heap) Approach

Uses a min-heap to efficiently get the vertex with minimum distance.

**Algorithm:**
```
1. Initialize distance array with infinity, except source = 0
2. Push (0, source) into priority queue
3. While priority queue is not empty:
   a. Extract vertex with minimum distance
   b. If already visited, skip
   c. Mark as visited
   d. For each neighbor:
      - Calculate new distance = current distance + edge weight
      - If new distance < stored distance:
        * Update distance
        * Push (new distance, neighbor) to queue
```

**Time Complexity:** O((V + E) log V)
- Each vertex is extracted once: O(V log V)
- Each edge is relaxed once: O(E log V)
- Total: O((V + E) log V)

**Space Complexity:** O(V + E)
- Distance array: O(V)
- Priority queue: O(V) in worst case
- Graph storage: O(V + E)

**Pros:**
- Simpler implementation
- Good for sparse graphs
- Standard approach in most competitive programming

**Cons:**
- May contain duplicate entries in the priority queue
- Cannot decrease priority of existing elements

### 2. Set (Ordered Set) Approach

Uses a set (typically implemented as a balanced BST like Red-Black tree) that allows both extraction of minimum and deletion of existing elements.

**Algorithm:**
```
1. Initialize distance array with infinity, except source = 0
2. Insert (0, source) into set
3. While set is not empty:
   a. Extract vertex with minimum distance
   b. Remove from set
   c. For each neighbor:
      - If new distance < stored distance:
        * Remove (old distance, neighbor) from set
        * Update distance
        * Insert (new distance, neighbor) to set
```

**Time Complexity:** O((V + E) log V)
- Each vertex is extracted once: O(V log V)
- Each edge is relaxed at most once: O(E log V)
- Deletions from set: O(E log V)
- Total: O((V + E) log V)

**Space Complexity:** O(V + E)
- Distance array: O(V)
- Set: O(V) - contains at most V elements
- Graph storage: O(V + E)

**Pros:**
- Set contains at most V elements (no duplicates)
- Can remove outdated entries
- Better space efficiency in practice

**Cons:**
- Slightly more complex implementation
- Need to store and erase pairs efficiently

## Comparison: Priority Queue vs Set

| Aspect | Priority Queue | Set |
|--------|---------------|-----|
| **Size** | Can grow to O(E) elements | Always ≤ V elements |
| **Duplicates** | Yes, keeps outdated entries | No, removes outdated entries |
| **Decrease Key** | Not supported directly | Supported via erase + insert |
| **Implementation** | Simpler | Slightly complex |
| **Practical Performance** | Good for sparse graphs | Better for dense graphs |
| **Memory Usage** | Higher (with duplicates) | Lower (no duplicates) |

## When to Use Which?

**Use Priority Queue when:**
- Graph is sparse (E << V²)
- Simplicity is preferred
- Doing competitive programming

**Use Set when:**
- Graph is dense
- Memory is a constraint
- Need to explicitly handle edge relaxation updates

## Important Notes

⚠️ **Dijkstra's algorithm does NOT work with negative edge weights!**
- The greedy property breaks down
- Use Bellman-Ford algorithm for negative weights

✅ **Works for:**
- Directed and undirected graphs
- Sparse and dense graphs
- Graphs with non-negative weights

## Summary

Both implementations have the same theoretical time complexity O((V + E) log V), but differ in practical considerations:

- **Priority Queue**: Standard choice, simpler to implement, may contain duplicates
- **Set**: More memory efficient, explicitly handles updates, slightly complex

Choose based on your specific requirements and constraints!