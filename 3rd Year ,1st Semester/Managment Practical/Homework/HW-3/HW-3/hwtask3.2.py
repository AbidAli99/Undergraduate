#2019380183 Mike Yondela
#2019380141 ABID ALI
#2019380135 MATMUSAEV DONIYOR
#Experiment 3
import numpy as np
import math

number = 10000

num = 32
duration = np.array(
    [0, 9, 5, 9, 10, 8, 1, 10, 6, 3, 9, 10, 4, 2, 4, 10, 9, 9, 10, 1, 7, 9, 5, 5, 3, 8, 4, 2, 1, 7, 8, 0],
    dtype=np.int32)

opduration = duration * 0.8  # Activity duration follows beta(a, b, 3- , 3+ ), a=0.8*duration, b=1.4*duration.
peduration = duration * 1.4  # Activity duration follows beta(a, b, 3- , 3+ ), a=0.8*duration, b=1.4*duration.
succ = [[1, 2, 3], [4, 9, 10], [6, 12, 17], [5, 8, 15], [14], [7, 11, 16], [21], [13], [21], [13, 28, 30], [20], [29],
        [15, 24], [24], [18], [19, 25], [22], [21], [20, 22], [23], [27], [24, 28], [29], [27, 30], [25], [26], [27],
        [29], [31], [31], [31], []]


# early_finish = [0 for _ in range(num)]


def cpm(actnum):
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

    return early_finish  # , early_start, early_finish, late_start, late_finish, free_slack, totalslack, critical_activity

    # def simulation():
    #     activity_prec = [[] for _ in range(num)]
    #     for i in range(num):
    #         for j in succ[i]:
    #             activity_prec[j].append(i)
    #
    #     pro_masp = []
    #     for i in range(number):
    #         early_start = [0 for _ in range(num)]
    #
    #         # early_finish=[0 for _ in range(num)]
    #         early_finish[0] = early_start[0] + opduration[0] + np.random.beta(3 - math.sqrt(2), 3 + math.sqrt(2)) * \
    #                           peduration[0]
    #         for i in range(1, num):
    #             early_start[i] = max(early_finish[j] for j in activity_prec[i])
    #             early_finish[i] = early_start[i] + opduration[i] + np.random.beta(3 - math.sqrt(2), 3 + math.sqrt(2)) * \
    #                               peduration[i]
    #         pro_masp.append(early_finish[-1])

    corr = np.zeros(num)
    # print(len(early_finish))
    # print(duration)
    # print(np.corrcoef(duration,early_finish)[0,1])


early_finish = cpm(num)

simd = np.zeros((number, num), dtype=np.float32)
for i in range(num):
    simd[:, 1] = duration[i] + np.random.beta(3 - math.sqrt(2), 3 + math.sqrt(2), size=(number,)) * (duration[i] - duration[i])

print(simd)

# print(duration[:,1])
# print(early_finish)

corr = np.corrcoef(simd[:,1], early_finish[i])[0, 1]
print(corr)
#
#
#     # print(duration[1:5])
#     # print(early_finish[:,1])
#
#     # for i in range(num):
#     #     print(np.corrcoef(duration, early_finish)[0, 1])
#     corr = np.corrcoef(duration, early_finish)[0, 1]
#     print(corr)
#
#     # for i in range(num):
#     #     corr[i] = np.corrcoef(duration[:, i], early_finish[:, -1])[0, 1]
#     # for i in range(num):
#     #     print('%d, %.4f' % (i, corr[i]))
#     #
#     # return pro_masp, corr
#
#
# corr_ = simulation()
#
# # if __name__ == "__main__":
# #     corr = simulation()
# print("done")
