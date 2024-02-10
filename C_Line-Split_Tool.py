def main():

    input_list:  list = []
    output_list: list = []
    
    longest_str: list = ["", 0]

    with open("Input.TXT", 'r') as input_file:
        input_list.extend(input_file.readlines())

    for input_line in input_list:
        input_str: str = input_line.split('\n')[0]
        output_line: str = "	\"" + input_str + "`\""
        output_list.append(output_line)
        
        if len(input_str) > longest_str[1]:
            longest_str[0] = input_str
            longest_str[1] = len(input_str)
            
    print(f"Longest String: {longest_str[0]} | Length: {longest_str[1]}")

    output_list[-1] += ";"

    with open("Input_C.TXT", "w+") as output_file:
        for i in range(len(output_list) - 1):
            output_file.write(output_list[i])
            output_file.write("\n")
        output_file.write(output_list[-1])


if __name__ == '__main__':
    main()