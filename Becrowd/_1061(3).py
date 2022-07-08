# #1061 Event time by Neilor Tonin.

# Function to verify if the first date is less than the seccond.
from typing import Sequence


def isLater(start, end):

    if start['hour'] > end['hour']:
        return False
    elif start['hour'] == end['hour']:
        if start['min'] > end['min']:
            return False
        elif start['min'] == end['min']:
            if start['sec'] > end['sec']:
                return False
            elif start['sec'] == end['sec']:
                return 0

    # If reach this end is because the end hour is after the start.
    return True


# Receiving and generating start day.
start = {}
hourtemp = (input().split())
start['day'] = int(hourtemp[1])
hourtemp = (input().split())
start['hour'] = int(hourtemp[0])
start['min'] = int(hourtemp[2])
start['sec'] = int(hourtemp[4])
# print(start)

# Receiving and gererating the end day.
end = {}
hourtemp = (input().split())
end['day'] = int(hourtemp[1])
hourtemp = (input().split())
end['hour'] = int(hourtemp[0])
end['min'] = int(hourtemp[2])
end['sec'] = int(hourtemp[4])
# print(end)

# Calculating the duration.
duration = {}

# Day
duration['day'] = end['day'] - start['day']
later = False
if isLater(start, end) == False:
    # print('The start hour is later than the end,')
    later = True
    duration['day'] -= 1

# Hour
if (later == True):
    duration['hour'] = 24 - start['hour'] + end['hour']
else:
    duration['hour'] = end['hour'] - start['hour']

# Min
if start['min'] > end['min']:
    duration['min'] = 60 - end['min'] + start['min']
    duration['hour'] -= 1
else:
    duration['min'] = end['min'] - start['min']

# Sec
if start['sec'] > end['sec']:
    duration['sec'] = 60 - end['sec'] + start['sec']
    duration['min'] -= 1
else:
    duration['sec'] = end['sec'] - start['sec']

# Showing output.
print(f"{duration['day']} dia(s)")
print(f"{duration['hour']} hora(s)")
print(f"{duration['min']} minuto(s)")
print(f"{duration['sec']} segundo(s)")
