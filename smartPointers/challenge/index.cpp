#include <iostream>
#include <vector>
#include <memory>

class Test
{
private:  
  int data;

public:
  Test() : data(0) { std::cout << "\tTest constructor(" << 0 << ")" << std::endl; }
  Test(const int data) : data(data) { std::cout << "\tTest constructor(" << data << ")" << std::endl; }
  int get_data() const { return this->data; }
  ~Test() { std::cout << "\tTest destructor(" << data << ")" << std::endl; }
};

auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

auto make()
{
  return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
  int temp {};
  for (int i {1}; i <= num; i++) {
    std::cout << "Enter data points at [" << i << "]: ";
    std::cin >> temp;
    vec.push_back(std::make_shared<Test>(temp));
  }
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
  std::cout << "============" << std::endl;
  for (const auto &ptr: vec)
    std::cout << ptr->get_data() << std::endl;
  std::cout << "============" << std::endl;
}

int main()
{
  std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
  vec_ptr = make();
  std::cout << "How many data points do you want to enter: ";
  int num;
  std::cin >> num;
  fill(*vec_ptr, num);
  display(*vec_ptr);

  return 0;
}
