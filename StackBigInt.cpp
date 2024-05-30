//By Daniel Sameh
//May 2024
#include <bits/stdc++.h>
#include <utility>
using namespace std;
/*
 * I made this code just to try
 * the stack in adding big integers
 */
class BigInt{
private:
    string num;
    stack<char>x,y,s;
public:
    explicit BigInt(string n):num(std::move(n)){
        for(auto i:num)
            x.push(i);
    }
    BigInt operator+(BigInt& other){
        for(auto i:other.num)
            y.push(i);
        int carry=-1;
        while(!x.empty()&&!y.empty()){
            int x1=x.top()-'0',y1=y.top()-'0';
            int r= x1+y1;
            r+= (carry==-1)? 0 : carry;
            if (r<10)
                s.push((char)(r+'0'));
            else{
                string tmp= to_string(r);
                s.push(tmp[1]);
                carry=tmp[0]-'0';
            }
            x.pop(),y.pop();
        }
        while(!x.empty()){
            int r= x.top()-'0';
            r += (carry==-1)? 0 : carry;
            if (r<10)
                s.push((char)(r+'0'));
            else{
                string tmp= to_string(r);
                s.push(tmp[1]);
                carry=tmp[0]-'0';
            }
            x.pop();
        }
        while(!y.empty()){
            int r= y.top()-'0';
            r += (carry==-1)? 0 : carry;
            if (r<10)
                s.push((char)(r+'0'));
            else{
                string tmp= to_string(r);
                s.push(tmp[1]);
                carry=tmp[0]-'0';
            }
            y.pop();
        }
        string result;
        while(!s.empty()){
            result= result+ s.top();
            s.pop();
        }
        return BigInt(result);
    }
    friend ostream& operator<<(ostream& os,const BigInt& b);

};
ostream& operator<<(ostream& os,const BigInt& b){
    os<<b.num;
    return os;
}


int main() {
    BigInt b("592"),i("3784");
    cout<<(b+i)<<'\n';
    cout<<592+3784<<'\n';
    
}
//10*2*8
// 10 2 * 8 *
