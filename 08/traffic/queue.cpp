#include "queue.hh"
#include <string>
#include <iostream>

using namespace std;
// Implement the member functions of Queue here



Queue::Queue(unsigned int cycle): cycle_(cycle)
{

}

Queue::~Queue()
{
    Vehicle *vehicle = dequeue();
    while (vehicle) {
        delete vehicle;
        vehicle = dequeue();
    }
}

void Queue::enqueue(string reg)
{
    if (!is_green_) {
        Vehicle* new_vehicle = new Vehicle;
        new_vehicle->reg_num = reg;
        new_vehicle->next = nullptr;
        if (!first_) {
            first_ = new_vehicle;
            last_ = new_vehicle;
        }
        else {
            last_->next = new_vehicle;
            last_ = new_vehicle;
        }
    }
    else {
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
    }
}

Queue::Vehicle *Queue::dequeue()
{
    if (first_) {
        Vehicle *vehicle = first_;
        first_ = vehicle->next;
        if (!first_)
            last_ = nullptr;
        return vehicle;
    }
    else {
        return nullptr;
    }
}

void Queue::switch_light()
{
    is_green_ = !is_green_;
    if (is_green_) {
        if (first_) {
            cout << "GREEN: Vehicle(s) ";
            for (unsigned int i = 1; i <= cycle_; i++) {
                Vehicle *vehicle = dequeue();
                if (vehicle) {
                    cout << vehicle->reg_num << " ";
                    delete vehicle;
                }
                else {
                    break;
                }
            }
            cout << "can go on" << endl;
            is_green_ = false;
        }
        else {
            print();
        }
    }
    else {
        print();
    }
}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print()
{
    if (is_green_) {
        std::cout << "GREEN: ";
    }
    else {
        std::cout << "RED: ";
    }
    if (first_) {
        cout << "Vehicle(s) ";
        Vehicle *vehicle = first_;
        while (vehicle) {
            std::cout << vehicle->reg_num << " ";
            vehicle = vehicle->next;
        }
        std::cout << "waiting in traffic lights" << std::endl;
    }
    else {
        std::cout << "No vehicles waiting in traffic lights" << std::endl;
    }
}


