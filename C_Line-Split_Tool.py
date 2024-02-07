def main():

    input_list:  list = []
    output_list: list = []

    with open("Input.TXT", 'r') as input_file:
        input_list.extend(input_file.readlines())

    for input_line in input_list:
        output_line: str = "	\"" + input_line.split('\n')[0] + "`\""
        output_list.append(output_line)

    output_list[-1] += ";"

    with open("Input_C.TXT", "w+") as output_file:
        for i in range(len(output_list) - 1):
            output_file.write(output_list[i])
            output_file.write("\n")
        output_file.write(output_list[-1])


if __name__ == '__main__':
    main()