#this is implent adminstative without Role Hirrachy
ua = {"Bob": ["PCMember"], "Alice": ["Lecturer"], "Oscar": ['TA'], "Charlie": ["Student", "TA"]}
pa = {"Faculty": ['delete_course1', 'modify_course2'], "Lecturer": ['modify_course2'], "TA": ['modify_course3'], "PCMember": ["delete_course2"], "Student": ['register_to_course1']}
us = {"Alice": ['s1','s2'], "Bob": ['s2'], 'Oscar': ['s1','s2'], 'Charlie':['s1']}
rs = {"Faculty": ['s1'], "Student": ['s2'], "PCMember": ['s1'], "Lecturer": ['s1'], "TA": ['s2'], "PTEmployee": ['s2']}

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

user = input("Input user: ")
permision = input("Input permission: ")
print(Determine(user,permision))