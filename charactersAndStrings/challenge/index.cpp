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

  std::cout << std::endl << "Encrypting and decrypting is processing..." << std::endl << std::endl;

  std::vector<size_t> alphabet_indexes {};
  std::vector<size_t> key_indexes {};
  int ran_num {};

  for (size_t i {0}; i < message.length(); i++) {
    key_indexes.push_back(distr(gen));
    alphabet_indexes.push_back(alphabet.find(message[i]));
  }

  std::string encrypted_message {};
  std::string decrypted_message {};

  for (size_t i {0}; i < message.length(); i++) {
    encrypted_message += key.at(key_indexes.at(i));

    if (alphabet_indexes.at(i) != std::string::npos) {
      decrypted_message += alphabet.at(alphabet_indexes.at(i));
    } else {
      decrypted_message += message.at(i);
    }
  }

  std::cout << "Encrypted message is: " << encrypted_message << std::endl << std::endl;
  std::cout << "Decrypted message is: " << decrypted_message << std::endl << std::endl;

  return 0;
}
