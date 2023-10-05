#include <iostream>
#include "lib.hpp"


int main()
{
    std::cout << "\n_____________ TASK 1 _____________\n";

    task_1::toPresentInt(555);
    task_1::toPresentInt(-555);


    std::cout << "\n_____________ TASK 2 _____________\n";

    char str_1[] = "AA BBB AAA";
    task_2::RemoveDups(str_1);
    printf("%s\n", str_1);

    char str_2[] = "AAA R BBB CCC DD F G";
    task_2::RemoveDups(str_2);
    printf("%s\n", str_2);


    std::cout << "\n_____________ TASK 3 _____________\n";

    task_3::List* obj_1 = new task_3::List();
    obj_1->addNodeToHead("Hello");
    obj_1->addNodeToHead("Buy");
    std::cout << "OBJ_1: " << obj_1->getHead()->next->data << "\n";

    FILE* ptrFile = fopen("file" , "wb");
    obj_1->Serialize(ptrFile);



    obj_1 = nullptr;
    obj_1 = new task_3::List();

    ptrFile = fopen("file" , "rb");
    obj_1->Deserialize(ptrFile);
    std::cout << "OBJ_2: " << obj_1->getHead()->next->data << "\n";

    delete obj_1;





    return 0;
}

