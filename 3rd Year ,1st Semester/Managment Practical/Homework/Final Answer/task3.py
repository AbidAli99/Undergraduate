import numpy as np
import math

number = 10000
num = 32
duration = np.array([0,9,5,9,10,8,1,10,6,3,9,10,4,2,4,10,9,9,10,1,7,9,5,5,3,8,4,2,1,7,8,0], dtype=np.int32)
opduration = duration*0.8
peduration = duration*1.4
succ = [[1,2,3],[4,9,10],[6,12,17],[5,8,15],[14],[7,11,16],[21],[13],[21],[13,28,30],[20],[29],[15,24],[24],[18],[19,25],[22],[21],[20,22],[23],[27],[24,28],[29],[27,30],[25],[26],[27],[29],[31],[31],[31],[]]

def riskanalysis():
	prec=[[] for _ in range(num)]
	for i in range(num):
		for j in succ[i]:
			prec[j].append(i)
	
	simduration = np.zeros((number,num),dtype=np.float32)
	for i in range(num):
		simduration[:,i] = opduration[i]+np.random.beta(3-math.sqrt(2),3+math.sqrt(2),size=(number,))*(peduration[i]-opduration[i])
	
	earlystart = np.zeros((number,num),dtype=np.float64)
	earlyfinish = np.zeros((number,num),dtype=np.float64)
	latestart = np.zeros((number,num),dtype=np.float64)
	latefinish = np.zeros((number,num),dtype=np.float64)
	totalfloat = np.zeros((number,num),dtype=np.float64)
	
	earlyfinish[:,0] = earlystart[:,0] + simduration[:,0]
	for i in range(1,num):
		earlystart[:,i] = np.max(earlyfinish[:,prec[i]], axis=1)
		earlyfinish[:,i] = earlystart[:,i] + simduration[:,i]
	
	latefinish[:,-1] = earlyfinish[:,-1]
	latestart[:,-1] = earlystart[:,-1]
	for i in range(num-2,-1,-1):
		latefinish[:,i] = np.min(latestart[:,succ[i]], axis=1)
		latestart[:,i] = latefinish[:,i] - simduration[:,i]
	
	totalfloat = latestart - earlystart
	ci = np.sum(totalfloat == 0, axis=0)/number
	
	cri = np.zeros(num)
	for i in range(num):
		cri[i] = np.corrcoef(simduration[:,i], earlyfinish[:,-1])[0,1]
	
	return ci, cri #return the Criticality Index and Cruciality Index of each activity

if __name__ == "__main__":
	ci, cri = riskanalysis()