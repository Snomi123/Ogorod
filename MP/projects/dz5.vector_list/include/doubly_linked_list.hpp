#pragma once
#include <cstddef>
#include <iostream>  

namespace biv {
    template <typename T>
    class DoublyLinkedList {
    private:
        class Node {
        public:
            T value;
            Node* prev = nullptr;
            Node* next = nullptr;

            Node(const T& value) : value(value) {}

            Node(const Node&) = delete;
            Node& operator=(const Node&) = delete;
        };

        Node* begin = nullptr;
        Node* end = nullptr;

    public:
        DoublyLinkedList() noexcept = default;
        DoublyLinkedList(const DoublyLinkedList&) = delete;
        DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

        ~DoublyLinkedList() {
            Node* current = begin;
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

        std::size_t get_size() const noexcept {
            std::size_t count = 0;
            Node* current = begin;
            while (current) {
                count++;
                current = current->next;
            }
            return count;
        }

        bool has_item(const T& value) const noexcept {
            Node* current = begin;
            while (current) {
                if (current->value == value) {
                    return true;
                }
                current = current->next;
            }
            return false;
        }

        void print() const noexcept {
            Node* current = begin;
            while (current) {
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        void push_back(const T& value) {
            Node* new_node = new Node(value);
            if (!begin) {
                begin = end = new_node;
            } else {
                new_node->prev = end;
                end->next = new_node;
                end = new_node;
            }
        }

        bool remove_first(const T& value) noexcept {
            Node* current = begin;
            while (current) {
                if (current->value == value) {
                    if (current->prev) {
                        current->prev->next = current->next;
                    } else {
                        begin = current->next;
                    }
                    if (current->next) {
                        current->next->prev = current->prev;
                    } else {
                        end = current->prev;
                    }
                    delete current;
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    };
}
