/* This is a c++ program that gonna help to shortlist the applied candidates according to their CGPA
Rules for selection
1) The student who comes first has some extra preference
2) The CGPA of the applicant should be at least 7.00 to get shortlisted
3) If an applicant comes an apply but an applicant having more than or equal to CGPA already applied for the job then he won't be selected
4) There will be search options to check whether an applicant has been selected or not
5) There will be option if the user wants so print the list of applicants
6) There will be a certain no of shortlisted candidates let's say 20
*/
/*
Concepts used
1) Object oriented programming for ease of implementation and easy understanding of the properties possessed by a candidate
1) self balancing binary search tree(Red black tree) which is included in map header file in C++(as there may be more than one  candidates with same name so we use a multimap)
2) File handling to write the applicants name into a text document
4) Trie data structure to check whether a student with a particular id applied before
*/

// we should take care that an applicant can not apply twice
// so we provide an unique id number for each applicant
// we store the id's on a trie data structure because the no of submitted applications may be very large so we can add the ids efficiently to a trie and
//later on search for the same on an efficient manner
// The id number consists of lowercase English letters(a-z)
#include <iostream>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;
// Class of Candidates(possesses three properties namely name, cgpa and id)

class Candidates
{

public:
  string name;

  float cgpa;

  string id;
};

class Node
{

public:
  char c;

  bool isWord;

  int Count;

  int terminating;

  Node *children[26];
};

Node *getNode(char c)
{

  Node *node = new Node();

  node->c = c;

  node->Count = 0;

  node->terminating = 0;

  node->isWord = false;

  for (int i = 0; i < 26; i++)

  {

    node->children[i] = NULL;
  }

  return node;
}

class Trie
{

private:
  Node *root;

public:
  Trie()
  {

    root = getNode('\0');
  }

  void insert(string &word)
  {

    Node *curr = root;

    for (int i = 0; i < (int)word.size(); i++)

    {

      char c = word[i];

      if (curr->children[c - 'a'] == NULL)

        curr->children[c - 'a'] = getNode(c);

      curr = curr->children[c - 'a'];

      (curr->Count) = (curr->Count) + 1;
    }

    curr->terminating = curr->terminating + 1;

    curr->isWord = true;
  }

  int search_count(string word)
  {

    Node *curr = root;

    for (int i = 0; i <(int) word.size(); i++)

    {

      char c = word[i];

      if (curr->children[c - 'a'] == NULL)

        return 0;

      curr = curr->children[c - 'a'];
    }

    return curr->terminating;
  }

  void construct_trie(vector<string> &words)
  {

    for (string &word : words)

    {

      insert(word);
    }
  }
};

int main()
{

  cout << "*****************************************************************************************************" << endl;

  cout << "   C++ Program to select a number of eligible candidates from a number of applied candidates: " << endl;

  cout << "*****************************************************************************************************" << endl;

  cout << "Enter the number of applicants: " << endl;

  int n;

  cin >> n;

  multimap<float, string> mp;

  multimap<string, float> mp_;

  Trie trie;

  cout << "Enter the expected number of applicants to be shortlisted: " << endl;

  int m;

  cin >> m;

  float curr_minimum = 11.00; // as the maximum cgpa can be only upto 10
  cout << "Enter the student_id in first line and on next line name and CGPA of the applicant in < name CGPA > format : " << endl;

here:
  while (n-- and mp.size() < m)

  {

    string id;

    Candidates candidate; // Creating an object of Candidates class
    cin >> id;

    candidate.id = id;

    bool is_duplicate = (trie.search_count(id) == 0 ? false : true);

    if (is_duplicate == true)

    {

      cout << "Seems like this applicant has already applied! Enter next candidates details!!!" << endl;

      goto here;
    }
    else

    {

      trie.insert(id);
    }

    //cout << endl;
    string name;

    // cout<<"Enter the name of applicant: "<<endl;
    cin >> name;

    candidate.name = name;

    // cout<<"Enter the corresponding CGPA: "<<endl;
    float cgpa;

    scanf("%f", &cgpa);

    candidate.cgpa = cgpa;

    // cin>>candidate.skill;

    if (mp.size() == 0 && cgpa >= 7.00)

    {

      mp.insert({cgpa, name});

      mp_.insert({name,cgpa});

      curr_minimum = min(curr_minimum, cgpa);
    }
    else if (cgpa > 7.5)

    {

      mp.insert({cgpa,name});

      mp_.insert({name,cgpa});
    }
    else if (cgpa <= 7.5 && cgpa > curr_minimum)

    {

      mp.insert({cgpa,name});

      mp_.insert({name,cgpa});
    }
  }

  cout << "Do you want to print the list of shortlisted candidates? Enter 'Y' for yes and 'N' for no: ";

  ofstream ofile("shortlisted_students.doc");

  ofile << "*The selected students are*" << endl;

  char choice;

  cin >> choice;

  if (choice == 'Y')

  {

    for (auto it : mp)

    {

      ofile << it.second << "  " << it.first << endl;

      cout << it.second << " " << it.first << endl;
    }
  }

  cout << "Do you want to check whether you got shortlisted or not? Enter 'Y' for 'YES' and 'N' for 'NO' : " << endl;

  cin >> choice;

  if (choice == 'Y')

  {

    string name;

    cout << "Enter your name: ";

    cin >> name;

    if (mp_.find(name) != mp_.end())

    {

      cout << "**************Congratulations! you are shortlisted!!!**************" << endl;
    }
    else

    {

      cout << "**************Unfortunately you are not shortlisted!!!**************" << endl;
    }
  }

  return 0;
}
