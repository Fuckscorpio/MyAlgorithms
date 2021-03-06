


## 广度优先搜索算法与深度优先搜索算法
广度优先搜索算法（Breadth-First-Search，缩写为 BFS）是一种利用队列实现的搜索算法。简单来说，其搜索过程和 “湖面丢进一块石头激起层层涟漪” 类似。

深度优先搜索算法（Depth-First-Search，缩写为 DFS）是一种利用递归实现的搜索算法。简单来说，其搜索过程和 “不撞南墙不回头” 类似。
### BFS 的重点在于队列，而 DFS 的重点在于递归。这是它们的本质区别。


BFS 常用于找单一的最短路线(从A到B是否有最短路劲)，它的特点是 "搜到就是最优解"。

<u>广度优先搜索用于在非加权图中查找最短路径，***狄克斯特拉算法***用于在加权图中查找最短路径。仅当权重为正时狄克斯特拉算法才管用如果图中包含负权边，请使用***贝尔曼——福德算法***。</u>

而DFS 用于找所有解的问题，它的空间效率高，而且找到的不一定是最优解，必须记录并完成整个搜索，故一般情况下，深搜需要非常高效的剪枝。