#this is implent adminstative without Role Hirrachy
import copy
ua = {"Bob": ["PCMember"], "Alice": ["Lecturer"], "Oscar": ['TA'], "Charlie": ["Student", "TA"]}
pa = {"Faculty": ['delete_course1', 'modify_course2'], "Lecturer": ['modify_course2'], "TA": ['modify_course3'], "PCMember": ["delete_course2"], "Student": ['register_to_course1']}
us = {"Alice": ['s1','s2'], "Bob": ['s2'], 'Oscar': ['s1','s2'], 'Charlie':['s1']}
rs = {"Faculty": ['s1'], "Student": ['s2'], "PCMember": ['s1'], "Lecturer": ['s1'], "TA": ['s2'], "PTEmployee": ['s2']}
member = ["Bob", "Alice", "Oscar", "Charlie"]

def Determine(user, permision):
    for i in range(0, len(ua[user])):
        role = ua[user][i]
        for j in range(0, len(rs[role])):
            role_session = rs[role][j]
            for x in range(0, len(us[user])):
                user_session = us[user][x]
                if (role_session == user_session):
                    for z in range(0, len(pa[role])):
                        if (pa[role][z] == permision):
                            return "Yes"
    return "No"

def getMemberFromRole(condition):
    res_mem = []
    for mem in member:
        cond_count = 0 # to count how manny condition it pass
        for cond in condition:
            if (cond[0] == "-"): cond_count+=1 #increase 1 statisfield condition if it pas
            for i in range(0, len(ua[mem])):
                if (ua[mem][i] == cond[1:] and cond[0] == "+"): # if pass 1 condition ==> +count
                    cond_count += 1
                elif (ua[mem][i] == cond[1:] and cond[0] == "-"): # if fail "-" condition ==> -count
                    cond_count -= 1
        if (cond_count == len(condition)): # if number of conditon pass = number of condition
            res_mem.append(mem)
    if not (res_mem): res_mem.append('none')
    return res_mem

def can_assign(ca, c, role):
    admin = getMemberFromRole(ca)[0]
    users = getMemberFromRole(c)
    for user in users:
        if (user != 'none' and admin != 'none'):
            ua[user].append(role)
    log = "Admin: {%s} is %s assign role '%s' to users {%s} is {%s}\n"% (','.join(ca),admin, role, ",".join(c),",".join(users))
    return log
def can_revoke(ca, role, none):
    admin = getMemberFromRole(ca)[0]
    role = "+" + role
    users = getMemberFromRole([role])
    for user in users:
        if (user != 'none' and admin != 'none'):
            ua[user].remove(role[1:])
    log = "Admin: {%s} is %s revoke role '%s' from users {%s}\n"% (','.join(ca),admin, role, ",".join(users))
    return log

def swap_role(user, permision):
    global ua # has to use or python will auto think ua become a local variable
    temp = copy.deepcopy(ua) # make a deep copy
    arr=[can_assign,can_revoke,can_assign]
    param = [[["+Falcuty"], ["+TA","-Student"], "Lecturer"],[["+Falcuty"], "Student", 'none'], [["+PCMember"], ["+Lecturer"], "Falcuty"]]
    if (Determine(user, permision) == "Yes"):
        return "Yes"
    for i in range(0,3):
        for j in range(0,3):
            if (i==j): continue
            for x in range(0,3):
                if (x==j or x==i): continue
                log = ''
                log += arr[i](param[i][0],param[i][1],param[i][2])
                log += arr[j](param[j][0],param[j][1],param[j][2])
                log += arr[x](param[x][0],param[x][1],param[x][2])
                if (Determine(user, permision) == "Yes"):
                    print(log)
                    return "Yes"
                else:
                    ua = copy.deepcopy(temp) # set dictionary to defaul
                print(100*"=")
    return "No" 

user = input("Input user: ")
permision = input("Input permission: ")

print("Can %s has permission %s?"%(user, permision))
try:
    print("Answer is:",swap_role(user,permision))
except KeyError:
    print("Wrong user or permission")