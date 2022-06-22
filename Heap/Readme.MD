
# Heap/Priority_queue

### Why heap exist in the first place
- Basically we can do the same operation with sorting in O(nlogn) time.
- Using heap we can do the same thing with O(nlogk) time (more optimized).

### Identification
- Top, closest, smallest, largest K elements
- KeyWord: K would be mentioned

### Technique
- When largest mentioned, use Min_heap (delete unnecessary smaller elements from queue.top())
- When smallest mentioned, use Max_heap (delete unnecessary larger elements from queue.top())

### Initialization (C++)
- Max-heap
```bash
priority_queue<int> pq;
```
- Min-heap
```bash
priority_queue<int,vector<int>,greater<int>> pq;
```

### Practice questions
- Kth largest element of an array
- Kth smallest element of an array 
- Kth closest elements of an given element from array
- Top frequent K elements of an array
- Sort a K-sorted array

