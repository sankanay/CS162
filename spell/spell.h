#ifndef SPELL_H
#define SPELL_H
#include <string>

using namespace std;


struct spellbook {
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell* s;
};

struct spell {
  string name;
  float success_rate;
  string effect; 
};

//function prototypes
void print_spellbook(spellbook*, int, int);
void print_spells(spell*, int);
void read_input_file(string);
void create_spell_list(spellbook*, int, spell*);
int get_spell_count(spellbook*, int);
void sort_spells_by_effect(spell*, int);
void get_user_sorting_option(spellbook*, int, spell*, int);
void print_to_screen(spellbook*, int, spell*, int, int);
void print_spellbook_to_file(spellbook*, int, int, fstream &);
void print_spell_to_file(spellbook*, int, int , fstream &);
void print_to_file(spellbook*, int, spell*, int, int);
void sort_spellbooks(spellbook*, int, int);
void check_spells(spellbook*, int, ifstream &);
spellbook* create_spellbooks(int);
void get_spellbook_data(spellbook*, int, ifstream &); 
spell* create_spells(int);
void get_spell_data(spell*, int, ifstream &);
void delete_spellbook_data(spellbook*, spell*, int);


#endif