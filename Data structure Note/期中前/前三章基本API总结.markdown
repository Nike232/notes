## 前三章基本API总结

1. 动态数组vector
   * Push_back
   * Pop_back
   * 使用这两个操作就可以模拟栈
   * size empty
   * insert(position, value) 必须用迭代器来指定位置比如.begin()+1就是第二个元素
2. 链表list（双链表）
   * Push_back
   * Push_front
   * Pop_back
   * Pop_front
   * Size empty
   * **front** **back**第一个和最后一个元素
   * insert(position,value)位置同样用迭代器
   * erase（position）位置同样用迭代器
3. 栈stack
   * push
   * pop
   * top
   * empty
   * size
   * 当然其他的数据结构也能当栈来使用（应该已经很熟悉，这里只是回顾一下cppstl中的api）

4. 队列
   1. Duque
      * Push_back
      * Push_front
      * Pop_back
      * Pop_front
      * Back front
      * Empty size
   2. queue
      * push
      * pop
      * front
      * back
      * empty size
   3. **Priority_queue**
      * Push 
      * pop
      * empty
      * **Top**
      * empty size