from collections import defaultdict

def solution(id_list, report, k):
    answer = []
    report = list(set(report))

    user = defaultdict(set)
    cnt = defaultdict(int)

    for i in report : 
        a, b = i.split()
        user[a].add(b)
        cnt[b] += 1
    
    for i in id_list :
        cnt = 0
        for j in user[i] :
            if cnt[j] >= k :
                cnt += 1
        answer.append(cnt)
    return answer
