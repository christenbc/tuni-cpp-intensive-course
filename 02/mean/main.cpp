#include <iostream>

// Write here a function counting the mean value

int main()
{
  std::cout << "From how many integer numbers you want to count the mean value? ";
  int i = 0;
  std::cin >> i;
  if(i<=0){
      std::cout << "Cannot count mean value from 0 numbers" << std::endl;
      return 0;
  }
  int value = 0;
  double new_value = 0;
  for(int number = 1; number <=i; number++){
      std::cout << "Input " << number << ". number: ";
      std::cin >> value;
      new_value += value;
  }

  double mean = 0;
  mean = new_value/i;
  std::cout << "Mean value of the given numbers is " << mean << std::endl;
}
