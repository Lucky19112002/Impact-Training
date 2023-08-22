'''

'''

def is_html_tags_valid(html):
    stack = []  # Initialize an empty stack to keep track of open tags
    i = 0
    
    while i < len(html):
        if html[i] == '<':  # Check if the current character is the start of a tag
            j = i + 1
            while j < len(html) and html[j] != '>':
                j += 1
            if j < len(html):
                tag = html[i + 1:j]  # Extract the tag name between '<' and '>'
                if tag.startswith('/'):
                    # If the tag is a closing tag, check if the corresponding opening tag exists
                    if not stack or stack[-1] != tag[1:]:
                        return False
                    stack.pop()  # Remove the corresponding opening tag from the stack
                else:
                    stack.append(tag)  # Push the opening tag onto the stack
                i = j
            else:
                return False
        else:
            i += 1
    
    return len(stack) == 0  # If there are still unclosed tags in the stack, the HTML is invalid

input_html = input("Enter an HTML string: ")
if is_html_tags_valid(input_html):
    print("Output: yes")
else:
    print("Output: no")
