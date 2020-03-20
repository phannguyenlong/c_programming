def findPath(path):
    for i in range(1, len(path)):
        if (int(path[i]) not in kripe_struc[int(path[i-1])][1]):
            return "No"
    return "Yes"

def checkLTL(formula, path):
    if (formula[0] == "G"):
        for i in range(0, len(path)):
            if (formula[1] not in kripe_struc[int(path[i])][0]):
                return "No"
    elif (formula[0] == "F"):
        res = "No"
        for i in range(0, len(path)):
            if (formula[1] not in kripe_struc[int(path[i])][0]):
                res = "Yes"
        return res
    elif (formula[0] == "X"):
        if (formula[1] not in kripe_struc[int(path[1])][0]):
            return "No"
    elif (formula[1] == "U"):
        res = "No"
        for i in range(1, len(path)):
            if ((formula[0] in kripe_struc[int(path[i-1])][0]) and (formula[2] in kripe_struc[int(path[i])][0])):
                res = "Yes"
        return res
    else: return "Invalid formula. Must use F,G,X,U."
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
    formula = input("Input LTL formula: ")
    if (findPath(user_path) == "Yes"):
        print(checkLTL(formula, user_path))
    else: 
        print("No. Invalid path")
except ValueError:
    print("Wrong input type. Must be number stage name")
