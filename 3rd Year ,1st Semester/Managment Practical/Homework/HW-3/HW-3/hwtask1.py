#2019380183 Mike Yondela
#2019380141 ABID ALI
#2019380135 MATMUSAEV DONIYOR
#Experiment 1
import numpy as np

actnum = 32
duration = np.array(
    [0, 9, 5, 9, 10, 8, 1, 10, 6, 3, 9, 10, 4, 2, 4, 10, 9, 9, 10, 1, 7, 9, 5, 5, 3, 8, 4, 2, 1, 7, 8, 0],
    dtype=np.int32)
succ = [[1, 2, 3], [4, 9, 10], [6, 12, 17], [5, 8, 15], [14], [7, 11, 16], [21], [13], [21], [13, 28, 30], [20], [29],
        [15, 24], [24], [18], [19, 25], [22], [21], [20, 22], [23], [27], [24, 28], [29], [27, 30], [25], [26], [27],
        [29], [31], [31], [31], []]


def cpm():
    # earlystart early start time of each activity
    early_start = [0 for _ in range(actnum)]
    # earlyfinish early finish time of each activity
    early_finish = [0 for _ in range(actnum)]
    # latestart late start time of each activity
    late_start = [0 for _ in range(actnum)]
    # late_finish late finish time of each activity
    late_finish = [0 for _ in range(actnum)]
    # free_slack free slack of each activity
    free_slack = [0 for _ in range(actnum)]
    # totalslack total slack of each activity
    totalslack = [0 for _ in range(actnum)]
    # critical critical activities of the project
    critical_activity = []

    activity_prec = [[] for _ in range(actnum)]
    for i in range(actnum):
        for j in succ[i]:
            activity_prec[j].append(i)

    for i in range(1, actnum):
        early_start[i] = max(early_finish[j] for j in activity_prec[i])
        early_finish[i] = early_start[i] + duration[i]

    late_start[-1] = early_finish[-1]
    late_finish[-1] = early_finish[-1]

    for i in range(actnum - 2, -1, -1):
        late_finish[i] = min(late_start[j] for j in succ[i])
        late_start[i] = late_finish[i] - duration[i]

    for i in range(actnum - 1):
        free_slack[i] = min(early_start[j] for j in succ[i]) - early_finish[i]
        totalslack[i] = late_start[i] - early_start[i]

    for i in range(actnum):
        if totalslack[i] == 0:
            critical_activity.append(i)

    return early_start, early_finish, late_start, late_finish, free_slack, totalslack, critical_activity


if __name__ == "__main__":
    early_start, early_finish, late_start, late_finish, free_slack, total_slack, critic_activity = cpm()
    print(early_finish)
    print('The early start, early finish, late start, late finish, free slack, total slack of each activity are:')
    for i in range(actnum):
        print('%d: %-4d%-4d%-4d%-4d%-4d%-4d' % (i, early_start[i], early_finish[i], late_start[i], late_finish[i],
                                                free_slack[i], total_slack[i]))
    print("The critic activities of this project are:")

    for acvitity in critic_activity:
        print(acvitity, end=" ")
