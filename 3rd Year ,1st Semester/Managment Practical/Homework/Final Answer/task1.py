import numpy as np
actnum = 32
duration = np.array([0,9,5,9,10,8,1,10,6,3,9,10,4,2,4,10,9,9,10,1,7,9,5,5,3,8,4,2,1,7,8,0], dtype=np.int32)
succ = [[1,2,3],[4,9,10],[6,12,17],[5,8,15],[14],[7,11,16],[21],[13],[21],[13,28,30],[20],[29],[15,24],[24],[18],[19,25],[22],[21],[20,22],[23],[27],[24,28],[29],[27,30],[25],[26],[27],[29],[31],[31],[31],[]]

def cpm():
	prec=[[] for _ in range(actnum)]
	for i in range(actnum):
		for j in succ[i]:
			prec[j].append(i)
	
	earlystart= np.zeros((actnum,), dtype=np.int32)
	earlyfinish= np.zeros((actnum,), dtype=np.int32)
	earlyfinish[0]= earlystart[0] + duration[0]
	for i in range(1,actnum):
		earlystart[i] = np.max(earlyfinish[prec[i]])
		earlyfinish[i] = earlystart[i]+duration[i]
	
	latestart=np.zeros((actnum,), dtype=np.int32)
	latefinish=np.zeros((actnum,), dtype=np.int32)
	latefinish[-1] = earlyfinish[-1]
	latestart[-1] = earlystart[-1]
	for i in range(actnum-2,-1,-1):
		latefinish[i]=np.min(latestart[succ[i]])
		latestart[i]=latefinish[i]-duration[i]
	
	totalslack =  latestart -  earlystart
	freeslack = np.zeros(actnum, dtype=np.int32)
	for i in range(actnum-1):
		freeslack[i] = np.min(earlystart[succ[i]]) - earlyfinish[i]
	
	critical = []
	for i in range(actnum):
		if totalslack[i] == 0:
			critical.append(i)
	return earlystart,earlyfinish,latestart,latefinish,freeslack,totalslack,critical

if __name__ == "__main__":
	early_start,early_finish,late_start,late_finish,free_slack,total_slack,critic_activity = cpm()
	print('The early start, early finish, late start, late finish, free slack, total slack of each activity are:')
	for i in range(actnum):
		print('%d: %-4d%-4d%-4d%-4d%-4d%-4d' %(i,early_start[i],early_finish[i],late_start[i],late_finish[i],
			free_slack[i],total_slack[i]))
	print("The critic activities of this project are:")
	for acvitity in critic_activity:
		print(acvitity,end=" ")