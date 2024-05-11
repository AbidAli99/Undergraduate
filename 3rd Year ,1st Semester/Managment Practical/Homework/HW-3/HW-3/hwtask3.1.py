import numpy as np
import math
number = 10000
num = 32
duration = np.array([0,9,5,9,10,8,1,10,6,3,9,10,4,2,4,10,9,9,10,1,7,9,5,5,3,8,4,2,1,7,8,0], dtype=np.int32)
opduration = duration*0.8  #Activity duration follows beta(a, b, 3- , 3+ ), a=0.8*duration, b=1.4*duration.
peduration = duration*1.4  #Activity duration follows beta(a, b, 3- , 3+ ), a=0.8*duration, b=1.4*duration.
succ = [[1,2,3],[4,9,10],[6,12,17],[5,8,15],[14],[7,11,16],[21],[13],[21],[13,28,30],[20],[29],[15,24],[24],[18],[19,25],[22],[21],[20,22],[23],[27],[24,28],[29],[27,30],[25],[26],[27],[29],[31],[31],[31],[]]
def riskanalysis():   
    activity_prec=[[] for _ in range(num)]
    for i in range(num):
        for j in succ[i]:
            activity_prec[j].append(i)            
    ci=[]
    for i in range(number):
        early_start=[0 for _ in range(num)]
        early_finish=[0 for _ in range(num)]
        late_start = [0 for _ in range(num)]
        free_slack = [0 for _ in range(num)]
        totalslack = [0 for _ in range(num)]
        totalfloat = [0 for _ in range(num)]
        early_finish[0]=early_start[0]+opduration[0]+\
            np.random.beta(3-math.sqrt(2),3+math.sqrt(2))*peduration[0]
        for i in range(1,num):
            early_start[i] = max(early_finish[j] for j in activity_prec[i])
            early_finish[i] = early_start[i]+opduration[i]+\
                np.random.beta(3-math.sqrt(2),3+math.sqrt(2))*peduration[i]
        for i in range(num - 1):
            free_slack[i] = min(early_start[j] for j in succ[i]) - early_finish[i]
            totalslack[i] = late_start[i] - early_start[i]
        ci.append(early_finish[-1])
 
        return ci
        
        for acvitity in ci:


         totalfloat =late_start - early_start
        ci =np.sum(totalfloat == 0,axis=0)/number
        for i in range (num):
            print('%d, %.4f'%(i,ci[i]))


if __name__ == "__main__":
	   ci = riskanalysis()
print(ci)