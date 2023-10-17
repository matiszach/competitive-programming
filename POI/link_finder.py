import requests

rootdir = input('path of the folder with codes: ')
newdir = input('path of the new folder: ')

if rootdir[-1] != '/':
    rootdir += '/'

if newdir[-1] != '/':
    newdir += '/'

URL = "https://szkopul.edu.pl/task_archive/oi/"
page = requests.get(URL)

special_chars = {'ą': 'a', 'ć': 'c', 'ę': 'e', 'ł': 'l', 'ń': 'n', 'ó': 'o', 'ś': 's', 'ż': 'z', 'ź': 'z'}
content = page.text

content = content.lower()
for c in special_chars.keys():
    content.replace(c, special_chars[c])

def matching(a, b):
    matches = 0
    a = a.lower()
    a.replace(' ', '')
    b.replace(' ', '')
    idx = 0
    for i in range(min(len(a), len(b))):
        idx += 1
        if idx - matches > 2:
            break

        if a[i] == b[i]:
            matches += 1

    if (a[-1] != b[-1]) and (b[-1] != '('):
        matches -= 1
    return matches / len(a)


def get_link(name):
    best_match, best_pos = 0, 0
    for i in range(len(content) - len(name) - 2):
        tmp = content[i: i + len(name) + 2]
        res = matching(name, tmp)
        if res > best_match:
            best_match = res
            best_pos = i

    pos = best_pos
    while content[pos: pos + 4] != 'href':
        pos -= 1
    nd = content.find('"', pos + 6)
    return "szkopul.edu.pl" + content[pos + 6: nd]


import os

counter = 1
for subdir, dirs, files in os.walk(rootdir):
    for file in files:
        name = os.path.join(subdir, file)
        print('#', counter)
        counter += 1
        if name[-3:] == 'cpp':
            filename = name[name.rfind('/') + 1:]
            folder = name[name.rfind('/', 0, len(name) - len(filename) - 1): name.rfind('/')]
            if not os.path.exists(newdir + folder):
                os.makedirs(newdir + folder)

            curr = open(name, 'r').read()
            print(filename[:-4])
            curr = "//Task statement: " + get_link(filename[: -4]) + "\n" + curr
            _file = open(newdir + folder + '/' + filename, 'w')
            _file.write(curr)
            _file.close()
