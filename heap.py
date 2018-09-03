def insert(arr,last,key):
	l = last
	n = int(last/2)
	arr.append(key)
	last += 1
	if n == 0:
		return last
	while arr[n] > key:
		arr[n], arr[l] = arr[l], arr[n]
		l, n = n, int(n/2)
	return last

def delete(arr, last):
	last = last-1
	arr[1] = arr[last]
	arr.pop()
	n = 1	
	while n*2 < last-1:
		smallChildIndex = n*2
		if (n*2)+1 < last:
			if arr[(n*2)+1] < arr[n*2]:
				smallChildIndex = (n*2)+1
		if arr[n] < arr[smallChildIndex]:
			break
		else:
			arr[n], arr[smallChildIndex] = arr[smallChildIndex], arr[n]
			n = smallChildIndex
	return last

arr = [0]
last = 1
last = insert(arr,last,5)
last = insert(arr,last,4)
last = insert(arr,last,10)
last = insert(arr,last,20)
last = insert(arr,last,2)
last = insert(arr,last,1)
print(arr)
last = delete(arr, last)
print(arr)
last = delete(arr, last)
print(arr)