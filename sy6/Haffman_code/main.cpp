//输入一段100—200字的英文短文，存入一文件a中。
//写函数统计短文出现的字母个数n及每个字母的出现次数
//写函数以字母出现次数作权值，建Haffman树（n个叶子），给出每个字母的Haffman编码。
//用每个字母编码对原短文进行编码，码文存入文件b中。
//用Haffman树对文件b中码文进行译码，结果存入文件c中，比较a,c是否一致，以检验编码、译码的正确性。
#include "function.h"

//TODO 更改文件名-这里是我的电脑的文件路径
int main() {
    std::cout << "Hello, World!" << std::endl;
    //将a文件中的出现的字母读出来
    ifstream fin_a;
    fin_a.open("C:\\Users\\xiaodian&\\Desktop\\Experiment\\exp_coding\\sy6\\Haffman_code\\a");
    char ch;
    int num_ch = 0;
    int letter[26] = {0};
    while(fin_a>>ch)
        letter[ch-'a']++;
    fin_a.clear();
    fin_a.seekg(ios::beg);

    //统计出现了多少种字母
    for(int i=0; i<26; i++)
        if(letter[i] != 0)
            num_ch++;
    cout<<"一共出现了"<<num_ch<<"种字母"<<endl;
    //创建哈夫曼树
    node haffman[2*num_ch-1];
    int j=0;
    //前n个结点的初始化
    for(int i=0; i<26; i++){
        if(letter[i] != 0)
            haffman[j++] = {i,letter[i],-1,-2,-2};
    }
    //合并产生哈夫曼树
    for(int end=2*num_ch-1; j<end; j++){
        int min1,min2;
        find(min1,min2,haffman,j-1);//此为找现有的结点中权值最小的且没有双亲的两个结点的函数
        haffman[j] = {-1,haffman[min1].weight+haffman[min2].weight,-1,min1,min2};
        haffman[min1].parent = haffman[min2].parent = j;
    }
    //进行编码
    haffmancode code[26];
    char path[num_ch];
    make_haffmancode(code,haffman,2*num_ch-2,path,0);
    //展示出现的字母的出现次数和相应的哈夫曼编码
    cout<<"相应的出现次数和哈夫曼编码:"<<endl;
    for(int i=0; i<26; i++){
        if(letter[i])
            cout<<char('a'+i)<<"-"<<letter[i]<<" :"<<code[i]<<endl;
    }

    //对a文件进行编码，并放入b文件中
    ofstream fout_b;
    fout_b.open("C:\\Users\\xiaodian&\\Desktop\\Experiment\\exp_coding\\sy6\\Haffman_code\\b");
    while (fin_a>>ch)
        fout_b<<code[ch-'a'];
    fout_b.close();//不用的时候尽量直接关掉，或者输入换行以刷新缓冲区，否则像此程序中translate时b文件还是空的呢。非常坑这一点。
    fin_a.clear();
    fin_a.seekg(ios::beg);

    //从b文件中译码写入c文件中
    translate(haffman,num_ch);

    //将c文件与a文件对比，而这应该完全相等。注意：a文件中有空格或者换行符，这里应该忽略掉
    ifstream fin_c;
    fin_c.open("C:\\Users\\xiaodian&\\Desktop\\Experiment\\exp_coding\\sy6\\Haffman_code\\c");
    char ch_a,ch_c;
    while (fin_a>>ch_a && fin_c>>ch_c){
        if(ch_a != ch_c){
            cout<<"wrong"<<endl;
            return 0;
        }
    }
    cout<<"right"<<endl;
    fin_a.close();
    fin_c.close();

    return 0;
}


