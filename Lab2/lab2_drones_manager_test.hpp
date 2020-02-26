#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
	}

	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));

		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))
	    return true;
	}

	// TODO: Implement all of the test cases below

	// PURPOSE: select() and search() work properly
	bool test3() {
	    DronesManager manager1;
	    manager1.insert_front(DronesManager::DroneRecord(1));
        manager1.insert_back(DronesManager::DroneRecord(2));
	    manager1.insert_back(DronesManager::DroneRecord(3));

	    ASSERT_TRUE(manager1.select(1) == DronesManager::DroneRecord(2))
	    ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(3)) == 2)
	    return true;
	}

	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
	    DronesManager manager1, manager2;
	    manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_front(DronesManager::DroneRecord(100));

		manager1.remove_front();
		manager2.remove_back();

		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 0)
		ASSERT_TRUE(manager1.empty() == true)
        ASSERT_TRUE(manager2.empty() == true)
        ASSERT_TRUE(manager1.first == NULL)
        ASSERT_TRUE(manager1.last == NULL)
        ASSERT_TRUE(manager2.first == NULL)
        ASSERT_TRUE(manager2.last == NULL)
        return true;
	}

	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
	    DronesManager manager1, manager2, manager3;
	    manager1.insert_back(DronesManager::DroneRecord(1));
        manager1.insert_back(DronesManager::DroneRecord(6));
	    manager1.insert_back(DronesManager::DroneRecord(3));

	    manager2.insert_back(DronesManager::DroneRecord(1));
        manager2.insert_back(DronesManager::DroneRecord(2));
	    manager2.insert_back(DronesManager::DroneRecord(3));

	    manager3.insert_back(DronesManager::DroneRecord(3));
        manager3.insert_back(DronesManager::DroneRecord(2));
	    manager3.insert_back(DronesManager::DroneRecord(1));

	    manager1.replace(1, DronesManager::DroneRecord(2));

	    for(int i = 0; i < manager1.get_size(); i++)
        {
            ASSERT_TRUE(manager1.select(i) == manager2.select(i))
        }

	    manager1.reverse_list();

	    for(int i = 0; i < manager1.get_size(); i++)
        {
            ASSERT_TRUE(manager1.select(i) == manager3.select(i))
        }

	    return true;
	}

	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
	    DronesManager manager1;
	    manager1.insert_front(DronesManager::DroneRecord(1));
        manager1.insert_front(DronesManager::DroneRecord(6));

        ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(1)) == 1)

	    manager1.insert_front(DronesManager::DroneRecord(3));

	    ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(1)) == 2)

	    manager1.insert_front(DronesManager::DroneRecord(5));

	    ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(1)) == 3)

	    return true;
	}

	// PURPOSE: inserting at different positions in the list
	bool test7() {
	    DronesManager manager1;
	    manager1.insert_back(DronesManager::DroneRecord(1));
	    manager1.insert_back(DronesManager::DroneRecord(3));

	    manager1.insert(DronesManager::DroneRecord(2), 3);

	    ASSERT_TRUE(manager1.get_size() == 2)

	    manager1.insert(DronesManager::DroneRecord(2), 2);

        ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(2)) == 2)
        ASSERT_TRUE(manager1.get_size() == 3)

        manager1.insert(DronesManager::DroneRecord(9), 0);

        ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(9)) == 0)
        ASSERT_TRUE(manager1.get_size() == 4)

	    return true;
	}

	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
	    return false;
	}

	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		return false;
	}

	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
	   return false;
	}
};

#endif
