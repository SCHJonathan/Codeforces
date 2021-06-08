import in_place

f = open('in.txt')

with in_place.InPlace('in.txt') as file:
    for line in file:
        line = line.replace('[', '{')
        line = line.replace(']', '}')
        file.write(line)
