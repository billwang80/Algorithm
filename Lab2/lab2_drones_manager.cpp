#include "lab2_drones_manager.hpp"

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
}

DronesManager::~DronesManager() {
}

//finished
bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
    if(lhs.batteryType != rhs.batteryType)
        return false;
    if(lhs.description != rhs.description)
        return false;
    if(lhs.droneID != rhs.droneID)
        return false;
    if(lhs.droneType != rhs.droneType)
        return false;
    if(lhs.manufacturer != rhs.manufacturer)
        return false;
    if(lhs.range != rhs.range)
        return false;
    if(lhs.yearBought != rhs.yearBought)
        return false;

	return true;
}

// finished
unsigned int DronesManager::get_size() const {
	return size;
}

// finished
bool DronesManager::empty() const {
	if(size == 0)
        return true;
	return false;
}

// finished
DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
    DroneRecord* selected = first;

    if(empty())
        return DroneRecord(0);
    if(index > size)
        return *last;

	for(int i = 0; i < index; i++)
	{
	    selected = selected -> next;
	}

	return *selected;
}

// finished
unsigned int DronesManager::search(DroneRecord value) const {
	DroneRecord* selected = first;

	if(empty())
        return 0;

    for(int i = 0; i < size; i++)
    {
        if(*selected == value)
            return i;
        selected = selected -> next;
    }
	return size;
}

void DronesManager::print() const {
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	return false;
}

// finished
bool DronesManager::insert_front(DroneRecord value) {
    // creates pointer for prev first and new value
    DroneRecord* temp = first;
    DroneRecord* newFirst = &value;

    // set the pointer of first of linkedlist to new first
    first = newFirst;
    // set next pointer of new value to old first
    newFirst -> next = temp;
    // set prev pointer of old first to new value
    temp -> prev = newFirst;
    size++;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	return false;
}

bool DronesManager::remove(unsigned int index) {
	return false;
}

// finished
bool DronesManager::remove_front() {
    if(size == 0)
        return false;

    DroneRecord *temp = first;


    temp = temp -> next;
    first = temp;
    // deleting the node
    temp -> prev -> next = NULL;
    delete(temp -> prev);
    temp -> prev = NULL;
    size--;
    return true;
}

// finished
bool DronesManager::remove_back() {
	if(size == 0)
        return false;

	DroneRecord *temp = last;

    temp = temp -> prev;
    last = temp;
    // deleting the node
    temp -> next -> prev = NULL;
    delete(temp -> next);
    temp -> next = NULL;
    size--;
    return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	return false;
}

// finished
bool DronesManager::reverse_list() {
    if(size <= 1)
        return true;

    // reverse first node and last node
    DroneRecord* temp = first;
    first = last;
    last = temp;

    DroneRecord* selected = last;
    for(int i = 0; i < size; i++)
    {
        DroneRecord* temp = selected -> next;
        selected -> next = selected -> prev;
        selected -> prev = temp;
        selected = selected -> prev;
    }
	return true;
}

