'''
Pyhton  datatypes.
'''

program_1_list=[]
print("Enter the list values",input(program_1_list))
pos1 = 0
pos2 = 0
print("Enter the pstiton of the value u want to change: " , input(pos1),input(pos2))
program_1_list[pos1],program_1_list[pos2] =program_1_list[pos2],program_1_list[pos1] 
print("After swap : \n",program_1_list)