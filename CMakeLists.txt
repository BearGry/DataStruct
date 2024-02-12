cmake_minimum_required(VERSION 3.23)
project(exp_coding)

set(CMAKE_CXX_STANDARD 14)

#include_directories(sy1/Dynamic_SeqList)
#include_directories(sy1/Static_SeqList)
#include_directories(sy2/sy_2)
#include_directories(sy3/calculator)
#include_directories(sy3/stack)
#include_directories(sy4/sy_4)
#include_directories(sy5/Tree_01)
#include_directories(sy6/Haffman_code)
#include_directories(sy7/graphs)
#include_directories(sy8/Hash)
#include_directories(sy8/SearchTable_hw)
#include_directories(sy9/Sort)



#可以写多个add_executable,开头这个是你的这个项目，下面的需要从这个project()括号里面的子目录为初始目录，如本例中的sy1、sy2......
#     实验一
#        动态内存分配实现
add_executable(Dynamic_SeqList
        sy1/Dynamic_SeqList/main.cpp
        sy1/Dynamic_SeqList/SeqList.cpp
        sy1/Dynamic_SeqList/SeqList.h)
#        静态内存分配实现
add_executable(Static_SeqList
        sy1/Static_SeqList/main.cpp
        sy1/Static_SeqList/SeqList.cpp
        sy1/Static_SeqList/SeqList.h)


#     实验二
add_executable(sy2
        sy2/sy_2/list.cpp
        sy2/sy_2/list.h
        sy2/sy_2/main.cpp)


#     实验三
#        算术表达式求值
add_executable(calculator
        sy3/calculator/function.h
        sy3/calculator/stack.h
        sy3/calculator/function.cpp
        sy3/calculator/main.cpp)
#        括号匹配检测 和 中心对称字符序列检测
add_executable(stack
        sy3/stack/main.cpp
        sy3/stack/stack.h)


#     实验四
add_executable(sy4
        sy4/sy_4/main.cpp
        sy4/sy_4/queue_stack.h)


#     实验五
add_executable(sy5
        sy5/Tree_01/main.cpp
        sy5/Tree_01/tree.cpp
        sy5/Tree_01/tree.h
        sy5/Tree_01/queue_stack.h)


#     实验六
add_executable(sy6
        sy6/Haffman_code/function.cpp
        sy6/Haffman_code/function.h
        sy6/Haffman_code/main.cpp)


#     实验七
add_executable(sy7
        sy7/graphs/main.cpp
        sy7/graphs/graph.cpp
        sy7/graphs/graph)


#     实验八
#        顺序表的查找算法
add_executable(SearchTable_hw
        sy8/SearchTable_hw/StaticSearchTable.h
        sy8/SearchTable_hw/main.cpp)
#        二叉排序树上的查找算法
add_executable(searchtree
        sy8/searchtree/queue.h
        sy8/searchtree/tree.h
        sy8/searchtree/tree.cpp
        sy8/searchtree/main.cpp)
#        Hash表查找算法
add_executable(Hash
        sy8/Hash/hash.h
        sy8/Hash/main.cpp)


#     实验九
add_executable(sy9
        sy9/Sort/array.h
        sy9/Sort/main.cpp)

add_executable(test
        test/Stack.h
        test/main.cpp)