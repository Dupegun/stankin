def select_sort(arr):
    if(len(arr) == 0): return
    for j in xrange(len(arr)):
        min = j
        for i in xrange(j+1, len(arr)):
            if(arr[i] < arr[min]): min = i
	if(min != j):
            value = arr[min]
            for l in xrange(min, j-1,-1):
                arr[l] = arr[l-1]
            arr[j] = value
