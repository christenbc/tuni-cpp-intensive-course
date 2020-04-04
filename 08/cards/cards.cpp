#include "cards.hh"
#include <iostream>

// TODO: Implement the methods here

Cards::Cards() : top_(nullptr){

}

void Cards::add(int id){
    Card_data* new_card_ptr = new Card_data;
    new_card_ptr->data = id;
    new_card_ptr->next = top_;
    top_ = new_card_ptr;
}

void Cards::print_from_top_to_bottom(std::ostream &s){
    Card_data* current_card = top_;
    int counter = 1;

    while (current_card != nullptr) {
        s << counter << ": " << current_card->data << std::endl;
        ++counter;
        current_card = current_card->next;
    }
}

bool Cards::remove(int &id){
    if (top_ == nullptr)
        return false;

    Card_data* remove_ptr = top_;
    top_ = top_->next;                          // point to the next card address
    id = remove_ptr->data;                      // return the deleted id
    delete remove_ptr;                          // free up the memory it points to

    return true;
}

bool Cards::bottom_to_top(){
    // if there is no card, return false
    if (top_ == nullptr)
        return false;

    // if there is one card no need to do anything
    if (top_->next == nullptr)
        return true;

    // bottom is last elemenet, top is first element
    // 1. find the before last element and make it point to null
    // 2. find the last element and make it point to the first element
    // 3. update top to point to the last element

    Card_data* second_to_last_ptr = top_;
    while (second_to_last_ptr->next->next != nullptr){
        second_to_last_ptr = second_to_last_ptr->next;
    }

    Card_data* old_last_ptr = second_to_last_ptr->next;
    second_to_last_ptr->next = nullptr;

    old_last_ptr->next = top_;
    top_ = old_last_ptr;

    return true;
}

bool Cards::top_to_bottom(){
    // if there is no card, return false
    if (top_ == nullptr)
        return false;

    // if there is one card no need to do anything
    if (top_->next == nullptr)
        return true;

    // find the last pointer
    Card_data* last_ptr = top_;
    while (last_ptr->next != nullptr)
        last_ptr = last_ptr->next;

    last_ptr->next = top_;
    top_ = top_->next;
    last_ptr->next->next = nullptr;

    return true;
}

void Cards::print_from_bottom_to_top(std::ostream &s){
    recursive_print(top_, s);
}

Cards::~Cards(){
    while (top_ != nullptr) {
        int dummy;
        remove(dummy);
    }
}

int Cards::recursive_print(Cards::Card_data *top, std::ostream &s){
    if (top == nullptr)
        return 1;
    else {
        int line_num = recursive_print(top->next, s);
        s << line_num << ": " << top->data << std::endl;
        return line_num +1;
    }
}
