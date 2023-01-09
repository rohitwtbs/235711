class File_io:
    def __init__(self):
        pass

    def read_content(self,delimiter,file_name):
        with open("input.txt") as f:
            while True:
                line = f.readLine()
                if (line == delimiter):
                    break
