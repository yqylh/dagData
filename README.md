## 数据集描述

1. 该数据集提供100组石油网络的数据 , 存放在data目录下 , 均为随机数据 , 可自行选择进行测试
2. 该数据集保证加权有向无环图 , 保证只有一个入度为0的源点
3. 根目录下的make.py为数据生成器 , **强烈建议**修改代码来产生你想要的大小的数据
4. 数据生成器依赖于库[cyaron](https://github.com/luogu-dev/cyaron/wiki) , 你可以阅读该文档以了解其使用方法和原理
5. ~~cyaron并没有指出生成的dag只有一个源点 , 但他的写法确实只有一个源点~~

## 数据集格式

第一行包含三个整数 `[n, m, l]` , 源点均为 ` 1 ` 号节点
-  ` n ` 表示节点个数
-  ` m ` 表示边的个数
-  ` l ` 表示最大边权 ( 可以认为是Pmax )

接下来 ` m ` 行 , 每行三个正整数`[x, y, c]`用来标识一条有向边
-  ` x ` 表示起点
-  ` y ` 表示终点
-  ` c ` 表示边权

## 可视化参考

1. Visualization.cpp提供了c++的可视化例子, 你可以参考这份代码以帮助你调试代码
2. 可视化依赖于graphviz / dot, 关于graphviz的使用和安装你可以参考[官网](http://www.graphviz.org/)
3. 可以参考的使用方式为 :
> install graphviz  
> g++ Visualization.cpp -o 1 -g  
> ./1 < data/input1.in  
> open solve1.jpg  