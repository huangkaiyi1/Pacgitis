#include <iostream>
#include <fstream>
int ans;
int func( int x, int n )
{
  if (n==1){return x; }
  else{ ans = func(x, n*n/4); }
}

int main () {

func(2, 4);
std::cout<<ans;

}
