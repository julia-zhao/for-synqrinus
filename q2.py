class Node: 
    def __init__ (self, data):
       self.data = data
       self.children = [] #dict of Nodes

    def insert(self, parent, data):
        if (self.data == parent):
            self.children.append(Node(data))
        else:
            #insert a child node into the last child
            self.children[-1].insert(parent, data) 

    def level(self, data, level):
        if (self.data == data): 
            return level

        #find the two children nodes that data falls between
        i = 0
        for node in self.children:
            #operating under the assumption that the inputs are in order (not random)
            if (node.data > data): 
                i-=1 
                break
            elif (node.data == data): #found the data within the children of current node
                return level + 1
            else:
                i+=1
                
        next_level = self.children[i].level(data, level+1)
        return next_level

    def print_out(self, level, num_chars, root):
        print(self.data)
        level = self.level(self.data,level+1)

        while self.children: #children is not empty 
            if (level > 1):
                s = root.make_string("",self.data)
                print (s, end = '')
            if (level > 0):
                print (u'\u2514', end = '') #check for └ (U+2514)

            self.children[0].print_out(level, num_chars + 1, root)
            self.children.pop(0) #remove this child once you have traversed through it 

    def right_check(self, data): #Check that all levels only have one children left
        if (len(self.children) > 1):
            return False
        elif (self.children):
            self.children[0].right_check(data)
        else:
            return True
    
    def make_string(self, s, data):
        if (len(self.children) > 1):
            s += u'\u2502'
        else:
            s += ' '

        #Check if data is found in one of the children nodes
        for node in self.children:
            if (node.data==data):
                return s

        if (self.data == data):
            return s

        #find the two children nodes that data falls between
        i = 0
        if (len(self.children) > 1):
            for node in self.children:
                #operating under the assumption that the inputs are in order (not random)
                if (node.data > data): 
                    i-=1 
                    break
                else:
                    i+=1

        s = self.children[i].make_string(s, data)
        return s
#end of class

def main():
    root = 0

    #loop until end of file
    with open('test.txt') as test_file:
        for line in test_file:
            data = line.strip('][ \n') #get only the data
            data = tuple([i for i in data.replace("\"", "").split(" ")])      

            if (data[1] == 'nil'):
                root = Node(data[0])
            else:
                root.insert(data[1], data[0])

    root.print_out(0, 0, root)

if __name__== "__main__":
    main()

#Case 1
# root = Node('A')
# root.insert('A', 'B')
# root.insert('B', 'C')
# root.insert('C', 'D')

#Case 2
# root = Node('A')
# root.insert('A', 'B')
# root.insert('B', 'C')
# root.insert('B', 'D')
# root.insert('A', 'E')

#Case 3
# root = Node('A')
# root.insert('A', 'B')
# root.insert('B', 'C')
# root.insert('B', 'D')
# root.insert('D', 'E')
# root.insert('B', 'F')
# root.insert('A', 'G')
# root.insert('G', 'H')

#Case 4
# root = Node('A')
# root.insert('A', 'B')
# root.insert('B', 'C')
# root.insert('C', 'D')
# root.insert('D', 'E')
# root.insert('E', 'F')
# root.insert('C', 'G')
# root.insert('A', 'H')
# root.insert('H', 'I')
# root.insert('I', 'J')
# root.insert('H', 'K')
# root.insert('K', 'L')

# level = root.level('E', 0)
# print ("level is: " + str(level))

#root.print_out(0, 0, root)