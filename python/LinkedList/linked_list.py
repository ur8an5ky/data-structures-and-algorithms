class Node:
    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node
        
    def get_value(self):
        return self.value
    
    def get_next_node(self):
        return self.next_node
    
    def set_next_node(self, next_node):
        self.next_node = next_node
        
class LinkedList:
    def __init__(self, value=None):
        self.head_node = Node(value)
    
    def get_head_node(self):
        return self.head_node
    
    def insert_beginning(self, new_value):
        new_node = Node(new_value)
        new_node.set_next_node(self.head_node)
        self.head_node = new_node
        
    def stringify_list(self):
        string_list = ""
        current_node = self.get_head_node()
        while current_node:
            if current_node.get_value() != None:
                string_list += str(current_node.get_value()) + "\n"
            current_node = current_node.get_next_node()
        return string_list
    
    def remove_node(self, value_to_remove):
        current_node = self.get_head_node()
        if current_node.get_value() == value_to_remove:
            self.head_node = current_node.get_next_node()
        else:
            while current_node:
                next_node = current_node.get_next_node()
                if next_node.get_value() == value_to_remove:
                    current_node.set_next_node(next_node.get_next_node())
                    current_node = None
                else:
                    current_node = next_node
                    
    def nth_last_node(self, n):
        n += 1
        result_node = None
        current_node = self.head_node
        count = 1

        while current_node:
            current_node = current_node.get_next_node()
            count += 1

            if count > n:
                if result_node:
                    result_node = result_node.get_next_node()
                else:
                    result_node = self.head_node

        return result_node
    
    def find_middle(self):
        middle_node = self.head_node
        current_node = self.head_node
        count = 1

        while current_node:
            if count%2 == 0:
                middle_node = middle_node.get_next_node()
            
            current_node = current_node.get_next_node()
            count += 1

        return middle_node

    def generate_test_linked_list(self, n):
        for i in range(n, 0, -1):
            self.insert_beginning(i)
        return self