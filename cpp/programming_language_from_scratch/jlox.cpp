#include <iostream>

class Lox
{
public:
  Lox();
  ~Lox();

  void start(int argc, char *argv[])
  {
    if (argc > 1)
    {
      std::cout << "Usage Jlox [script]" << std::endl;
      exit(64);
    }
    else if (argc == 1)
    {
      // Run the file
    }
    else
    {
      // Run the prompt
    }
  }

private:
  void runFile(std::string path)
  {
    // Read all the butes from the file .
  }
};

Lox::Lox()
{
}

Lox::~Lox()
{
}

int main(int argc, char *argv[])
{

  return 0;
}
