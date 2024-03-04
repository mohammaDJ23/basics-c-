#include <iostream>
#include <string>
#include <random>

int main()
{
  std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
  std::string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr(0, key.length() - 1); // define the range

  std::string message {};
  std::cout << "Enter your message: ";
  std::getline(std::cin, message);

  std::cout << "Encrypting is processing..." << std::endl;
  std::string encrypted_message {};
  std::vector<size_t> alphabet_indexes {};
  size_t index {};

  for (auto chr : message) {
    index = alphabet.find(chr);

    if (index != std::string::npos) {
      encrypted_message += key.at(distr(gen));
      alphabet_indexes.push_back(index);
    } else {
      encrypted_message += chr;
      alphabet_indexes.push_back(-1);
    }
  }

  std::cout << "Encrypted message is: " << encrypted_message << std::endl;

  std::cout << "Decrypting is processing..." << std::endl;
  std::string decrypted_message {};

  for (size_t i {0}; i < alphabet_indexes.size(); i++) {
    if (alphabet_indexes.at(i) != -1)
      decrypted_message += alphabet.at(alphabet_indexes.at(i));
    else
      decrypted_message += encrypted_message.at(i);
  }

  std::cout << "Decrypted message is: " << decrypted_message << std::endl;

  return 0;
}
