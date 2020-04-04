#include <iostream>
#include <memory>
#include "cards.hh"


Cards::Cards(): top_( nullptr ) {
}


void Cards::add(int id) {
    std::shared_ptr<Card_data> new_card 
            = std::make_shared<Card_data>(Card_data{id, top_});
    top_ = new_card;
}

void Cards::print(std::ostream& s) {
   std::shared_ptr<Card_data> to_be_printed = top_;
   int nr = 1;

   while( to_be_printed != 0 ) {
      s << nr << ": " << to_be_printed->data << std::endl;
      to_be_printed = to_be_printed->next;
      ++nr;
   }
}

bool Cards::remove(int &id)
{
    if(top_ == nullptr){
        return false;
    }
    id = top_->data;
    top_ = top_->next;
    /*
    delete does not need to be used with shared pointers
    if there are no pointers pointing to any memory allocation, it will be deleted
    automatically
    */

    return true;
}

void Cards::reverse()
{
    if(top_ == nullptr or top_->next == nullptr){
        return;
    }
    std::shared_ptr<Card_data> new_top(nullptr);
    while (top_ != nullptr) {
        std::shared_ptr<Card_data> move_card_ptr(top_);
        top_ = top_->next;
        move_card_ptr->next = new_top;
        new_top = move_card_ptr;
    }
    top_ = new_top;
}

// Do not write the stubs of the methods remove and reverse by yourself here,
// but open the file reverse.hh and click the declaration of the method
// by the right mouse button and select
// Refactor > Add definition in reverse.cpp
