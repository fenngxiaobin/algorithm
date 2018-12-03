#include <iostream>
#include <stack>
#include <exception>
using std::clog;
using std::endl;

/**
 * 用两个栈模拟队列操作 画好过程图
 * @tparam T
 */
template <class T>
class QStack{
public:
    QStack(){}
    ~QStack(){}
    T q_pop();
    void q_push(T x);
private:
    std::stack<T> s1;
    std::stack<T> s2;
};
template <class T>
T QStack::q_pop(){
    if(s1.size()<=0){
        while(s2.size()>0){
            T& data=s2.top();
            s2.pop();
            s1.push(data);
        }
    }
    if(s1.size()==0){
        clog<<"stack is empty"<<endl;
        throw std::exception();
    }
    T head=s1.top();
    s1.pop();
    return head;
}
template <class T>
void QStack::q_push(T x) {
    s2.push(x);
}

int main() {

    return 0;
}