#include<bits/stdc++.h>
using namespace std;

class one{
  public:
  int calc;
  one *left;
  one *right;
  int height;
};
int max(int a, int b);
int height(one *c){
  if (c == NULL)
  return 0;
  return c->height;
}
int max(int a, int b){
  return (a > b)? a : b;
}
one* two(int calc){
  one* num= new one();
  num->calc= calc;
  num->left= NULL;
  num->right= NULL;
  num->height= 1;
  return(num);
}
one *rTurn(one *y){
  one *x= y->left;
  one *T2= x->right;
  x->right= y;
  y->left= T2;
  y->height= max(height(y->left),height(y->right)) + 1;
  x->height= max(height(x->left),height(x->right)) + 1;
  return x;
}
one *lTurn(one *x){
  one *y= x->right;
  one *T2= y->left;
  y->left= x;
  x->right= T2;
  x->height= max(height(x->left),height(x->right)) + 1;
  y->height= max(height(y->left),height(y->right)) + 1;
  return y;
}
int getBalance(one *c){
  if (c == NULL)
  return 0;
  return height(c->left) - height(c->right);
}
one* insert(one* num, int calc){
  if (num == NULL)
  return(two(calc));
  if (calc< num->calc) 
  num->left= insert(num->left, calc);
  else if (calc> num->calc) 
  num->right= insert(num->right, calc);
  else
  return num;
  num->height= 1 + max(height(num->left),height(num->right));
  int balance= getBalance(num);
  if (balance> 1 && calc < num->left->calc)
  return rTurn(num);
  if (balance< -1 && calc > num->right->calc)
  return lTurn(num);
  if (balance> 1 && calc > num->left->calc){
    num->left= lTurn(num->left);
    return rTurn(num);
  }
  if (balance< -1 && calc < num->right->calc){
    num->right= rTurn(num->right);
    return lTurn(num);
  }
  return num;
}
void order(one *o){
  if(o!= NULL){
    cout << o->calc << " ";
    order(o->left);
    order(o->right);
  }
}
int main(){
  one *o = NULL;
  o= insert(o, 2);
  o= insert(o, 5);
  o= insert(o, 10);
  o= insert(o, 15);
  o= insert(o, 20);
  o= insert(o, 25);
  cout<< "The AVL tree is: \n";
  order(o);
  return 0;
}