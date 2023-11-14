#include <iostream>
#include <ctime>
using namespace std;

int tries = 6;
string message = "You have 3 chances";
string message_one = "";

void hangMan(char);
int checkGuess(char, string, string&);

int main() {
  char letter;
  string hangManWord;
  string handManWords[] = {"kalio", "roechelon", "tseries", "tandoori", "anabolic"};

  srand(time(NULL));
  int word_number = rand()% 5;
  hangManWord = handManWords[word_number];

  string hide_word(hangManWord.length(), '_');
  while(tries != 0) {
    hangMan('n');
    cout << "\t\t\t\tTries left: " << tries << endl;
    cout << hide_word << endl;
    cout << "\t\t\t\tGuess a letter: " << endl;
    cin >> letter;

    system("clear");

    if(checkGuess(letter, hangManWord, hide_word) == 0) {
      message_one = "Incorrect Letter!";
      tries--;
    }
    else {
      message_one = "Nice! You guess correctly";
    }
    if(hide_word == hangManWord) {
      message = "You WIN, and freed the man!";
      hangMan('f');
      cout << "\t\t\t\tTries left: " << tries << endl;
      cout << endl;
      cout << "\t\t\t\tThe word is: " << hangManWord << endl;
      cout << endl;
      cout << "\t\t\t\t" << message << endl;
      break;
    }
  }

  if(tries == 0) {
    message = "You did not free the kalio!";
    hangMan('h');
    cout << "\t\t\t\tTries left: " << tries << endl;
    cout << endl;
    cout << "\t\t\t\tThe word was: " << hangManWord << endl;
    cout << endl;
    cout << "\t\t\t\t" << message << endl;
  }

  return 0;
}

int checkGuess(char guess, string real_word, string &hidden_word) {
  int matches = 0;
  int len = real_word.length();
  for(int i=0; i < len; i++) {
    if(guess == hidden_word[i]) {
      return 0;
    }
    if(guess == real_word[i]){
      hidden_word[i] = guess;
      matches++;
    }
  }
  return matches;
}

void hangMan(char state) {
  string head_string = "|";
  string stage = "=";
  if(state == 'f') {
    head_string = " ";
  }
  else if(state == 'h') {
    stage = " ";
  }

  if(tries == 6) {
    cout << "\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t=====================" << endl;
  }
  if(tries == 5) {
    cout << "\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|         O         |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t=====================" << endl;
  }
  if(tries == 4) {
    cout << "\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|         O         |" << endl;
    cout << "\t\t\t\t|        /          |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t=====================" << endl;
  }
  if(tries == 3) {
    cout << "\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|         O         |" << endl;
    cout << "\t\t\t\t|        / \\        |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t=====================" << endl;
  }
  if(tries == 2) {
    cout << "\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|         O         |" << endl;
    cout << "\t\t\t\t|        / \\        |" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t=====================" << endl;
  }
  if(tries == 1) {
    cout << "\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|         O         |" << endl;
    cout << "\t\t\t\t|        / \\        |" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|        /          |" << endl;
    cout << "\t\t\t\t=====================" << endl;
  }
  if(tries == 0) {
    cout << "\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|         O         |" << endl;
    cout << "\t\t\t\t|        / \\        |" << endl;
    cout << "\t\t\t\t|         |         |" << endl;
    cout << "\t\t\t\t|        / \\         |" << endl;
    cout << "\t\t\t\t=====================" << endl;
  }
  cout << "\t\t\t\t" << message_one << endl;
  cout << endl;

}