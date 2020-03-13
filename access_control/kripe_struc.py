def findPath(path):
    for i in range(1, len(path)):
        if (int(path[i]) not in kripe_struc[int(path[i-1])][1]):
            return "No"
    return "Yes"

def initialKripe():
    for i in range(0, num_state):
        label = input("Input label for s%d: "%i)
        label = label.split(',')
        kripe_struc[i] = [label, []]

    while True:
        path = input("Set transition (press e to stop): ")
        if (path == 'e'): break
        try: 
            if (path[1] != "-"):
                print("Wrong format!. Must be <stage>-<stage>")
                continue
        except IndexError:
            print("Wrong format!. Must be <stage>-<stage>")
            continue
        path = path.split('-')
        try:
            int(path[0])
            int(path[1])
        except ValueError:
            print("Stage name must be number")
            continue
        if (int(path[0]) >= num_state or int(path[1]) >= num_state):
            print("There maxium is s%d. Try again" % (num_state-1) )
            continue
        kripe_struc[int(path[0])][1].append(int(path[1]))
        kripe_struc[int(path[0])][1] = list(set(kripe_struc[int(path[0])][1])) # remove duplicate

kripe_struc = {}
try:
    num_state = int(input("How many state? "))
    initialKripe()
    user_path = input("Check if the path belongs to Kripe structure: ")
    user_path = user_path.split('-')
    print(findPath(user_path))
except ValueError:
    print("Wrong input type. Must be number stage name")
