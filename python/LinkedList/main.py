from linked_list import Node, LinkedList

def swap_nodes(input_list, val1, val2):
  print(f'Swapping {val1} with {val2}')

  node1_prev = None
  node2_prev = None
  node1 = input_list.head_node
  node2 = input_list.head_node

  if val1 == val2:
    print("Elements are the same - no swap needed")
    return

  while node1 is not None:
    if node1.get_value() == val1:
      break
    node1_prev = node1
    node1 = node1.get_next_node()

  while node2 is not None:
    if node2.get_value() == val2:
      break
    node2_prev = node2
    node2 = node2.get_next_node()

  if (node1 is None or node2 is None):
    print("Swap not possible - one or more element is not in the list")
    return

  if node1_prev is None:
    input_list.head_node = node2
  else:
    node1_prev.set_next_node(node2)

  if node2_prev is None:
    input_list.head_node = node1
  else:
    node2_prev.set_next_node(node1)

  temp = node1.get_next_node()
  node1.set_next_node(node2.get_next_node())
  node2.set_next_node(temp)

###########################################################################
#####       Adding Nodes to Linked List
###########################################################################
print("Adding Nodes to LinkedList:")
node1 = Node(1)
node2 = Node(2, node1)
node3 = Node(3)
node1.set_next_node(node3)
node4 = Node(4, node2)
node5 = Node(5)
node3.set_next_node(node5)

ll1 = LinkedList(0)
ll1.get_head_node().set_next_node(node4)
print(ll1.stringify_list())

###########################################################################
#####       Swapping Elements in a Linked List
###########################################################################
print("\n\nTest of Nodes swapping\nLinkedList before swapping:")
ll2 = LinkedList()
for i in range(10):
  ll2.insert_beginning(i)

print(ll2.stringify_list())
print("LinkedList after swapping:")
swap_nodes(ll2, 9, 5)
print(ll2.stringify_list())

###########################################################################
#####       Two-Pointer Linked List Techniques
###########################################################################
print("\n\nTest of two-pointer techniques\nLinkedList generation:")
ll3 = LinkedList()

ll3.generate_test_linked_list(12)
print(ll3.stringify_list())

print("4-th last node in LinkedList:")
nth_last = ll3.nth_last_node(4)
print(nth_last.value)

print("\nMiddle node in LinkedList:")
middle_node = ll3.find_middle()
print(middle_node.value)