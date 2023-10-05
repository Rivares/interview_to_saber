#pragma once

#include <iostream>

namespace task_1
{
    void toPresentInt(int value)
    {
        constexpr uint8_t digits = sizeof(int) * 8;
        constexpr int max = (2 << (digits - 2));

        // std::cout << value << "\t" << max << "\n";

        while (value != 0)
        {
            std::cout << ((value & max) ? '1' : '0');
            value <<= 1;
        }
        std::cout << "\n";
    }
}

namespace task_2
{
    void RemoveDups(char* str)
    {
        if (str == nullptr)
        {   return; }

        size_t idx = 0;
        for (; str[idx] != '\0'; ++idx)
        {
            size_t idy = idx + 1;

            if (str[idy] == '\0')
            {   return; }

            if (str[idx] == str[idy])
            {
                for (; str[idy] != '\0'; ++idy)
                {
                    if (str[idx] != str[idy])
                    {
                        size_t shift = idx + 1;
                        for (size_t idz = idy; str[idz - 1] != '\0'; ++idz)
                        {
                            str[shift + (idz - idy)] = std::move(str[idz]);
                        }
                        break;
                    }
                }
            }

            if (str[idy] == '\0')
            {
                str[idx + 1] = '\0';
                break;
            }
        }
    }
}

namespace task_3
{
    #include <string>
    #include <cstdio>
    #include <string.h>


    struct ListNode
    {
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* rand = nullptr;
        std::string data = "";
    };

    class List
    {
    public:

        List() = default;

        void addNodeToHead(std::string data_)
        {
            ListNode* newNode = new ListNode{nullptr,
                                             nullptr,
                                             nullptr,
                                             data_};
            newNode->next = head;
            newNode->prev = nullptr;

            if (head != nullptr)
            {
                head->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            head = newNode;

            ++count;
        }

        void addNodeToTail(std::string data_)
        {
            ListNode* newNode = new ListNode{nullptr,
                                         nullptr,
                                         nullptr,
                                         data_};

            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                tail->next = newNode;
            }
            tail = newNode;

            ++count;
        }

        ListNode* getHead() const
        {
            return head;
        }

        ListNode* getTail() const
        {
            return tail;
        }

        int getCount() const
        {
            return count;
        }

        void Serialize(FILE* file)
        {
            fwrite(this , 1 , sizeof(*this) , file);
            fclose(file);

        }
        void Deserialize(FILE* file)
        {
            if (file == nullptr)
            {
                fputs("Error. File is not exsit\n", stderr);
                exit(1);
            }

            fseek(file , 0 , SEEK_END);
            long lSize = ftell(file);
            rewind (file);

            List* buffer = (List*) malloc(sizeof(List) * lSize);
            if (buffer == nullptr)
            {
                fputs("Error allocation memory\n", stderr);
                exit(2);
            }

            size_t result = fread(buffer, 1, lSize, file);
            if (result != lSize)
            {
                fputs("Error reading\n", stderr);
                exit (3);
            }

            fclose(file);


            head = buffer->head;
            tail = buffer->head;
            count = buffer->count;

            free (buffer);
        }
    private:
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int count = 0;
    };
}
