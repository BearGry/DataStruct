#include "graph"
using namespace std;

void visit(vertextype & a){
    cout<<a<<"  ";
}

int main() {
    std::cout << "Hello, World!" << std::endl;

//深度优先测试
    cout<<"深度优先搜索测试:"<<endl;
    cout<<"(1)、数组表示法的:"<<endl;
    mgraph a = UDG;
    cin>>a;
    a.DFS(0);
    cout<<endl;
    cout<<"(2)、邻接表表示法的:"<<endl;
    algraph b = UDG;
    cin>>b;
    b.DFS(visit,0);
    cout<<endl;


    return 0;
}


