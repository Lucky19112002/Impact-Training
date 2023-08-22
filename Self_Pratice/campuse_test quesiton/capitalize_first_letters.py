def capitalize_first_letters(input_string):
    words = input_string.split()
    capitalized_words = [word.capitalize() for word in words]
    output_string = ' '.join(capitalized_words)
    print(output_string)

input_string = input("Enter a string: ")
output_string = capitalize_first_letters(input_string)
